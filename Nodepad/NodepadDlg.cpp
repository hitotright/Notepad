
// NodepadDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Nodepad.h"
#include "NodepadDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNodepadDlg �Ի���



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


// CNodepadDlg ��Ϣ�������

BOOL CNodepadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CNodepadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CNodepadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CNodepadDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TCHAR sFile[256];
	DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
	CFile file;
	if (!file.Open(sFile, CFile::modeRead))
	{
		AfxMessageBox(TEXT('�����ļ�ʧ�ܣ�'));
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
}


void CNodepadDlg::OnEditDate()
{
	// TODO: �ڴ���������������
}


void CNodepadDlg::OnEditFindNext()
{
	// TODO: �ڴ���������������
}


void CNodepadDlg::OnEditGo()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
}
