//test_class_wrapper.cpp
#include <python.h>
#include <boost/python.hpp>
#include "test_class.h"

BOOST_PYTHON_MODULE(test_class)
{
    using namespace boost::python;
    // ������
    class_<A>("A", init<>())                            //���Ĭ�Ϲ��캯��û�в���������ʡ��
        .def(init<int>())                               //�������캯��
        .def("get", &A::get)                            //��Ա����
        .def("set", &A::set)                            //��Ա����
        .def_readwrite("publicVal", &A::publicVal)      //���ݳ�Ա����Ȼ�ǹ�����
    ;
    def("printA", &printA);
    def("addA", &addA);
}
