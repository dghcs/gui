/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: address.cpp
\brief  CWidgetAddress类的实现文件

\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2018/9
*/
#include "address.h"


CWidgetAddress::CWidgetAddress(QWidget* pParent) : QWidget(pParent) {
    ui.setupUi(this);

	//connect(ui.m_btnSave, SIGNAL(clicked()), this, SLOT(on_addressSaved()));
	connect(ui.m_btnSave, &QPushButton::clicked,
        this, &CWidgetAddress::slot_btnSaveClicked);
}

CWidgetAddress::~CWidgetAddress(){
	
}


void CWidgetAddress::slot_btnSaveClicked()
{
    emit sigAddressSaved(ui.m_lineEdit->text());
}
