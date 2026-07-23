#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node* next;
}Node;

typedef struct Stack {
	Node* top;
	int size;
}Stack;

typedef struct Queue {
	Node* front;
	Node* rear;
	int size;
}Queue;

struct _Node n; //struct _Node의 변수 n 선언
struct Stack s; //struct Stack의 변수 s 선언
struct Queue q; //struct Stack의 변수 q 선언

void push(Stack* stack, int data); //push함수 선언
int pop(Stack* stack); //pop함수 선언
void Enqueue(Queue* queue, char data); //Enqueue함수 선언
int Dequeue(Queue* queue); //Dequeue함수 선언

int main()
{
	
	char Pal[31] = { '\0', }; //회문 여부를 판단하고자 하는 입력된 문자열 저장할 배열을 선언 및 NULL로 초기화
	printf("회문 여부를 판단할 문자열을 입력하세요(공백 포함 최대 30글자) : ");
	scanf("%[^\n]", &Pal);

	for (int i = 0; Pal[i] != '\0'; i++) //i=0부터 입력받은 문자열이 '\0'이 아닐때까지 반복
	{
		if (Pal[i] != ' ')//배열의 원소가 공백이 아니라면
		{
			push(&s, Pal[i]); //push 함수 호출. push는 Stack 구조체와 관련있으므로, 함수s를 인자로, 공백이 아닌 배열의 해당 원소를 인자로 삼음
			Enqueue(&q, Pal[i]);//Enqueue 함수 호출. Enqueue는 Queue 구조체와 관련있으므로, 함수q를 인자로, 공백이 아닌 배열의 해당 원소를 인자로 삼음
		}
	}

	int is_Pal = 1; //회문 판단값 저장 변수 선언 빛 1(회문이 맞음)으로 초기화

	while (s.size > 0)//stack의 사이즈가 0이 아닐때(원소가 남아있을때)까지. (stack과 Queue의 값의 갯수는 같으므로 stack의 사이즈만 고려)
	{
		char pop_ = pop(&s); //pop의 값들 저장할 배열 선언
		char Dequeue_ = Dequeue(&q); //Dequeue의 값들 저장할 배열 선언

		if (pop_ != Dequeue_) //pop의 배열순서와 Dequeue의 배열순서가 같지 않다면
							//pop과 Dequeue는 각각 값이 나가면 삭제되기때문에, 계속해서 배열들을 비교가능
		{
			is_Pal = 0; //0으로.(회문이 아님)
			break;//뒤에건 비교해볼 필요도 없기 때문에 종료
		}
	}
	if (is_Pal == 1) //회문이 맞다면
		printf("회문입니다. ");

	else//회문이 아니라면
		printf("회문이 아닙니다.");

	return 0;
	
}

void push(Stack* stack, char data) //push함수
{
	Node* new = (Node*)malloc(sizeof(Node)); //새로 넣을 숫자를 저장할 노드 주소
	new->data = data;//새로운 노드(new)의 숫자 자리에 입력한 숫자 저장
	new->next = stack->top; //새로운 노드(new)의 다음 자리에 기존 top값을 저장
	stack->top = new; //stack의 top에 숫자가 들어간 새로운 노드(new) 저장
	stack->size++; //stack의 사이즈가 +1이 됨
}

int pop(Stack* stack) //pop함수 
{
		Node* still_top; //노드의 기존 top 자리(still_top)에 대한 임의의 변수 주소
		still_top = stack->top; //기존 top자리(still_top)에 stack 함수의 top자리 주소 저장
		int still_data = still_top->data;//기존 top 자리(still_top)에 놓인 숫자에 대한 변수를 선언(이따 pop한 값 출력할 때 쓰기 위해 임시 저장)
		stack->top = still_top->next; //top 자리에 기존 top 다음 자리가 저장
		stack->size--;//stack의 사이즈가 -1이 됨

		free(still_top); //기존 top 자리 해제
	
		return still_data;
}

void Enqueue(Queue* queue, char data) //Enqueue함수
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

int Dequeue(Queue* queue)//Dequeue함수
{	
		Node* still_front;//기존 front값을 저장하는 변수 선언
		still_front = queue->front; //still_front에 기존 front값을 저장
		char still_data = still_front->data;//기존 front의 값 저장하는 변수 선언(이따 Dequeue한 값 출력해야되서)
		queue->front = still_front->next;//front의 주소에 still_front의 다음 값을 저장
		queue->size--; //사이즈-1

		free(still_front);//still_front 해제

		return still_data;
}
