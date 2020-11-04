#ifdef _WIN64
#ifdef _MSC_VER_
#include <iostream>
int main(){
    std::cout<<"cannot compile with vc++!!"<<std::endl;
}
#endif
#ifdef __GNUC__
#include <windows.h>
#include <bits/stdc++.h>
#include <csignal>
BOOL WINAPI ConsoleHandler(DWORD);
int main(){
    SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler,TRUE);
    for(;;){

    }

}
BOOL WINAPI ConsoleHandler(DWORD dwType) {
    switch(dwType){
        case CTRL_C_EVENT:
            std::cout<<"now I have to end program!"<<std::endl;
            ::system("pause");
            break;
    }
    exit(1);
    return TRUE;
}
#endif
#endif
#ifdef _LINUX
#include <signal.h>
#include <iostream>
void exit_func(int key){
    if (key==2)
        std::cout<<"now I have to end program(with ctrl-c)!"<<std::endl;
    exit(1);
}

int main(){
    signal(SIGINT, exit_func);
    for(;;);
}
#endif
