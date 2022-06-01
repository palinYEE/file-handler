/**
 * @file file_handler.c
 * @author YYJ (alwns28@kookmin.ac.kr)
 * @brief 파일 헨들러 세부 함수
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
#include"file_handler.h"

/**
 * @brief 입력한 문자열을 파일에 쓰는 함수 (해당 함수는 append가 아닌 recreate 이다.)
 * 
 * @param filename 파일 이름
 * @param message 파일에 쓸 메세지
 * 
 * @return int 0: 성공, -1: 실패
 */
int yj_write_to_file(char *filename, char *message)
{
    FILE *fp = NULL;

    if(!(fp = fopen(filename, "w"))){
        perror("[ERROR] fopen error\n");
        goto err;
    }

    if(fputs((const char *)message, fp) == 1){
        printf("[SUCCESS] SAVE MESSAGE IN %s\n", filename);
    }
    else{
        printf("[ERROR] fputs error\n");
        goto err;
    }

    fclose(fp);
    return 0;

err:
    if(fp != NULL){
        fclose(fp);
    }
    return -1;
}

/**
 * @brief 파일의 문자열을 읽는 함수 (최대 1024 바이트 까지만 읽는다.)
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 실패
 */
int yj_read_to_file(char *filename)
{
    FILE *fp = NULL;
    char buf[1024];

    if(!(fp = fopen(filename, "r"))){
        perror("[ERROR] fopen error\n");
        goto err;
    }

    memset((void *)buf, 0, sizeof(buf));

    if(fgets(buf, sizeof(buf), fp) == NULL){
        printf("[ERROR] fread error\n");
        goto err;
    }

    printf("MESSAGE - %s\n", buf);

    return 0;

err:
    if(fp != NULL){
        fclose(fp);
    }
    return -1;
}

/**
 * @brief 파일에 해당 message를 append 하는 함수
 * 
 * @param filename 파일 이름
 * @param message 쓸 메세지
 * @return int 0: 성공, -1: 실패
 */
int yj_append_to_file(char *filename, char *message)
{
    FILE *fp = NULL;

    if(!(fp = fopen(filename, "a"))){
        perror("[ERROR] fopen error\n");
        goto err;
    }
    
    printf("after fopen(), offset = %ld\n", ftell(fp));

    if(fputs((const char *)message, fp) == 1){
        printf("[SUCCESS] SAVE MESSAGE IN %s\n", filename);
    }
    else{
        printf("[ERROR] fputs error\n");
        goto err;
    }

    printf("before fclose(). offset=%ld\n", ftell(fp));

    fclose(fp);
    return 0;

err:
    if(fp != NULL){
        fclose(fp);
    }
    return -1;
}

/**
 * @brief 해당 파일의 오프셋을 출력한다.
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 싪패
 */
int yj_file_len_print(char *filename)
{
    FILE *fp;
    unsigned long int start, end;

    if(!(fp = fopen(filename, "r+"))){
        perror("[ERROR] fopen error\n");
        goto err;
    }
    start = ftell(fp);
    fseek(fp, 0, SEEK_END);
    end = ftell(fp);

    printf("OFFSET TOTAL : %ld\n", end-start);
    fclose(fp);
    return 0;

err:
    if(fp != NULL){
        fclose(fp);
    }
    return -1;
}

/**
 * @brief 하드 링크를 생성하는 함수 
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 실패
 */
int create_hardlink(char *filename)
{
    return 0;
}

/**
 * @brief Create a softlink object
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 실패
 */
int create_softlink(char *filename)
{
    return 0;
}