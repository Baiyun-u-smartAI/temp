#include <bits/stdc++.h>
#include <Python.h>

int main(int argc, char* argv[])
{

    Py_Initialize();//��ʼ��python
    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is', ctime(time()))\n");//ֱ������python����
    Py_FinalizeEx() ; //�ͷ�python
     return 0;
}
