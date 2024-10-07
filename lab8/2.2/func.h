#pragma once
#include <iostream>

const int SIZE = 2;
const int MAXNUMSIZE = 10;

int** create2dMatrix();

void delete2dMatrix(int** matrix);

void fill2dMatrix(int** matrix);

int** square2dMatrix(int** matrix);

void print2dMatrix(int** matrix);

int* multiply2dMatrixVector(int** matrix, int* vector);



int* create1dMatrix();

void delete1dMatrix(int* matrix);

void fill1dMatrix(int* matrix);

int* square1dMatrix(int* matrix);

void print1dMatrix(int* matrix);

int getIndex(int i, int j);

void printVector(int* vector);

int* multiply1dMatrixVector(int* matrix, int* vector);

void fillVector(int* vector);