#include "modAlphaCipher.h"
#include <iostream>
#include <locale>
#include <algorithm>

void check(const std::wstring& Text, const std::wstring& key, bool destructCipherText = false)
{
    try {
        std::wstring cipherText;
        std::wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        
        if (destructCipherText && !cipherText.empty()) {
            cipherText[0] = std::towlower(cipherText[0]);
        }
        
        decryptedText = cipher.decrypt(cipherText);
        std::wcout << L"key=" << key << std::endl;
        std::wcout << L"Original: " << Text << std::endl;
        std::wcout << L"Encrypted: " << cipherText << std::endl;
        std::wcout << L"Decrypted: " << decryptedText << std::endl;

        // Используем публичный метод для сравнения
        std::wstring expected = cipher.removeNonAlphaPublic(Text);
        if(decryptedText == expected)
            std::wcout << L"Ok\n";
        else
            std::wcout << L"Err\n";
        
    } catch (const cipher_error& e) {
        std::wcout << L"Error: " << e.what() << std::endl;
    }
    
    std::wcout << L"-------------------" << std::endl;
}

int main()
{
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());

    // Нормальные тесты
    check(L"Привет", L"Ключ");
    check(L"ПРИВЕТ", L"ДРУГОЙ");
    check(L"привет мир", L"Тест");
    
    // Тесты с исключениями
    check(L"Привет", L""); // Пустой ключ
    check(L"Привет", L"123"); // Ключ с цифрами
    check(L"", L"Ключ"); // Пустой текст
    check(L"123", L"Ключ"); // Текст без букв
    check(L"ПРИВЕТ", L"Ключ", true); // Испорченный шифротекст

    return 0;
}