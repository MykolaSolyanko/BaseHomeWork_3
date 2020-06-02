#pragma once
#include "Constants.h"

void encrypt(char encryptMatrix[][kMatrixSize], char *string, int key);
void decrypt(char encryptMatrix[][kMatrixSize], char *string, int key);