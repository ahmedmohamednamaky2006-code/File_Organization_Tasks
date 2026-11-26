#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    char name[20];
    int id;
    float grade;
    char delim;
};

int main()
{
    ofstream file("students.txt", ios::app);

    if (!file)
    {
        cout << "Error: could not open students.txt" << endl;
        return 1;
    }

    char choice;

    do
    {
        Student s;

        cout << "Enter student name: ";
        cin.getline(s.name, 20);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter student ID: ";
        cin >> s.id;

        cout << "Enter student grade: ";
        cin >> s.grade;

        s.delim = '$';

        file << s.name << ", " << s.id << ", " << s.grade << " " << s.delim << endl;

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
        cin.ignore(1000, '\n');

    } while (choice == 'y' || choice == 'Y');

    file.close();

    cout << "Records saved in students.txt" << endl;

    return 0;
}