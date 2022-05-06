// 정보보호학과 20194581
// 이중연결 리스트 실습

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
} DListNode;

// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode *before, element data)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	strcpy(&newnode->data, &data);
    //newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// 노드 removed를 삭제한다.
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}


// 이중 연결 리스트를 초기화
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 역순으로 출력
void print_dlist_rev(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf(" %d ", p->data);
	}
	printf("\n");
}


// 이중 연결 리스트 테스트 프로그램
int main(void)
{
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);

	int input = 0;
	printf("데이터의 개수를 입력하시오 : ");
	scanf("%d", &input);

	for (int i = 1; i < input+1; i++) {
		int data = 0;
		printf("노드 #%d의 데이터를 입력하시오: ", i);
	
		scanf("%d", &data);
		// 헤드 노드의 오른쪽에 삽입
		dinsert(head, data);
	}

	printf("데이터를 역순으로 출력:");
	print_dlist_rev(head);

	free(head);
	return 0;
}