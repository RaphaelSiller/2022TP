#include "vektorMethoden.h"

vector vectorSum( vector v1, vector v2) {
	vector ret;
	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	return ret;
}

vector vectorScale( int k, vector v) {
	vector ret;
	ret.x = k * v.x;
	ret.y = k * v.y;
	return ret;
}
