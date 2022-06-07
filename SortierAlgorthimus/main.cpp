#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int nElemente = 1000;

int cmpfunc (const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}

int main(int ) {
	int firstSorting;
	if ((firstSorting = shmget(IPC_PRIVATE, nElemente, IPC_CREAT | 0666)) < 0) {
  		printf("Fehler beim bekommen von Shared Memory\n");
  		return -1;
	}

	srand(time(NULL));
	int * dataPnt;
	dataPnt = (int *) shmat (firstSorting, 0, 0);
	for (int i = 0; i < nElemente; i++) {
		dataPnt[i] = rand() % 2500;
	}
	shmdt(dataPnt);

	for (int i = 0; i < 4; i++) {
		int PPID = fork();
		int arrayForSorting[nElemente/4];

		switch (PPID) {
		case -1: //Fehlermeldung
			fprintf(stderr, "Fehler beim Forken von Kind %i Runde 1\n", i);
			break;
		
		case 0: //Kindprozess rechnet
			dataPnt = (int *) shmat(firstSorting, 0, 0);
			
			for (int j = 0; j < nElemente/4; j++) {
				arrayForSorting[j] = dataPnt[j+(i*nElemente/4)];
			}
			qsort(arrayForSorting, nElemente/4, sizeof(int), cmpfunc);
			for (int j = 0; j < nElemente; j++) {
				dataPnt[j+(i*nElemente/4)] = arrayForSorting[j];
			}
			
			shmdt(dataPnt);
			exit(0);
			break;

		default: //Elternprozess macht nichts
			fprintf(stderr, "%i Kind gemacht Runde 1\n", i);
			break;
		}
	}
	
	//Elternprozess wartet, bis alle Kinder tot sind
	for (int i = 0; i < 4; i++)
		wait(NULL);
	
	dataPnt = (int *) shmat (firstSorting, 0, 0);
	for (int i = 0; i < nElemente; i++) {
		printf("%i. = ;%i\n", i, dataPnt[i]);
	}

	shmdt(dataPnt);
	fflush(stderr);
	fflush(stdout);

	int mergedList;
	if ((mergedList = shmget(IPC_PRIVATE, nElemente, IPC_CREAT | 0666)) < 0) {
  		printf("Fehler beim bekommen von Shared Memory fuer mergedList\n");
  		return -1;
	}

	for (int i = 0; i < 2; i++) {
		int PPID = fork();

		switch (PPID) {
		case -1: //Fehlermeldung
			fprintf(stderr, "Fehler beim Forken von Kind %i Runde 2\n", i);
			break;
		
		case 0: //Kindprozess merged

			break;

		default: //Elternprozess macht nichts
			fprintf(stderr, "%i Kind gemacht Runde 2\n", i);
			break;
		}
	}
	//Elternprozess wartet, bis alle Kinder tot sind
	for (int i = 0; i < 2; i++)
		wait(NULL);

	shmctl(firstSorting, IPC_RMID, 0);

	int finalList[nElemente];
	int firstHalfIndex = 0;
	int secondHalfIndex = nElemente/2;
	dataPnt = (int *) shmat (firstSorting, 0, 0);

	for (int i = 0; i < nElemente; i++) {
		if(dataPnt[firstHalfIndex] <= dataPnt[secondHalfIndex]) {
			finalList[i] = dataPnt[firstHalfIndex];
			firstHalfIndex++;
		} else {
			finalList[i] = dataPnt[secondHalfIndex];
			secondHalfIndex++;
		}
	}
	shmctl(mergedList, IPC_RMID, 0);


	return 0;
}