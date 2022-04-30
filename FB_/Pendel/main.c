#include <stdio.h>
#include "formeln.h"
int main(void) {
	float deltaT = 0.1;
	float winkel = 1;
	float laenge = 2;
	
	//Eingabe
	fprintf(stderr, "Zeitabstand: ");
	scanf(" %f", &deltaT);
	fprintf(stderr, "Startwinkel: ");
	scanf(" %f", &winkel);
	fprintf(stderr, "Laenge des Seils: ");
	scanf(" %f", &laenge);

	float geschw = 0.0;
	float beschl = 0.0;
	float zeit = 0;
	printf("t[s]\ta[m/s^2]\tv[m/s]\talpha[rad]\n");
	while (beschl < 9.81) {
		beschl = accel(winkel);
		geschw = velo(geschw, beschl, deltaT);
		winkel = angle(winkel, geschw, deltaT, laenge);
		printf("%f\t%f\t%f\t%f\n", zeit, beschl, geschw, winkel);
		zeit += deltaT;
	}
	return 0;
}
