#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef char* element;

typedef struct ListNode { 	// ��� Ÿ���� ����ü�� �����Ѵ�.
    element word;
    struct ListNode* link;
} ListNode;

ListNode* insert(ListNode* head, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
  //  char *word = (char*)malloc(strlen(value) * sizeof(char));
//    memset(p->word, '\0', MAX * sizeof(char));				
    p->word = value;
    p->link = head;	// ��� �������� ���� ����
    head = p;	// ��� ������ ����	
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
    // ��ȸ �����ͷ� p, q, r�� ���
    ListNode* p, * q, * r;

    p = head;         // p�� �������� ���� ����Ʈ
    q = NULL;        // q�� �������� ���� ���
    while (p != NULL) {
        r = q;          // r�� �������� �� ����Ʈ.    
            // r�� q, q�� p�� ���ʷ� ���󰣴�.
        q = p;
        p = p->link;
        q->link = r;      // q�� ��ũ ������ �ٲ۴�.
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
    // 	�� ������ ��忡 �� ������ char�� ������
    ListNode* p = head;
    while (1) {
        if (p->link == NULL) {
            //ù��° �ܾ��Է½� link=null��.
            //�̿����� ���ܻ���
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
                //�����϶�
                char *lastWord = &p->word[len - 1];
                return lastWord;
            }
            else {
                //�ѱ��϶�
                char* lastWord = &p->word[len - 2];
                return lastWord;
            }
        }
    }
}