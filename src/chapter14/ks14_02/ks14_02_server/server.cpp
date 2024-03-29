﻿/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: server.cpp
\brief  CServer 
        本示例用于演示服务端响应多个客户端请求
        且服务端与客户端单次传输的数据量较少的情况。

\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2019/4
*/
#include "server.h"

#include <QApplication>
#include <QMutexLocker>
#include <QtNetwork>
#include <QTcpSocket>
#include "clientconnection.h"
#include "task.h"

CServer::CServer():QObject(){
    // 创建服务端对象
    tcpServer = new QTcpServer(this);
    
    connect(tcpServer, &QTcpServer::newConnection,
        this, &CServer::slot_newConnection);
}

CServer::~CServer() {

}
bool CServer::startListen()
{
     //启动监听
    if (!tcpServer->listen()) {
        qDebug("startlisten failed");
        return false;
    }
    qDebug("server port:%d", tcpServer->serverPort());
    return true;
}

void CServer::slot_newConnection()
{   
    qDebug("new client connected.");
    // 取得下一个客户端连接对象
    QTcpSocket *pClientSocket = tcpServer->nextPendingConnection();

    connect(pClientSocket, &QAbstractSocket::disconnected,
        this, &CServer::slot_disconnected);
    //    pClientSocket, &QObject::deleteLater);
    connect(pClientSocket, &QIODevice::readyRead, 
        this, &CServer::slot_readyToRead);

    CClientConnection* pConnection = new CClientConnection(pClientSocket, this);
    CHelloTask* pTask = new CHelloTask;
    pConnection->addTask(pTask);
    pConnection->sendDeal(); // pTask在该接口内部已释放

    m_clientSockets.append(pClientSocket);
}
void CServer::slot_disconnected()
{
    QTcpSocket *pClientSocket = dynamic_cast<QTcpSocket*>(sender());
    
    m_clientSockets.removeAll(pClientSocket);

    pClientSocket->deleteLater();
}
void CServer::slot_readyToRead()
{
    QDataStream inStream;
    QTcpSocket *pClientSocket = dynamic_cast<QTcpSocket *>(sender());
    inStream.setDevice(pClientSocket);
    inStream.setVersion(QDataStream::Qt_5_11);

    inStream.startTransaction(); // 启动事务

    ETASKTYPE taskType = CTask::parseTaskType(inStream);
    CTask* pTask = CTask::createTask(taskType);
    if (NULL == pTask) {
        inStream.rollbackTransaction(); // 回滚事务
        return;
    }

    pTask->parseFrame(inStream); // 解析收到的数据

    if (!inStream.commitTransaction()) { // 数据没有接收完毕，返回。
        delete pTask;
        return;
    }

    CHelloTask* pHelloTask = NULL;
    CSetOneDataTask* pSetOneDataTask = NULL;
    CGetOneDataTask* pGetOneDataTask = NULL;
    COneDataReturnedTask* pOneDataReturnedTask = NULL;
    QString str;
    switch (taskType) {
     case ETASK_SETONEDATA: // 设置数据
        pSetOneDataTask = dynamic_cast<CSetOneDataTask*>(pTask);
        if (NULL != pSetOneDataTask) {
            qint32 id = pSetOneDataTask->getDataId();
            qreal value = pSetOneDataTask->getDataValue();
            setData(id, value);
            qDebug("setData:%d, %f", id, value);
        }
        break;
    case ETASK_GETONEDATA:
        pGetOneDataTask = dynamic_cast<CGetOneDataTask*>(pTask);
        if (NULL != pGetOneDataTask) {
            qint32 id = pGetOneDataTask->getDataId();
            qreal value = getDataById(id);
            qDebug("getData:%d, %f", id, value);
            
            pOneDataReturnedTask = new COneDataReturnedTask;
            pOneDataReturnedTask->setDataId(id);
            pOneDataReturnedTask->setDataValue(value);

            QDataStream ds;
            ds.setDevice(pClientSocket);
            ds.setVersion(QDataStream::Qt_5_11);
            pOneDataReturnedTask->sendFrame(ds);
            delete pOneDataReturnedTask;
            pOneDataReturnedTask = NULL;
        }
        break;
    default:
        break;
    }

    delete pTask;
}

qreal CServer::getDataById(qint32 id) 
{
    QMutexLocker locker(&m_mtxData);
    QMap<qint32, qreal>::ConstIterator ite = m_mapData.constFind(id);
    if (ite != m_mapData.constEnd()) {
        return (ite.value());
    }
    return 0;
}

void CServer::setData(qint32 id, qreal value)
{
    QMutexLocker locker(&m_mtxData);
    m_mapData[id] = value;
}
