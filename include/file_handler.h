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

#else
#endif