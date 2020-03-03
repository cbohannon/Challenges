#include <iostream>
#include <string>

using namespace std;

int main()
{
    string Letters{};

    cout << "Enter a string of letters so I can create a Letter Pyramid from it: ";
    getline(cin, Letters);

    size_t LetterCount = Letters.length();
    size_t Position {0};

    // for each letter in the string
    for (char CurrentLetter : Letters)
    {
        size_t SpacesCount = LetterCount - Position;
        while (SpacesCount > 0)
        {
            cout << " ";
            --SpacesCount;
        }

        // Display in order up to the current character
        for (size_t Index = 0; Index < Position; Index++)
        {
            cout << Letters.at(Index);
        }

        // Display the current 'center' character
        cout << CurrentLetter;

        // Display the remaining characters in reverse order
        for (int Index = Position-1; Index >= 0; --Index)
        {
            auto CastedIndex = static_cast<size_t>(Index);
            cout << Letters.at(CastedIndex);
        }

        cout << endl; // Don't forget the end line
        ++Position;
    }

    return 0;
}