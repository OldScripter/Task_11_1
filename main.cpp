#include <iostream>

char shiftTheChar(char initialChar, int shift, char minChar, char maxChar)
{
    int shiftedLetter = initialChar + (char) shift;
    if (shiftedLetter > maxChar) shiftedLetter = minChar + shiftedLetter % maxChar - 1;
    else if (shiftedLetter < minChar) shiftedLetter = maxChar - minChar % shiftedLetter + 1;
    return shiftedLetter;
}


std::string encrypt_caesar(std::string text, int parameter)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = shiftTheChar(text[i], parameter, 'a', 'z');
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = shiftTheChar(text[i], parameter, 'A', 'Z');
        }
    }
    return text;
}

std::string decrypt_caesar(std::string text, int parameter)
{
    return encrypt_caesar(text, -parameter);
}

int main() {


    int parameter;

    std::string textToEncrypt;
    std::cout << "Please enter the text to be encrypted: ";
    std::getline(std::cin, textToEncrypt);

    std::cout << "Please enter the parameter of encryption: ";
    std::cin >> parameter;

    std::cout << "\n---Encrypting---\n\n";

    std::cout << "Encrypted text:\n" << encrypt_caesar(textToEncrypt, parameter) << "\n";

    std::cout << "\n---Decrypting---\n\n";

    std::cout << "Decrypted text:\n" << decrypt_caesar(encrypt_caesar(textToEncrypt, parameter), parameter) << "\n";

    return 0;
}
