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

#include "dialog.h"


CDialog::CDialog(QWidget* pParent) : QDialog(pParent) {
    ui.setupUi(this);

	//connect(ui.fontComboBox, SIGNAL(currentFontChanged(const QFont &)), this, SLOT(on_fontFamilyChanged(const QFont &)));
	connect(ui.cbFontSize, SIGNAL(currentIndexChanged(int)), this, SLOT(on_fontSizeChanged(int)));

	connect(ui.fontComboBox, &QFontComboBox::currentFontChanged, this, &CDialog::on_fontFamilyChanged);
	//connect(ui.cbFontSize, &QFontComboBox::currentIndexChanged, this, &CDialog::on_fontSizeChanged);
}

CDialog::~CDialog(){
	
}


void CDialog::on_fontFamilyChanged(const QFont &font){
	int fontSize = ui.cbFontSize->currentText().toInt();
	QFont ft = font;
	ft.setPointSize(fontSize);
    ui.plainTextEdit->setFont(ft);
}

void CDialog::on_fontSizeChanged(int /*idx*/){
	int fontSize = ui.cbFontSize->currentText().toInt();
	QFont ft = ui.fontComboBox->currentFont();
	ft.setPointSize(fontSize);
    ui.plainTextEdit->setFont(ft);
}