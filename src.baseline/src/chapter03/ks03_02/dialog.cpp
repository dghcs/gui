/*!
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: dialog.cpp
\brief ʾ��ʵ���ļ�

\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2018/9
*/
#include "dialog.h"


CDialog::CDialog(QWidget* pParent) : QDialog(pParent)
{
	ui.setupUi(this);
	ui.m_pLabel2->setText(tr("i like text file!"));
}

CDialog::~CDialog()
{
	
}