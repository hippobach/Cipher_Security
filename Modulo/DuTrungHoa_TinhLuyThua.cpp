#include<iostream>
#include<math.h>
#include<vector>
#include <fstream>
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
int eulerValue(vector <int> &thuaSo) {
    int res = 1, count = 0;
if(thuaSo.size() == 2) {
        if(KiemTraSoNguyenToCungNhau(thuaSo[0], thuaSo[1])) return (thuaSo[0] - 1) * (thuaSo[1] - 1); 
    } else {
        for(int i = 0; i < thuaSo.size(); i++) {
            if(count != 0) {
              count--;
              continue;
            } 
            if(thuaSo[i] == thuaSo[i+1]) count++;
            res *= (pow(thuaSo[i], count + 1) - pow(thuaSo[i], count));
        }
        // cout << "Gia tri ham Euler: " << res << endl;
        return res;
    }
    return -1;
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
int inverseModuloWithEuclid(int a, int n) {
  int x = 1, y = 0, r = n, R = a;
  if(n == 1) cout << "0";
  while(R > 1) {
    int q = r / R;

    int tmp1,tmp2;
    tmp1 = y;
    y = x;
    x = tmp1 - q * x;
    tmp2 = r;
    r = R;
    R = tmp2 - q * R;
  }
  if(R > 1) cout << "khong ton tai";
  else if( x <= 0) return x + n;
  else return x;
  
  return -1;
}
int main() {
    int a,m,n;
    
    ifstream inputFile("PDTH_input.txt");
    ofstream outputFile("PDTH_output.txt");

    if (!inputFile) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    if (!outputFile) {
        cout << "Failed to open output file." << endl;
        return 1;
    }
    

    inputFile >>a; 
	inputFile>> m ;
	inputFile>> n;
    // int A = a % n;
    int phi, res = 0;
    vector<int> thuaSo;
    vector<int> thuaSoPhi;
    vector<int> Modulo;
    PhanTichThuaSoNguyenTo(n,thuaSo);
    //cout << thuaSo.size();
    for(int i = 0; i < thuaSo.size(); i++) {
        int tmp = a % thuaSo[i];
        if(tmp != 0) {
            if(GCD(thuaSo[i], tmp) == 1) {
                if(KiemTraSoNguyenTo(thuaSo[i])) phi = thuaSo[i] - 1;
                else {
                  PhanTichThuaSoNguyenTo(thuaSo[i], thuaSoPhi);
                  phi = eulerValue(thuaSoPhi);
                } 
            }
            m = m % phi;
            Modulo.push_back(powMod(tmp, m, thuaSo[i]));
        } else Modulo.push_back(tmp);
        // cout << tmp;
    }
    
    int k = thuaSo.size();
    int M[k];
    for(int i = 0; i < k; i++) {
        M[i] = n / thuaSo[i];
    }
    int Inverse[k];
    for(int i = 0; i < k; i++) {
        Inverse[i] = inverseModuloWithEuclid(M[i], thuaSo[i]);
    }
    for(int i = 0; i < k; i++) {
        //cout << Modulo[i] << " " << M[i] << " " << Inverse[i] << endl;
        res += Modulo[i] * M[i] * Inverse[i];
    }
    // for(int i = 0; i < k; i++) {
    //   cout << Modulo[i] << " ";
    // } 
    outputFile <<"Luy thua modulo bang CRT: " << res % n;
    return 0;
}
