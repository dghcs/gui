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


// �������������ui�ļ��жԻ��������������鿴���е�����
class CDialog : public QDialog
{
	Q_OBJECT
public:
	CDialog(QWidget* pParent);
	~CDialog();

private slots:
	void on_fontFamilyChanged(const QFont &font);
	void on_fontSizeChanged(int);
private:
    Ui::CDialogBase ui;
};

#endif