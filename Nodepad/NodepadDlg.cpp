
// NodepadDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Nodepad.h"
#include "NodepadDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNodepadDlg 对话框



CNodepadDlg::CNodepadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NODEPAD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNodepadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNodepadDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DROPFILES()
	ON_COMMAND(IDOK, &CNodepadDlg::OnIdok)
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_COMMAND(IDCANCEL, &CNodepadDlg::OnIdcancel)
	ON_COMMAND(ID_EDIT_CLEAR, &CNodepadDlg::OnEditClear)
	ON_COMMAND(ID_EDIT_COPY, &CNodepadDlg::OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, &CNodepadDlg::OnEditCut)
	ON_COMMAND(ID_EDIT_FIND, &CNodepadDlg::OnEditFind)
	ON_COMMAND(ID_EDIT_DATE, &CNodepadDlg::OnEditDate)
	ON_COMMAND(ID_EDIT_FIND_NEXT, &CNodepadDlg::OnEditFindNext)
	ON_COMMAND(ID_EDIT_GO, &CNodepadDlg::OnEditGo)
	ON_COMMAND(ID_EDIT_PASTE, &CNodepadDlg::OnEditPaste)
	ON_COMMAND(ID_EDIT_UNDO, &CNodepadDlg::OnEditUndo)
	ON_COMMAND(ID_EDIT_SELECT_ALL, &CNodepadDlg::OnEditSelectAll)
	ON_COMMAND(ID_EDIT_REPLACE, &CNodepadDlg::OnEditReplace)
END_MESSAGE_MAP()


// CNodepadDlg 消息处理程序

BOOL CNodepadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CNodepadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CNodepadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CNodepadDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TCHAR sFile[256];
	DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
	CFile file;
	if (!file.Open(sFile, CFile::modeRead))
	{
		AfxMessageBox(TEXT('加载文件失败！'));
	}

	CHAR utf8[256];
	CString text,unicode;
	
	while (file.Read(utf8,sizeof(utf8)) == sizeof(utf8))
	{
		text+=utf8;
	}
	SetDlgItemText(IDC_TEXT, text);
	CDialogEx::OnDropFiles(hDropInfo);
}


void CNodepadDlg::OnIdok()
{
	// TODO: 在此添加命令处理程序代码
}


void CNodepadDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	CWnd* p = GetDlgItem(IDC_TEXT);
	CRect rect;
	if (p)
	{
		GetClientRect(rect);
		p->MoveWindow(rect);
	}
}


void CNodepadDlg::OnClose()
{
	
	EndDialog(IDCANCEL);
	//CDialogEx::OnClose();
}


void CNodepadDlg::OnIdcancel()
{
	// TODO: 在此添加命令处理程序代码
}


void CNodepadDlg::OnEditClear()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->Clear();
}


void CNodepadDlg::OnEditCopy()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->Copy();
}


void CNodepadDlg::OnEditCut()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->Cut();
}


void CNodepadDlg::OnEditFind()
{
	// TODO: 在此添加命令处理程序代码
}


void CNodepadDlg::OnEditDate()
{
	// TODO: 在此添加命令处理程序代码
}


void CNodepadDlg::OnEditFindNext()
{
	// TODO: 在此添加命令处理程序代码
}


void CNodepadDlg::OnEditGo()
{
	// TODO: 在此添加命令处理程序代码
}


void CNodepadDlg::OnEditPaste()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->Paste();
}


void CNodepadDlg::OnEditUndo()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->Undo();
}


void CNodepadDlg::OnEditSelectAll()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->SetSel(0,-1);
}


void CNodepadDlg::OnEditReplace()
{
	// TODO: 在此添加命令处理程序代码
}
