// KiemTra.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "KiemTra.h"

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
INT_PTR CALLBACK    RegisterStudent(HWND, UINT, WPARAM, LPARAM);


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
    LoadStringW(hInstance, IDC_KIEMTRA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_KIEMTRA));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KIEMTRA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_KIEMTRA);
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
    static HWND btnThoat, lstDSSV, editHT;
    static int index;
    static TCHAR item[30];
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_BTN_Sua:
                if (index < 0) {
                    MessageBox(NULL, TEXT("Please select an item!"), TEXT("OK"), MB_OK | MB_ICONWARNING);
                    return 0;
                }
               
                GetWindowText(editHT, item, 30);
                SendMessage(lstDSSV, LB_DELETESTRING, index, 0);
                SendMessage(lstDSSV, LB_INSERTSTRING, index, (LPARAM)item);
                break;

            case ID_BTN_Thoat:
                if (MessageBox(NULL, TEXT("Bạn có muốn thoát không?"), TEXT("TB"), MB_YESNO | MB_ICONQUESTION) == IDYES)
                    EndDialog(btnThoat, TRUE);
                break;

            case ID_BTN_Xoa:
                // lay vi tri
                index = SendMessage(lstDSSV, LB_GETCURSEL, 0, 0);
                if (HIWORD(wParam) == LBN_DBLCLK) {
                    if (MessageBox(NULL, TEXT("Do you want to delete this item?"),
                        TEXT("Yes or no"), MB_YESNO | MB_ICONQUESTION) == IDYES) {
                        SendMessage(lstDSSV, LB_DELETESTRING, index, 0);
                    }
                    break;
                }
                SendMessage(lstDSSV, LB_GETTEXT, index, (LPARAM)item);
                SetWindowText(editHT, item);
                break;
            case ID_QLSV:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, RegisterStudent);
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

INT_PTR CALLBACK RegisterStudent(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam) 
{
    static HWND editHT, lstDSSV, btnThem, btnSua, btnXoa, btnTim, btnThoat;
    switch (message)
    {
    case WM_INITDIALOG:
        editHT = GetDlgItem(hwndDlg, IDC_EDIT_HT);
        lstDSSV = GetDlgItem(hwndDlg, ID_LST_DSSV);
        btnThem = GetDlgItem(hwndDlg, ID_BTN_Them);
        btnSua = GetDlgItem(hwndDlg, ID_BTN_Sua);
        btnXoa = GetDlgItem(hwndDlg, ID_BTN_Xoa);
        btnTim = GetDlgItem(hwndDlg, ID_BTN_Tim);
        btnThoat = GetDlgItem(hwndDlg, ID_BTN_Thoat);
        SendMessage(lstDSSV, CB_INSERTSTRING, -1, (LPARAM)TEXT("Hà Văn Thời"));
        SendMessage(lstDSSV, CB_INSERTSTRING, -1, (LPARAM)TEXT("Hà Văn Hùng"));
        SendMessage(lstDSSV, CB_INSERTSTRING, -1, (LPARAM)TEXT("Hà Văn Nam"));
        SendMessage(lstDSSV, CB_INSERTSTRING, -1, (LPARAM)TEXT("Hà Văn Hoàng"));

        break;
    default:
        break;
    }
    return FALSE;
}
