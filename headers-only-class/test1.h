//
// Created by pc001 on 2021/5/12.
//

#ifndef CV_TEST1_H
#define CV_TEST1_H
#include <iostream>
class haha{
public:
  // 采用对象实现headers-only
  haha(){
    std::cout<<"haha"<<std::endl;
  }
  // 函数没有实现，是被另一个cpp文件封装了
  void mm();
};


#endif // CV_TEST1_H
