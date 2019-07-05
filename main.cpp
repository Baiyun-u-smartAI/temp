#include <iostream>
#include <list>

using namespace std;
template <typename Unknown>

void edit(list<Unknown> *m, int n, Unknown l){


    auto it1d = (*m).begin();//内层指针
    int k = (*m).size();//数值外层长度
    if (n>=k )
    {
        cout<<"error!!!"<<endl;
    }
    else
    {
        for (int i =0; i<n;i++){
            it1d++;
        }
        *it1d = l;
    }


}
template < typename unk, typename unk2>
void find_add(list<unk> a,int m, unk2 *b){
    if (m>=a.size()){
        throw -1; // 报错

    }
    else{
        auto d=a.begin();
        for (int i =0; i<m;i++){++d;}
        *b=d;
        //cout<<&(a.begin());
    }



}

template < typename unk3>
void erase_row(list<unk3> *m, int n){
    list<unk3> mat;
    auto it2d = (*m).begin();
    int k = (*m).size();
    for (int i=0;i<k;i++){

        if (i!=n){
            mat.push_back(*it2d);


        }
        it2d++;

    }
    *m = mat;



}




double mould(list<list <double> > mat){





}

int main()
{
    list<list <string> > mat; //二维数组
    list<string> a{"sdas","fhskaduhgfukias"};
    list<string> b{"sdas","fhskaduhgfukias","sdas","fhskaduhgfukias"};
    mat.push_back(a);
    mat.push_back(b);
    list<list <string> >::iterator it2d; //外层指针
    list<string>::iterator it1d; //内层指针

    cout << "\xca\xe4\xc8\xeb:"<<endl;
    cout << "output:\n\n";
    cout << *(mat.begin()) << "\n\n";
    for (it2d=mat.begin();it2d!=mat.end();it2d++){
        edit(&(*it2d),1,(string)"dfas"); //&(*it2d)指的是外层指针对应的内层string的指针
        //上述是每一个内层指针指向的string的第二项为"dfas"

        //输出修改后的二维string list（内层）
        for (it1d=(*it2d).begin();it1d!=(*it2d).end();it1d++){
            cout<<*it1d<<"\t";

        }
        cout<<"\n";


        list<string>::iterator c;

        try{
            cout<<*((*it2d).begin())<<endl;
            find_add((*it2d),0,&c);
            cout<<"output:\t";

            cout<<*c<<endl;
        }
        catch(int){
            ;
        }


    }
    list<string> c{"sda6s","fhskaduhgfuki9as","sdas","fhsuhgfukias"};
    mat.push_back(c);
    cout<<"\n new:\n";
    for (it2d=mat.begin();it2d!=mat.end();it2d++){
        for (it1d=(*it2d).begin();it1d!=(*it2d).end();it1d++){
            cout<<*it1d<<"\t";

        }
        cout<<"\n";

    }
    erase_row(&mat,0);

}
