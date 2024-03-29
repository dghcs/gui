﻿/*!
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: server.cpp
\brief  CServer 

\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2019/4
*/
#include <QtNetwork>
#include <QTcpSocket>
#include "server.h"

CServer::CServer():QObject(){
    // 创建服务端对象
    tcpServer = new QTcpServer(this);
    
    connect(tcpServer, &QTcpServer::newConnection,
        this, &CServer::sendData);

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

void CServer::sendData()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);
    QTime tm = QTime::currentTime();
    out << tm;
    QString str = "Hi! This is server talking.";
    out << str;
    qDebug("new client connected.");
    // 取得下一个客户端连接对象
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();

    connect(clientConnection, &QAbstractSocket::disconnected,
        clientConnection, &QObject::deleteLater);
   
    clientConnection->write(block);
    clientConnection->disconnectFromHost(); 
}