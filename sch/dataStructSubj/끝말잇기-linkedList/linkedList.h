#pragma once
#define MAX 100

typedef char* element;

typedef struct ListNode { 	// 노드 타입을 구조체로 정의한다.
    element word;
    struct ListNode* link;
} ListNode;

ListNode* insert(ListNode* head, element value);

void deleteRecent(ListNode* head);

ListNode* reverse(ListNode* head);

void printHisotry(ListNode* head);

char* getLastWord_at_lastNode(ListNode* head, bool isEng);

void get_last_node(ListNode* head);



