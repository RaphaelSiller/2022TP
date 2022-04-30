#include <stdio.h>
// #include "MatrixStruct.h"
extern "C" {
#include "matrixMeth.h"
}
#include <iostream>
// #include "matrixScan.cpp"

int matrixScan(MatrixEigen_t *MatrixA, MatrixEigen_t *MatrixB);

// using namespace std;

int main(void) {
    // MatrixEigen_t MatrixA = matrixScan('MatrixA');
    // MatrixEigen_t MatrixB = matrixScan('MatrixB');
    MatrixEigen_t MatrixA;
    MatrixEigen_t MatrixB;
    MatrixEigen_t MatrixC;


    matrixInit(&MatrixA);
    matrixInit(&MatrixB);
    matrixInit(&MatrixC);

    matrixScan(&MatrixA, &MatrixB);
    // //input Matrix MatrixA
    // freopen("./MatrixBluePrints/A.txt", "r", stdin);
    // cin >> MatrixA.laenge >> MatrixA.breite;
    // for (int i = 0; i < MatrixA.breite; i++) {
    //     for (int j = 0; j < MatrixA.laenge; j++) {
    //         cin >> MatrixA.data[i][j];
    //     }
    //     printf("\n");
    // }
    // fclose(stdin);

    // //input Matrix MatrixB
    // freopen("./MatrixBluePrints/B.txt", "r", stdin);
    // cin >> MatrixB.laenge >> MatrixB.breite;
    // for (int i = 0; i < MatrixB.breite; i++) {
    //     for (int j = 0; j < MatrixB.laenge; j++) {
    //         cin >> MatrixB.data[i][j];
    //     }
    //     printf("\n");
    // }
    // fclose(stdin);


    matrixPrint(&MatrixA);
    matrixPrint(&MatrixB);

	// MatrixC = matrixAdd(MatrixA, MatrixB);
    // matrixPrint(MatrixC);

    // MatrixC = matrixSub(MatrixA, MatrixB);
    // matrixPrint(MatrixC);

    // MatrixC = matrixMultiSkalar(MatrixA, 4);
    // matrixPrint(MatrixC);

    // MatrixC = matrixMultiMatrix(MatrixA, MatrixB);
    // matrixPrint(MatrixC);
    return 0;
}