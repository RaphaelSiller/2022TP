#include <stdio.h>
#include <math.h>

int main(void) {
	double dt = 0;
	double v0 = 0;
	double alpha = 91;
	double dauer = 0;

	//Input
	//Zeitabstand
	fprintf(stderr, "Bitte geben Sie den Zeitabstand an\n");
	scanf("%lf", &dt);
	//Startgeschwindigkeit
	fprintf(stderr, "Bitte geben Sie die Startgeschwindigkeit ein\n");
	scanf("%lf", &v0);
	//Steigung
	fprintf(stderr, "Bitte geben Sie die Steigung in Grad ein\n");
	while (alpha > 90 || alpha < 0) {
		scanf("%lf", &alpha);
		if (alpha > 90 || alpha < 0)
			fprintf(stderr, "Die Steigung muss zwischen 0 und 90 liegen\n"); 
	}
	//Dauer des rutschens
	fprintf(stderr, "Finale Frage: Wie lange soll das Obkjekt rutschen?\n");
	scanf("%lf", &dauer);
	
	//Berechnung FINAL
	alpha = alpha * 180/3.14159;
	double a = 9.81 * sin(alpha);
	double dV = a / dt;

	double ds = 0;
	double s = 0;
	//Ausgabe
	printf("Zeit	Geschwindigkeit	Strecke seit %lf	Strecke\n", dt);
	for (double i = 0; i < dauer + dt; i = i + dt) {
		printf("%lf\t", i);
		//neue Geschwindigkeit
		v0 = v0 + dV;
		printf("%lf\t", v0*-1);
		//zurückgelegter Abstand
		ds = dt * v0;
		printf("%lf\t", ds*-1);
		//Strecke gesamt 
		s = s + ds;
		printf("%lf\t", s*-1);
		printf("\n");
	}
}
