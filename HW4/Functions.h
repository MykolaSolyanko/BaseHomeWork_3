#pragma once
#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include "Constants.h"

bool PredLess(int first, int second);
bool PredGreater(int first, int second);
bool PredLess(unsigned int first, unsigned int second);
bool PredGreater(unsigned int first, unsigned int second);
bool PredLess(double first, double second);
bool PredGreater(double first, double second);
bool PredLess(char first, char second);
bool PredGreater(char first, char second);

using Pred = std::function<bool(int, int)>;
using PredUI = std::function<bool(unsigned int, unsigned int)>;
using PredD = std::function<bool(double, double)>;
using PredC = std::function<bool(char, char)>;

void output_array_range(unsigned int *begin, unsigned int *end);
void output_array_range(double *begin, double *end);
void output_array_range(char *begin, char *end);
void output_array_range(int *begin, int *end);

void fill_array(int *begin, int *end);
void fill_array(unsigned int *begin, unsigned int *end);
void fill_array(double *begin, double *end);
void fill_array(char *begin, char *end);

void buble_sort(int *begin, int *end, Pred pred);
void buble_sort(unsigned int *begin, unsigned int *end, PredUI pred);
void buble_sort(double *begin, double *end, PredD pred);
void buble_sort(char *begin, char *end, PredC pred);

void qSort(int *begin, int size, Pred pred);
void qSort(unsigned int *begin, int size, PredUI pred);
void qSort(double *begin, int size, PredD pred);
void qSort(char *begin, int size, PredC pred);

void encrypt(char encryptMatrix[][kMatrixSize], char *string, int key);
void decrypt(char encryptMatrix[][kMatrixSize], char *string, int key);

void TaskOneSortComparsion();

void TaskTwoSortUint();

void TaskTwoSortDouble();

void TaskTwoSortChar();

void EncryptionTask();