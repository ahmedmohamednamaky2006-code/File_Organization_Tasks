#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    ofstream out("grades.txt");

    if (out.fail())
    {
        cout << "Unable to create the file";
        return 1;
    }

    int grade;
    cout << "Enter 5 integer grades:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> grade;
        out << grade << endl;
    }
    out.close();

    ifstream in("grades.txt");

    if (in.fail())
    {
        cout << "Unable to open the file";
        return 1;
    }

    cout << "Grades in the file:" << endl;
    while (in >> grade)
    {
        cout << grade << endl;
    }
    in.close();

    int toDelete;
    cout << "Enter the grade you want to delete: ";
    cin >> toDelete;

    in.open("grades.txt");
    ofstream temp("temporary.txt");
    int deleted = 0;

    while (in >> grade)
    {
        if (grade != toDelete)
            temp << grade << endl;
        else
            deleted++;
    }
    in.close();
    temp.close();

    if (deleted == 0)
    {
        remove("temporary.txt");
        cout << "Error: grade " << toDelete << " was not found" << endl;
        return 1;
    }

    if (remove("grades.txt") != 0 || rename("temporary.txt", "grades.txt") != 0)
    {
        cout << "Error: could not replace the original file" << endl;
        return 1;
    }

    cout << "Grade " << toDelete << " deleted successfully" << endl;

    in.open("grades.txt");
    cout << "Grades after deletion:" << endl;
    while (in >> grade)
    {
        cout << grade << endl;
    }
    in.close();

    return 0;
}