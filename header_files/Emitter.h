#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/*
    Emitter class to write the output data to a file
*/
class Emitter{

    private:
    string outputFile;
    ofstream file;
    
    public:
    Emitter()
    {
        outputFile = "output_packets";
        file.open(outputFile);
    }

    bool emit(string outputData)
    {
        if(!file.is_open())
        {
            cout<<"Error opening file"<<endl;
            exit(1);
        }
        file << outputData << endl;
        return true;
    }

    ~Emitter()
    {
        file.close();
    }
};