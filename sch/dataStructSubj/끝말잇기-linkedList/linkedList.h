#pragma once
#define MAX 100

typedef char* element;

typedef struct ListNode { 	// ��� Ÿ���� ����ü�� �����Ѵ�.
    element word;
    struct ListNode* link;
} ListNode;

ListNode* insert(ListNode* head, element value);

void deleteRecent(ListNode* head);

ListNode* reverse(ListNode* head);

void printHisotry(ListNode* head);

char* getLastWord_at_lastNode(ListNode* head, bool isEng);

void get_last_node(ListNode* head);



