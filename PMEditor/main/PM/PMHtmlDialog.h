#pragma once

#include <stack>
// CPMHtmlDialog 对话框
namespace MVC{namespace Start{
class CStartView;
class CPMHtmlDialog : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CPMHtmlDialog)

public:
	CString m_LocalURL;			// 当前网络地址
	CString m_HomeRUL;			// 主页地址
	BOOL m_IsButtonLink;		// 判断用户是否是点击按钮超链接，导致的网页跳转
	CStartView *m_pStartPageView;

	stack<CString> m_BackStack;	// 后退堆栈
	stack<CString> m_FrontStack;// 前进堆栈

public:
	CPMHtmlDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPMHtmlDialog();
// 重写
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);
	void OnNewProj(IHTMLElement *pElement);
	void OnOpenProj(IHTMLElement *pElement);
	void OnOpenProjWith(IHTMLElement *pElement);
	void OnShowHelp(IHTMLElement *pElement);

// 对话框数据
	enum { IDD = IDD_PMHTMLDIALOG, IDH = IDR_HTML_PMHTMLDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	virtual void SetHomeProjItem(CString htmlText);
	virtual void GoBack();
	virtual void GoForward();
	virtual void GoHome();
	virtual void ClearFrontStack();
	virtual void ClearBackStack();
	virtual void OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	virtual void OnOK();
};
}}