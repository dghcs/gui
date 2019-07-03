/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: step2.h
\brief  �Ի�����ʾ��, Ԥ�������ඨ��ͷ�ļ�
\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2019/7
*/

#pragma once

#include <QWidget>

#include "ui_step2.h"

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class CStep2 : public QWidget
{
    Q_OBJECT

public:
    /// ���캯��
    CStep2(QWidget *parent = 0);

Q_SIGNALS:
    void showpage(int page_index);

private slots:
    void slot_previous();
    void slot_next();

private:
    Ui::CStep2 ui;
};


