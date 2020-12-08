
// MFCApplication1Dlg.h : header file
//

#pragma once


#include "Product.h"

// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedbtnadd();
	void UpdateTotalPriceLabel();
	afx_msg void OnBnClickedbtnclear();
	afx_msg void OnBnClickedbtnradioclean();
	afx_msg void OnBnClickedbtnradiogarment();
	afx_msg void OnBnClickedbtnradiofood();
	afx_msg void OnBnClickedbtnupdateitem();
	afx_msg void OnLbnSelchangelistproducts();

public:
	

	CTypedPtrArray<CObArray, Product*> allProducts;

	void UpdateListAfterChange();
	afx_msg void OnBnClickedbtnsave();
	afx_msg void OnBnClickedbtnload();

	double totalPrice = 0.0;
	afx_msg void OnBnClickedbtnradioellipse();
	afx_msg void OnBnClickedbtnradioretangel();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedbtnline();
};
