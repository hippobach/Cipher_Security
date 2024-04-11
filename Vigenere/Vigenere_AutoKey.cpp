#include<bits/stdc++.h>
#define ll long long
#define MAX 1e9+7
#define MIN -1e9+7
#define f first
#define s second
using namespace std;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string RepeatKey(string input, string key){
    string keyNew = key;
    int length = input.length();
    while(keyNew.length() < length){
        for(int j = 0; j < input.length(); j++){
            keyNew += input[j];
            if(keyNew.length() == length) break;
        }
    }
    return keyNew;
}

int position(char c){
    if(c > 'Z') return c - 'a';
    return c - 'A';
}

string VigenereAutoKeyEncryption(string input, string key){
    string cipher = "";
    int p, k, c;
    for(int i = 0; i < input.length(); i++){
        p = position(input[i]);
        k = position(key[i]);
        c = (p + k) % 26;
        cipher += alphabet[c];
    }
    return cipher;
}

string VigenereAutoKeyDecryption(string input, string key){
    string cipher = "";
    int p, k, c;
    for(int i = 0; i < input.length(); i++){
        c = position(input[i]);
        k = position(key[i]);
        p = (c - k + 26) % 26;
        cipher += alphabet[p];
        key += alphabet[p];
    }
    return cipher;
}

int main(){
    string input, key;
    ifstream inputFile("Vigenere_input.txt");
    ofstream outputFile("Autokey_output.txt");

    if (!inputFile) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    if (!outputFile) {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    inputFile >> input >> key;

    key = RepeatKey(input, key);
    string encryptedText = VigenereAutoKeyEncryption(input, key);
    string decryptedText = VigenereAutoKeyDecryption(encryptedText, key);

    outputFile << "Input: " << input << endl;
    outputFile << "Key: " << key << endl;
    outputFile << "Key New: " << key << endl;
    outputFile << "Vigenere Encryption: " << encryptedText << endl;
    outputFile << "Vigenere Decryption: " << decryptedText << endl;

    cout << "Encryption and decryption completed successfully." << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}