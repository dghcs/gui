/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: dialog.cpp
\brief  CDialog

\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2018/9
*/

#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "dialog.h"


CDialog::CDialog(QWidget* pParent) : QDialog(pParent), m_pCurrentLabel(NULL){
	ui.setupUi(this);

	connect(ui.btnDefault, &QPushButton::clicked, this, &CDialog::on_setDefaultFont);

	connect(ui.fontComboBox, SIGNAL(currentFontChanged(const QFont &)), this, SLOT(on_fontFamilyChanged(const QFont &)));
	connect(ui.cbFontSize, SIGNAL(currentIndexChanged(int)), this, SLOT(on_fontSizeChanged(int)));

	connect(ui.lineEdit, &QLineEdit::selectionChanged, this, &CDialog::labelClicked);
	connect(ui.lineEdit_2, &QLineEdit::selectionChanged, this, &CDialog::label2Clicked);
}

CDialog::~CDialog(){
	
}


void CDialog::on_fontFamilyChanged(const QFont &font){
	if (NULL == m_pCurrentLabel) {
		return;
	}

	int fontSize = ui.cbFontSize->currentText().toInt();
	QFont ft = font;
	ft.setPointSize(fontSize);

	setTextFont(m_pCurrentLabel, ft);
}

void CDialog::on_fontSizeChanged(int /*idx*/){
	if (NULL == m_pCurrentLabel) {
		return;
	}	
	
	int fontSize = ui.cbFontSize->currentText().toInt();
	QFont ft = ui.fontComboBox->currentFont();
	ft.setPointSize(fontSize);

	setTextFont(m_pCurrentLabel, ft);
}

void CDialog::setTextFont(QLineEdit* pLabel, const QFont& newFont)
{
	qDebug() << "setTextFont: " << pLabel;
	if (NULL != pLabel) {
		pLabel->setFont(newFont);
		updateFontWidget();
	}
}

void CDialog::labelClicked(){
	m_pCurrentLabel = ui.lineEdit;
	updateFontWidget();
}

void CDialog::label2Clicked() {
	m_pCurrentLabel = ui.lineEdit_2;
	updateFontWidget();
}
void CDialog::updateFontWidget(){
	if (NULL == m_pCurrentLabel) {
		return;
	}
    ui.cbFontSize->blockSignals(true);
    ui.fontComboBox->blockSignals(true);

	QFont ft = m_pCurrentLabel->font();
	QString str;
	str.sprintf("%d", ft.pointSize());
    ui.cbFontSize->setCurrentText(str);
    ui.fontComboBox->setCurrentFont(ft);

    ui.cbFontSize->blockSignals(false);
    ui.fontComboBox->blockSignals(false);
}

void CDialog::on_setDefaultFont() {
	QFont defaultFont("songti", 12);
	setTextFont(ui.lineEdit, defaultFont);
	setTextFont(ui.lineEdit_2, defaultFont);
}