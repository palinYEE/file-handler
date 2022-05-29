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
`./yj_file_handler [option] filename message`
</center>

해당 프로그램에서 제공하는 기능은 다음과 같습니다.
* `-r`: 파일 읽기
* `-w`: 파일에 메세지 쓰기
* `-a`: 파일에 문자열 append 하기
* `-o`: 파일의 전체 offset print

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