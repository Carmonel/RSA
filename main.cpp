#include <iostream>

#include "RSA.h"
#include "Utils.h"

int main() {
    std::string message = "Hello, World!";
    RSA rsa(43261, 10501);
    rsa.printValues();
    std::vector<BigInteger> encrypted;
    std::string decrypted;
    std::cout << "Encrypted message: " << (encrypted = rsa.encrypt(message)) << std::endl;
    std::cout << "Decrypted message: " << (decrypted = rsa.decrypt(encrypted));

    std::cout << std::endl;
    for (int i = 0; i < decrypted.size(); i++){
        std::cout << (int)message[i] << " " << (int)decrypted[i] << std::endl;
    }
}
