#ifndef INCLUDED_XBUILDER_MAINFRAME_H
#define INCLUDED_XBUILDER_MAINFRAME_H

#ifndef INCLUDED_WINDOWS_H
#define INCLUDED_WINDOWS_H
#include <windows.h>
#endif /*INCLUDED_WINDOWS_H*/

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

BOOL xBuilder_MainFrame_Register(HINSTANCE hInstance);

HWND xBuilder_MainFrame_Create(HINSTANCE hInstance, int x, int y, int width, int height);

void xBuilder_MainFrame_Show(HWND hwnd, int nCmdShow);

#endif /*INCLUDED_XBUILDER_MAINFRAME_H*/
