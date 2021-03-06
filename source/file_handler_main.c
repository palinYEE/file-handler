/**
 * @file file_handler_main.c
 * @author YYJ (alwns28@kookmin.ac.kr)
 * @brief main source 
 * @version 0.1
 * @date 2022-05-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include"yj_utils.h"
#include"file_handler.h"

int main(int argc, char **argv)      // 옵션의 개수와 옵션 문자열을 배열로 받음
{
    if(argc < 2){
        help();
        return -1;
    }

    switch (argv[1][1])
    {
    case 'w':
        if(argv[3]){
            if(yj_write_to_file(argv[2], argv[3]) != 0){
                printf("[ERROR] yj_write_to_file error\n");
            }
        } 
        else {
            goto goto_help;
        }
        break;
    case 'r':
        if(argv[3]){
            goto goto_help;
        } 
        else {
            if(yj_read_to_file(argv[2]) != 0){
                printf("[ERROR] yj_read_to_file \n");
            }
        }
        break;
    case 'a':
        if(argv[3]){
            if(yj_append_to_file(argv[2], argv[3]) != 0){
                printf("[ERROR] yj_append_to_file error\n");
            }
        } 
        else {
            goto goto_help;
        }
        break;
    case 'o':
        if(argv[2]){
            if(yj_file_len_print(argv[2]) != 0){
                printf("[ERROR] yj_offset_print error\n");
            }
        } 
        else {
            goto goto_help;
        }
        break;
    case 'l':
        switch (argv[2][2])
        {
        case 'h':   /* hard link */
            create_hardlink(argv[3]);
            break;
        case 's':   /* soft link */
            create_softlink(argv[3]);
            break;
        case 'd':   /* delete link */
            delete_link(argv[3]);
            break;
        default:
            break;
        }
        break;
    case 'p':       /* 파일 정보 print 함수 */
        stat_file(argv[2]);
        break;
    case 't':       /* 입력 디렉토리 하위 파일 리스트 출력 함수 */
        print_tree(argv[2]);
        break;
    case 's':
        monitor_directory(argv[2]);
        break;
    case 'm':   /* TODO: select 또는 epoll을 사용하여 여러 디렉토리를 watch 하는 함수 작성. */
        monitor_multi_directory(argc - 2, argv);
        break;
    default:
        printf("./file_handler_main: invalid option -- %s\n", argv[1]);
        help();
        break;
    }
    return 0;

goto_help:
    printf("./file_handler_main: invalid option\n");
    help();
}