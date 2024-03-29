/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: city.h
\brief 城市类定义文件。
       
\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2018/10
*/

#ifndef _CITY_H_
#define _CITY_H_

#include<QString>
#include<QDataStream>

#include "base/basedll/serialize.h"

class CProvince;

// 名片类
class CCard {
public:
	CCard() {}
	~CCard() {}

	/**
	* @brief 设置名片字符串.
	* @param[in] str 名片字符串.
	* @return void
	*/
	void  setString(const QString& str) { m_str = str; }

	/**
	* @brief 获取名片字符串.
	* @return 名片字符串.
	*/
	QString  getString(void) const { return m_str; }
	/**
	* @brief 用来把类对象进行二进制方式序列化的函数。本接口内部已经调用QDataStream::setByteOrder(QDataStream::LittleEndian)。
	* @param[in] ds 文件流对象。
	* @param[in|out] pError 错误信息。
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode serializeBinary(QDataStream& ds, QString* /*pError*/) const {
		ds.setByteOrder(QDataStream::LittleEndian); 
		ds << m_str;
		return ESERIALIZECODE_OK;
	}
	/**
	* @brief 用来把类对象进行二进制方式序列化的函数。
	*        打开的文件与保存时采用相同的ByteOrder。本接口内部已经调用QDataStream::setByteOrder(QDataStream::LittleEndian)。
	* @param[in] ds 文件流对象。
	* @param[in|out] pError 错误信息。
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode deSerializeBinary(QDataStream& ds, QString* /*pError*/) {
		ds.setByteOrder(QDataStream::LittleEndian); 
		ds >> m_str;
		return ESERIALIZECODE_OK;
	}

private:
	QString m_str;
};
// 城市类
//-----------------------------------------
class CCity
{
public:
	CCity();
	~CCity();
	/**
	* @brief 清空数据
	* @return void
	*/
	void clear(void);

    /**
    * @brief 设置城市名称.
    * @param[in] strName 城市名称
    * @return void
    */
	void  setName(const QString& str) {m_strName = str;}

    /**
    * @brief 获取城市名称.
    * @return 城市名称
    */
	QString  getName(void)const {return m_strName;}
 
    /**
    * @brief 设置城市所在省(州)
    * @param[in] pProvince 城市所在省(州)
    * @return void
    */
	void  setProvince(CProvince* pProvince) { m_pProvince = pProvince;}

    /**
    * @brief 获取城市所在省(州)
    * @return 城市所在省(州)
    */
	CProvince*  getProvince(void) const {return m_pProvince;}
	/**
	* @brief 用来把类对象进行二进制方式序列化的函数。本接口内部已经调用QDataStream::setByteOrder(QDataStream::LittleEndian)。
	* @param[in] ds 文件流对象。
	* @param[in|out] pError 错误信息。
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode serializeBinary(QDataStream& ds, QString* pError) const;
	/**
	* @brief 用来把类对象进行二进制方式序列化的函数。
	*        打开的文件与保存时采用相同的ByteOrder。本接口内部已经调用QDataStream::setByteOrder(QDataStream::LittleEndian)。
	* @param[in] ds 文件流对象。
	* @param[in|out] pError 错误信息。
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode deSerializeBinary(QDataStream& ds, QString* pError);


	/**
	* @brief 设置城市名片
	* @param[in] pCard 城市市名片
	* @return void
	*/
	void  setCard(CCard* pCard) { m_pCard = pCard; }

	/**
	* @brief 获取城市名片
	* @return 城市名片
	*/
	CCard*  getCard(void) const { return m_pCard; }

private:
	QString	m_strName;
	CProvince*	m_pProvince;
	CCard* m_pCard;

};



#endif  // for _CITY_H_
