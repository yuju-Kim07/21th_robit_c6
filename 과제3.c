#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int size;
}Queue;

struct _Node n; //struct _Node의 변수 n 선언
struct Queue q; //struct Stack의 변수 q 선언

void Enqueue(Queue* queue, char data); //Enqueue함수 선언
void Dequeue(Queue* queue); //Dequeue함수 선언
void size(Queue* queue); //size함수 선언
void front(Queue* queue); //front함수 선언
void rear(Queue* queue); //rear함수 선언
void isEmpty(Queue* queue); //isEmpty함수 선언
void printQueue(Queue* queue); //printQueue함수 선언

int strcmp(char* a, char* b); //두 배열 비교하는 strcmp함수 선언

int main()
{
	//입력문자열 별 역할 설명
	printf("Enqueue : Queue에 data 입력\n\n");
	printf("Dequeue : Dequeue하고 Dequeue된 값 출력. Queue가 비어있을 시 비어있다고 출력\n\n");
	printf("size : Queue 크기 출력\n\n");
	printf("front : front에 위치한 값 반환\n\n");
	printf("rear : rear에 위치한 값 반환\n\n");
	printf("isEmpty : Queue에 데이터가 없으면 true, 있으면 false 반환\n\n");
	printf("printQueue : Queue 내 모든 값 출력. Queue가 비어있을 시 비어있다고 출력\n\n\n");

	while (1) //무한반복
	{
		char queue_val[15] = { '\0', }; //입력문자열의 배열크기를 넉넉하게 15로 설정
		printf("입력(ex.Enqueue / rear): ");
		scanf("%s", &queue_val); //입력문자열 입력받기

		if (strcmp("Enqueue", queue_val)) //입력한 문자열(queue_val)이 Enqueue와 같다면
		{
			printf("Enqueue할 문자를 입력하세요. : ");
			scanf(" %c", &n.data);
			Enqueue(&q, n.data);//Enqueue함수 호출
		}

		else if (strcmp("Dequeue",queue_val))//입력한 문자열(queue_val)이 Dequeue와 같다면
		{
			Dequeue(&q);//Dequeue함수 호출
		}

		else if (strcmp("size", queue_val))//입력한 문자열(queue_val)이 size와 같다면
		{
			size(&q);//size함수 호출
		}

		else if (strcmp("front", queue_val))//입력한 문자열(queue_val)이 front와 같다면
		{
			front(&q);//front함수 호출
		}

		else if (strcmp("rear", queue_val))//입력한 문자열(queue_val)이 rear와 같다면
		{
			rear(&q);//rear함수 호출
		}

		else if (strcmp("isEmpty", queue_val))//입력한 문자열(queue_val)이 isEmpty와 같다면
		{
			isEmpty(&q);//isEmpty 호출
		}

		else if (strcmp("printQueue", queue_val))//입력한 문자열(queue_val)이 printQueue와 같다면
		{
			printQueue(&q);//printQueue함수 호출
		}

		else//문자열을 잘못 입력했다면
			printf("잘못 입력했습니다. 다시 입력하시기 바랍니다.\n"); 
	}
}

void Enqueue(Queue*queue, char data) //Enqueue함수
{
	Node* new = (Node*)malloc(sizeof(Node));//새로 넣을 숫자를 저장할 노드 주소
	new->data = data; // 새로운 노드(new)의 문자 자리에 입력한 문자 저장
	new->next = '\0';// 새로운 노드(new)의 문자 자리를 NULL로 초기화

	if (queue->size == 0)//노드가 비어있을 경우
	{
		queue->front = new;//front의 문자도 새로운 노드(new)
		queue->rear = new;//rear의 문자도 새로운 노드(new)
	}

	else //노드의 값이 2개 이상일때부터
	{
		queue->rear->next = new;//rear의 다음 노드에 새로운 노드(new) 추가
		queue->rear = new;//rear의 문자는 새로운 노드(new)
	}

	queue->size++; //사이즈 +1
}

void Dequeue(Queue* queue)//Dequeue함수
{
	if (queue->size == 0)//노드가 비어있을 경우
		printf("queue이 비어있습니다.\n");

	else//노드 값이 존재할 때
	{
		Node* still_front;//기존 front값을 저장하는 변수 선언
		still_front = queue->front; //still_front에 기존 front값을 저장
		char still_data = still_front->data;//기존 front의 값 저장하는 변수 선언(이따 Dequeue한 값 출력해야되서)
		queue->front = still_front->next;//front의 주소에 still_front의 다음 값을 저장
		queue->size--; //사이즈-1

		printf("dequeue 된 값 : %c\n", still_data);
		free(still_front);//still_front 해제
	}
}

void size(Queue* queue)//size함수
{
	if (queue->size == 0)//노드가 비어있을 경우
		printf("queue에 값이 존재하지 않습니다.\n");

	else//노드 값이 존재할 때
	printf("queue의 크기 : %d\n", queue->size);
}

void front(Queue* queue)//front함수
{
	if (queue->size == 0)//노드가 비어있을 경우
		printf("queue에 값이 존재하지 않습니다.\n");

	else//노드 값이 존재할 때
	printf("front 값 : %c\n", queue->front->data);
}

void rear(Queue* queue)//rear함수
{
	printf("rear 값 : %c\n", queue->rear->data);
}

void isEmpty(Queue* queue)//isEmpty 
{
	if (queue->size == 0)//노드가 비어있을 경우
		printf("true\n");

	else//노드 값이 존재할 때
		printf("false\n");
}

void printQueue(Queue* queue)//printQueue함수
{
	if (queue->size == 0)//노드가 비어있을 경우
		printf("queue에 값이 존재하지 않습니다.\n");

	else//노드 값이 존재할 때
	{
		Node* all = queue->front; //노드의 front값을 저장할 변수 선언

		while (all != '\0') //all이 NULL이 아니면 반복
		{
			printf("%c ", all->data); //all의 값 출력
			all = all->next; //all에 all의 다음값 대입
		}

		printf("\n");
	}
}

int strcmp(char* a, char* b) // 두 배열 비교하는 strcmp함수
{
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0')//두 배열의 원소값이 '\0'이 아닐때 반복
	{
		if (a[i] != b[i])//두 배열의 원소가 다르면
			return 0; //0반환(=거짓)
		i++;//i증가
	}
	if (a[i] == '\0' && b[i] == '\0')//두 배열의 원소가 같고, 특정 원소가 둘다 '\0'이라면
		return 1; //1반환

	return 0;//특정 원소가 둘다 '\0'인것은 아니라면 0반환
}