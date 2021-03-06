// PMApp.h : PMEditor 应用程序的主头文件
//
#pragma once
#ifndef __AFXWIN_H__
	#error 在包含用于 PCH 的此文件之前包含“stdafx.h” 
#endif
#include "resource.h"       // 主符号

// CPMApp:
// 有关此类的实现，请参阅 PMEditor.cpp
//
class CProjectMgr;
namespace MVC{namespace Start{class CPMHtmlDialog;}}
namespace XmlInfo{class CXmlMgr;}
class CPMApp : public CWinApp
{
public:
	CMultiDocTemplate* m_pStartDocMgr;
	CMultiDocTemplate* m_pItemDocMgr;
	MVC::Start::CPMHtmlDialog* m_StartPage;				/**< 当前的起始页Dialog指针 */

	std::shared_ptr<XmlInfo::CXmlMgr> m_XmlMgr;

public:
	std::shared_ptr<XmlInfo::CXmlMgr> GetXmlMgr(){return m_XmlMgr;}
	MVC::Start::CPMHtmlDialog* GetStartPage(){return m_StartPage;}

	void SetStartPage(MVC::Start::CPMHtmlDialog* page){m_StartPage = page;}				/**< 当前的起始页Dialog指针 */
	CRecentFileList* GetRecentFileList(){return m_pRecentFileList;}

public:
	CPMApp();
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual void AddToRecentFileList(LPCTSTR lpszPathName);
	virtual void DeleteRecentFile(LPCTSTR lpszPathName);
	virtual void ShowStartPage();			// 打开起始页

	afx_msg void OnAppAbout();
	afx_msg void MRUFileHandler(UINT index);
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void ReadCmdLine(CString cmdLine);		// 解析命令行
};

extern CPMApp g_App;
