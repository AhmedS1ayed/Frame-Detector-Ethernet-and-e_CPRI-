#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Scanner.h"
#include "Basic_Frame.h"
using namespace std;


class Analyser
{
    private:
    vector<string> inputData;
    string packet;

    public:
    Analyser()
    {
    }

    void analyse(string inputFile){
        //get the input data
        Scanner scanner(inputFile);
        this->inputData = scanner.scanFile();
        //loop through the input data and process each packet
        for (size_t i = 0; i < inputData.size(); i++)
        {
            packet = inputData[i];
            Basic_Frame* frame = new Basic_Frame(packet);
            frame = Frame_type_object(frame);
            
            if(frame == nullptr) 
                return;
            
            cout <<"Packet #"<<i<<": " << endl;
            cout << packet << endl;
            frame->Print();
            delete(frame);
            cout << "*******************************************************************************************************************************************************" << endl;
        }
    }

    Basic_Frame* Frame_type_object(Basic_Frame* input)
    {
        if(input->Frame_type() == "e-CPRI")
        {
            ecpri_Frame* new_frame = new ecpri_Frame(input->get_Frame(),input->get_source(),input->get_destination(),input->get_type(),input->get_crc());
            return new_frame;
        }
        else if(input->Frame_type() == "Ethernet")
        {
            return input;
        }
        else
        {
            return nullptr;
        }
    }


};