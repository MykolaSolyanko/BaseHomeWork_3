#include "encrypt.h"
#include <cstring>

void encrypt(char encryptMatrix[][kMatrixSize], char *str, int key) {
  const int kStringSize = strlen(str);
  int i{0};
  int j{0};
  int k{0};

  // fill encrypt matrix with encryption data
  /*
  if string is = "Hello"; and key = 3
  matrix will be
  H l 0 0
  e o 0 0
  l 0 0 0
  0 0 0 0
  */
  while (str[i] != '\0') {
    encryptMatrix[k][j] = str[i] ^ key;
    ++i;
    ++k;
    if (k > key - 1) {
      ++j;
      k = 0;
    }
  }
  memset(str, '\0', kStringSize);
  for (k = 0, i = 0; i != kStringSize; ++k) {

    for (j = 0; encryptMatrix[k][j] != '\0'; ++j, ++i)
      str[i] = encryptMatrix[k][j];
  }
}

void decrypt(char encryptMatrix[][kMatrixSize], char *str, int key) {
  const int kStringSize = strlen(str);
  int i{0};
  int j{0};
  int k{0};

  while (i != kStringSize) {
    while (encryptMatrix[j][k] != '\0') {
      str[i++] = encryptMatrix[j][k] ^ key;
      j++;
    }

    j = 0;
    k++;
  }
}