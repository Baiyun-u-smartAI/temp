#ifndef TEST_CLASS_H
#define TEST_CLASS_H

class A
{
    public:
        A(){privateVal=0;}                      //Ĭ�Ϲ��캯��
        A(int val){privateVal=val;}             //�������Ĺ��캯��
        void set(int val){privateVal=val;}      //��Ա����
        int get() const {return privateVal;};   //��Ա����
        int publicVal;                          //�������ݳ�Ա
    private:
        int privateVal;                         //˽�����ݳ�Ա
};

int addA(A &a, int addVal);                   //��ͨ�������з���ֵ��ͨ�������޸Ĳ���
void printA(const A& a);
#endif
