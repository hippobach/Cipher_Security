#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

map<char, char> M;

void reverKey(string key) {
    int d = 0;
    for (char i = 'A'; i <= 'Z'; i++)
        M[i] = key[d++];
}

void inreverKey(string key) {
    char d = 'A';
    for (auto x : key)
        M[x] = d++;
}

string monoalphabeticEncyption(string input, string key) {
    reverKey(key);
    string output = "";
    for (int i = 0; i < input.length(); i++)
        output += M[input[i]];
    return output;
}

string monoalphabeticDecyption(string input, string key) {
    inreverKey(key);
    string output = "";
    for (int i = 0; i < input.length(); i++)
        output += M[input[i]];
    return output;
}

bool checkKey(string key) {
    if (key.length() != 26)
        return false;
    map<char, bool> M;
    for (int i = 0; i < key.length(); i++) {
        if (M[key[i]] == false) {
            M[key[i]] = true;
        } else if (M[key[i]] == true) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream inputFile("MaHoaChuDon_input.txt");
    ofstream outputFile("MaHoaChuDon_output.txt");

    string input, key, output = "";
    inputFile >> input;
    inputFile >> key;

    if (checkKey(key) == false) {
        outputFile << "Key khong hop le";
        return 0;
    }

    outputFile << "input: " << input << "\nkey: " << key << endl;
    output = monoalphabeticEncyption(input, key);
    outputFile << "Monoalphabetic Encyption : " << output << endl;
    outputFile << "Monoalphabetic Decyption : " << monoalphabeticDecyption(output, key);

    inputFile.close();
    outputFile.close();
    return 0;
}