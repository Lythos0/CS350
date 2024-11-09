#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<int, int> mod_inverses = {
    {5, 29}, {7, 31}, {11, 23}, {13, 25},
    {17, 17}, {19, 19}, {23, 11}, {25, 13},
    {29, 5}, {31, 7}, {35, 35}
};

namespace Ciphers {
    const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string caesar_cipher(const std::string& text, int shift) {
        std::string result;
        for (char c : text) {
            if (std::isalpha(c)) {
                char base = std::isupper(c) ? 'A' : 'a';
                result += (c - base + shift + 26) % 26 + base;
            } else {
                result += c;
            }
        }
        return result;
    }

    std::string affine_cipher(const std::string& text, int a, int b) {
        std::string result;
        int mod = ALPHABET.size();
        
 
        if (mod_inverses.find(a) == mod_inverses.end()) {
            throw std::invalid_argument("a and mod have to be coprime");
        }

      
        int mod_inv = mod_inverses[a];

        for (char c : text) {
            if (std::isalpha(c)) {
                char base = std::isupper(c) ? 'A' : 'a';
                int index = (mod_inv * (c - base - b + mod)) % mod;
                result += index + base;
            } else {
                result += c;
            }
        }
        return result;
    }
}

int main() {
    std::string text;
    std::cout << "Enter a text: ";
    std::getline(std::cin, text);

    std::string caesar_encrypted = Ciphers::caesar_cipher(text, 3);
    std::string caesar_decrypted = Ciphers::caesar_cipher(caesar_encrypted, -3);

   
    std::string affine_encrypted = Ciphers::affine_cipher(text, 5, 8); // Using 5 as 'a'
    std::string affine_decrypted = Ciphers::affine_cipher(affine_encrypted, 5, 8); // Using 5 as 'a'

  
    std::cout << "Caesar Cipher:\n";
    std::cout << "  Encrypted: " << caesar_encrypted << std::endl;
    std::cout << "  Decrypted: " << caesar_decrypted << std::endl;

    std::cout << "Affine Cipher:\n";
    std::cout << "  Encrypted: " << affine_encrypted << std::endl;
    std::cout << "  Decrypted: " << affine_decrypted << std::endl;

    return 0;
}

