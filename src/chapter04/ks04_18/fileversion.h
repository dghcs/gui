/*! \file: fileversion.h
	\brief 文件头定义类
	\author 星点课堂
	\Date : 2018
* please import basedll.dll
*/
#pragma once

#include "qglobal.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 版本变更记录
// 1.0 初始版本
// 1.1 CCard增加了id值的序列化
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



static const quint16 c_MainVersion= 1;		/// 当前文件的主版本号
static const quint16 c_SubVersion = 1;		/// 当前文件的次版本号

/// 获取当前系统的主版本号（使用本程序保存文件时的版本号）
static quint16 getSystemMainVersion() {
	return c_MainVersion;
}
/// 获取当前系统的次版本号（使用本程序保存文件时的版本号）
static quint16 getSystemSubVersion() {
	return c_SubVersion;
}
