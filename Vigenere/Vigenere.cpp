#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string RepeatKey(string input, string key) {
    string keyNew = key;
    int length = input.length();
    while (keyNew.length() < length) {
        for (int j = 0; j < key.length(); j++) {
            keyNew += key[j];
            if (keyNew.length() == length) break;
        }
    }
    return keyNew;
}

int position(char c) {
    if (c > 'Z') return c - 'a';
    return c - 'A';
}

string VigenereEncryption(string input, string key) {
    string cipher = "";
    int p, k, c, m = key.length();
    for (int i = 0; i < input.length(); i++) {
        p = position(input[i]);
        k = position(key[i % m]);
        c = (p + k) % 26;
        cipher += alphabet[c];
    }
    return cipher;
}z

string VigenereDecryption(string input, string key) {
    string cipher = "";
    int p, k, c, m = key.length();
    for (int i = 0; i < input.length(); i++) {
        c = position(input[i]);
        k = position(key[i % m]);
        p = (c - k + 26) % 26;
        cipher += alphabet[p];
    }
    return cipher;
}

int main() {
    string input, key;
    ifstream inputFile("Vigenere_input.txt");
    ofstream outputFile("Vigenere_output.txt");

    if (!inputFile) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    if (!outputFile) {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    inputFile >> input;
    inputFile >> key;

    key = RepeatKey(input, key);
    input = VigenereEncryption(input, key);

    outputFile << "Vigenere Encryption: " << input << endl;
    outputFile << "Vigenere Decryption: " << VigenereDecryption(input, key) << endl;

    cout << "Encryption and decryption completed successfully." << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}