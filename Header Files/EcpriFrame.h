#pragma once
#include "../Configration Files/Ecpri_Frame_config.h"
#include"BasicFrame.h"
class EcpriFrame : public BasicFrame
{
    private:
    string protocolVersion;
    string concatinationByte;
    string concatinationBit;
    string messageType;
    string payloadSize;
    string rtcId;
    string seqId;

    public:
    //Default Constructor : this is Special Constructor made in case you want to instantiate Ecpriframe immediatly frome frame
    EcpriFrame(string frame)
    {
        setFrame(frame);
    };
    //Full Frame Constructor : it is optimized constructor used to copy pre-determined arguement
    EcpriFrame(string frame , string source , string dest , string type , string crc ) : BasicFrame(frame , source , dest , type , crc)
    {
    };

//----------------------------------------------------
    //Processing The Frame :
    
    //This is Special Constructor made in case you want to instantiate Ecpriframe immediatly frome frame
    void processFrameFull()
    {
        BasicFrame::processFrame();
        processFrame();
    }
    
    //This Process just the remaining part of the frame:
    void processFrame()
    {
        processProtocolVersion();
        processConcatinationByte();
        processMessageType();
        processPayloadSize();
        processRtcId();
        processSeqId();
    }

    // Details :
    void processProtocolVersion()
    {
        protocolVersion = getFrame().substr(PROTOCOL_REVISION_INDEX , PROTOCOL_REVISION_SIZE);
    }
    void processConcatinationByte()
    {
        concatinationByte = getFrame().substr(CONCATENATION_INDICATOR_BYTE_INDEX,CONCATENATION_INDICATOR_BYTE_SIZE);
        // convert hex to decimal 
        int decimalConcatinationByte = stoi(concatinationByte, 0, 16);
        // check if it is even or odd
        if(decimalConcatinationByte % 2 == 0)
        {
            concatinationBit = "0";
        }
        else
        {
            concatinationBit = "1";
        }
        
    }
    void processMessageType()
    {
        messageType = getFrame().substr(MESSAGE_TYPE_INDEX,MESSAGE_TYPE_SIZE);
    }
    void processPayloadSize()
    {
        payloadSize = getFrame().substr(PAYLOAD_SIZE_INDEX,PAYLOAD_SIZE_SIZE);
    }
    void processRtcId()
    {
        rtcId = getFrame().substr(RTC_ID_INDEX,RTC_ID_SIZE);
    }
    void processSeqId()
    {
        seqId = getFrame().substr(SEQUENCE_ID_INDEX,SEQUENCE_ID_SIZE);
    }
//----------------------------------------------------
    //Printers :
    virtual string print()
    {
        string temp;
        temp += printCrc();
        temp += printConcatinationIndicator();
        temp += printDest();
        temp += printMessageType();
        temp += printPayloadSize();
        temp += printProtocolVersion();
        temp += printRtcId();
        temp += printSeqID();
        temp += printSource();
        temp += printType();   
        return temp;
    }
    string printProtocolVersion()
    {
        return "Protocol Version: " + protocolVersion + "\n";
    }
    string printConcatinationIndicator()
    {
        return "Concatenation Indicator: " + concatinationBit + "\n";
    }
    string printMessageType()
    {
        return "Message Type: " + messageType + "\n";
    }
    string printPayloadSize()
    {
        return "Payload Size: " + payloadSize + "\n";
    }
    string printRtcId()
    {
        return "RTC ID: " + rtcId + "\n";
    }
    string printSeqID()
    {
        return "Sequence ID: " + seqId + "\n";
    }
};