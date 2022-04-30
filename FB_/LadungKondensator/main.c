#include "UKon.h"
#include <stdio.h>

int main(void) {
	float ue = 0, Res = 82000, deltaT = 0.1, C = 0.001;
	float theta;
	float uc = 0;
	float zeit = 0;
	
	printf("Wie sehr sind Sie auf die Ergebnisse gespannt?\n");
	scanf(" %f", &ue);
	printf("Wie sehr können SIe der Spannung resistieren?\n");
	scanf(" %f", &Res);
	printf("Wie lange können Sie überleben, ohne die Messwerte ansehen zu können?\n");
	scanf(" %f", &deltaT);
	printf("Wie viel Energie  können Sie in sich aufnehmen? ");
	scanf(" %f", &C);
	
	theta = Res * C;
	//printf("uc=%f\nue=%f\nRes=%f\nC=%f\ntheta=%f\n", uc, ue, Res, C,theta);
	while (uc < ue*0.9){
		uc = UKon(uc, ue, deltaT, theta);
		printf("%f	%f\n", zeit, uc);
		zeit += deltaT;
	}
	
	return 0;
}
