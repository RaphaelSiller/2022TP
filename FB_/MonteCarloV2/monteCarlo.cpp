#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

using namespace std;

const int nPunkte = 100;
const int maxChilds = 4;

bool isPunktAussen();

//Berechnung von Pi mithilfe der Monte-Carlo-Simulation.
int main(void) {
	int nPunkteInnen = 0;
	int nPunkteAussen = 0;
	int addressOffset = 0;

	//Erstellung des Shared Memory
	int speicher[maxChilds];
	for (int i = 0; i < maxChilds; i++) {
		if((speicher[i] = shmget(IPC_PRIVATE, sizeof(bool), IPC_CREAT | 0666)) < 0) {
			printf("Etwas ist beim erstellen des gemeinsamen Speicher schiefgegangen\n");
			exit(-1);
		}
	}
	int IDChild = 0;
	for (int i = 0; i < nPunkte; i++) {
		//TODO Dem nächsten Kind ID geben
		fflush(stdout);
		int PPID = fork();

		switch (PPID) {
		case -1:
			i = nPunkte;
			printf("Etwas ist beim forken fehlgeschlagen\n");
			break;

		case 0: //Kindprozess berechnet einen Punkt und speichert ihn ab
			srand(time(NULL) + IDChild);
			int *z;
   			z = (int *) shmat (speicher[IDChild], 0, 0);
			*z = isPunktAussen() ? 1 : 0;
			shmdt(z);
			break;

		default: //Elternprozess
			//Wenn noch Kinder Platz haben, dann noch eines machen, sonst warten bis alle Tod sind und Ergebnesse ernten
			if (IDChild > maxChilds) {
				IDChild = 0;
				for (int j = 0; j < maxChilds; j++) {
					wait(NULL);
				}
				for (int j = 0; j < maxChilds; j++) {
					z = (int *) shmat (speicher[j], 0, 0);
					if(z[j] == 1)
						nPunkteInnen++;
					else
						nPunkteAussen++;
				}
				shmdt(z);

			} else 
				IDChild++;
			break;
		}
	}
	for (int j = 0; j < maxChilds; j++) {
		if(shmctl(speicher[j], IPC_RMID, 0) != -1) {
			printf("Etwas ist beim loeschen des Shared Memory schiefgegangen\n");
		}
	}
	printf("%i Punkte innen\n", nPunkteInnen);
	printf("%i Punkte ausen\n", nPunkteAussen);
	
}

/**
 * @brief Erstellt einen zufaelligen Punkt auf einer Flaeche von 1x1 und gibt zurueck, ob sich dieser im Einheitskreis befindet.
 * beachtet nur den 1. Quadranten
 * 
 * @return true, wenn sich der zufaellige Punkt im Kreis befindet
 * @return false , wenn sich der zufaellige Punkt ausserhalb des Kreises befindet
 */
bool isPunktAussen() {
	double x = rand() / __INT_MAX__;
	double y = rand() / __INT_MAX__;

	if (pow(x, 2) + pow(y, 2) < 1) {
		return true;
	} else {
		return false;
	}
}
