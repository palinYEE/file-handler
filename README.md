# file-handler

## 개요

* 해당 프로젝트는 file io를 익숙하게 사용하기 위해서 만든 프로그램입니다. 

```
================================================
                 YYJ_FILE_HANDLER

 * @author YYJ (alwns28@kookmin.ac.kr)
 * @version 0.1
 * @date 2022-05-29
 * @copyright Copyright (c) 2022
 * @current OS : LINUX
================================================
Usage: ./file_handler_main [options] [variable[=value] ...]

Options:
    -r [filename]: read file
    -w [filename] [Message]: write message in file
    -a [filename] [Message]: append message in file
    -o [filename]: print total offset
    -l  [--hsd] [filename]
        --h: create hard link
        --s: create soft link
        --d: delete link
    -p [filename]: print file summary
    -t [directory]: print sub-files in the directory.
    -s [directory]: monitor directory
    -m [directory1] [directory2] ...: monitor multi directory
```


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
* `-p [filename]`: 파일 정보 출력 (stat)
* `-t [directory]`: 입력 디렉토리에 있는 모든 파일 및 디렉토리 출력
* `-s [directory]: monitor directory`
* `-m [directory1] [directory2] ...: monitor multi directory`

## TODO

* inotify 에서 unknown 나오는 현상 수정 

## 문의

* 해당 프로그램에 대해서 피드백을 주실 분들은 아래 이메일로 메일 주시면 감사합니다. 
* 코드 리뷰 또한 환영합니다.
<center>

**alwns28@kookmin.ac.kr**

</center>
