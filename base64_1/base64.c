//
// Created by pc001 on 2021/4/14.
//
#include "base64.h"

static short transformLeft;
static char put_left=0;//第三个字符输出标识位

static char getBase64Char(unsigned short src) {
    switch (src) {
        case 62:return '+';
        case 63:return '/';
        default:;
    }
    if (src <= 25) {
        return src + 'A';
    } else if (src <= 51) {
        return src - 26 + 'a';
    } else if (src <= 61) {
        return src - 52 + '0';
    } else {
        fprintf(stderr,"error in %s\n",__func__ );
        return -1;
    }
}

void base64encode_str(char* src) {
    char tmp=*src;//每次做转换的字符
    char i;
    do {
        i=locationNow();
        unsigned short baseInt =fromCharTo6(tmp,i);
        printf(PRINT_FORMAT1,getBase64Char(baseInt));
        if (put_left) printf(PRINT_FORMAT2,getBase64Char(transformLeft));//如果标识位为1，说明当前还剩下一个字符未输出，要从transformLeft输出
        src++;
        tmp=*src;
    } while (*src!='\0');
    // 输入的字符数不是三的倍数，要在最后输出剩下的transformLeft，并补=
    if (i==2) {
        printf(PRINT_FORMAT2,getBase64Char(transformLeft<<2));
        printf("=");
    } else if (i==1){
        printf(PRINT_FORMAT2,getBase64Char(transformLeft<<4));
        printf("=\n=");
    }

}


void base64encode(char src , ...) {
    va_list vl;
    va_start(vl,src);

    char tmp=src;//每次做转换的字符
    char i;
    do {
        i=locationNow();
        unsigned short baseInt =fromCharTo6(tmp,i);
        printf(PRINT_FORMAT1,getBase64Char(baseInt));
        if (put_left) printf(PRINT_FORMAT2,getBase64Char(transformLeft));//如果标识位为1，说明当前还剩下一个字符未输出，要从transformLeft输出
        tmp= va_arg(vl, int );//取下一个字符
    }while (tmp!=END_base64);
    // 输入的字符数不是三的倍数，要在最后输出剩下的transformLeft，并补=
    if (i==2) {
        printf(PRINT_FORMAT2,getBase64Char(transformLeft<<2));
        printf("=");
    } else if (i==1){
        printf(PRINT_FORMAT2,getBase64Char(transformLeft<<4));
        printf("=\n=");
    }
}

//这个是一个1-2-3生成器，每次调用会按照1-2-3顺序输出，（如果上次输出2，本次输出3）
static unsigned char locationNow(){
    static unsigned char dst=0;
    put_left=0;//标识位清0
    dst = (dst==3)? 1:(dst+1);
    if (dst==3) put_left=1;//如果当前输出3，要让标识位为1
    return dst;
}

//把8位二进制数，拆分成base64算法所对应的6位二进制
static unsigned short fromCharTo6(char src, unsigned char location){
    static unsigned short dst;
    if (location==1){
        dst = src>>2;
        transformLeft = src & 0b00000011;
    }else if (location==2) {
        dst = (src>>4)|(transformLeft<<4);
        transformLeft = src & 0b00001111;
    }else {
        dst = (src>>6)|(transformLeft<<2);
        transformLeft = src & 0b00111111;
    }
    return dst;
}