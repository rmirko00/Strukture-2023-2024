#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ID_LEN 16
#define MAX_NAME_LEN 32

typedef struct _member {
	char name[MAX_NAME_LEN];
	char surname[MAX_NAME_LEN];
	int id;
	int readbooks;
	struct _member* next;
}Member;

typedef struct _book {
	char name[MAX_NAME_LEN];
	int memberid;
	struct _book* next;

}Book;

int main() {
	Member *head = NULL;
	Member *current = NULL;
	Member *prev = NULL;
	int id;
	char surname[MAX_NAME_LEN];
	char name[MAX_NAME_LEN];
	FILE* fp;
	fp = fopen("clanovi.txt", "r");
	if (!fp) {
		printf("greska u otvaranju datoteke");
	}
	while (fscanf(fp,"%d %s %s", &id, surname, name) == 3)
	{
		Member* new = (Member*)malloc(sizeof(Member));
		new->id = id;
		strcpy(new->name, name);
		strcpy(new->surname, surname);
		new->next = NULL;
		new->readbooks = 0;
		if (head == NULL)
		{
			head = new;
			current = head;
			continue;
		}
		current = head;
		prev = NULL;
		while (current != NULL)
		{
				if (strcmp(new->surname, current->surname) > 0)
				{
					if (current->next == NULL)
					{
						current->next = new;
						break;
					}
					else
					{
						prev = current;
						current = current->next;
					}
				}
				if (strcmp(new->surname, current->surname) < 0)
				{
					if (prev == NULL)
					{
						new->next = head;
						head = new;
						break;
					}
					else
					{
						prev->next = new;
						new->next = current;
						break;
					}
				}
				if (strcmp(new->surname, current->surname) == 0)
				{
					if (strcmp(new->name, current->name) > 0)
					{
						if (current->next == NULL)
						{
							current->next = new;
							break;
						}
						else
						{
							prev = current;
							current = current->next;
						}
					}
					if (strcmp(new->name, current->name) < 0)
					{
						if (prev == NULL)
						{
							new->next = head;
							head = new;
							break;
						}
						else
						{
							prev->next = new;
							new->next = current;
							break;
						}
					}
					if (strcmp(new->name, current->name) == 0)
					{
						if (current->next == NULL)
						{
							current->next = new;
							break;
						}
						else
						{
							prev = current;
							current = current->next;
						}
					}
				}
			
		}
	}
	current = head;
	while (current != NULL) {
		printf("%s %s\n",current->name,current->surname);
		current = current->next;
	}
	printf("\n\n\n");
	Book *head2;
	Book *current2;
	Book *prev2;
	FILE* fp2;
	char bookname[MAX_NAME_LEN];
	int memberid;
	printf("unesite ime clana za kojeg zelite vidit koliko je knjiga procitao");
	fp2 = fopen("knjige.txt", "r");
	
	while (fscanf(fp2, "%d %s", &memberid, bookname) == 2) {
		Book* new = (Book*)malloc(sizeof(Book));
		strcpy(new->name, bookname);
		new->memberid;
		current = head;
		while(current!=NULL){
			if (new->memberid == current->id) {
				current->readbooks++;
			}
			current = current->next;
		}
	}
	int max = 0;
	while (current != NULL) {
		if (current->readbooks > max) {
			max = current->readbooks;

		}
		current = current->next;
	}


	return 0;
}