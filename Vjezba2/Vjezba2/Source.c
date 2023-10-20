﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50

typedef struct _osoba{
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int year;
	struct _osoba* next;
}osoba;

osoba* AddAtBeggining(osoba* people);
void PrintList(osoba* people);
osoba* AddAtEnd(osoba* people);
void SearchBySurname(osoba* people);
void Delete(osoba* people);

int main() {
	osoba* people=NULL;
	char znak=NULL;
	printf("Unesi A za(dodati novi element na pocetak liste)\n"
		   "Unesi B za(ispis liste)\n"
		   "Unesi C za(dinamicki dodati novi element na kraj liste)\n"
		   "Unesi D za(trazenje element u listi (po prezimenu))\n"
		   "Unesi E za(brisanje odredenog elementa iz liste)\n"
		   "Unesi F za kraj\n");
	
	scanf("%c", &znak);

	while (znak!='F' && znak!='f') {
		switch (znak) {
			case 'A':
			case 'a':
				people=AddAtBeggining(people);
				break;
			case 'B':
			case 'b':
				PrintList(people);
				break;
			case 'C':
			case 'c':
				people=AddAtEnd(people);
				break;
			case 'D':
			case 'd':
				SearchBySurname(people);
				break;
			case 'E':
			case 'e':
				Delete(people);
				break;

			default:
				break;

		}
		printf("Unesi A za(dodati novi element na pocetak liste)\n"
			"Unesi B za(ispis liste)\n"
			"Unesi C za(dinamicki dodati novi element na kraj liste)\n"
			"Unesi D za(trazenje element u listi (po prezimenu))\n"
			"Unesi E za(brisanje odredenog elementa iz liste)\n"
			"Unesi F za kraj\n");

			scanf(" %c", &znak);
	}
	
	return 0;
}
osoba* AddAtBeggining(osoba* people) {
	osoba *new=(osoba*)malloc(sizeof(osoba));
	printf("Unesite Ime osobe\n");
	scanf("%s", new->name);
	printf("Unesite Prezime osobe\n");
	scanf("%s", new->surname);
	printf("Unesite Godiste osobe\n");
	scanf("%d", &new->year);
	new->next = NULL;
	if (people == NULL) {
		return new;
	}
	else {
	
		new->next =people;
		return new;
	}
	
}
void PrintList(osoba* people) {
	printf("\n\n");
	int indeks=0;
	while(people!=NULL){
		printf("%d.%s %s %d\n",indeks,people->name, people->surname, people->year);
		people = people->next;
		indeks++;
	}
	printf("\n\n");
}


osoba* AddAtEnd(osoba* people) {

	osoba* new = (osoba*)malloc(sizeof(osoba));
	osoba* current = people;
	printf("Unesite Ime osobe\n");
	scanf("%s", new->name);
	printf("Unesite Prezime osobe\n");
	scanf("%s", new->surname);
	printf("Unesite Godiste osobe\n");
	scanf("%d", &new->year);
	new->next = NULL;
	if (people == NULL) {
		return new;
	}

	while (current->next != NULL) {
		current = current->next;

	}
	current->next = new;

	return people;
}

void SearchBySurname(osoba* people) {
	if (people == NULL) {
		printf("Lista je prazna");
			return;
	}

	char prezime[MAX_SIZE];
	printf("Unesite prezime koje trazimo\n");
	scanf("%s", prezime);

		
	while (people!= NULL) {
		if (!strcmp(people->surname,prezime)) {
			printf("%s %s %d\n", people->name, people->surname, people->year);

		}

		
		people = people->next;
	}
}

void Delete(osoba* people) {
	osoba* previous;
	int indeks=0;
	int brojac = 0;
	printf("Unesite redni broj clana kojeg zelite izbrisat\n");
	scanf("%d",&indeks);
	previous = people;

	while (people != NULL) {
		if (brojac == indeks) {
			previous->next = people->next;
			free(people);
			return;
		}
		previous = people;
		people = people->next;
		brojac++;
	}
	printf("Dali ste nepostojeci indeks\n");
}