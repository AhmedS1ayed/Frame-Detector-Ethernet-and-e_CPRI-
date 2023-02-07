#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/*
    Scanner class to read the input file and return the data as a string
*/
class Scanner 
{
    private: 
    string inputFile;
    

    public:
    Scanner(string inputFile)
    {
        this->inputFile = inputFile;
    }

    vector<string> scanFile()
    {
        string line;
        ifstream file;
        vector<string> inputData;
        file.open(this->inputFile);
        if(!file.is_open())
        {
            cout<<"Error opening file"<<endl;
            exit(1);
        }
        while(getline(file,line))
        {
            inputData.push_back(line);
        }
        file.close();
        return inputData;
    }

};
