#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vector1;
    vector <int> vector2;
    
    vector1.push_back(10);
    vector1.push_back(20);
    
    for (int CurrentElement : vector1) 
    {
        cout << "Current element value: " << CurrentElement << endl;
    }
    cout << "vector1 size: " << vector1.size() << endl;
    
    vector2.push_back(100);
    vector2.push_back(200);
    
    for (int CurrentElement : vector2)
    {
        cout << "Current element value: " << CurrentElement << endl;
    }
    cout << "vector2 size: " << vector2.size() << endl;
    
    vector <vector<int>> vector_2d;
    // vector < vector<int> >::iterator row;
    // vector <int>::iterator col;
    
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    cout << "\nvector_2d:" << endl;
    cout << vector_2d.at(0).at(0) << "  " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << "  " << vector_2d.at(1).at(1) << endl;
    
    vector1.at(0) = 1000;
    
    cout << "\nvector_2d:" << endl;
    cout << vector_2d.at(0).at(0) << "  " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << "  " << vector_2d.at(1).at(1) << endl;
    
    cout << "\nvector1: " << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "vector1 contains " << vector1.size() << " elements" << endl;
    /*
    for (unsigned int index = 0; index < vector_2d.size(); index++)
    {
            cout << "Current row and column: " << vector_2d.at(index).at(index) << endl;
    }
    
    vector1.at(0) = 1000;
    
    for (unsigned int index = 0; index < vector_2d.size(); index++)
    {
            cout << "Current row and column: " << vector_2d.at(index).at(index) << endl;
    }
    */
    
    /*
    for (row = vector_2d.begin(); row != vector_2d.end(); row++)
    {
        for (col = row->begin(); col != row->end(); col++)
            {
                // cout << "Current row: " << vector_2d << endl;
                cout << "Current column: " << *col << endl;
            }
    }
     */
    
    /*
    vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
    vowels.at
    for (char CurrentVowel : vowels)
    {
        cout << CurrentVowel << endl;
    }

    vowels.push_back('y');
    
    cout << vowels.size() << endl;;    
    cout << vowels.at(vowels.size() - 1) << endl;
    */
    return 0;
}