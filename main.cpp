#include <iostream>

std::string encrypt_caesar(std::string text, int parameter)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            char shiftedLetter = text[i] + (char) parameter;
            if (shiftedLetter > 'z') shiftedLetter = 'a' + shiftedLetter % 'z' - 1;
            else if (shiftedLetter < 'a') shiftedLetter = 'z' - 'a' % shiftedLetter + 1;
            text[i] = shiftedLetter;
        }
    }
    return text;
}

std::string decrypt_caesar(std::string text, int parameter)
{
    return encrypt_caesar(text, -parameter);
}

int main() {

    char menuCommand;
    std::string textToEncrypt;
    std::string textToDecrypt;
    int parameter;

    bool badInput = false;

    while (true)
    {
        std::cout << "Please enter the menu command ('e' - to encrypt, 'd' - to decrypt, 'q' - to exit): ";
        std::cin >> menuCommand;

        if (menuCommand == 'e')
        {
            std::cout << "Please enter the text to be encrypted: ";
            std::cin >> textToEncrypt;

            std::cout << "Please enter the parameter of encryption: ";
            std::cin >> parameter;

            std::cout << "\n---Encrypting---\n\n";

            std::cout << "Encrypted text:\n" << encrypt_caesar(textToEncrypt, parameter) << "\n";
        }
        else if (menuCommand == 'd')
        {
            std::cout << "Please enter the text to be decrypted: ";
            std::cin >> textToDecrypt;

            std::cout << "Please enter the parameter of decryption: ";
            std::cin >> parameter;

            std::cout << "\n---Decrypting---\n\n";

            std::cout << "Decrypted text:\n" << decrypt_caesar(textToDecrypt, parameter) << "\n";
        }
        else if (menuCommand == 'q')
        {
            break;
        }
        else
        {
            std::cout << "Bad command. Try again.\n";
        }
    }
    return 0;
}
