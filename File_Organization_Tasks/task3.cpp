#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file("welcome.txt", ios::out);

    if (!file.is_open())
    {
        cout << "Error: could not create welcome.txt" << endl;
        return 1;
    }

    file << "Hello Everybody";
    file.close();

    file.open("welcome.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error: could not open welcome.txt" << endl;
        return 1;
    }

    string text;
    getline(file, text);
    file.close();

    size_t pos = text.find("body");
    if (pos != string::npos)
    {
        text.replace(pos, 4, "one");
    }

    file.open("welcome.txt", ios::out | ios::trunc);
    file.seekp(0, ios::beg);
    file << text;
    file.close();

    cout << text << endl;

    return 0;
}