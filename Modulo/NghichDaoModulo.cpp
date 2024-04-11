#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("NghichDao_input.txt");
    ofstream outputFile("NghichDao_output.txt");

    if (!inputFile) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    if (!outputFile) {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    int a, n;
    inputFile >> a >> n;
    outputFile << "----------------------------- a^-1 mod n -----------------------------" << endl;
    outputFile << "a: " << a << endl;
    outputFile << "n: " << n << endl;
    outputFile << endl;
    outputFile << a << "^-1 mod " << n << endl;

    int Q, A1 = 1, A2 = 0, A3 = n, B1 = 0, B2 = 1, B3 = a;

    while (B3 != 0 && B3 != 1) {
        Q = A3 / B3;

        int B1_cp = B1, B2_cp = B2, B3_cp = B3;

        B1 = A1 - B1 * Q;
        B2 = A2 - B2 * Q;
        B3 = A3 - B3 * Q;

        A1 = B1_cp;
        A2 = B2_cp;
        A3 = B3_cp;
    }
    
    if (B3 == 1) {
        outputFile << endl;
        outputFile << "The modular inverse of " << a << " is: " << B2 << endl;
        outputFile << "Result of a^-1 mod n = " << (B2 + n) % n << endl;
    } else {
        outputFile << "\nNo modular inverse found." << endl;
    }

    cout << "Calculation completed successfully." << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}