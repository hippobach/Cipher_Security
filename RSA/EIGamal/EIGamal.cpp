#include <bits/stdc++.h>
using namespace std;

long long haBac(long long a, long long m, long long n) {
    if (m == 1) return a % n;
    if (m % 2 == 0) {
        return (haBac(a, m / 2, n) * haBac(a, m / 2, n)) % n;
    } else {
        return (haBac(a, m / 2, n) * haBac(a, m / 2, n) * haBac(a, 1, n)) % n;
    }
}

long long nghichdao(long long a, long long n) {
    long long Q, A1 = 1, A2 = 0, A3 = n, B1 = 0, B2 = 1, B3 = a;
    while (B3 != 0 && B3 != 1) {
        Q = A3 / B3;
        long long B1_cp = B1, B2_cp = B2, B3_cp = B3;
        B1 = A1 - B1 * Q;
        B2 = A2 - B2 * Q;
        B3 = A3 - B3 * Q;

        A1 = B1_cp;
        A2 = B2_cp;
        A3 = B3_cp;
    }
    return (B2 + n) % n;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long q, a, xA, k, M;

    cin >> q;
    cin >> a;
    cin >> xA;
    long long yA = haBac(a, xA, q);
    cout << "a) Khoa cong khai cua An PU={ " << q << ", " << a << ", " << yA << "};" << endl;
    cin >> k;
    cin >> M;
    long long K = haBac(yA, k, q);
    long long C1 = haBac(a, k, q);
    long long C2 = (K * M) % q;
    cout << "b) Ban ma la: (C1;C2) = (" << C1 << "; " << C2 << ");";
    long long KA = haBac(C1, xA, q);
    long long MA = ((C2 % q) * nghichdao(KA, q)) % q;
    cout << endl << "c) K = " << KA << "; M = " << MA;

    return 0;
}
