#include <stdio.h>
#include <stdlib.h>		//exit 사용
#include <string.h>		//strcmp 함수 사용
#include <stdbool.h>	//부울함수 사용

#define MAX_STACK 10000

typedef int Data;

typedef struct {
	int top;
	int stack[MAX_STACK];
}Stack;

void InitStack(Stack* pstack) {	//스택 초기화
	pstack->top = -1;
}

bool IsFull(Stack* pstack) {	//스택 full
	return pstack->top == MAX_STACK - 1;
}

bool IsEmpty(Stack* pstack) {	//스택 empty
	return pstack->top == -1;
}

void Push(Stack* pstack, int item) {	//스택 push
	if(IsFull(pstack))
		exit(1);
	pstack->stack[++(pstack->top)] = item;
}

int Pop(Stack* pstack) {	//스택 pop
	if (IsEmpty(pstack))
		return -1;
	else
		--(pstack->top);
}

int Peek(Stack* pstack) {	//스택의 top값 추출
	if (IsEmpty(pstack))
		return -1;
	else
		return pstack->stack[pstack->top];
}

int Size(Stack* pstack) {	//스택의 사이즈
	return pstack->top + 1;
}

int main() {
	Stack stack;
	InitStack(&stack);
	char command[6];	//문자열 끝은 NULL
	int n, push;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", command);
		if (!strcmp("push", command)) {	//문자열 비교 strcmp가 핵심 !
			scanf("%d", &push);
			Push(&stack, push);
		}
		else if (!strcmp("pop", command)) {
			
			printf("%d\n", Peek(&stack));
			Pop(&stack);
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", Size(&stack));
		}
		else if (!strcmp(command, "empty")) {
			printf("%d\n", IsEmpty(&stack));
		}
		else if (!strcmp(command, "top")) {
			printf("%d\n", Peek(&stack));
		}
	}
}

문자열 비교 strcmp함수를 처음 사용했다.
원랜 command == "push" 이렇게 비교 했었는데 오류가 나서 구글링 하던 도중 strcmp함수를 찾아냈다.
헤더파일은 string.h
매개변수로 들어온 2개의 문자열을 비교하는 함수
정의  : int strcmp(문자열 1, 문자열 2)
문자열1 < 문자열2 인 경우에는 음수 반환
문자열1 > 문자열2 인 경우에는 양수 반환
문자열1 == 문자열2 인 경우에는 0을 반환

문제풀이할 때는 문자열이 같아야 하므로 !을 사용해서 0을 1로 바꿔줬다.
scanf를 사용할 때 띄어쓰기 해서 입력을 해도 command와 push변수에 값이 따로따로 들어갔다.

그리고 항상 스택을 구현하기 전에 Init를 생각하자.
