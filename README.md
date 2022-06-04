# file-handler

## 개요

* 해당 프로젝트는 file io를 익숙하게 사용하기 위해서 만든 프로그램입니다. 
* 숙지를 위한 함수는 다음과 같습니다. 
    *  `fopen, fclose`: 파일 소켓 open, close 함수.
    * `fputs, fgets`: 파일 string 읽고 쓰기.
    * `ftell, fseek`: 파일 offset 값 다루기


## 기능

프로그램의 사용 형식은 다음과 같습니다.
<center>
`./file_handler_main [options] [variable[=value] ...]`
</center>

해당 프로그램에서 제공하는 기능은 다음과 같습니다.
* `-r [filename]`: 파일 읽기
* `-w [filename] [Message]`: 파일에 메세지 쓰기
* `-a [filename] [Message]`: 파일에 문자열 append 하기
* `-o [filename]`: 파일의 전체 offset print
* `-l [--hsd] [filename]`: 링크파일 관련 옵션
    * `--h`: 하드 링크 생성
    * `--s`: 소프트 링크 생성
    * `--d`: 링크 삭제

## 예시

```
alwns28@ubuntu1804:~/YYJ/01.LSP/01_fileHandler/source$ ./yj_file_handler -w test.txt "yyj test"
[SUCCESS] SAVE MESSAGE IN test.txt
alwns28@ubuntu1804:~/YYJ/01.LSP/01_fileHandler/source$ ./yj_file_handler -r test.txt
MESSAGE - yyj test
alwns28@ubuntu1804:~/YYJ/01.LSP/01_fileHandler/source$ ./yj_file_handler -o test.txt
OFFSET TOTAL : 8
alwns28@ubuntu1804:~/YYJ/01.LSP/01_fileHandler/source$ ./yj_file_handler -a test.txt " 2 YYJ TEST"
after fopen(), offset = 8
[SUCCESS] SAVE MESSAGE IN test.txt
before fclose(). offset=19
alwns28@ubuntu1804:~/YYJ/01.LSP/01_fileHandler/source$ ./yj_file_handler -r test.txt
MESSAGE - yyj test 2 YYJ TEST
```

## 문의

* 해당 프로그램에 대해서 피드백을 주실 분들은 아래 이메일로 메일 주시면 감사합니다. 
<center>

**alwns28@kookmin.ac.kr**

</center>