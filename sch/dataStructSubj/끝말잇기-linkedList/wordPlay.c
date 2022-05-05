//정보보호학과 20194581 문성훈
//Linked List를 이용한 끝말잇기 프로그램
//특징 : 영어와 한글을 동시에 지원함

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "linkedList.h"

//선언부
bool isKor(char* word);


//
int main(void) {
    ListNode* head = NULL;
    head = (ListNode*)malloc(sizeof(ListNode));

    bool isEng = false;

    while (true) {

        char *tmpWord = malloc(sizeof(char) * MAX);
        element inputWord;

        printf("시작 단어: ");
        scanf("%s", tmpWord);

        inputWord = (char*)malloc(strlen(tmpWord) * sizeof(char));
        strcpy(inputWord, tmpWord);
        head->word = inputWord;

        head->link = NULL;
        isEng = !isKor(head->word);
        break;
    }

    printf("==============\n");
    printf("끝말잇기 시작!!\n");
    printf("종료하려면 \"!종료\"를 입력해주세요.\n");
    printf("==============\n");
    printf("단어: ");

    while (true) {

        char *tmpWord = malloc(sizeof(char) * MAX);;
        element inputWord;
        scanf("%s", tmpWord);

        if (strcmp(tmpWord, "!종료") == 0) {
            printf("종료합니다.");
            break;
        }

        if (tmpWord == '\0') {
            printf("[오류] 단어를 다시 입력해주세요.\n");
            continue;
        }

        if (isEng && isKor(tmpWord)) {
            printf("[오류] 영어로 입력 해 주세요.\n");
            continue;
        }
        else if (!isEng && !isKor(tmpWord)) {
            printf("[오류] 한글로 입력 해 주세요.\n");
            continue;
        }

        inputWord = (char*)malloc(strlen(tmpWord) * sizeof(char));
        strcpy(inputWord, tmpWord);

        char* firstWord;


        if (isEng) {
            //영어일때 첫글자 가져오기
            char *tmp = tmpWord[0];
            firstWord = &tmp;
        }
        else {
            //한글일때 첫글자 가져오기
            char tmp[3] = { tmpWord[0], tmpWord[1], '\0' };
            firstWord = tmp;
        }

        char* lastWord = getLastWord_at_lastNode(head, isEng);

        int cmp = strcmp(firstWord, lastWord);
        if (cmp != 0) {
            printf("[오류] %s로 시작하는 단어를 입력 해 주세요.\n", lastWord);
            continue;
        }
        else if (cmp == 0) {
            //correct!
            head = insert(head, inputWord);
            printHisotry(head);
        }

    }
    free(&head);
}


bool isKor(char* word) {
    return (word[0] & 0x80);
}