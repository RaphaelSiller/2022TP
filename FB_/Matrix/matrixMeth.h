// #include "./MatrixStruct.h"
#ifndef __MATRIX_H__
#define __MATRIX_H__
typedef
struct MatrixEigen_s {
    double data[10][10];
    int laenge;
    int breite;
} MatrixEigen_t;
#endif

int matrixAdd(MatrixEigen_t *MatrixRet, MatrixEigen_t *MatrixA, MatrixEigen_t *MatrixB);
int matrixSub(MatrixEigen_t *MatrixRet, MatrixEigen_t *MatrixA, MatrixEigen_t *MatrixB);
int matrixMultiSkalar(MatrixEigen_t *MatrixRet, MatrixEigen_t *MatrixA, int skalar);
int matrixMultiMatrix (MatrixEigen_t *MatricRet, MatrixEigen_t *MatrixA, MatrixEigen_t *MatrixB);
// MatrixEigen_t matrixScan(char nr);
int matrixPrint(MatrixEigen_t *A);
int matrixInit (MatrixEigen_t *MatrixA);