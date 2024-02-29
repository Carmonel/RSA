#ifndef RSA_RSA_H
#define RSA_RSA_H

#include <string>
#include <vector>

#include "BIGINT/BigIntegerLibrary.hh"

class RSA {
private:
    long int p;
    long int q;
    BigInteger n;
    BigInteger d;
    BigInteger phi;
    BigInteger e;
public:
    RSA(long int p, long int q);
    void printValues();
    std::vector<BigInteger> encrypt(const std::string& message);
    std::string decrypt(const std::vector<BigInteger>& message);
};

#endif //RSA_RSA_H
