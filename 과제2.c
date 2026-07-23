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

struct _Node n; //struct _Node의 변수 n 선언
struct Stack s; //struct Stack의 변수 s 선언

void push(Stack* stack, int data); //push함수 선언
void pop(Stack* stack); //pop함수 선언
void size(Stack* stack); //size함수 선언
void top(Stack* stack); //top함수 선언
void isEmpty(Stack* stack); //isEmpty함수 선언
void printStack(Stack* stack); //printStack함수 선언

int strcmp(char* a, char* b); //두 배열 비교하는 strcmp함수 선언

int main()
{
	//입력문자열 별 역할 설명
	printf("push : 정수 push\n\n");
	printf("pop : pop하고 pop된 값 출력. stack이 비어있을 시 비어있다고 출력\n\n");
	printf("size : stack 크기 출력\n\n");
	printf("top : top에 위치한 값 반환\n\n");
	printf("isEmpty : stack에 데이터가 없으면 true, 있으면 false 반환\n\n");
	printf("printStack : stack 내 모든 값 출력. stack이 비어있을 시 비어있다고 출력\n\n\n");

	while (1) //무한반복
	{
		char stack_val[15] = { '\0', }; //입력문자열의 배열크기를 넉넉히 15로 정함
		printf("입력(ex. push / top): ");
		scanf("%s", stack_val); //입력문자열 입력받기


		if (strcmp("push", stack_val)) //입력한 문자열(stack_val)이 push와 같다면
		{
			printf("push할 정수를 입력하세요. : "); //push할 정수 입력받기
			scanf("%d", &n.data);
			push(&s, n.data); //push 함수 호출
		}
		else if (strcmp("pop", stack_val)) //입력한 문자열(stack_val)이 pop과 같다면
			pop(&s);//pop함수 호출

		else if (strcmp("size", stack_val)) //입력한 문자열(stack_val)이 size와 같다면
			size(&s);//size함수 호출

		else if (strcmp("top", stack_val)) //입력한 문자열(stack_val)이 top과 같다면
			top(&s);//top함수 호출

		else if (strcmp("isEmpty", stack_val)) //입력한 문자열(stack_val)이 isEmpty와 같다면
			isEmpty(&s);//isEmpty함수 호출

		else if (strcmp("printStack", stack_val)) //입력한 문자열(stack_val)이 printStack과 같다면
			printStack(&s);//printStack함수 호출

		else
			printf("잘못 입력했습니다. 다시 입력하시기 바랍니다.\n");


	}
}

void push(Stack* stack, int data) //push함수
{
	Node* new = (Node*)malloc(sizeof(Node)); //새로 넣을 숫자를 저장할 노드 주소
	new->data = data;//새로운 노드(new)의 숫자 자리에 입력한 숫자 저장
	new->next = stack->top; //새로운 노드(new)의 다음 자리에 기존 top값을 저장
	stack->top = new; //stack의 top에 숫자가 들어간 새로운 노드(new) 저장
	stack->size++; //stack의 사이즈가 +1이 됨
}

void pop(Stack* stack) //pop함수 
{
	if (s.size == 0)//노드가 비어있을 경우
	{
		printf("stack이 비어있습니다.");
	}

	else
	{
		Node* still_top; //노드의 기존 top 자리(still_top)에 대한 임의의 변수 주소
		still_top = stack->top; //기존 top자리(still_top)에 stack 함수의 top자리 주소 저장
		int still_data = still_top->data;//기존 top 자리(still_top)에 놓인 숫자에 대한 변수를 선언(이따 pop한 값 출력할 때 쓰기 위해 임시 저장)
		stack->top = still_top->next; //top 자리에 기존 top 다음 자리가 저장
		stack->size--;//stack의 사이즈가 -1이 됨

		printf("pop 된 값 : %d\n", still_data);
		free(still_top); //기존 top 자리 해제
	}
}

void size(Stack* stack) //size함수 
{
	printf("stack의 크기 : %d\n", stack->size);
}

void top(Stack* stack) //top함수 
{
	if (stack->size == 0) //stack의 사이즈가 0이라면(=stack에 숫자가 없음)
		printf("stack에 값이 없습니다.\n");
	else//stack에 숫자가 존재한다면
		printf("top에 위치한 값 : %d\n", stack->top->data);//top의 숫자 출력
}

void isEmpty(Stack* stack) //isEmpty함수 
{
	if (stack->size == 0) //stack의 사이즈가 0이라면(=stack에 숫자가 없음)
		printf("true\n");
	else//stack에 숫자가 존재한다면
		printf("false\n");
}

void printStack(Stack* stack) //printStack함수 
{
	if (stack->size == 0) //stack의 사이즈가 0이라면(=stack에 숫자가 없음)
		printf("stack이 비어있습니다.\n");

	else//stack에 숫자가 존재한다면
	{
		Node* all = stack->top;//top위치(=stack에 저장된 숫자를 꺼내는 횟수)를 저장할 변수 all 선언

		while (all != '\0')//top의 위치가 0이 아니라면(=stack에 값이 있다면)
		{
			printf("%d ", all->data);//all에 저장된 top위치의 숫자 출력
			all = all->next; //다음위치의 숫자 출력
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