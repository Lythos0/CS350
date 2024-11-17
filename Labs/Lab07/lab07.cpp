#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int charToNum(char c) {
    return std::isupper(c) ? c - 'A' : std::tolower(c) - 'a';
}
char numToChar(int n) {
    return 'A' + n;
}

std::string encryptLine(const std::string& line, const std::string& key) {
    std::string result;
    int keyIndex = 0;

    for (char c : line) {
        if (std::isalpha(c)) {
            int textValue = charToNum(c);
            int keyValue = charToNum(key[keyIndex % key.length()]);
            result += numToChar((textValue + keyValue) % 26); 
            keyIndex++;
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    std::string key, filename;
    std::cout << "Please enter a key (Use letters only): ";
    std::cin >> key;
    for (char c : key) {
        if (!std::isalpha(c)) {
            std::cout << "This key is invalid. Only letters are allowed.\n";
            return 1;
        }
    }

    std::cout << "Enter the filename to encrypt: ";
    std::cin >> filename;

    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cout << "File could not be opened.\n";
        return 1;
    }
    std::ofstream outputFile("ECopy.txt");
    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << encryptLine(line, key) << "\n";
    }
    std::cout << "Encryption complete! Saved to 'ECopy.txt'.\n";
    return 0;
}
