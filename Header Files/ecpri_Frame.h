#pragma once
#include "../Configration Files/Ecpri_Frame_config.h"
#include"Basic_Frame.h"
class ecpri_Frame : public Basic_Frame
{
    string protocol_version;
    string concatination_byte;
    string concatination_bit;
    string message_type;
    string payload_size;
    string rtc_id;
    string seq_id;

    public:
    //Default Constructor
    ecpri_Frame(string frame)
    {
        set_Frame(frame);
        process_Frame_full();
    };
    //Full Frame Constructor
    ecpri_Frame(string fr,string s , string d , string t , string cr ) : Basic_Frame(fr,s , d , t ,cr)
    {
        process_Frame();
    };
//----------------------------------------------------
    // Setters and Getters :

//----------------------------------------------------
    //Processing The Frame :
    void process_Frame_full()
    {
        Basic_Frame::process_Frame();
        process_Frame();
    }
    void process_Frame()
    {
        process_protocol_version();
        process_concatination_byte();
        process_message_type();
        process_payload_size();
        process_rtc_id();
    }

    // Details :
    void process_protocol_version()
    {
        protocol_version = get_Frame().substr(PROTOCOL_REVISION_INDEX , PROTOCOL_REVISION_SIZE);
    }
    void process_concatination_byte()
    {
        concatination_byte = get_Frame().substr(CONCATENATION_INDICATOR_BYTE_INDEX,CONCATENATION_INDICATOR_BYTE_SIZE);

        switch(concatination_byte[0])
        {
            case '0':
                concatination_bit = '0';
                break;
            case '1':
                concatination_bit = '1';
                break;
            case '2':
                concatination_bit = '0';
                break;
            case '3':
                concatination_bit = '1';
                break;
            case '4':
                concatination_bit = '0';
                break;
            case '5':
                concatination_bit = '1';
                break;
            case '6':
                concatination_bit = '0';
                break;
            case '7':
                concatination_bit = '1';
                break;
            case '8':
                concatination_bit = '0';
                break;
            case '9':
                concatination_bit = '1';
                break;
            case 'A':
            case 'a':
                concatination_bit = '0';
                break;
            case 'B':
            case 'b':
                concatination_bit = '1';
                break;
            case 'C':
            case 'c':
                concatination_bit = '0';
                break;
            case 'D':
            case 'd':
                concatination_bit = '1';
                break;
            case 'E':
            case 'e':
                concatination_bit = '0';
                break;
            case 'F':
            case 'f':
                concatination_bit = '1';
                break;
        }
    }
    void process_message_type()
    {
        message_type = get_Frame().substr(MESSAGE_TYPE_INDEX,MESSAGE_TYPE_SIZE);
    }
    void process_payload_size()
    {
        payload_size = get_Frame().substr(PAYLOAD_SIZE_INDEX,PAYLOAD_SIZE_SIZE);
    }
    void process_rtc_id()
    {
        rtc_id = get_Frame().substr(RTC_ID_INDEX,RTC_ID_SIZE);
    }
    void process_seq_id()
    {
        rtc_id = get_Frame().substr(SEQUENCE_ID_INDEX,SEQUENCE_ID_SIZE);
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
        cout<<"Protocol Version: "<< protocol_version + "\n";
    }
    void Print_concatination_indicator()
    {
        cout<<"Concatenation Indicator: "<< concatination_bit + "\n";
    }
    void Print_message_type()
    {
        cout<<"Message Type: "<< message_type + "\n";
    }
    void Print_payload_size()
    {
        cout<<"Payload Size: "<< payload_size + "\n";
    }
    void Print_rtc_id()
    {
        cout<<"RTC ID: "<< rtc_id + "\n";
    }
    void Print_seq_id()
    {
        cout<<"Sequence ID; "<< seq_id + "\n";
    }
};