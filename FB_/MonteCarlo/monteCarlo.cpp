#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
using namespace std;

const int nPunkte = 10;
const int maxChilds = 5;

bool isPunktAussen();

//Berechnung von Pi mithilfe der Monte-Carlo-Simulation.
int main(void) {
	int nPunkteInnen = 0;
	int nPunkteAussen = 0;
	//Erstellung der Pipes
	int MariosPipe[maxChilds][2];
	for(int i = 0; i < maxChilds; i++) 
		pipe(MariosPipe[i]);

	for (int i = 0; i < nPunkte; i++) {
		int IDChild = 0; 
		//TODO Dem nächsten Kind ID geben
		int PPID = fork();
		int istPunktimKreis = -1;
		switch (PPID) {
		case -1:
			i = nPunkte;
			printf("Etwas ist beim forken fehlgeschlagen");
			break;

		case 0: //Kindprozess
			srand(time(NULL) + IDChild);
			i = nPunkte;
			//TODO aufrufen von isPunktAussen und durch Pipe zum Elternprozess zurueckleiten
			close(MariosPipe[IDChild][0]);
			istPunktimKreis = isPunktAussen() ? 1 : 0;
			write(MariosPipe[IDChild][1], &istPunktimKreis, sizeof(int));
			exit(0);
			break;
		
		default: //Elternprozess
			//TODO Herausfinden, was hier zu tun ist.
			if (IDChild >= maxChilds) {
				IDChild = 0;
				for (int j = 0; j < maxChilds; j++) {
					int temp1 = 0;
					if (read(MariosPipe[j][0], &temp1, sizeof(int)) == 1) {
						nPunkteInnen++;
					} else
						nPunkteAussen++;	
				}
				
			} else 
				IDChild++;
			break;
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
