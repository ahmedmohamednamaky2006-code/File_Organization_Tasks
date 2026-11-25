#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fullName;
    string id;
    double grade;

    cout << "Enter student's full name: ";
    getline(cin, fullName);

    cout << "Enter student's ID: ";
    cin >> id;

    cout << "Enter student's grade: ";
    cin >> grade;

    ofstream file("Student.txt");

    if (!file)
    {
        cout << "Error: could not create the file." << endl;
        return 1;
    }

    file << "Full Name: " << fullName << endl;
    file << "ID: " << id << endl;
    file << "Grade: " << grade << endl;

    file.close();

    cout << "Data saved successfully in Student.txt" << endl;
    return 0;
}
