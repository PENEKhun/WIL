#include <stdio.h>
#include <stdlib.h>

// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType *q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
			int i = q->front;
			do {
				i = (i + 1) % (MAX_QUEUE_SIZE);
				printf("%d | ", q->data[i]);
				if (i == q->rear)
					break;
			} while (i != q->front);
		}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}


int main(void)
{
	QueueType queue;
	QueueType queue2;
	QueueType queue3;
	QueueType queue4;
	int element;

	init_queue(&queue);
	init_queue(&queue2);
	init_queue(&queue3);


	printf("1. 문자 A,B,C,D,E를 큐에 넣었다가 다시 꺼내어 출력한 결과는?\n");
	enqueue(&queue, 'A');
	enqueue(&queue, 'B');
	enqueue(&queue, 'C');
	enqueue(&queue, 'D');
	enqueue(&queue, 'E');

    while (!is_empty(&queue)){
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	printf("\n\n");

/*
	printf("2. 원형큐에서 front가 3이고 rear5라고 하면 현재 원형큐에 저장된 요소들의 개수는?");
    while(1){
	    enqueue(&queue2, 1);
        if ((queue2.front==3) && (queue2.rear==5)) break;
    }
    queue_print(&queue2);
    */


	printf("3. 10,20,30,40,50을 넣고 3개 빼면\n");
	enqueue(&queue3, 10);
	enqueue(&queue3, 20);
	enqueue(&queue3, 30);
	enqueue(&queue3, 40);
	enqueue(&queue3, 50);
    dequeue(&queue3);
    dequeue(&queue3);
    dequeue(&queue3);
    queue_print(&queue3);


	printf("\n\n");
    
	printf("4. 크기10, front3,rear가5 일때 하나 넣으면 front rear값은 ?\n");
	enqueue(&queue4, 1);
    dequeue(&queue4);
	enqueue(&queue4, 1);
    dequeue(&queue4);
	enqueue(&queue4, 1);
    dequeue(&queue4);
	enqueue(&queue4, 1);
	enqueue(&queue4, 1); queue_print(&queue4);
    printf("현재 front3, rear 5인 상태.\n");
	enqueue(&queue4, 1);
    printf("추가 후 큐의 상태\n");
    queue_print(&queue4);
    
	printf("\n\n");

    


    



/*
	while (!is_full(&queue))
	{
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
	}
	printf("큐는 포화상태입니다.\n\n");
    */

	return 0;
}


/*
2. 2
3. 

4. 원형 큐에서 공백상태  front와 rear와 같을때
	return (q->front == q->rear);

5. 

*/