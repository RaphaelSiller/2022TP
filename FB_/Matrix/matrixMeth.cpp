#include <stdio.h>
// #include "./MatrixStruct.h"
#include "./matrixMeth.h"
#include <math.h>

// using namespace std;

int matrixAdd(MatrixEigen_t *MatrixRet, MatrixEigen_t *MatrixA, MatrixEigen_t *MatrixB) {
	if(MatrixA->breite == MatrixB->breite && MatrixA->laenge == MatrixB->laenge) {
        MatrixRet->laenge = MatrixA->laenge;
        MatrixRet->breite = MatrixA->breite;
        for (int i = 0; i < MatrixA->laenge; i++) {
            for (int j = 0; j < MatrixA->breite; j++) {
                MatrixRet->data[i][j] = MatrixA->data[i][j] + MatrixB->data[i][j];
            }
        }
    }
    return 0;
}


int matrixSub(MatrixEigen_t *MatrixRet, MatrixEigen_t *MatrixA, MatrixEigen_t *MatrixB) {
    if(MatrixA->breite == MatrixB->breite && MatrixA->laenge == MatrixB->laenge) {
        MatrixRet->laenge = MatrixA->laenge;
        MatrixRet->breite = MatrixA->breite;
        for (int i = 0; i < MatrixA->laenge; i++) {
            for (int j = 0; j < MatrixA->breite; j++) {
                MatrixRet->data[i][j] = MatrixA->data[i][j] + MatrixB->data[i][j];
            }
        }
    }
    return 0;
}


int matrixMultiSkalar(MatrixEigen_t *MatrixRet, MatrixEigen_t *MatrixA, int skalar) {
        MatrixRet->laenge = MatrixA->laenge;
        MatrixRet->breite = MatrixA->breite;
        for (int i = 0; i < MatrixA->laenge; i++) {
            for (int j = 0; j < MatrixA->breite; j++) {
                MatrixRet->data[i][j] = MatrixA->data[i][j] * skalar;
            }
        }
    return 0;
}


int matrixMultiMatrix (MatrixEigen_t *MatricRet, MatrixEigen_t *MatrixA, MatrixEigen_t *MatrixB) {
  int i, j, k, sum;
  if ((MatrixA->laenge  < 0) || (MatrixA->laenge  > 10) || (MatrixB->laenge  < 0) || (MatrixB->laenge  > 10) ||
      (MatrixA->breite < 0) || (MatrixA->breite > 10) || (MatrixB->breite < 0) || (MatrixB->breite > 10))
     
  if (((MatrixA->breite != MatrixB->laenge)))
    return -1;
  
  for (i = 0; i < MatrixA->laenge; i++)
    for (j = 0; j < MatrixB->breite; j++)
      for (MatricRet->data[i][j] = 0, k = 0; k < MatrixA->breite; k++)
        MatricRet->data[i][j] += MatrixA->data[i][k]*MatrixB->data[k][j];
  MatricRet->laenge  = MatrixA->laenge;
  MatricRet->breite = MatrixB->breite;
  return 0;
}

int matrixInit (MatrixEigen_t *MatrixA) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            MatrixA->data[i][j] = 0;
        }
        
    }
    return 0;
}

int matrixPrint(MatrixEigen_t *MatrixA) {
    for (int i = 0; i < MatrixA->breite; i++) {
        for (int j = 0; j < MatrixA->laenge; j++) {
            printf("%lf\t", MatrixA->data[i][j]);
            // cout << (MatrixA->data[i][j]) << '\t';
        }
        printf("\n");
    }
    return 0;
}


int matrixDreh(MatrixEigen_t *MatrixRet ,MatrixEigen_t *MatrixA, int angle) {
    //Erstellung der Drehmatrix
    MatrixEigen_t drehMatrix;
    drehMatrix.breite = 2;
    drehMatrix.laenge = 2;
    drehMatrix.data[0][0] = cos(angle);
    drehMatrix.data[1][0] = -sin(angle);
    drehMatrix.data[0][1] = sin(angle);
    drehMatrix.data[1][1] = cos(angle); 

    matrixMultiMatrix(MatrixRet, MatrixA, &drehMatrix);
    return 0;
}
