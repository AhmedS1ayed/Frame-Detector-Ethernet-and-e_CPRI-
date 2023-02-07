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
    // FIXME: Refactor this functions
    virtual string Print()
    {
        string temp;
        temp += Print_crc();
        temp += Print_concatination_indicator();
        temp += Print_dst();
        temp += Print_message_type();
        temp += Print_payload_size();
        temp += Print_protocol_version();
        temp += Print_rtc_id();
        temp += Print_seq_id();
        temp += Print_src();
        temp += Print_type();    
        return temp;
    }
    string Print_protocol_version()
    {
        return "Protocol Version: " + protocolVersion + "\n";
    }
    string Print_concatination_indicator()
    {
        return "Concatenation Indicator: " + concatinationBit + "\n";
    }
    string Print_message_type()
    {
        return "Message Type: " + messageType + "\n";
    }
    string Print_payload_size()
    {
        return "Payload Size: " + payloadSize + "\n";
    }
    string Print_rtc_id()
    {
        return "RTC ID: " + rtcId + "\n";
    }
    string Print_seq_id()
    {
        return "Sequence ID: " + seqId + "\n";
    }
};