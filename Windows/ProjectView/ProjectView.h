#ifndef INCLUDED_PROJECTVIEW_H
#define INCLUDED_PROJECTVIEW_H

#ifndef INCLUDED_WINDOWS_H
#define INCLUDED_WINDOWS_H
#include <windows.h>
#endif /*INCLUDED_WINDOWS_H*/


/* -------------------------------------------------------------------------------------------------------------- */
/*  */

BOOL ProjectView_Register(HINSTANCE hInstance);

const char* ProjectView_GetClassName(void);

#endif /* INCLUDED_PROJECTVIEW_H */
