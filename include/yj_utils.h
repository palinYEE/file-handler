/**
 * @file yj_utils.h
 * @author YYJ (alwns28@kookmin.ac.kr)
 * @brief 유틸리티 모음
 * @version 0.1
 * @date 2022-05-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef YJ_UTILS_H
#define YJ_UTILS_H

/**
 * @brief 도움말 출력 함수
 * 
 */
void help(void);

/**
 * @brief int 형 배열에서 최대값 찾는 함수
 * 
 * @param arr int 형 배열
 * @param arr_num 배열 내에 있는 변수 개수 
 * @return int 최대값 출력
 */
int yj_find_max(int *arr, int arr_num);

#else
#endif