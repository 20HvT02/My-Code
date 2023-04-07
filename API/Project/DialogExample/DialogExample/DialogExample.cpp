
// DialogExample.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "DialogExample.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    DlgStudent(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    DlgStudentNew(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DIALOGEXAMPLE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DIALOGEXAMPLE));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DIALOGEXAMPLE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DIALOGEXAMPLE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_HELP_GETSTUDENTINFOMATION:
                HWND hwndDlg;
                hwndDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DlgStudent);
                ShowWindow(hwndDlg, SW_SHOW);
                //DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DlgStudent);
                break;
            case ID_HELP_ADDSTUDENTNEWMENU:
                HWND hwndDlgnew;
                hwndDlgnew = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DlgStudentNew);
                ShowWindow(hwndDlgnew, SW_SHOW);
                //DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DlgStudent);
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK    DlgStudent(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hwndEditHT, hwndListSV, hwndBtnOK, hwndBtnCancel;
    static TCHAR hoten[30];
    static int len;
    switch (message) {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            len = GetWindowText(hwndEditHT, hoten, 30);
            if (len == 0) {
                MessageBox(NULL, TEXT("Please enter your name!"), TEXT("Warning"), MB_OK);
                return 0;
            }
            SendMessage(hwndListSV, LB_INSERTSTRING, -1, (LPARAM)hoten);
            SetWindowText(hwndEditHT, TEXT(""));
            SetFocus(hwndEditHT);
            break;
        default:
            break;
        }
        break;
    case WM_INITDIALOG:
        hwndEditHT = GetDlgItem(hwndDlg, IDC_EDIT_HT);
        hwndListSV = GetDlgItem(hwndDlg, IDC_LIST_SV);
        hwndBtnOK = GetDlgItem(hwndDlg, IDOK);
        hwndBtnCancel = GetDlgItem(hwndDlg, IDCANCEL);

        SetFocus(GetDlgItem(hwndDlg, IDC_EDIT_HT));
        break;
    case WM_CLOSE:
        EndDialog(hwndDlg, TRUE);
        break;
    default:
        break;

    }
    return FALSE;

}

INT_PTR CALLBACK    DlgStudentNew(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hwndEditMaSv, hwndEditHT, hwndListSV, hwndBtnDangKy, hwndBtnLamLai, hwndBtnThoat, hwndBtnXoa;
    static TCHAR hoten[30], ketqua[100],monhoc[100], maSV[20], khoa[20], KhoaHoc[20];
    static int len, count = 0, indexKhoa = 0, indexKhoaHoc = 0, listCount = 0;
    switch (message) {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON_THOAT:

            if (MessageBox(NULL, TEXT("Bạn có muốn thoát không?"), TEXT("TB"), MB_YESNO | MB_ICONQUESTION) == IDYES)
                EndDialog(hwndDlg, TRUE);
            break;
        case IDC_BUTTON_LAMLAI:
            SetWindowText(GetDlgItem(hwndDlg, IDC_EDIT_MASV), TEXT(""));
            SetWindowText(GetDlgItem(hwndDlg, IDC_EDIT_HT2), TEXT(""));
            SendMessage(GetDlgItem(hwndDlg, IDC_CHECK_TINDC), BM_SETCHECK, 0, 0);
            SendMessage(GetDlgItem(hwndDlg, IDC_CHECK_GT), BM_SETCHECK, 0, 0);
            SendMessage(GetDlgItem(hwndDlg, IDC_CHECK_TA), BM_SETCHECK, 0, 0);
            SendMessage(GetDlgItem(hwndDlg, IDC_CHECK_TRIET), BM_SETCHECK, 0, 0);
            SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOA), CB_SETCURSEL, -1, 0);
            SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOAS), CB_SETCURSEL, -1, 0);
            count = 0;
            break;
        case IDC_BUTTON_DKI:
            wsprintf(ketqua, L"");
            wsprintf(monhoc, L"");
            if (GetWindowText(GetDlgItem(hwndDlg, IDC_EDIT_MASV), maSV, 9) != 8)
            {
                MessageBox(NULL, TEXT("Bạn phải nhập mã SV là chuỗi gồm 8 ký tự"), TEXT(""), MB_OK);
                SetFocus(GetDlgItem(hwndDlg, IDC_EDIT_MASV));
                return 0;
            }
            if (GetWindowText(GetDlgItem(hwndDlg, IDC_EDIT_HT2), hoten, 30) == 0)
            {
                MessageBox(NULL, TEXT("Bạn phải nhập họ tên SV"), TEXT(""), MB_OK);
                SetFocus(GetDlgItem(hwndDlg, IDC_EDIT_HT2));
                return 0;
            }
            indexKhoa = SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOA), CB_GETCURSEL, 0, 0);
            if (indexKhoa < 0)
            {
                MessageBox(NULL, TEXT("Bạn phải chọn Khoa"), TEXT(""), MB_OK);

            }

            else
                SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOAS), CB_GETLBTEXT, indexKhoa, (LPARAM)khoa);
            indexKhoaHoc = SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOAS), CB_GETCURSEL, 0, 0);
            if (indexKhoaHoc < 0)
            {
                MessageBox(NULL, TEXT("Bạn phải chọn Khóa học"), TEXT(""), MB_OK);

            }

            else
                SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOAS), CB_GETLBTEXT, indexKhoaHoc, (LPARAM)KhoaHoc);
            if (SendMessage(GetDlgItem(hwndDlg, IDC_CHECK_TINDC), BM_GETCHECK, 0, 0) == TRUE)
            {
                count++;
                wsprintfW(monhoc, L"%s;Tin học đại cương", monhoc);
            }
            if (SendMessage(GetDlgItem(hwndDlg, IDC_CHECK_GT), BM_GETCHECK, 0, 0) == TRUE)
            {
                count++;
                wsprintfW(monhoc, L"%s;Giải tích F1", monhoc);
            }
            if (SendMessage(GetDlgItem(hwndDlg, IDC_CHECK_TA), BM_GETCHECK, 0, 0) == TRUE)
            {
                count++;
                wsprintfW(monhoc, L"%s;Tiếng anh A1", monhoc);
            }
            if (SendMessage(GetDlgItem(hwndDlg, IDC_CHECK_TRIET), BM_GETCHECK, 0, 0) == TRUE)
            {
                count++;
                wsprintfW(monhoc, L"%s;Triết học F1", monhoc);
            }
            if (count < 2)
            {
                MessageBox(NULL, TEXT("Bạn phải đăng ký ít nhất hai môn"), TEXT("Hi"), MB_OK);
                return 0;
            }
            listCount = SendMessage(GetDlgItem(hwndDlg, IDC_LIST_SV2), LB_GETCOUNT, 0, 0);
            wsprintfW(ketqua, L"%d.%s|%s|%s|%s|%s", (listCount + 1), maSV, hoten, khoa, KhoaHoc, monhoc);

            SendMessage(GetDlgItem(hwndDlg, IDC_LIST_SV2), LB_INSERTSTRING, -1, (LPARAM)ketqua);
            break;


        /*case IDOK:
            len = GetWindowText(hwndEditHT, hoten, 30);
            if (len == 0) {
                MessageBox(NULL, TEXT("Please enter your name!"), TEXT("Warning"), MB_OK);
                return 0;
            }
            SendMessage(hwndListSV, LB_INSERTSTRING, -1, (LPARAM)hoten);
            SetWindowText(hwndEditHT, TEXT(""));
            SetFocus(hwndEditHT);
            break;*/
        default:
            break;
        }
        break;
    case WM_INITDIALOG:
        hwndEditMaSv = GetDlgItem(hwndDlg, IDC_EDIT_MASV);
        hwndEditHT = GetDlgItem(hwndDlg, IDC_EDIT_HT2);
        hwndListSV = GetDlgItem(hwndDlg, IDC_LIST_SV2);
        hwndBtnDangKy = GetDlgItem(hwndDlg, IDC_BUTTON_DKI);
        hwndBtnLamLai = GetDlgItem(hwndDlg, IDC_BUTTON_LAMLAI);
        hwndBtnThoat = GetDlgItem(hwndDlg, IDC_BUTTON_THOAT);
        hwndBtnXoa = GetDlgItem(hwndDlg, IDC_BTN_XOA);

        SetFocus(GetDlgItem(hwndDlg, IDC_EDIT_HT2));

        SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOA), CB_INSERTSTRING, -1, (LPARAM)TEXT("Công nghệ thông tin"));
        SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOA), CB_INSERTSTRING, -1, (LPARAM)TEXT("Công trình"));
        SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOA), CB_INSERTSTRING, -1, (LPARAM)TEXT("Kinh tế vận tải"));
        SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOAS), CB_INSERTSTRING, -1, (LPARAM)TEXT("55"));
        SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOAS), CB_INSERTSTRING, -1, (LPARAM)TEXT("56"));
        SendMessage(GetDlgItem(hwndDlg, IDC_COMBO_KHOAS), CB_INSERTSTRING, -1, (LPARAM)TEXT("57"));
        EnableWindow(GetDlgItem(hwndDlg, IDC_BTN_XOA), TRUE);
        count = 0;
        return (INT_PTR)TRUE;
        break;
    case WM_CLOSE:
        EndDialog(hwndDlg, TRUE);
        break;
    default:
        break;

    }
    return FALSE;

}
