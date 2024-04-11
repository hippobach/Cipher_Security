#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

long long powerMod(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;
//    while (exponent > 0) {
//        if (exponent % 2 == 1) {
//            result = (result * base) % modulus;
//        }
//        base = (base * base) % modulus;
//        exponent /= 2;
//    }
while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long q, a, xA, xB;
    cin >> q;
	cin >> a;
	cin >> xA;
	cin >> xB;

    // a) Tính khóa công khai và khóa phiên c?a An
    long long yA = powerMod(a, xA, q);
    long long yB = powerMod(a, xB, q);
    long long K_A = powerMod(yB, xA, q);
    long long K_B = powerMod(yA, xB, q);

    cout << "a) Khoa cong khai cua An: yA = " << yA << ", K = " << K_A << endl;

    cout << "b) Khoa cong khai cua Ba: yB = " << yB << ", K = " << K_B << endl;

    return 0;
}
