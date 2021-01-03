#include <bits/stdc++.h>
#include <Python.h>

int main(int argc, char* argv[])
{

    Py_Initialize();//初始化python
    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is', ctime(time()))\n");//直接运行python代码
    Py_FinalizeEx() ; //释放python
     return 0;
}
