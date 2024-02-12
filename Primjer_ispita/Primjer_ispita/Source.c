#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_NAME_LEN 32

typedef struct _student
{
	char name[MAX_NAME_LEN];
	char surname[MAX_NAME_LEN];
	int id;
	int grade;
	struct _student *next;
}Student;

int main() {
	Student* head = NULL;
	Student *prev=NULL;
	Student* prev2 = NULL;
	Student* current = NULL;
	Student* head2 = NULL;
	Student* current2 = NULL;
	FILE* fp;
	char name[MAX_NAME_LEN];
	char surname[MAX_NAME_LEN];
	int id=0;
	int counter = 0;
	FILE* fp2;
	int grade;


	fp = fopen("studenti.txt", "r");
	while (fscanf(fp, "%s %s %d", surname, name, &id) == 3) {
		Student* new = (Student*)malloc(sizeof(Student));
		new->grade = 1;
		strcpy(new->name, name);
		strcpy(new->surname, surname);
		new->next = NULL;
		new->id = id;
		if (head == NULL) {
			head = new;
			prev = new;
			continue;
		}
		current = head;
		prev = NULL;

		while (current != NULL) {
			if (strcmp(new->surname, current->surname) < 0) {
				if (prev == NULL) {
					new->next = current;
					head = new;
				}
				else {
					new->next = current;
					prev->next = new;
				}
				break;
			}
			else if (strcmp(new->surname, current->surname) > 0) {
				if (current->next == NULL) {
					current->next = new;
					break;
				}
				prev = current;
				current = current->next;
			}
			else if (strcmp(new->surname, current->surname) == 0) {
				if (strcmp(new->name, current->name) < 0) {
					new->next = current;
					prev->next = new;
					break;
				}
				else if (strcmp(new->name, current->name) > 0) {
					prev = current;
					current = current->next;
				}
				else if (strcmp(new->name, current->name) == 0) {
					new->next = current;
					prev->next = new;
					break;
				}
			}
			
		}


	}
	fp2 = fopen("predmet1.txt", "r");
	fscanf(fp2, "%s", name);
	while(fscanf(fp2,"%d %d",&id,&grade)==2){
		current = head;
		while(current!=NULL){
			if (current->id == id) {
				current->grade = grade;
				break;
			}
			current = current->next;
		}
	}
	
		
		
	current = head;
	while (current != NULL) {
		printf("%s %s %d %d\n", current->name, current->surname, current->id,current->grade);
		current = current->next;
		counter++;
	}
	printf("%d\n", counter);

	current = head;
	prev = NULL;
	/*printf("Unesite ime studenta kojeg zelite eliminirati");
	scanf("%s", name);
	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			printf("izbrisan je %s %s", current->name, current->surname);
			if (prev == NULL) {
				head = current->next;
				free(current);
				current = head;
			}
			else {
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
			continue;
		}
		prev = current;
		current = current->next;
	}*/
	current = head;
	prev = NULL;
	head2 = NULL;
	current2 = NULL;
	while (current != NULL) {
		if (current->grade > 1) {
			if (head2 == NULL) {
				if (prev == NULL) {
					head = head->next;
				}
				else {
					prev->next = current->next;
				}
				current2 = current;
				head2 = current2;
				current = current->next;
				current2->next = NULL;
			}
			else {
				prev->next = current->next;
				current2->next = current;
				current2 = current;
				current2->next = NULL;
				current = prev->next;
			}


		}
		else {
			prev = current;
			current = current->next;
		}

	}
	current2 = head2;
	while (current2 != NULL) {
		printf("%s %s %d\n", current2->name, current2->surname, current2->grade);
		current2 = current2->next;
	}
	printf("\n\n\n");
	current = head;
	while (current != NULL) {
		printf("%s %s %d\n", current->name, current->surname, current->grade);
		current = current->next;
	}
	
	return 0;
}