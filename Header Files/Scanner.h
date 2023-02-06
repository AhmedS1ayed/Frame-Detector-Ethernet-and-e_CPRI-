#pragma once


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
    Scanner class to read the input file and return the data as a string
*/
class Scanner 
{
    private: 
    string inputFile;
    string inputData;

    public:
    Scanner(string inputFile)
    {
        this->inputFile = inputFile;
    }

    string scanFile()
    {
        ifstream file;
        file.open(this->inputFile);
        string line;
        if(!file.is_open())
        {
            cout<<"Error opening file"<<endl;
            return "";
        }
        while(getline(file,line))
        {
            inputData += line;
        }
        file.close();
        return inputData;
    }

};
