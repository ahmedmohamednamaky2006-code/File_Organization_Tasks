#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inFile("fruit.txt");

    if (!inFile)
    {
        cout << "Error: could not open fruit.txt" << endl;
        return 1;
    }

    char ch;
    char last = '\n';
    while (inFile.get(ch))
    {
        cout << ch;
        last = ch;
    }
    inFile.close();

    ofstream outFile("fruit.txt", ios::app);

    if (!outFile)
    {
        cout << "Error: could not write to fruit.txt" << endl;
        return 1;
    }

    if (last != '\n')
    {
        outFile << endl;
    }
    outFile << "Fresh Fruits" << endl;
    outFile.close();

    return 0;
}