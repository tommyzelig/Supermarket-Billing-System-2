
// MFCApplication1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#include "Product.h"
#include "CleanProduct.h"
#include "Food.h"
#include "Garment.h"
#include "NonFood.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication1Dlg dialog

CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btnAdd, &CMFCApplication1Dlg::OnBnClickedbtnadd)
	ON_BN_CLICKED(btnClear, &CMFCApplication1Dlg::OnBnClickedbtnclear)
	ON_BN_CLICKED(btnRadioClean, &CMFCApplication1Dlg::OnBnClickedbtnradioclean)
	ON_BN_CLICKED(btnRadioGarment, &CMFCApplication1Dlg::OnBnClickedbtnradiogarment)
	ON_BN_CLICKED(btnRadioFood, &CMFCApplication1Dlg::OnBnClickedbtnradiofood)
	ON_BN_CLICKED(btnUpdateItem, &CMFCApplication1Dlg::OnBnClickedbtnupdateitem)
	ON_LBN_SELCHANGE(listProducts, &CMFCApplication1Dlg::OnLbnSelchangelistproducts)
	ON_BN_CLICKED(btnSave, &CMFCApplication1Dlg::OnBnClickedbtnsave)
	ON_BN_CLICKED(btnLoad, &CMFCApplication1Dlg::OnBnClickedbtnload)
	ON_BN_CLICKED(btnRadioEllipse, &CMFCApplication1Dlg::OnBnClickedbtnradioellipse)
	ON_BN_CLICKED(btnRadioRetangel, &CMFCApplication1Dlg::OnBnClickedbtnradioretangel)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(btnLine, &CMFCApplication1Dlg::OnBnClickedbtnline)
END_MESSAGE_MAP()

// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{


	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		// repaint all shapes after invalidation:
		CPaintDC dc(this);



		CDialogEx::OnPaint();
	}

	//if (IsIconic())
	//{
	//	CPaintDC dc(this); // device context for painting

	//	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

	//	// Center icon in client rectangle
	//	int cxIcon = GetSystemMetrics(SM_CXICON);
	//	int cyIcon = GetSystemMetrics(SM_CYICON);
	//	CRect rect;
	//	GetClientRect(&rect);
	//	int x = (rect.Width() - cxIcon + 1) / 2;
	//	int y = (rect.Height() - cyIcon + 1) / 2;

	//	// Draw the icon
	//	dc.DrawIcon(x, y, m_hIcon);
	//}
	//else
	//{
	//	//CPaintDC dc(this);
	//	//CDialogEx::OnPaint();
	//	
	//	
	//	//CPen Pen(PS_SOLID,7, RGB(255, 0, 0));
	//	
	//	//CPen* old = dc.SelectObject(&Pen);
	//	//CBrush brush(RGB(0, 255, 0));
	//	//CBrush* oldB = dc.SelectObject(&brush);
	//	//dc.Rectangle(20, 30, 50, 50);
	//	//dc.Ellipse(20, 20, 10, 10);
	//	//dc.MoveTo(70, 70);
	//	//dc.LineTo(500, 100);
	//	//dc.SelectObject(old);
	//	//dc.SelectObject(oldB);
	//}


}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication1Dlg::OnBnClickedbtnadd()
{
	// TODO: Add your control notification handler code here
	CButton *radioClean = (CButton*)GetDlgItem(btnRadioClean);
	CButton *radioGarment = (CButton*)GetDlgItem(btnRadioGarment);
	CButton *radioFood = (CButton*)GetDlgItem(btnRadioFood);

	CButton *checkManufacturer = (CButton*)GetDlgItem(btnCheckMani);
	CButton *checkDangerous = (CButton*)GetDlgItem(btnRadioDangerous);

	CListBox *list = (CListBox*)GetDlgItem(listProducts);

	Product *prod = NULL;

	bool madeInIsrael;

	if ((*checkManufacturer).GetCheck())
	{
		madeInIsrael = true;
	}
	else
	{
		madeInIsrael = false;
	}

	bool isDangerous;

	if (radioClean->GetCheck())
	{
		if (checkDangerous->GetCheck())
		{
			isDangerous = true;
		}
		else
		{
			isDangerous = false;
		}

		prod = new CleanProduct("Clean", 40, madeInIsrael, isDangerous);

		CString str;

		str.Format(_T("%d. Clean, Dangerous: %s,isManufacturer: %s, Price %0.2lf"), allProducts.GetCount() + 1, isDangerous ? _T("Yes") : _T("No"), madeInIsrael ? _T("yes") : _T("no"), prod->GetTotalPrice());

		list->AddString(str);// לראות את זה בעיניים - כאילו הפלט לקונטרולר
	}
	else if (radioGarment->GetCheck())
	{
		CButton *radioSmall = (CButton*)GetDlgItem(btnRadioSmall);
		CButton *radioMedium = (CButton*)GetDlgItem(btnRadioMedium);
		CButton *radioLarge = (CButton*)GetDlgItem(btnRadioLarge);

		int size;

		char strSize;

		if (radioSmall->GetCheck())
		{
			size = Size_Small;
			strSize = 'S';
		}
		else if (radioMedium->GetCheck())
		{
			size = Size_Medium;
			strSize = 'M';
		}
		else
		{
			size = Size_Large;
			strSize = 'L';
		}
		CButton *under7 = (CButton*)GetDlgItem(IDC_under7);
		CButton *between7_18 = (CButton*)GetDlgItem(IDC_under7to18);
		CButton *above18 = (CButton*)GetDlgItem(IDC_above18);

		int age;

		if (under7->GetCheck())
		{
			age = 6;
		}
		else if (between7_18->GetCheck())
		{
			age = 15;
		}
		else
		{
			age = 21;
		}

		prod = new Garment("Garment", 60, madeInIsrael, age, size);

		CString str;

		str.Format(_T("%d. Garment ,Israel: %s  , Size: %c, Price %0.2lf"), allProducts.GetCount() + 1, madeInIsrael ? _T("yes") : _T("no"), strSize, prod->GetTotalPrice());

		list->AddString(str);

	}
	else if (radioFood->GetCheck())
	{
		bool IsDairy;
		bool IsHot;

		CButton *CheckHot = (CButton*)GetDlgItem(btnCheckHot);
		CButton *CheckDairy = (CButton*)GetDlgItem(btnCheckDairy);

		if (CheckHot->GetCheck())
		{
			IsHot = true;
		}
		else
		{
			IsHot = false;
		}

		if (CheckDairy->GetCheck())
		{
			IsDairy = true;
		}
		else
		{
			IsDairy = false;
		}

		prod = new Food("Food", 40, IsHot, IsDairy);
		CString str;
		str.Format(_T("%d. food, Hot: %s,Dairy: %s, Price %0.2lf,"), allProducts.GetCount() + 1, IsHot ? _T("yes") : _T("no"), IsDairy ? _T("yes") : _T("no"), prod->GetTotalPrice());

		list->AddString(str);
	}

	if (prod != NULL) {

		allProducts.Add(prod);

		totalPrice += prod->GetTotalPrice();

		UpdateTotalPriceLabel();
	}
}

void CMFCApplication1Dlg::UpdateTotalPriceLabel() {
	CStatic *totalPriceText = (CStatic*)GetDlgItem(textTotalPrice);

	CString strPrice;

	strPrice.Format(_T("%0.2lf"), totalPrice);

	totalPriceText->SetWindowTextW(strPrice);
}

void CMFCApplication1Dlg::OnBnClickedbtnclear()
{
	CListBox *list = (CListBox*)GetDlgItem(listProducts);

	list->ResetContent();// פיזי

	for (int i = 0; i < allProducts.GetCount(); i++)
	{
		delete allProducts[i];// מקום בזכרון
	}
	allProducts.RemoveAll();// מוחק את הפוינטרים , כמו מטריצה

	totalPrice = 0.0;

	UpdateTotalPriceLabel();
	CButton *update = (CButton*)GetDlgItem(btnUpdateItem);
	update->EnableWindow(false);

	CButton *radioClean = (CButton*)GetDlgItem(btnRadioClean);
	CButton *radioGarment = (CButton*)GetDlgItem(btnRadioGarment);
	CButton *radioFood = (CButton*)GetDlgItem(btnRadioFood);

	if (radioGarment->GetCheck()) {
		this->OnBnClickedbtnradiogarment();
	}
	else if (radioClean->GetCheck()) {
		this->OnBnClickedbtnradioclean();
	}
	else {
		this->OnBnClickedbtnradiofood();
	}
		radioGarment->EnableWindow(true);
		radioClean->EnableWindow(true);
		radioFood->EnableWindow(true);
	CButton *add = (CButton*)GetDlgItem(btnAdd);
	add->EnableWindow(true);
}

void CMFCApplication1Dlg::OnBnClickedbtnradioclean()
{

	CButton *checkManufacturer = (CButton*)GetDlgItem(btnCheckMani);
	CButton *checkDangerous = (CButton*)GetDlgItem(btnRadioDangerous);

	checkManufacturer->EnableWindow(true);// מאפשר כיבוי והדלקה
	checkDangerous->EnableWindow(true);

	CButton *CheckHot = (CButton*)GetDlgItem(btnCheckHot);
	CButton *CheckDairy = (CButton*)GetDlgItem(btnCheckDairy);
	CButton *under7 = (CButton*)GetDlgItem(IDC_under7);
	CButton *between7_18 = (CButton*)GetDlgItem(IDC_under7to18);
	CButton *above18 = (CButton*)GetDlgItem(IDC_above18);
	CButton *radioSmall = (CButton*)GetDlgItem(btnRadioSmall);
	CButton *radioMedium = (CButton*)GetDlgItem(btnRadioMedium);
	CButton *radioLarge = (CButton*)GetDlgItem(btnRadioLarge);

	CheckHot->EnableWindow(false);
	CheckDairy->EnableWindow(false);
	under7->EnableWindow(false);
	between7_18->EnableWindow(false);
	above18->EnableWindow(false);
	radioSmall->EnableWindow(false);
	radioMedium->EnableWindow(false);
	radioLarge->EnableWindow(false);
}

void CMFCApplication1Dlg::OnBnClickedbtnradiogarment()
{

	CButton *checkManufacturer = (CButton*)GetDlgItem(btnCheckMani);
	CButton *checkDangerous = (CButton*)GetDlgItem(btnRadioDangerous);

	checkManufacturer->EnableWindow(true);
	checkDangerous->EnableWindow(false);

	CButton *CheckHot = (CButton*)GetDlgItem(btnCheckHot);
	CButton *CheckDairy = (CButton*)GetDlgItem(btnCheckDairy);
	CButton *under7 = (CButton*)GetDlgItem(IDC_under7);
	CButton *between7_18 = (CButton*)GetDlgItem(IDC_under7to18);
	CButton *above18 = (CButton*)GetDlgItem(IDC_above18);
	CButton *radioSmall = (CButton*)GetDlgItem(btnRadioSmall);
	CButton *radioMedium = (CButton*)GetDlgItem(btnRadioMedium);
	CButton *radioLarge = (CButton*)GetDlgItem(btnRadioLarge);

	CheckHot->EnableWindow(false);
	CheckDairy->EnableWindow(false);

	under7->EnableWindow(true);
	between7_18->EnableWindow(true);
	above18->EnableWindow(true);
	radioSmall->EnableWindow(true);
	radioMedium->EnableWindow(true);
	radioLarge->EnableWindow(true);
}

void CMFCApplication1Dlg::OnBnClickedbtnradiofood()
{
	CButton *checkManufacturer = (CButton*)GetDlgItem(btnCheckMani);
	CButton *checkDangerous = (CButton*)GetDlgItem(btnRadioDangerous);

	checkManufacturer->EnableWindow(false);
	checkDangerous->EnableWindow(false);

	CButton *CheckHot = (CButton*)GetDlgItem(btnCheckHot);
	CButton *CheckDairy = (CButton*)GetDlgItem(btnCheckDairy);
	CButton *under7 = (CButton*)GetDlgItem(IDC_under7);
	CButton *between7_18 = (CButton*)GetDlgItem(IDC_under7to18);
	CButton *above18 = (CButton*)GetDlgItem(IDC_above18);
	CButton *radioSmall = (CButton*)GetDlgItem(btnRadioSmall);
	CButton *radioMedium = (CButton*)GetDlgItem(btnRadioMedium);
	CButton *radioLarge = (CButton*)GetDlgItem(btnRadioLarge);

	CheckHot->EnableWindow(true);
	CheckDairy->EnableWindow(true);

	under7->EnableWindow(false);
	between7_18->EnableWindow(false);
	above18->EnableWindow(false);
	radioSmall->EnableWindow(false);
	radioMedium->EnableWindow(false);
	radioLarge->EnableWindow(false);
}

void CMFCApplication1Dlg::OnBnClickedbtnupdateitem()
{
	CListBox *list = (CListBox*)GetDlgItem(listProducts);

	if (list->GetCount() > 0) //  | N |
	{
		CString str;
		int index = list->GetCaretIndex(); // index relevant

		Product * prod = allProducts[index];

		Food *food = dynamic_cast<Food*>(prod);

		CleanProduct *clean = dynamic_cast<CleanProduct*>(prod);
		Garment *garment = dynamic_cast<Garment*>(prod);


		CButton *radioClean = (CButton*)GetDlgItem(btnRadioClean);
		CButton *radioGarment = (CButton*)GetDlgItem(btnRadioGarment);
		CButton *radioFood = (CButton*)GetDlgItem(btnRadioFood);


		radioClean->EnableWindow(true);
		radioGarment->EnableWindow(true);
		radioFood->EnableWindow(true);

		CButton *add = (CButton*)GetDlgItem(btnAdd);

		add->EnableWindow(true);

		if (food != NULL)
		{
			CButton *CheckHot = (CButton*)GetDlgItem(btnCheckHot);
			bool answer = CheckHot->GetCheck();
			food->SetIsHot(answer);
		}
		else if (garment != NULL)
		{

			CButton *radioSmall = (CButton*)GetDlgItem(btnRadioSmall);
			CButton *radioMedium = (CButton*)GetDlgItem(btnRadioMedium);
			CButton *radioLarge = (CButton*)GetDlgItem(btnRadioLarge);

			if (radioLarge->GetCheck())
			{
				garment->SetSize(Size_Large);
			}
			else if (radioMedium->GetCheck())
			{
				garment->SetSize(Size_Medium);
			}
			else // radioSmall->GetCheck()
			{
				garment->SetSize(Size_Small);
			}
		}
		else // (clean != NULL) 
		{
			CButton *checkDangerous = (CButton*)GetDlgItem(btnRadioDangerous);
			bool answer = checkDangerous->GetCheck();
			clean->SetDangerous(answer);
		}

		UpdateListAfterChange();

	}
}

void CMFCApplication1Dlg::OnLbnSelchangelistproducts()
{
	CListBox *list = (CListBox*)GetDlgItem(listProducts);

	if (list->GetCount() > 0)
	{
		CString str;
		int index = list->GetCaretIndex();

		Product * prod = allProducts[index];

		Food *food = dynamic_cast<Food*>(prod);

		CleanProduct *clean = dynamic_cast<CleanProduct*>(prod);
		Garment *garment = dynamic_cast<Garment*>(prod);

		CButton *updateItem = (CButton*)GetDlgItem(btnUpdateItem);

		updateItem->EnableWindow(true);

		CButton *radioClean = (CButton*)GetDlgItem(btnRadioClean);
		CButton *radioGarment = (CButton*)GetDlgItem(btnRadioGarment);
		CButton *radioFood = (CButton*)GetDlgItem(btnRadioFood);
		CButton *checkManufacturer = (CButton*)GetDlgItem(btnCheckMani);

		CButton *add = (CButton*)GetDlgItem(btnAdd);

		add->EnableWindow(false);

		radioClean->EnableWindow(false);
		radioGarment->EnableWindow(false);
		radioFood->EnableWindow(false);

		if (food != NULL) {

			this->OnBnClickedbtnradiofood();
			CButton *CheckDairy = (CButton*)GetDlgItem(btnCheckDairy);
			CButton *CheckHot = (CButton*)GetDlgItem(btnCheckHot);

			bool answer = food->GetIsHot();
			CheckHot->SetCheck(answer);
			CheckDairy->EnableWindow(false);

			radioClean->SetCheck(false);
			radioGarment->SetCheck(false);
			radioFood->SetCheck(true);

		}
		else if (clean != NULL)
		{
			this->OnBnClickedbtnradioclean();
			CButton *checkDangerous = (CButton*)GetDlgItem(btnRadioDangerous);

			bool answer = clean->GetIsDangerous();
			checkDangerous->SetCheck(answer);

			radioClean->SetCheck(true);
			radioGarment->SetCheck(false);
			radioFood->SetCheck(false);
			checkManufacturer->EnableWindow(false);
		}
		else
		{
			this->OnBnClickedbtnradiogarment();
			garment->SetSize(Size_Large);

			CButton *under7 = (CButton*)GetDlgItem(IDC_under7);
			CButton *between7_18 = (CButton*)GetDlgItem(IDC_under7to18);
			CButton *above18 = (CButton*)GetDlgItem(IDC_above18);

			CButton *radioSmall = (CButton*)GetDlgItem(btnRadioSmall);
			CButton *radioMedium = (CButton*)GetDlgItem(btnRadioMedium);
			CButton *radioLarge = (CButton*)GetDlgItem(btnRadioLarge);

			checkManufacturer->EnableWindow(false);

			under7->EnableWindow(false);
			between7_18->EnableWindow(false);
			above18->EnableWindow(false);

			radioClean->SetCheck(false);
			radioGarment->SetCheck(true);
			radioFood->SetCheck(false);

			radioSmall->SetCheck(false);
			radioMedium->SetCheck(false);
			radioLarge->SetCheck(false);

			int option = garment->GetSize();

			if (option == Size_Large)
			{
				radioLarge->SetCheck(true);
			}
			else if (option == Size_Medium)
			{
				radioMedium->SetCheck(true);
			}
			else
			{
				radioSmall->SetCheck(true);
			}
		}
	}
}

void CMFCApplication1Dlg::UpdateListAfterChange()
{
	CListBox *list = (CListBox*)GetDlgItem(listProducts);
	list->ResetContent();

	totalPrice = 0.0;

	for (int i = 0; i < allProducts.GetCount(); i++)
	{
		Product * prod = allProducts[i];

		Food *food = dynamic_cast<Food*>(prod);
		CleanProduct *clean = dynamic_cast<CleanProduct*>(prod);
		Garment *garment = dynamic_cast<Garment*>(prod);

		CString str;

		if (food != NULL) {

			str.Format(_T("%d. food, Hot: %s,Dairy: %s, Price %0.2lf,"), i + 1, food->GetIsHot() ? _T("Yes") : _T("No"), food->GetIsDairy() ? _T("yes") : _T("no"), prod->GetTotalPrice());

		}
		else if (clean != NULL)
		{
			str.Format(_T("%d. Clean, Dangerous: %s, Price %0.2lf"), i + 1, clean->GetIsDangerous() ? _T("Yes") : _T("No"), prod->GetTotalPrice());

		}
		else // if (garment != NULL)
		{
			char strSize;
			int size = garment->GetSize();
			if (size == Size_Small)
			{

				strSize = 'S';
			}
			else if (size == Size_Medium)
			{

				strSize = 'M';
			}
			else // size == Size_Large;
			{
				strSize = 'L';
			}

			str.Format(_T("%d. Garment ,Israel: %s  , Size: %c, Price %0.2lf"), i + 1, garment->GetIsLocalManufacturer() ? _T("yes") : _T("no"), strSize, prod->GetTotalPrice());
		}

		list->AddString(str);
		totalPrice += allProducts[i]->GetTotalPrice();

	}

	UpdateTotalPriceLabel();

}

// serializtion//

void CMFCApplication1Dlg::OnBnClickedbtnsave()
{
	const TCHAR czFilter[] = _T("Products files (*.t34)|*.t34|All Files (*.*)|*.*||");
	CFileDialog fDialog(FALSE, _T("t34"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (fDialog.DoModal() == IDOK) {
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		allProducts.Serialize(ar);
		ar.Close();
		file.Close();
	}
}

void CMFCApplication1Dlg::OnBnClickedbtnload()
{
	const TCHAR czFilter[] = _T("Products files (*.t34)|*.t34|All Files (*.*)|*.*||");
	CFileDialog fDialog(TRUE, _T("t34"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (fDialog.DoModal() == IDOK) {
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		allProducts.Serialize(ar);
		ar.Close();
		file.Close();

		Invalidate();

		UpdateListAfterChange();
	}
}

void CMFCApplication1Dlg::OnBnClickedbtnradioellipse()
{
	CClientDC dc(this);
	//CDialogEx::OnPaint();
	CPen Pen(PS_SOLID, 7, RGB(255, 0, 0));
	CPen* old = dc.SelectObject(&Pen);
	CBrush brush(RGB(0, 255, 0));
	CBrush* oldB = dc.SelectObject(&brush);
	dc.Ellipse(100, 100, 0, 0);
	dc.SelectObject(old);
	dc.SelectObject(oldB);
}

void CMFCApplication1Dlg::OnBnClickedbtnradioretangel()
{
	CClientDC dc(this);
	//	CDialogEx::OnPaint();
	CPen Pen(PS_SOLID, 7, RGB(255, 0, 0));
	CPen* old = dc.SelectObject(&Pen);
	CBrush brush(RGB(0, 255, 0));
	CBrush* oldB = dc.SelectObject(&brush);
	dc.Rectangle(300, 0, 200, 100);
	dc.SelectObject(old);
	dc.SelectObject(oldB);

}



//ON_BN_CLICKED(btnRadioEllipse, &CMFCApplication1Dlg::OnBnClickedbtnradioellipse)
//ON_BN_CLICKED(btnRadioRetangel, &CMFCApplication1Dlg::OnBnClickedbtnradioretangel)

void CMFCApplication1Dlg::OnBnClickedButton4()
{
	Invalidate();

	// OnPaint();

}


void CMFCApplication1Dlg::OnBnClickedbtnline()
{
	CClientDC dc(this);
	CPen Pen(PS_SOLID, 7, RGB(255, 0, 0));
	CPen* old = dc.SelectObject(&Pen);
	CBrush brush(RGB(0, 255, 0));
	CBrush* oldB = dc.SelectObject(&brush);
	dc.MoveTo(10, 10); // start
	dc.LineTo(200, 50); // point
	dc.SelectObject(old);
	dc.SelectObject(oldB);
}
