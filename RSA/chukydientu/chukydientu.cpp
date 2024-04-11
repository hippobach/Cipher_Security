#include <iostream>
#include <fstream>

using namespace std;

// Tính a mu b modulo n
long long powerMod(long long a, long long b, long long n) {
    long long result = 1;
    a = a % n;
    while (b > 0) {
        if (b & 1)
            result = (result * a) % n;
        a = (a * a) % n;
        b >>= 1;
    }
    return result;
}

// Tìm u?c chung l?n nh?t c?a a và b
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Tìm ngh?ch d?o modulo c?a a theo modulo m
long long modInverse(long long a, long long m) {
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        long long q = a / m;
        long long t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    long long p, q, h, xA,k;
    cin >> p;
	cin >> q;
	cin >> h;
	cin >> xA;
	cin >> k;

//    long long p = 67, q = 11, h = 43;
//    long long xA = 6, k = 12;

    // T?o khóa công khai c?a An: yA = h^xA mod p
    long long yA = powerMod(h, xA, p);
    cout << "a) Khoa cong khai cua An (yA) = " << yA << endl;

    // Ð?c b?n tin M t? file input.txt
    string message;
    cin >> message;

    // Bam b?n tin M: H(M) = hash(message)
    long long hashedMessage = 0;
    for (char c : message) {
        hashedMessage += c;
    }
    hashedMessage = hashedMessage % q;

    // T?o ch? ký s? c?a An cho b?n tin M
    long long r = 0, s = 0;
    while (r == 0 || s == 0) {
        long long kInverse = modInverse(k, q);
        r = powerMod(h, k, p) % q;
        s = (kInverse * (hashedMessage + xA * r)) % q;
    }
    cout << "b) Chu ky so cua An cho ban tin M (r, s) = (" << r << ", " << s << ")" << endl;

    // Ba xác minh ch? ký s?
    long long w = modInverse(s, q);
    long long u1 = (hashedMessage * w) % q;
    long long u2 = (r * w) % q;
    long long v = ((powerMod(h, u1, p) * powerMod(yA, u2, p)) % p) % q;

    if (v == r) {
        cout << "c) Chu ky so hop le. Ba xac minh thanh cong." << endl;
    } else {
        cout << "c) Chu ky so khong hop le. Ba xac minh that bai." << endl;
    }

    return 0;
}
