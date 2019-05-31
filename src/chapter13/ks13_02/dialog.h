/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: dialog.h
\brief  CDialog�ඨ��ͷ�ļ�

\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2018/9
*/

#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialogbase.h" // ͷ�ļ���������: dialogbase.ui  ---> ui_dialogbase.h

QT_BEGIN_NAMESPACE
class QEvent;
QT_END_NAMESPACE


class CRecvThread;
class CSendThread;

class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* pParent);
	~CDialog();

protected:
    virtual void customEvent(QEvent *event);

private slots:
	void on_startthread();

private:
    Ui::CDialogBase ui;
    CRecvThread* m_pRecvThread;
    CSendThread* m_pSendThread;
};

#endif