/*! 
* Copyright (C) 2018 女儿叫老白
* 版权所有。
* 代码仅用于课程《Qt入门与提高-GUI产品开发》的学习，请勿传播。
* 免责声明:代码不保证稳定性，请勿用作商业用途，否则后果自负。

\file: country.h
\brief 国家类定义文件。
       
\author 女儿叫老白  星点分享: http://xingdianketang.cn/
\Date 2018/10
*/

#ifndef _COUNTRY_H_
#define _COUNTRY_H_

#include <QList>
#include <QString>
#include <QDomDocument>
#include <QMap>

#include "base/basedll/serialize.h"

class CProvince;



// 国家类
//-----------------------------------------
class CCountry
{
public:
	CCountry();
	CCountry(const QString& str) :m_strName(str) { ; }
	~CCountry();

    /**
    * @brief 设置国家名称.
    * @param[in] strName 国家名称
    * @return void
    */
	void  setName(const QString& str) {m_strName = str;}

    /**
    * @brief 获取国家名称.
    * @return 国家名称
    */
	QString  getName(void) const {return m_strName;}   
   
    /**
    * @brief 设置国家所在大洲名称
    * @param[in] str 国家所在大洲名称
    * @return void
    */
	void  setContinent(const QString& str) {m_strContinent = str;}

    /**
    * @brief 获取国家所在大洲名称
    * @return 国家所在大洲名称
    */
	QString  getContinent(void) const {return m_strContinent;}

	/**
	* @brief 添加省
	* @param[in] pProvince 省
	* @return 添加后的省个数
	*/
	int addProvince(CProvince* pProvince);

	/**
	* @brief 获取省列表
	* @param[out] lstProvinces 省列表
	* @return 已有省个数
	*/
	int getProvinces(QList<CProvince*>& lstProvinces) const { lstProvinces = m_lstProvinces; return lstProvinces.size(); }

    ////////////////////////////////////////////////////////////////////////////////////
    // 序列化相关

	/**
	* @brief 用来把类对象进行二进制方式序列化的函数。
	* @param[in] fileName 文件名。
	* @param[in|out] pError 错误信息。
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode serializeBinary(const QString& fileName, QString* pError) const;
	/**
	* @brief 用来把类对象进行二进制方式序列化的函数。保存二进制时默认采用QDataStream::LittleEndian。调用者无需关注ByteOrder.
	* @param[in] ds 文件流对象。要求调用者以（QFile::ReadWrite | QFile::Truncate）模式打开。
	* @param[in|out] pError 错误信息。
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode serializeBinary(QDataStream& ds, QString* pError) const;

	/**
	* @brief 用来把类对象进行二进制方式反序列化的函数。
	* @param[in] fileName 文件名。
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode deSerializeBinary(const QString& fileName, QString* pError);
	/**
	* @brief 用来把类对象进行二进制方式序列化的函数。
	*        打开的文件与保存时采用相同的ByteOrder(本接口内部已经调用QDataStream::setByteOrder)。
	* @param[in] ds 文件流对象。
	* @param[in|out] pError 错误信息。
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode deSerializeBinary(QDataStream& ds, QString* pError);

	/**
	* @brief 用来把类对象进行文本方式序列化的函数。
	* @param[in] fileName xml文件名。
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode serializeXML(const QString& fileName, QString* pError) const;
	/**
	* @brief 用来把类对象进行文本方式序列化的函数。
	* @param[in|out] doc QDomDocument对象，需要外部构建
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode serializeXML(QDomDocument& doc, QString* pError) const;
	/**
	* @brief 用来把类对象进行文本方式反序列化的函数。
	* @param[in] fileName xml文件名。
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode deSerializeXML(const QString& fileName, QString* pError);
	/**
	* @brief 用来把类对象进行文本方式序列化的函数。
	* @param[in|out] doc QDomDocument对象，需要外部构建
	* @return ESerializeCode枚举值。
	*/
	ESerializeCode deSerializeXML(const QDomDocument& doc, QString* pError = NULL);

    ////////////////////////////////////////////////////////////////////////////////////
    // 自定义属性相关
    /**
    * @brief 添加自定义属性名
    * @param[in] name 自定义属性名
    * @return true:成功,false:已存在
    */
    bool addCustomData(const QString& name);

    /**
    * @brief 添加自定义属性值,找到自定义属性并赋值，没找到则添加.
    * @param[in] name 自定义属性名
    * @param[in] data 自定义属性值
    * @return void
    */
    void addCustomData(const QString& name, const QVariant& data);

	/**
	* @brief 获取自定义属性名称列表
	* @param[out] lst 自定义属性名称列表
	* @return 自定义属性名称个数。
	*/   
    int getAllCustomDataName(QStringList& lst) const;

    /**
    * @brief 根据自定义属性名获取自定义属性值
    * @param[in] name 自定义属性名
    * @return 自定义属性值
    */
    QVariant getCustomData(const QString& name) const;

    /**
    * @brief 设置自定义属性值
    * @param[in] name 自定义属性名
    * @param[in] data 自定义属性值
    * @return true:找到自定义属性并赋值,false:未找到该属性
    */
    bool setCustomData(const QString& name, const QVariant& data);

private:


private:
    QString	m_strName;
    QString	m_strContinent;	
	QList<CProvince*> m_lstProvinces;
    QMap<QString, QVariant> m_mapCustomData;
};


#endif  // for _COUNTRY_H_
