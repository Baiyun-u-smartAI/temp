//
// Created by pc001 on 2021/4/14.
//

#ifndef BASE64_1_BASE64_H
#define BASE64_1_BASE64_H
#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define END_base64 '\0'

#if 1
#define PRINT_FORMAT1 "%d,%c\n",baseInt
#define PRINT_FORMAT2 "%d,%c\n",transformLeft
#else
#define PRINT_FORMAT1 "%c\n"
#define PRINT_FORMAT2 "%c\n"
#endif


// 用字符来编码
void base64encode(char src , ...);
// 用字符串来编码
void base64encode_str(char* src);
// 这些是不允许别人调用的函数
static char getBase64Char(unsigned short src);
static unsigned char locationNow();
static unsigned short fromCharTo6(char src, unsigned char location);

#ifdef __cplusplus
};
#endif
#endif //BASE64_1_BASE64_H
