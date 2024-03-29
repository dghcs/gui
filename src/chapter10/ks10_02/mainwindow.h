/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: mainwindow.h
\brief 主窗体头文件
  
\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2018/12 
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QToolBar>
#include <QLabel>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
class QMenu;
class QActionGroup;
class QAction;
class QLabel;
class QToolbar;
QT_END_NAMESPACE

class CEditMdiArea;

class CGraphView;

class CMainWindow : public QMainWindow
{
	Q_OBJECT
public:
	CMainWindow(QWidget* parent);
	~CMainWindow(){;}

protected:

private slots:

    void onMouseMoveInView(const QPointF&);    
    void about();


private:
	void createActions();		/// 构建菜单项对应的QAction。
	void createMenus();		    /// 构建菜单
	void createStatusBar();		/// 构建状态栏
	void initialize();			/// 初始化	
	void connectSignalAndSlot();/// 绑定信号槽
	
private:
	QMenu *m_pHelpMenu;			/// 帮助菜单
	
	QAction *m_pAboutAct;	/// 关于

	QLabel *m_pInfoLabel;	/// 信息标签
	QLabel* m_pMouseLabel;	/// 鼠标位置显示

    CEditMdiArea* 	m_pMdiArea;
};

#endif // MAINWINDOW_H