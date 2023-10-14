#include "pch.h"?
#include <string>
#include <cctype> 
#include "Dll2.h"



DLL2_API std::string Encrypt(std::string str, int key) {
    std::string encrypted = str;

    for (int i = 0; i < encrypted.size(); i++)
    {
        char base = 32; 
        char end = 126;  
        encrypted[i] = static_cast<char>(base + (encrypted[i] - base + (key % (end - base + 1))) % (end - base + 1));
    }

    return encrypted;
}

DLL2_API std::string Decrypt(std::string str, int key) {
    std::string decrypted = str;

    for (int i = 0; i < decrypted.size(); i++)
    {
        char base = 32; 
        char end = 126;  
        decrypted[i] = static_cast<char>(base + (decrypted[i] - base - (key % (end - base + 1)) + (end - base + 1)) % (end - base + 1));
    }

    return decrypted;
}



