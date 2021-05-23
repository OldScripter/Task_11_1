#include <iostream>

char shiftTheChar(char initialChar, int shift, char minChar, char maxChar)
{
    char shiftedLetter;
    char range = char(maxChar - minChar + 1);
    if ((int)initialChar + shift > (int) maxChar)
    {
        char restRight = char(maxChar - initialChar);
        int restShift = shift - restRight;
        int normedShift = restShift % (int)range;
        if (normedShift == 0) shiftedLetter = minChar;
        else shiftedLetter = char(minChar + normedShift - 1);
    }
    else if ((int)initialChar + shift < (int) minChar)
    {
        char restLeft = char(initialChar - minChar);
        int restShift = shift + restLeft;
        int normedShift = restShift % range;
        if (normedShift == 0) shiftedLetter = minChar;
        else shiftedLetter = char(maxChar + normedShift + 1);
    }
    else
    {
        shiftedLetter = char(initialChar + shift);
    }
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
