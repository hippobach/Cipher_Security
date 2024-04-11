#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string CaesarEncryption(string input, int key) {
    int length = input.length();
    for (int i = 0; i < length; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = ((input[i] - 'A' + key) % 26) + 'A';
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = ((input[i] - 'a' + key) % 26) + 'a';
        }
    }
    return input;
}

string CaesarDecryption(string output, int key) {
    int length = output.length();
    for (int i = 0; i < length; i++) {
        if (output[i] >= 'A' && output[i] <= 'Z') {
            output[i] = ((output[i] - 'A' - key + 26) % 26) + 'A';
        } else if (output[i] >= 'a' && output[i] <= 'z') {
            output[i] = ((output[i] - 'a' - key + 26) % 26) + 'a';
        }
    }
    return output;
}

int main() {
    string input;
    int key;
    ifstream inputFile("Caesar_input.txt");
    ofstream outputFile("Caesar_output.txt");

    if (!inputFile) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    if (!outputFile) {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    getline(inputFile, input);
    inputFile >> key;
    key %= 26;

    string output = CaesarEncryption(input, key);

    outputFile << "Cipher Key: " << input << endl;
    outputFile << "Shift Key: " << key << endl;
    outputFile << "Caesar Cipher: " << output << endl;
    outputFile << "Caesar Cipher Decryption: " << CaesarDecryption(output, key) << endl;

    cout << "Encryption and decryption completed successfully." << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}