#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
#define MAX_LINE 1024
typedef struct _student {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	double points;
} Student;
int main() {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	double points;
	int i;
	int noRows = 0;
	FILE* filePointer = NULL;
	char buffer[MAX_LINE] = { 0 };
	Student* studenti = NULL;
	if (filePointer = fopen("students.txt", "r")) {
		printf("Uspjesno otvoren file");
	}
	if (!filePointer) {
		printf("File is not open!\n");
		return -1; 
	}
	while (!feof(filePointer)) {
		fgets(buffer, MAX_LINE, filePointer);
		noRows++;
	}
	printf("%d\n", noRows);

	studenti=(Student*)malloc((sizeof(Student) * noRows));

	rewind(filePointer);

	for (i = 0; i < noRows; i++) {
		fscanf(filePointer, "%s %s %d",studenti[i].name, studenti[i].surname,&studenti[i].points);
		printf("%s %s %d\n", studenti[i].name, studenti[i].surname, studenti[i].points);
	}

	fclose(filePointer);
}