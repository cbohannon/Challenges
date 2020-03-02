#include <iostream>

using namespace std;

int CalculateChange(int InputAmount)
{
    unsigned int CurrentRemainder = {0};
    
    // Initialized values in cents
    unsigned const int Dollar = {100};
    unsigned const int Quarter = {25};
    unsigned const int Dime = {10};
    unsigned const int Nickel = {5};
    unsigned const int Penny = {1};    
    
    // Start with dollar (1: Get the remainder 2: Subtract remainder from InputAmount 3: Divide the difference by constant dollar 4: Output result)
    CurrentRemainder = InputAmount % Dollar;
    InputAmount -= CurrentRemainder;
    InputAmount  /= Dollar;
    cout << "Dollars: " <<  InputAmount << endl;
    
    // Move to quarter (1: Reset the input amount to the previous remainder 2: Get a new remainder 3: Divide InputAmount by constant Quarter 4: Output result)
    InputAmount = CurrentRemainder;
    CurrentRemainder = InputAmount % Quarter;
    InputAmount /= Quarter;
    cout << "Quarters: " << InputAmount << endl;
    
    // Move to dime (1: Reset the input amount to the previous remainder 2: Get a new remainder 3: Divide InputAmount by constant Dime 4: Output result)
    InputAmount = CurrentRemainder;
    CurrentRemainder = InputAmount % Dime;
    InputAmount /= Dime;
    cout << "Dimes: " << InputAmount <<endl;
    
    // Move to nickel (1: Reset the input amount to the previous remainder 2: Get a new remainder 3: Divide InputAmount by constant Nickel 4: Output result)
    InputAmount = CurrentRemainder;
    CurrentRemainder = InputAmount % Nickel;
    InputAmount /= Nickel;
    cout << "Nickles: " << InputAmount << endl;
    
    // Move to penny (1: Reset the input amount to the previous remainder 2: Get a new remainder 3: Divide InputAmount by constant Penny 4: Output result)
    InputAmount = CurrentRemainder;
    CurrentRemainder = InputAmount % Penny;
    InputAmount /= Penny;
    cout << "Pennies: " << InputAmount << endl;
    
    cout << endl << endl;
    
    return 0;
}

int main()
{
    unsigned int UserEnteredAmount = {0};
    
    cout << "Enter an amount in cents: ";    
    cin >> UserEnteredAmount;
    
    // Just a quick check to make sure we have good values to start with
    if (UserEnteredAmount < 0 || UserEnteredAmount >= 100000)
    {
        cout << "Please enter a value great than 0 or less than or equal to 1000000"<< endl << endl;
        return 0;
    }            
    cout << "Change can be provided as follows:" << endl;
    
    CalculateChange(UserEnteredAmount);
    
    return 0;
}