/**
 * @file yj_utils.c
 * @author YYJ (alwns28@kookmin.ac.kr)
 * @brief 유틸리티 세부 함수 
 * @version 0.1
 * @date 2022-05-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include"yj_utils.h"

void help(void)
{
    printf("================================================\n");
    printf("                 YYJ_FILE_HANDLER               \n");
    printf("\n");
    printf(" * @author YYJ (alwns28@kookmin.ac.kr)\n");
    printf(" * @version 0.1\n");
    printf(" * @date 2022-05-29\n");
    printf(" * @copyright Copyright (c) 2022\n");
    printf("================================================\n");
    printf("usage: ./file_handler_main [-rwao] <file name> <message>\n");
    printf("    -r : read file\n");
    printf("    -w : write message in file\n");
    printf("    -a : append message in file\n");
    printf("    -o : print total offset \n");
}
