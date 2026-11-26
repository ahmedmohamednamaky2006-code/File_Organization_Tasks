#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "How many persons do you want to add? ";
    cin >> n;
    cin.ignore();

    if (n <= 0) {
        cout << "Invalid number of persons." << endl;
        return 1;
    }

    ofstream outFile("persons.txt");

    if (!outFile) {
        cout << "Error: could not create persons.txt" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        string name;
        int age;

        cout << "Enter name of person " << i + 1 << ": ";
        getline(cin, name);

        cout << "Enter age of person " << i + 1 << ": ";
        cin >> age;
        cin.ignore();

        outFile << name << "," << age << endl;
    }
    outFile.close();

    ifstream inFile("persons.txt");

    if (!inFile) {
        cout << "Error: could not open persons.txt" << endl;
        return 1;
    }

    vector<Person> persons;
    Person p;

    while (getline(inFile, p.name, ',') && inFile >> p.age) {
        inFile.ignore();
        persons.push_back(p);
    }
    inFile.close();

    if (persons.empty()) {
        cout << "No data found in the file." << endl;
        return 1;
    }

    Person youngest = persons[0];
    Person oldest = persons[0];

    for (size_t i = 1; i < persons.size(); i++) {
        if (persons[i].age < youngest.age) {
            youngest = persons[i];
        }
        if (persons[i].age > oldest.age) {
            oldest = persons[i];
        }
    }

    ofstream results("results.txt");

    if (!results) {
        cout << "Error: could not create results.txt" << endl;
        return 1;
    }

    results << "Youngest person: " << youngest.name << ", " << youngest.age << endl;
    results << "Oldest person: " << oldest.name << ", " << oldest.age << endl;
    results.close();

    cout << "Done. Results saved in results.txt" << endl;

    return 0;
}