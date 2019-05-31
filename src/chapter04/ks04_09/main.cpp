/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: main.cpp
\brief      QVariant��ʹ��
            
\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2018/9
*/

#include <QApplication>
#include <QMessageBox>
#include <iostream>

void example01();
void example02();
void example03();
void example04();

using std::cout;
using std::endl;
using std::cin;

//
int main(int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);
    QApplication app(argc, argv);

	// example01 
	if (1) {
		example01();
	}

	// example02 
	if (1) {
		example02();
	}

    // example03 
    if (1) {
        example03();
    }

    // example04
    if (1) {
        example04();
    }


	return 0;
}

/**
* @brief  ������ʾ��Ϣ
* @return ��
*/
void example01(){
	
    QMessageBox::information(NULL, 
                            QObject::tr("Qt Gui Application"), 
                            QObject::tr("This is a normal information"), 
                            QMessageBox::Yes | QMessageBox::No, 
                            QMessageBox::Yes);

}
/**
* @brief  �������ش�����Ϣ
* @return ��
*/
void example02(){
    QMessageBox::critical(NULL,
                            QObject::tr("Qt Gui Application"), 
                            QObject::tr("This is a critical information"), 
                            QMessageBox::Yes | QMessageBox::No, 
                            QMessageBox::Yes);
}

/**
* @brief  ����������Ϣ
* @return ��
*/
void example03() {
    QMessageBox::StandardButton btn = QMessageBox::question(NULL,
                            QObject::tr("Qt Gui Application"), 
                            QObject::tr("This is a question information\nPlease make your choice:"), 
                            QMessageBox::Yes | QMessageBox::No, 
                            QMessageBox::Yes);

    if (QMessageBox::Yes == btn) {
        cout << "button 'Yes' selected." << endl;
    }
    else {
        cout << "button 'No' selected." << endl;
    }
}

/**
* @brief  ����������Ϣ
* @return ��
*/
void example04() {
    QMessageBox::about(NULL,
        QObject::tr("Qt Gui Application"),
        QObject::tr("This is an about information"));
}
