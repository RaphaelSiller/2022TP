#include <stdio.h>
#include <iostream>
extern "C" {
#include "matrixMeth.h"
}

using namespace std;

int matrixScan(MatrixEigen_t *MatrixA, MatrixEigen_t *MatrixB) {
	
	
	//input Matrix MatrixA
    freopen("./MatrixBluePrints/A.txt", "r", stdin);
    cin >> MatrixA->laenge >> MatrixA->breite;
    for (int i = 0; i < MatrixA->breite; i++) {
        for (int j = 0; j < MatrixA->laenge; j++) {
            cin >> MatrixA->data[i][j];
        }
        printf("\n");
    }
    fclose(stdin);

    //input Matrix MatrixB
    freopen("./MatrixBluePrints/B.txt", "r", stdin);
    cin >> MatrixB->laenge >> MatrixB->breite;
    for (int i = 0; i < MatrixB->breite; i++) {
        for (int j = 0; j < MatrixB->laenge; j++) {
            cin >> MatrixB->data[i][j];
        }
        printf("\n");
    }
    fclose(stdin);
	return 0;
}