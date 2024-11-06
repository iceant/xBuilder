#ifndef INCLUDED_MAINFRAME_ONPAINT_HPP
#define INCLUDED_MAINFRAME_ONPAINT_HPP

#ifndef INCLUDED_WINDOWS_H
#define INCLUDED_WINDOWS_H
#include <windows.h>
#endif /*INCLUDED_WINDOWS_H*/

#ifndef INCLUDED_UITOOLKIT_VIEW_H
#include <uiToolkit_View.h>
#endif /*INCLUDED_UITOOLKIT_VIEW_H*/

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

void MainFrame_OnPaint(HWND hwnd){
    uiToolkit_FitParent(MainFrame_GetProjectView(), hwnd);
}


#endif /* INCLUDED_MAINFRAME_ONPAINT_HPP */
