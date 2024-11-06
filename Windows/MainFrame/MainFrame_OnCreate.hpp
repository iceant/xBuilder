#ifndef INCLUDED_MAINFRAME_ONCREATE_HPP
#define INCLUDED_MAINFRAME_ONCREATE_HPP

#ifndef INCLUDED_WINDOWS_H
#define INCLUDED_WINDOWS_H
#include <windows.h>
#endif /*INCLUDED_WINDOWS_H*/

#ifndef INCLUDED_PROJECTVIEW_H
#include <ProjectView.h>
#endif /*INCLUDED_PROJECTVIEW_H*/

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

extern HINSTANCE MainFrame_hInstance;

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

BOOL MainFrame_OnCreate(HWND hwnd,  LPCREATESTRUCT pCreateStruct)
{
    HWND ProjectView_hwnd = CreateWindow(ProjectView_GetClassName(), "ProjectView"
                            , WS_CHILD | WS_VSCROLL | WS_BORDER
                            , CW_USEDEFAULT, CW_USEDEFAULT
                            , CW_USEDEFAULT, CW_USEDEFAULT
                            , hwnd, NULL, MainFrame_hInstance, NULL);
    
    MainFrame_SetProjectView(ProjectView_hwnd);
    
    return TRUE;
}


#endif /* INCLUDED_MAINFRAME_ONCREATE_HPP */
