#include <MainFrame_OnDestroy.h>

void MainFrame_OnDestroy(HWND hwnd){
    PostQuitMessage(0);
}
