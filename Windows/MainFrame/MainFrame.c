#include <MainFrame.h>
#include <assert.h>
#include "MainFrame_OnDestroy.h"
#include "MainFrame_OnPaint.hpp"
#include "MainFrame_OnCreate.hpp"
/* -------------------------------------------------------------------------------------------------------------- */
/*  */

#define MAIN_FRAME_CLASSNAME "xBuilder.MainFrame"

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

HINSTANCE MainFrame_hInstance;

/* -------------------------------------------------------------------------------------------------------------- */
/*  */


static HWND ProjectView_HWND;

/* -------------------------------------------------------------------------------------------------------------- */
/*  */
static LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
    switch(Message){
        HANDLE_MSG(hwnd, WM_CREATE, MainFrame_OnCreate);
        HANDLE_MSG(hwnd, WM_DESTROY, MainFrame_OnDestroy);
        HANDLE_MSG(hwnd, WM_PAINT, MainFrame_OnPaint);
        default:
            return DefWindowProc(hwnd, Message, wParam, lParam);
    }
}

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

BOOL MainFrame_Register(HINSTANCE hInstance){
    WNDCLASS WndClass;
    
    memset(&WndClass, 0, sizeof(WndClass));
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    WndClass.lpfnWndProc = WndProc;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = hInstance;
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    WndClass.lpszMenuName = 0;
    WndClass.lpszClassName = MAIN_FRAME_CLASSNAME;
    
    MainFrame_hInstance = hInstance;
    
    return (RegisterClass(&WndClass)!=0)?TRUE:FALSE;
}

HWND MainFrame_Create(HINSTANCE hInstance){
    HWND hwnd = CreateWindow(MAIN_FRAME_CLASSNAME, "MainFrame"
                             , WS_OVERLAPPEDWINDOW
                             , CW_USEDEFAULT, CW_USEDEFAULT
                             , CW_USEDEFAULT, CW_USEDEFAULT
                             , NULL, NULL, hInstance, NULL
                             );
    assert(hwnd);
    return hwnd;
}

void MainFrame_Show(HWND hwnd, int nCmdShow){
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
}

const char* MainFrame_GetClassName(void){
    return MAIN_FRAME_CLASSNAME;
}

void MainFrame_SetProjectView(HWND hwnd){
    ProjectView_HWND = hwnd;
}

HWND MainFrame_GetProjectView(void){
    return ProjectView_HWND;
}
