#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

const int nPunkte = 10;

//Berechnung von Pi mithilfe der Monte-Carlo-Simulation.
int main(void) {
	int nPunkteInnen = 0;
	int nPunkteAussen = 0;

	for (int i = 0; i < nPunkte; i++) {
		//TODO Pipe erstellen
		
		int PPID = fork();
		switch (PPID)
		{
		case -1:
			i = nPunkte;
			printf("Etwas ist beim forken fehlgeschlagen");
			break;

		case 0: //Kindprozess
			//TODO aufrufen von isPunktAussen und durch Pipe zum Elternprozess zurueckleiten
			break;
		
		default: //Elternprozess
			//TODO Herausfinden, was hier zu tun ist.
			break;
		}
	}
	

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
