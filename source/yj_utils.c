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
    printf("Usage: ./file_handler_main [options] [variable[=value] ...]\n\n");
    printf("Options:\n");
    printf("    -r [filename]: read file\n");
    printf("    -w [filename] [Message]: write message in file\n");
    printf("    -a [filename] [Message]: append message in file\n");
    printf("    -o [filename]: print total offset \n");
    printf("    -l  [--hsd] [filename]\n");
    printf("        --h: create hard link\n");
    printf("        --s: create soft link\n");
    printf("        --d: delete link \n");
    printf("    -p [filename]: print file summary\n");
    printf("    -t [directory]: print sub-files in the directory.\n");
}
