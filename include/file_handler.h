/**
 * @file file_handler.h
 * @author YYJ (alwns28@kookmin.ac.kr)
 * @brief file handler function collection
 * @version 0.1
 * @date 2022-05-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include<sys/types.h>
#include<dirent.h>
#include<sys/inotify.h>

#define TYPE2STR(X)\
    ((X) == DT_BLK    ? "block device" :\
     (X) == DT_CHR    ? "char device" :\
     (X) == DT_DIR    ? "directory" :\
     (X) == DT_FIFO   ? "fifo" :\
     (X) == DT_LNK    ? "symlink" :\
     (X) == DT_REG    ? "regular file" :\
     (X) == DT_SOCK   ? "socket" :\
     "unknown")

#define INOTIFY2STR(X)\
           ((X) & IN_ACCESS            ? "파일에 접근했습니다.":\
            (X) & IN_ATTRIB            ? "권한, 타임스템프, 확장 속성, 링크 카운트, 사용자/그룹ID 가 변경되었습니다.":\
            (X) & IN_CLOSE_WRITE       ? "쓰기용으로 열린 파일이 닫혔습니다.":\
            (X) & IN_CLOSE_NOWRITE     ? "쓰기용으로 열리지 않은 파일 내지 디렉터리가 닫혔습니다.":\
            (X) & IN_CREATE            ? "감시 대상 디렉터리 내에 파일/디렉터리가 생성되었습니다.":\
            (X) & IN_DELETE            ? "감시 대상 디렉터리에서 파일/디렉터리가 삭제되었습니다.":\
            (X) & IN_DELETE_SELF       ? "감시 대상 파일/디렉터리 자체가 삭제되었습니다.":\
            (X) & IN_MODIFY            ? "파일이 변경되었습니다.":\
            (X) & IN_MOVE_SELF         ? "감시 대상 파일/디렉터리 자체가 이동되었습니다.":\
            (X) & IN_MOVED_FROM        ? "파일 이름이 바뀔 때 이전 파일명을 담은 디렉터리에서 생성되었습니다.":\
            (X) & IN_MOVED_TO          ? "???":\
            (X) & IN_OPEN              ? "파일 또는 폴더가 열렸습니다.":\
            "unknown" )

/**
 * @brief 입력한 문자열을 파일에 쓰는 함수 (해당 함수는 append가 아닌 recreate 이다.)
 * 
 * @param filename 파일 이름
 * @param message 파일에 쓸 메세지
 * 
 * @return int 0: 성공, -1: 실패
 */
int yj_write_to_file(char *filename, char *message);

/**
 * @brief 파일의 문자열을 읽는 함수 (최대 1024 바이트 까지만 읽는다.)
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 실패
 */
int yj_read_to_file(char *filename);


/**
 * @brief 파일에 해당 message를 append 하는 함수
 * 
 * @param filename 파일 이름
 * @param message 쓸 메세지
 * @return int 0: 성공, -1: 실패
 */
int yj_append_to_file(char *filename, char *message);


/**
 * @brief 해당 파일의 오프셋을 출력한다.
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 싪패
 */
int yj_file_len_print(char *filename);

/**
 * @brief 하드 링크를 생성하는 함수 
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 실패
 */
int create_hardlink(const char *filename);

/**
 * @brief Create a softlink object
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 실패
 */
int create_softlink(const char *filename);

/**
 * @brief delete a link file
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 실패
 */
int delete_link(const char *filename);

/**
 * @brief print info of file
 * 
 * @param filename 파일 이름
 * @return int 0: 성공, -1: 실패
 */
int stat_file(const char *filename);

/**
 * @brief print sub-files in the directory.
 * 
 * @param filename 파일 이름 
 * @return int 0: 성공, -1: 실패
 */
int print_tree(const char *directory);

/**
 * @brief 입력 경로 감시하는 함수
 * 
 * @param directory 경로 이름 
 * @return int 0: 성공, -1: 실패
 */
int monitor_directory(const char *directory);

/**
 * @brief 여러개의 디렉토리를 모니터링하는 함수
 * 
 * @param argc 디렉터리 
 * @return int 0: 성공, -1: 실패
 */
int monitor_multi_directory(char **argc);

#else
#endif