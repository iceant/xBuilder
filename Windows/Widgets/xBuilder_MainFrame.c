#include <xBuilder_MainFrame.h>
#include <windowsx.h>
#include <xBuilder_MainFrame_OnDestroy.h>

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

#define XBUILDER_MAINFRAME_CLASSNAME "xBuilder_MainFrame"



/* -------------------------------------------------------------------------------------------------------------- */
/*  */

static LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
    switch (Message) {
        HANDLE_MSG(hwnd, WM_DESTROY, xBuilder_MainFrame_OnDestroy);
        default:
            return DefWindowProc(hwnd, Message, wParam, lParam);
    }
}


/* -------------------------------------------------------------------------------------------------------------- */
/*  */

BOOL xBuilder_MainFrame_Register(HINSTANCE hInstance){
    WNDCLASS WndClass;
    memset(&WndClass, 0, sizeof(WndClass));
    WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    WndClass.lpfnWndProc = WndProc;
    WndClass.hInstance = hInstance;
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    WndClass.lpszMenuName = NULL;
    WndClass.lpszClassName = XBUILDER_MAINFRAME_CLASSNAME;
    return (RegisterClass(&WndClass)!=0)?TRUE:FALSE;
}

HWND xBuilder_MainFrame_Create(HINSTANCE hInstance, int x, int y, int width, int height){
    HWND hwnd = CreateWindow(XBUILDER_MAINFRAME_CLASSNAME, XBUILDER_MAINFRAME_CLASSNAME
                             , WS_OVERLAPPEDWINDOW
                             , x, y, width, height
                             , NULL, NULL
                             , hInstance, NULL);

    return hwnd;
}

void xBuilder_MainFrame_Show(HWND hwnd, int nCmdShow){
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
}