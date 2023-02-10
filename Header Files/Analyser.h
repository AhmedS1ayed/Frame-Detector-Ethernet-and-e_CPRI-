#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Scanner.h"
#include "BasicFrame.h"
#include "Emitter.h"
using namespace std;


class Analyser
{
    private:
    vector<string> inputData;
    string outputData;
    string packet;
    Scanner scanner;
    Emitter emitter;

    //TODO: add destructor !!
    public:
    Analyser()
    {
        outputData = "";
    }
//-----------------------------------------------------------------------------
    // Analyses :
    void analyse(string inputFile){
        //get the input data
        this->inputData = scanner.scanFile(inputFile);
        //loop through the input data and process each packet
        for (size_t i = 0; i < inputData.size(); i++)
        {
            packet = inputData[i];
            outputData += "Packet #" + to_string(i) + ": \n" + packet + "\n";
            
            //Verifying the packet
            bool verify = verifyFrame(packet);
            if( verify == false)
            {
                continue;
            }

            //instantiate frame
            BasicFrame* frame = new BasicFrame(packet);
            
            //call the process_Frame function to process the packet
            frame->processFrame();
            
            //check the frame type if it is e-CPRI or Ethernet and do ecpri processing
            frame = checkFrameType(frame);
            
            //add the output to the outputData string
            outputData += frame->print() + "\n";
            
            //clean allocated resources
            delete(frame);
            
            //add line at the end of the test case
            outputData += astricLine();
        }
            cout << outputData << endl;
            emitter.emit(outputData);
    }
    BasicFrame* checkFrameType(BasicFrame* input)
    {
        string temp = input->getFrameType();
        if(temp == "e-CPRI")
        {
            EcpriFrame* newframe = new EcpriFrame(input->getFrame(),input->getSource(),input->getDestination(),input->getType(),input->getCRC());
            
            // clean the allocated resources
            delete(input);
            
            newframe->processFrame();

            //return e-CPRI frame object
            return newframe;
        }
        else if(temp == "Ethernet")
        {
            //return Ethernate frame object
            return input;
        }
        return nullptr;
    }

//-----------------------------------------------------------------------------
    // Verifications :
    bool verifyFrame(string frame)
    {
        bool verify = true;

        //verify frame Length :
        int frameLength = frame.length();
        verify = checkLength(frameLength);
        
        if(verify == false)
        {
            outputData += "Length of the frame is not Acceptable \n \n";
            outputData += astricLine();
            return false;
        }

        //verify the format:
        verify = checkFormat(frame);

        if(verify == false)
        {
            outputData += "invalid characters in the frame \n \n";
            outputData += astricLine();
            return false;
        }
        return true;
    }
    bool checkLength(int length)
    {
        if(MINIMUM_FRAME_SIZE <= length && length <= MAXIMUM_FRAME_SIZE)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool checkFormat(string frame)
    {
        for(int i=0; i<frame.length();i++)
        {
            bool character_Checker = characterChecker(frame[i]);
            if (character_Checker == false) 
            {
                return false;
            }
        }
        return true;
    }
    bool characterChecker(char input)
    {
        // it Check if it is not out of range
        if( ('0' <= input) && (input <='9') || ('A' <= input) && (input <= 'F'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Test Separator in print :
    string astricLine()
    {
        return "*******************************************************************************************************************************************************\n";
    }
};