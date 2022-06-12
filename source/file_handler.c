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
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/sysmacros.h>
#include<unistd.h>
#include <time.h>
#include<errno.h>
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

    printf("[SUCCESS] OFFSET TOTAL : %ld\n", end-start);
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
int create_hardlink(const char *filename)
{   
    char *temp = malloc(sizeof(char) * 20);    // char 20개 크기만큼 동적 메모리 할당
    strcpy(temp, (const char *)filename);   // s2에 Hello 문자열 복사
    strcat(temp, "_hardlink");       // s2 뒤에 s1을 붙임
    if(link((const char *)filename, (const char*)temp)){
        printf("[ERROR] Create hardlink FAIL\n");
        return -1;
    }
    printf("[SUCCESS] Create hardlink of %s: %s\n", filename, temp);
    free(temp);
    return 0;
}

/**
 * @brief Create a softlink object
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 실패
 */
int create_softlink(const char *filename)
{
    char *temp = malloc(sizeof(char) * 20);    // char 20개 크기만큼 동적 메모리 할당
    strcpy(temp, (const char *)filename);   // s2에 Hello 문자열 복사
    strcat(temp, "_softlink");       // s2 뒤에 s1을 붙임
    if(symlink((const char *)filename, (const char*)temp)){
        printf("[ERROR] Create softlink FAIL\n");
        return -1;
    }
    printf("[SUCCESS] Create softlink of %s: %s\n", filename, temp);
    free(temp);
    return 0;
}

/**
 * @brief delete a link file
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 실패
 */
int delete_link(const char *filename)
{
    if(unlink(filename)){
        printf("[ERROR] Delete link FAIL\n");
        return -1;
    }
    printf("[SUCCESS] Delete link %s\n",filename);
    return 0;
}

/**
 * @brief print info of file
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 실패
 */
int stat_file(const char *filename)
{
    struct stat sb;
    if(stat(filename, &sb)){
        printf("[ERROR] Print stat FAIL\n");
        return -1;
    }
    printf("================================================\n");
    printf("[*] Filename:                 %s\n",filename);
    printf("[*] ID of containing device:  [%lx,%lx]\n",
                (long) major(sb.st_dev), (long) minor(sb.st_dev));
    printf("[*] File type:                ");

    switch (sb.st_mode & S_IFMT) {
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFIFO:  printf("FIFO/pipe\n");               break;
    case S_IFLNK:  printf("symlink\n");                 break;
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
    }

    printf("[*] I-node number:            %ld\n", (long) sb.st_ino);

    printf("[*] Mode:                     %lo (octal)\n",
            (unsigned long) sb.st_mode);

    printf("[*] Link count:               %ld\n", (long) sb.st_nlink);
    printf("[*] Ownership:                UID=%ld   GID=%ld\n",
            (long) sb.st_uid, (long) sb.st_gid);

    printf("[*] Preferred I/O block size: %ld bytes\n",
            (long) sb.st_blksize);
    printf("[*] File size:                %lld bytes\n",
            (long long) sb.st_size);
    printf("[*] Blocks allocated:         %lld\n",
            (long long) sb.st_blocks);

    printf("[*] Last status change:       %s", ctime(&sb.st_ctime));
    printf("[*] Last file access:         %s", ctime(&sb.st_atime));
    printf("[*] Last file modification:   %s", ctime(&sb.st_mtime));
    printf("================================================\n");

    return 0;
}

/**
 * @brief print sub-files in the directory.
 * 
 * @param directory 디렉토리 이름 
 * @return int 0: 성공, -1: 실패
 */
int print_tree(const char *directory)
{
    DIR *dp;
    struct dirent *entry;

    dp = opendir(directory);
    if(!dp){
        printf("[ERROR] opendir() fail\n");
        return -1;
    }

    while((entry = readdir(dp))){
        printf("     |- %s: %s\n",entry->d_name, TYPE2STR(entry->d_type));
    }

    closedir(dp);
    return 0;
}

/**
 * @brief 입력 경로 감시하는 함수
 * 
 * @param directory 경로 이름 
 * @return int 0: 성공, -1: 실패
 */
int monitor_directory(const char *directory)
{
    int fd = -1;
    int wd = -1;
    int ret;
    char buf[1024];
    struct inotify_event *event;

    fd = inotify_init();
    if(fd == -1){
        printf("[ERROR] inotify_init() fail (errno = %d, error string = %s)\n",errno, strerror(errno));
        return -1;
    }
    wd = inotify_add_watch(fd, directory, IN_ALL_EVENTS);
    if(wd == -1){
        printf("[ERROR] inotify_add_watch() fail (errno = %d, error string = %s)\n",errno, strerror(errno));
        goto inotify_err;
    }
    while(1){
        ret = read(fd, (void *)buf, sizeof(buf));
        if(ret == -1){
            printf("[ERROR] read fail (errno = %d, error string = %s)\n",errno, strerror(errno));
            goto inotify_err;
        }
        event = (struct inotify_event *)buf;
        while(ret > 0){
            printf("[noti] %s : %s\n", event->name, INOTIFY2STR(event->mask));
            ret -= (sizeof(struct inotify_event) + event->len);
            event = (struct inotify_event *)((char *)event + sizeof(struct inotify_event) + event->len);
        }
    }
    close(wd);
    close(fd);
    return 0;
inotify_err:
    if(fd > 0){
        close(fd);
    }
    if(wd > 0){
        close(wd);
    }
    return -1;
}

/**
 * @brief 여러개의 디렉토리를 모니터링하는 함수
 * 
 * @param argc 디렉터리 
 * @return int 
 */
int monitor_multi_directory(char **argc)
{
    return 0;
}