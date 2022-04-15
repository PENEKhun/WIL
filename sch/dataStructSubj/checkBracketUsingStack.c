#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stack.c"


void bracket_matching(char * in ) {
  StackType s, count;
  char ch;
  int i, n = strlen( in );

  int openCnt = 0;
  int tmpOpenCnt = 0;
  int tmpCloseCnt = 0;

  printf("%s\n", in);

    if(n > MAX_STACK_SIZE){
      printf("[Err] 확인할 문자열의 길이가 너무 깁니다.\n");
      return;
  }

  init(&count); //스택 초기화
  for (i = 0; i < n; i++) {
    ch = in[i];
    switch (ch) {
        case '(':
            push(&count, ++openCnt);
            printf("%d", openCnt);
        break;

        case ')':
            if(is_empty(&count)){
                printf("\n");
                printf("[Err]괄호 닫기 에러\n");
                printf("매칭된 (가 없습니다.");
                return;
            }
            
            printf("%d", pop(&count));
        break;

        default:
            printf("\n");
            printf("[Err]허용되지 않은 구분자 발견");
            return;
    }
  }
    printf("\n");
}



int main(void){
    //((((() -> 123455
    //((())(())) -> 1233245541

    //testCase
    bracket_matching("((())(()))");
    bracket_matching("((((()");

    return 0;
}
 