#include <iostream>

#include "RSA.h"
#include "Utils.h"

BigInteger E(const BigInteger& phi);
BigInteger D(const BigInteger& e, const BigInteger& phi);

RSA::RSA(long int p, long int q) {
    this->p = p;
    this->q = q;
    n = p * q;
    phi = (p - 1) * (q - 1);
    e = E(phi); // открытая экспонента e = [1; φ(n)], gcd(e, φ(n)) = 1
    d = D(e, phi); // сектерная экспонента d ⋅ e ≡ 1 (mod φ(n))

    std::cout << "Public key: (e = " << e << ", n = " << n << ")" << std::endl;
    std::cout << "Private key: (d = " << d << ", n = " << n << ")" << std::endl;
}

std::vector<BigInteger> RSA::encrypt(const std::string &message) {
    std::vector<BigInteger> resultVector;
    for (auto i: message){
        BigInteger current, result;
        current = i;
        result = 1;

        for (BigInteger j = 0; j < e; j++){
            result = result * current;
            result = result % n;
        }

        resultVector.push_back(result);
    }

    return resultVector;
}

void RSA::printValues() {
    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "phi = " << phi << std::endl;
    std::cout << "e = " << e << std::endl;
}

std::string RSA::decrypt(const std::vector<BigInteger> &message) {
    std::string resultString;
    for (int i = 0; i < message.size(); i++){
        std::vector<BigInteger> vector;
        vector.reserve(e.getLength());
        vector.push_back(message[i]);

        for (BigInteger j = 1; j < e.getLength(); j++){
            BigInteger tmp = vector[j.toInt() - 1] * vector[j.toInt() - 1];
            BigInteger tmp2 = 1;
            for (int k = 0; k < e.getLength() - i; k++) tmp2 = tmp2 * vector[i];
            BigInteger tmp3 = tmp * tmp2;
            tmp3 = tmp3 % n;
            vector.push_back(tmp3);
        }

        resultString.push_back((char)vector.back().toInt());
        vector.clear();
    }
    return resultString;
}

BigInteger E(const BigInteger& phi){
    BigInteger e;
    for ( e = 2; e < phi; e++ ) if (greatestCommonDivisor(e, phi ) == 1) return e;
    return -1;
}

BigInteger D(const BigInteger& e, const BigInteger& phi){
    BigInteger d;
    BigInteger k = 1;
    while (true){
        k = k + phi;
        if ( k % e == 0){
            d = (k / e);
            return d;
        }
    }
}
