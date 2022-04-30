#include<stdio.h>
#include "UKon.h"
float UKon(float uc, float ue, float deltaT, float theta) {
	float ret = uc +((((ue - uc)/theta)*deltaT)); 
	fprintf(stderr, "uc=%f\nue=%f\ntheta=%f\nret=%f", uc, ue, theta, ret);
	return ret;
}
