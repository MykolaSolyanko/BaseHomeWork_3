#pragma once

using Pred = bool(*)(int, int);
using PredUI = bool(*) (unsigned int, unsigned int);
using PredD = bool(*)(double, double);
using PredC = bool(*)(char, char);

void buble_sort(int* begin, int* end, Pred pred);
void buble_sort(unsigned int* begin, unsigned int* end, PredUI pred);
void buble_sort(double* begin, double* end, PredD pred);
void buble_sort(char* begin, char* end, PredC pred);

void qSort(int* begin, int size, Pred pred);
void qSort(unsigned int* begin, int size, PredUI pred);
void qSort(double* begin, int size, PredD pred);
void qSort(char* begin, int size, PredC pred);