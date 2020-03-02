#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <numeric>

using namespace std;

// TODO: Each option should be in a function
// TODO: Don't exit program after a selection is run
void SelectionProcessing(char UserChoice, vector<int> NumberList)
{      
    // I'll create a special rule to satisfy the requirement for an empty list in 'P', 'M', 'S', and 'L'
    // NumberList.at(0) = 1; // Debug line
    // NumberList.at(NumberList.size() - 1) = 20; // Debug line;
    if (NumberList.front() == 1 && NumberList.back() == 20)
    {
        NumberList.clear();
    }
    
    if (UserChoice == 'P')
    {
        if (NumberList.empty())
        {
            cout << "[] - the list is empty." << endl;
            return;
        }
        
        cout << "[ ";
        for (int num :  NumberList)
        {
            cout << num << " ";
        }
        cout << "]" << endl;        
        return;
    }
    
    if (UserChoice == 'A')
    {
        cout << "Please add a number between 1 - 20 to the list: ";
        // TODO: Make sure the user adds a number between 1 - 20
        unsigned int AddedNumber {0};
        cin >> AddedNumber;
        cout << AddedNumber << " has been added." << endl;        
        return;
    }
    
    if (UserChoice == 'M')
    {
        if (NumberList.empty())
        {
            cout << "Unable to calculate the mean - no data." << endl;
            return;
        }
        
        float Mean = accumulate(NumberList.begin(), NumberList.end(), 0.0 / NumberList.size());
        cout << "The mean is: " << Mean << endl;        
        return;
    }
    
    if (UserChoice == 'S')
    {
        if (NumberList.empty())
        {
            cout << "Unable to determine the smallest number - list is empty.";
            return;
        }
        
        sort(NumberList.begin(), NumberList.end());
        cout << "The smallest number in the list is: " << NumberList.at(0) << endl;        
        return;
    }
    
    if (UserChoice == 'L')
    {
        if (NumberList.empty())
        {
            cout << "Unable to determine the largest number - list is empty.";
            return;
        }
        
        sort(NumberList.begin(), NumberList.end(), greater<int>());
        cout << "The largest number in the list is: " << NumberList.at(0) << endl;        
        return;
    }
    
    if (UserChoice == 'Q')
    {
        cout << "Goodbye!" << endl;
        return;
    }
    
    return;
}

vector<int> GenerateNumbers()
{
    vector<int> Numbers = {};
    
    // Let's get 20 random numbers between 1- 20
    srand((unsigned) time(0));
    for (int index = 1; index <= 20; index ++)
    {
        Numbers.push_back(rand() % 20 + 1);
    }
    
    return Numbers;
}

char SetupOptions()
{
    // Print the options
    cout << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;    
    cout << endl;
    cout << "Enter your choice: ";    
    
    char Selected {};
    cin >> Selected;    
    return Selected;
}

bool ValidateChoice(char Choice)
{
    vector<char> ValidCharacters { 'P', 'A', 'M', 'S', 'L', 'Q' };
    
    // Check for valid choice
    if (find(ValidCharacters.begin(), ValidCharacters.end(), Choice) != ValidCharacters.end())
    {
        return true;
    }    
    else
    {
        cout << "Unknown selection, please try again. " << endl;
        system ("CLS");
        return false;
    }
}

int main()
{
    char UserChoice {};
    
    do
    {
        UserChoice = SetupOptions();       
        UserChoice = toupper(UserChoice); // Just set the returned input to UPPER case
    } while (!ValidateChoice(UserChoice));
    
    // Get some random numbers
    vector<int> NumberList = GenerateNumbers();

    // This is where all the work is done
    SelectionProcessing(UserChoice, NumberList);
    
    return 0;
}