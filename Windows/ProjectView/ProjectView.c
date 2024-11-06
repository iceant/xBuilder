#include <ProjectView.h>
#include <windowsx.h>
#include <ProjectView_OnCreate.hpp>
#include <ProjectView_OnPaint.hpp>
/* -------------------------------------------------------------------------------------------------------------- */
/*  */

#define PROJECT_VIEW_CLASSNAME "xBuilder.ProjectView"
/* -------------------------------------------------------------------------------------------------------------- */
/*  */

static LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
    switch(Message){
        HANDLE_MSG(hwnd, WM_CREATE, ProjectView_OnCreate);
        HANDLE_MSG(hwnd, WM_PAINT, ProjectView_OnPaint);
        default:
            return DefWindowProc(hwnd, Message, wParam, lParam);
    }
}

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

BOOL ProjectView_Register(HINSTANCE hInstance){
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
    WndClass.lpszClassName = PROJECT_VIEW_CLASSNAME;
    return (RegisterClass(&WndClass)!=0)?TRUE:FALSE;
}

const char* ProjectView_GetClassName(void){
    return PROJECT_VIEW_CLASSNAME;
}
