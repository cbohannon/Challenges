#include <iostream>

using namespace std;

int main()
{
    const string Alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.?!'"};
    const string Key {"?XZNLWEBGJHQDYVTKFUOMPCIASR!xznlwebgjhqdyvtkfuompciasr'."};
    const string Space = " ";
    string SecretPhrase {};
    string CipherPhrase {};
    string FinalPhrase {};
    
    cout << endl;
    cout << "Please enter your secret phrase." << endl << endl;
    getline(cin, SecretPhrase);
    
    cout << endl;
    
    // Do the cipher and just strip out unsuported characters and spaces
    for (char SecretChar : SecretPhrase)
    {
        if (Key.find(SecretChar) != string::npos)
        {
            CipherPhrase += Key.at(Alphabet.find(SecretChar));
        }        
    }
    
    // Undo the cipher
    for (char CipherChar : CipherPhrase)
    {
        if (Alphabet.find(CipherChar) != string::npos)
        {
            FinalPhrase += Alphabet.at(Key.find(CipherChar));
        }
    }
    
    // Find every occurrence of Space in the SecretPhrase and then insert 
    for (unsigned int index = 0; index < SecretPhrase.length(); index++)
    {
        if (SecretPhrase.substr(index, Space.length()) == Space)
        {
            FinalPhrase.insert(index, Space);
        }
    }
    
    cout << "Secret phrase: " << SecretPhrase << endl;
    cout << "Encrypted phrase: " << CipherPhrase << endl;
    cout << "Decrypted phrase: " << FinalPhrase << endl;
    cout << endl;
    
    return 0;
}