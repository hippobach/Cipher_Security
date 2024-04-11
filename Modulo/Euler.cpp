#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;
void PhanTichThuaSoNguyenTo(int n, vector<int> &thuaSo) {
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      thuaSo.push_back(i);
      n /= i;
    }
  }
  if (n > 1) {
    thuaSo.push_back(n);
  }
}
//Tim UCLN
int GCD(int a, int b) {
  if (a < 0 || b < 0) {
    return -1; // Lỗi: Số âm không hợp lệ
  }
  if (a == 0) return b;
  if (b == 0) return a;
  while (b > 0) {
    int tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
bool KiemTraSoNguyenTo(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

bool KiemTraSoNguyenToCungNhau(int a, int b) {
  if (a < b) swap(a, b);
  while (b > 0) {
    int tmp = a % b;
    a = b;
    b = tmp;
  }
  return a == 1;
}
//Tinh ham euler
int eulerValue(vector<int> &thuaSo) {
    int res = 1, count = 0;
    if (thuaSo.size() == 2) {
        if (KiemTraSoNguyenToCungNhau(thuaSo[0], thuaSo[1])) return (thuaSo[0] - 1) * (thuaSo[1] - 1);
    } else {
        for (int i = 0; i < thuaSo.size(); i++) {
            if (count != 0) {
                count--;
                continue;
            }
            if (thuaSo[i] == thuaSo[i + 1]) count++;
            res *= (pow(thuaSo[i], count + 1) - pow(thuaSo[i], count));
        }
        return res;
    }
    // Default return statement
    return 0;
}
//Ha bac
int powMod(int a, int b, int m) {
    //a^b mod m 
  int res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % m;
    }
    a = (a * a) % m;
    b /= 2;
  }
  return res;
}

int main() {
    int a,m,n;
    freopen("inputEuler.txt", "r", stdin);
    freopen("outputEuler.txt", "w", stdout);
    cin >> a;
    cin >> m;
    cin >> n;
    int A = a % n;
    int phi;
    vector<int> thuaSo;
    if(A == 0) cout << "lut thua modulo bang 0";
    else {
      if(GCD(n,A) == 1) {
        if(KiemTraSoNguyenTo(n)) cout << n - 1;
        else {
          PhanTichThuaSoNguyenTo(n, thuaSo);
          phi = eulerValue(thuaSo);
        } 
    // cout << thuaSo.size(); 
    }
    m = m % phi; 
     cout << "Luy thua modulo: "<< powMod(A,m,n);
    }
    
}