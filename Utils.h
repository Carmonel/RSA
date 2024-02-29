#ifndef RSA_UTILS_H
#define RSA_UTILS_H

inline BigInteger greatestCommonDivisor(BigInteger a, BigInteger b){
    while (a > 0){
        BigInteger tmp;
        tmp = a;
        a = b % a;
        b = tmp;
    }
    return b;
}

inline std::ostream& operator<<(std::ostream& os, const std::vector<BigInteger>& a){
    for (auto i: a){
        os << bigIntegerToString(i) << " ";
    }
    os << std::endl;
    return os;
}

#endif //RSA_UTILS_H
