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
    //Default Constructor
    EcpriFrame(string frame)
    {
        setFrame(frame);
    };
    //Full Frame Constructor
    EcpriFrame(string fr,string s , string d , string t , string cr ) : BasicFrame(fr,s , d , t ,cr)
    {
        processFrame();
    };
//----------------------------------------------------
    // Setters and Getters :

//----------------------------------------------------
    //Processing The Frame :
    void processFrameFull()
    {
        BasicFrame::processFrame();
        processFrame();
    }
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
        // check it it even or odd
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
    virtual void Print()
    {
        Print_crc();
        Print_concatination_indicator();
        Print_dst();
        Print_message_type();
        Print_payload_size();
        Print_protocol_version();
        Print_rtc_id();
        Print_seq_id();
        Print_src();
        Print_type();    
    }
    void Print_protocol_version()
    {
        cout<<"Protocol Version: "<< protocolVersion + "\n";
    }
    void Print_concatination_indicator()
    {
        cout<<"Concatenation Indicator: "<< concatinationBit + "\n";
    }
    void Print_message_type()
    {
        cout<<"Message Type: "<< messageType + "\n";
    }
    void Print_payload_size()
    {
        cout<<"Payload Size: "<< payloadSize + "\n";
    }
    void Print_rtc_id()
    {
        cout<<"RTC ID: "<< rtcId + "\n";
    }
    void Print_seq_id()
    {
        cout<<"Sequence ID: "<< seqId + "\n";
    }
};