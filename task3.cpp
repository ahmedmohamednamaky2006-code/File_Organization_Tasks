#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("welcome.txt");

    if (!outFile) {
        cout << "Error: could not create welcome.txt" << endl;
        return 1;
    }

    outFile << "Hello Everybody" << endl;
    outFile.close();

    ifstream inFile("welcome.txt");

    if (!inFile) {
        cout << "Error: could not open welcome.txt" << endl;
        return 1;
    }

    string text;
    getline(inFile, text);
    inFile.close();

    size_t pos = text.find("body");
    if (pos != string::npos) {
        text.replace(pos, 4, "one");
    }

    ofstream result("welcome.txt");
    result << text << endl;
    result.close();

    cout << text << endl;

    return 0;
}