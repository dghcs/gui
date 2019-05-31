/*! 
* Copyright (C) 2018 Ů�����ϰ�
* ��Ȩ���С�
* ��������ڿγ̡�Qt���������-GUI��Ʒ��������ѧϰ�����𴫲���
* ��������:���벻��֤�ȶ��ԣ�����������ҵ��;���������Ը���

\file: main.cpp
\brief QInputDialog��ʹ��
            
\author Ů�����ϰ�  �ǵ����: http://xingdianketang.cn/
\Date 2018/9
*/

#include <QApplication>
#include <QInputDialog>
#include <QMessagebox>
#include <iostream>

void example01();
void example02();
void example03();
void example04();
void example05();

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

    // example05 
    if (1) {
        example05();
    }

	return 0;
}

/**
* @brief  ��ȡ�ı�
* @return ��
*/
void example01(){
	
    QString str = QInputDialog::getText(NULL, 
                            QString::fromLocal8Bit("QInputDialogʾ��"), 
                            QString::fromLocal8Bit("��ȡ�ı�"));
    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialogʾ��"),
        str);
}
/**
* @brief  ��ȡ�����ı�
* @return ��
*/
void example02(){
    QString str = QInputDialog::getMultiLineText(NULL,
        QString::fromLocal8Bit("QInputDialogʾ��"),
        QString::fromLocal8Bit("��ȡ�����ı�"));
    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialogʾ��"),
        str);
}

/**
* @brief  ��ȡ��Ŀ
* @return ��
*/
void example03() {
    QStringList lst;
    lst << QString::fromLocal8Bit("ƻ��")
        << QString::fromLocal8Bit("�㽶")
        << QString::fromLocal8Bit("orange")
        << QString::fromLocal8Bit("pear");
    QString str = QInputDialog::getItem(NULL,
        QString::fromLocal8Bit("QInputDialogʾ��"),
        QString::fromLocal8Bit("��ȡ��Ŀ"),
        lst);
    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialogʾ��"),
        str);
}

/**
* @brief  ��ȡ����
* @return ��
*/
void example04() {
    int i = QInputDialog::getInt(NULL,
        QString::fromLocal8Bit("QInputDialogʾ��"),
        QString::fromLocal8Bit("��ȡ����"),
        200,
        100,
        1000,
        10);
    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialogʾ��"),
        QString("%1").arg(i));
}

/**
* @brief  ��ȡ������
* @return ��
*/
void example05() {
    double d = QInputDialog::getDouble(NULL,
        QString::fromLocal8Bit("QInputDialogʾ��"),
        QString::fromLocal8Bit("��ȡ������"),
        200.5,
        100.05,
        999.99);
    QMessageBox::information(NULL,
        QString::fromLocal8Bit("QInputDialogʾ��"),
        QString("%1").arg(d));

}
