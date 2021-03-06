#pragma once
#include "ObjectInProperty.h"

namespace MVC{namespace Item{
class CItem;
class CPropertyItems : public Dialog::CObjectInProperty
{
private:
	std::list< std::shared_ptr<CItem> > m_ltEditItem;	// 要被修改的所有变量
	std::shared_ptr<CItem> m_ShowItem;				// 显示出来的临时变量

	BOOL m_bValType;			// 工程值类型是否相同
	BOOL m_bSrcType;			// 数据源类型是否相同
	BOOL m_bGroup;				// 所属变量组是否相同
	BOOL m_bDefValue;			// 默认值类型是否相同
	BOOL m_bAccessRight;		// 访问权限是否相同
	BOOL m_bReservFlag;			// 是否是保留值是否相同
	BOOL m_bReservDB;			// 是否是保留数据库是否相同
	BOOL m_bFreshTime;			// 刷新时间是否相同
	BOOL m_bConvertFlag;		// 转换类型是否相同
	BOOL m_bMinProj;			// 最小工程值是否相同
	BOOL m_bMaxProj;			// 最大工程值是否相同
	BOOL m_bMinIO;				// 最小原始值是否相同
	BOOL m_bMaxIO;				// 最大原始值是否相同

public:
	CPropertyItems(void);
	~CPropertyItems(void);
	void SetItemList(std::list< std::shared_ptr<CItem> >& ltItem){m_ltEditItem = ltItem;}

private:
	void CreateEdit();												// 编辑前的数据准备方法
	virtual void OnShowHelp();										// 显示帮助信息
	virtual void ShowInfo(CXTPPropertyGrid& grid);					// 显示表格的函数
	virtual CString GetTitle();										// 获得本窗体的名称
	virtual bool OnSaveModify(CXTPPropertyGrid& grid);				// 要保存被改变的内容
	virtual void OnItemModify(CXTPPropertyGrid& grid, UINT id);		// 当某一项被修改时
};
}}