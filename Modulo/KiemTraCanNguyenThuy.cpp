#include <stdio.h>
#include <math.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int isPrimitiveRoot(long long a, long long n) {
    if (a <= 1 || a >= n || n <= 1) {
        return 0;
    }

    long long phi = n - 1;
    for (long long i = 2; i * i <= phi; ++i) {
        if (phi % i == 0) {
            // `i` is a prime factor of `phi`
            if ((long long)pow(a, phi / i) % n == 1) {
                return 0;
            }
            while (phi % i == 0) {
                phi /= i;
            }
        }
    }

    if (phi > 1) {
        // `phi` is a prime factor of `phi`
        if ((long long)pow(a, phi) % n == 1) {
            return 0;
        }
    }

    return 1;
}

int main() {
    freopen("inputCNT.txt", "r", stdin);
    freopen("outputCNT.txt", "w", stdout);
    long long a, n;
    cin >> a;
    cin >> n;
//    printf("Enter a: ");
//    scanf("%lld", &a);
//    printf("Enter n: ");
//    scanf("%lld", &n);

    if (isPrimitiveRoot(a, n)) {
        printf("%lld is a primitive root of %lld\n", a, n);
        cout<<a<<" is a primitive root of "<<n<<"\n";
    } else {
    	 cout<<a<<" is not a primitive root of "<<n<<"\n";
    }

    return 0;
}
