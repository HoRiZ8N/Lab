#pragma once
#include <iostream>

const int SIZE = 2000;
const int effSize = (SIZE*(SIZE + 1)) / 2;

int* createMatrix();

void fillMatrix(int* matrix);

int getIndex(int i, int j);

void printMatrix(int* matrix);

void getMatrixSquared(int* sourceMatrix, int* resulMatrix);