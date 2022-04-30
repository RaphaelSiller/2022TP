#include <stdio.h>
#include <math.h>
#include "vektorMethoden.h"

int main(void) {
	//Konstanten
	double gravi = -9.81;
	double startV = 0;
	double winkel = 0; //in Rad
	double deltaT = 0.1;
	
	fprintf(stderr, "Bitte geben Sie die Startgeschwindigkeit [m2/s] an: ");
	scanf(" %lf", &startV);
	fprintf(stderr, "Bitte geben Sie den Winkel [rad] an: ");
	scanf(" %lf", &winkel);
	fprintf(stderr, "Bitte geben Sie den Zeitabstand [s] an: ");
	scanf(" %lf", &deltaT);
	
	//nicht-Konstanten
	vector v;
	v.x = startV * cos(winkel);
	v.y = startV * sin(winkel);
	
	vector s = {0, 0};
	double zeit = 0;

	//Berechnung
	printf("t[s]\tvy[m2/s]\tx[m]\ty[m]\n");
		
	do { 
		printf("%f\t%f\t%f\t%f\n", zeit, v.y, s.x, s.y);
		v.y = v.y + gravi * deltaT;
		s.x = s.x + v.x * deltaT;
		s.y = s.y + v.y * deltaT;
		zeit += deltaT;
	} while (s.y > 0);
}
