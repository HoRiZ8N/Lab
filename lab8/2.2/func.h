#pragma once
#include <iostream>

const int SIZE = 2;
const int MAXNUMSIZE = 10;

int** create2dMatrix(int size);

void delete2dMatrix(int** matrix, int size);

void fill2dMatrix(int** matrix, int size);

void square2dMatrix(int **matrix, int size);

void print2dMatrix(int** matrix, int size);

int* multiply2dMatrixVector(int** matrix, int* vector, int size);



int* create1dMatrix(int size);

void fill1dMatrix(int* matrix, int size);

void square1dMatrix(int* matrix, int size);

void print1dMatrix(int* matrix, int size);

int getIndex(int i, int j, int size);

void printVector(int* vector, int size);

int* multiply1dMatrixVector(int *matrix, int *vector, int size);

void fillVector(int* vector, int size);