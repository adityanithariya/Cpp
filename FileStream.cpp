#include <iostream>
#include <fstream>

using namespace std;

/*
    File I/O using fstream:
    fstream contains a class named fstreambase from which ifstream, ofstream are derived.
    Usage: 
     - ifstream(Input File Stream - Input from file) for reading files.
     - ofstream(Output File Stream - Input to file) for writing files.
*/

int main()
{
    // ofstream object
    ofstream out;

    // Opening File by Objects
    out.open("sample.txt");

    // Writing to files
    out << "This is a sample file";

    // Closing Pipe to file
    out.close();

    // ifstream object
    ifstream in;
    in.open("sample.txt");

    // String to get content of file
    string content;

    // Reading files
    in >> content;
    cout << content;
    getline(in, content);
    cout << content;

    // Closing Pipe from file
    in.close();

    return 0;
}