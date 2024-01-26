#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 128
#define EXIT_SUCCESS 1
#define EXIT_FAILURE -1

struct _StackMember;
typedef struct _StackMember
{
	int number;
	struct _StackMember* next;
}StackMember;

int pop(StackMember** head,int* result);
int push(StackMember** head,int number);

int main() {
	StackMember* head=NULL;
	int result;
	int i=0;
	int operand;
	char buffer[MAX_VALUE];
	FILE* fp = fopen("program.txt", "r");
	if (!fp) {
		printf("krivo otvoren file");
	}
	fgets(buffer, MAX_VALUE, fp);
	printf("%s\n", buffer);
	result = buffer[0]-'0';
	i++;
	while (buffer[i] != '\0') {
		if (buffer[i] >= '0' && buffer[i] <= '9') {
			push(&head, (int)(buffer[i] - '0'));
		}
		else if (buffer[i] == ' ') {
			i++;
			continue;
		}
		else {
			pop(&head, &operand);
			switch (buffer[i])
			{
			case '+':
				result += operand;
				break;
			case '-':
				result -= operand;
				break;
			case '*':
				result *= operand;
				break;
			case '/':
				result /= operand;
				break;
			default:
				break;
			}
		}
		i++;
	}
	printf("Rezultat je %d", result);
}


int pop(StackMember** head,int* result) {
	StackMember* toDelete;
	toDelete = *head;
	if(!toDelete){
		printf("Stog je prazan");
		return EXIT_FAILURE;
	}

	*result = toDelete->number;
	*head = toDelete->next;
	free(toDelete);

	return EXIT_SUCCESS;
}
int push(StackMember** head, int number) {
	StackMember* new = (StackMember*)malloc(sizeof(StackMember));
	new->number = number;
	new->next = *head;
	*head = new;
	return EXIT_SUCCESS;
}