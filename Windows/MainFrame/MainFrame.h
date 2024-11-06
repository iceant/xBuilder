#ifndef INCLUDED_MAINFRAME_H
#define INCLUDED_MAINFRAME_H

#ifndef INCLUDED_WINDOWS_H
#define INCLUDED_WINDOWS_H
#include <windows.h>
#endif /*INCLUDED_WINDOWS_H*/

#ifndef INCLUDED_WINDOWSX_H
#define INCLUDED_WINDOWSX_H
#include <windowsx.h>
#endif /*INCLUDED_WINDOWSX_H*/

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

BOOL MainFrame_Register(HINSTANCE hInstance);

void MainFrame_Show(HWND hwnd, int nCmdShow);

const char* MainFrame_GetClassName(void);

HWND MainFrame_Create(HINSTANCE hInstance);

void MainFrame_SetProjectView(HWND hwnd);

HWND MainFrame_GetProjectView(void);

#endif /* INCLUDED_MAINFRAME_H */
