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

private Q_SLOTS:
	void onChecked(bool checked);
private:
    Ui::CDialogBase ui;
};

#endif