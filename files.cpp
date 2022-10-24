#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string text;
    ifstream Myfile("files.txt");
    ofstream Mile("files.txt");

    Mile << "Hello enw line";

    while (getline(Myfile, text))
    {
        cout << text;
    }
    Myfile.close();
}