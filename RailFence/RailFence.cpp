#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string railFenceEncrypt(const string& plaintext, int rails) {
    vector<string> fence(rails, string(plaintext.length(), ' '));
    int row = 0;
    int dir = 1;

    for (int i = 0; i < plaintext.length(); i++) {
        fence[row][i] = plaintext[i];

        if (row == 0)
            dir = 1;
        else if (row == rails - 1)
            dir = -1;

        row += dir;
    }

    string ciphertext;
    for (const string& rail : fence) {
        ciphertext += rail;
    }

    return ciphertext;
}

string railFenceDecrypt(const string& ciphertext, int rails) {
    vector<vector<bool>> isOccupied(rails, vector<bool>(ciphertext.length(), false));
    vector<int> positions(ciphertext.length(), 0);
    int row = 0;
    int dir = 1;

    for (int i = 0; i < ciphertext.length(); i++) {
        positions[i] = row;
        isOccupied[row][i] = true;

        if (row == 0)
            dir = 1;
        else if (row == rails - 1)
            dir = -1;

        row += dir;
    }

    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < ciphertext.length(); j++) {
            if (isOccupied[i][j]) {
                isOccupied[i][j] = false;
                positions[j] = index++;
            }
        }
    }

    string plaintext(ciphertext.length(), ' ');
    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext[positions[i]] = ciphertext[i];
    }

    return plaintext;
}

int main() {
    ifstream inputFile("RailFence_input.txt");
    ofstream outputFile("RailFence_output.txt");

    string plaintext, encrypted, decrypted;
    int rails;

    getline(inputFile, plaintext);
    inputFile >> rails;

    encrypted = railFenceEncrypt(plaintext, rails);
    decrypted = railFenceDecrypt(encrypted, rails);

    outputFile << "Plaintext: " << plaintext << endl;
    outputFile << "Rails: " << rails << endl;
    outputFile << "Encrypted: " << encrypted << endl;
    outputFile << "Decrypted: " << decrypted << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}