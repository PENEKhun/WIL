#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef char* element;

typedef struct ListNode { 	// 노드 타입을 구조체로 정의한다.
    element word;
    struct ListNode* link;
} ListNode;

ListNode* insert(ListNode* head, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
  //  char *word = (char*)malloc(strlen(value) * sizeof(char));
//    memset(p->word, '\0', MAX * sizeof(char));				
    p->word = value;
    p->link = head;	// 헤드 포인터의 값을 복사
    head = p;	// 헤드 포인터 변경	
    return head;
}

void deleteRecent(ListNode* head)
{
    ListNode* lastNode = head;
    while (lastNode->link->link != NULL)
        lastNode = lastNode->link;
    //  ListNode *tmp = lastNode;
    //  printf("tmp : %s\n", tmp->word);
    lastNode->link = NULL;


    free(lastNode);
}

ListNode* reverse(ListNode* head)
{
    // 순회 포인터로 p, q, r을 사용
    ListNode* p, * q, * r;

    p = head;         // p는 역순으로 만들 리스트
    q = NULL;        // q는 역순으로 만들 노드
    while (p != NULL) {
        r = q;          // r은 역순으로 된 리스트.    
            // r은 q, q는 p를 차례로 따라간다.
        q = p;
        p = p->link;
        q->link = r;      // q의 링크 방향을 바꾼다.
    }
    return q;
}


void printHisotry(ListNode* head)
{
    ListNode* reversed = reverse(head);
    for (ListNode* p = reversed; p != NULL; p = p->link)
        printf("%s->", p->word);
}


char* getLastWord_at_lastNode(ListNode* head, bool isEng) {
    // 	맨 마지막 노드에 맨 마지막 char을 가져옴
    ListNode* p = head;
    while (1) {
        if (p->link == NULL) {
            //첫번째 단어입력시 link=null임.
            //이에대한 예외사항
            if (isEng) {
                int len = strlen(p->word);
                char* lastWord = &p->word[len - 1];
                return lastWord;
            }
            else {
                int len = strlen(p->word);
                char* lastWord = &p->word[len - 2];
                return lastWord;
            }
        }

        p = p->link;
        if (p != NULL) {
            int len = strlen(p->word);
            if (isEng) {
                //영어일때
                char *lastWord = &p->word[len - 1];
                return lastWord;
            }
            else {
                //한글일때
                char* lastWord = &p->word[len - 2];
                return lastWord;
            }
        }
    }
}