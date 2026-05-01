#include <string.h>
#include "../../config.h"
#include "encryption.h"

// XOR encryption
void encrypt(char* data) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] ^= 7;
    }
}

// XOR decryption
void decrypt(char* data) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] ^= 7;
    }
}

