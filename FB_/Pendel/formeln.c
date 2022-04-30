#include <math.h>

float accel(float winkel) {
	float ret = -9.81 * winkel;
	return ret;
}

float velo(float geschw, float beschl, float deltaT) {
	float ret = geschw + (beschl * deltaT);
	return ret;
}

float angle(float winkel, float geschw, float deltaT, float laenge) {
	float ret = winkel + ((geschw * deltaT) / laenge);
	return ret;
}
