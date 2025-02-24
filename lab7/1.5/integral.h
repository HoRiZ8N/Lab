#pragma once

double f(double x, double s, double t);
double leftRectangleMethod(double a, double b, double s, double t, double epsilon, int &k_iter, double (*func)(double, double, double));
double testFunc(double, double, double);