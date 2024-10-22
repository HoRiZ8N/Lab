#pragma once
#include <iostream>

const int SIZE = 10000;
const int effSize = (SIZE / 2 * (SIZE + 1));

int* createMatrix();

void fillMatrix(int* matrix);

int getIndex(int i, int j);

void printMatrix(int* matrix);

void getMatrixSquared(int* sourceMatrix, int* resulMatrix);