#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

long long powerMod(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long p, q, e, M;
    cin >> p;
	cin >> q;
	cin >> e;
	cin >> M;

    long long n = p * q;
    long long phi_n = (p - 1) * (q - 1);

    // a) Kh�a c�ng khai c?a An: PU = {e, n}
    cout << "a) Khoa cong khai cua An (PU) = {" << e << ", " << n << "}" << endl;

    // b) Kh�a ri�ng c?a An: PR = {d, n}
    long long d = powerMod(e, -1, phi_n);
    cout << "b) Khoa rieng cua An (PR) = {" << d << ", " << n << "}" << endl;

    // c) M� h�a th�ng di?p M = 43
    long long C = powerMod(M, e, n);
    cout << "c) Thong diep sau khi ma hoa (C) = " << C << endl;

    // d) Gi?i m� b?n m� C
    long long decrypted_M = powerMod(C, d, n);
    cout << "d) Ban ma C sau khi giai ma (M) = " << decrypted_M << endl;

    // e) M� h�a ? c�u c) th?c hi?n nhi?m v? b?o m?t
    cout << "e) Ma hoa tai cau c) thuc hien nhiem vu bao mat." << endl;

    return 0;
}
