REM g++ -o test.exe main.cpp -Wall -lpython37 -L"D:\Program Files\Anaconda3\libs" -I"D:\Program Files\Anaconda3\include"
g++ -o test_class.pyd test_class.cpp test_class.h test_class_wrapper.cpp -shared -fPIC -L"D:\Program Files\Anaconda3" -I"D:\Program Files\Anaconda3\include" -I. -L. -lboost_python37-mgw81-mt-d-x64-1_71 -lpython37
