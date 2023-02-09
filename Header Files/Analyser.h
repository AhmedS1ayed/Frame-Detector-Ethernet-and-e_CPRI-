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
            
            bool verify = verifyFrame(packet);
            if( verify == false)
            {
                continue;
            }
            BasicFrame* frame = new BasicFrame(packet);
            //call thq process_Frame function to process the packet
            frame->processFrame();
            //check the frame type if it is e-CPRI or Ethernet and do ecpri processing
            frame = checkFrameType(frame);
            //add the output to the outputData string
            outputData += frame->print() + "\n";
            delete(frame);
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
            delete(input);
            newframe->processFrameFull();
            return newframe;
        }
        else if(temp == "Ethernet")
        {
            return input;
        }
        return nullptr;
    }

//-----------------------------------------------------------------------------
    // Verifications :
    bool verifyFrame(string frame)
    {
        bool verify = true;
        int frameLength = frame.length();
        verify = checkLength(frameLength);
        
        if(verify == false)
        {
            outputData += "Length of the frame is not Acceptable \n \n";
            outputData += astricLine();
            return false;
        }

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
        cout<<"length : "<<length <<endl;
        if(  length >= MINIMUM_FRAME_SIZE && length <= MAXIMUM_FRAME_SIZE )
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
    string astricLine()
    {
        return "*******************************************************************************************************************************************************\n";
    }
    ~Analyser()
    {

    }
};