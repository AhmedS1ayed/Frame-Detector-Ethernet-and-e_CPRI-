#include"./Header Files/Basic_Frame.h"
#include"./Header Files/ecpri_Frame.h"
#include"./Header Files/Ethernet_Frame.h"
#include "./Header Files/Analyser.h"

int main()
{
    Analyser analyser;
    analyser.analyse("input_packets");

    return 0;
}




    // FB555555555555D50000000000C1ECCD655507D9AEFE1002001480680180900000400101D10000100000FFFE7E040000000000000000000000000000000000000000000099AC762B
    // CRC: 99AC762B
    // Concatenation Indicator: 0
    // Destination Address: 0000000000C1
    // Message Type: 02
    // Payload Size: 0014
    // Protocol Version: 1
    // RTC ID: 8068
    // Sequence ID: 0180
    // Source Address: ECCD655507D9
    // Type: AEFE


    // string input = "FB555555555555D50000000000C1ECCD655507D9AEFE1002001480680180900000400101D10000100000FFFE7E040000000000000000000000000000000000000000000099AC762B";
    // cout<<"protocol revision : "<<input.substr(PROTOCOL_REVISION_INDEX , PROTOCOL_REVISION_SIZE) + "\n";
    // cout<<"concatenation indicator byte : " <<input.substr(CONCATENATION_INDICATOR_BYTE_INDEX,CONCATENATION_INDICATOR_BYTE_SIZE) + "\n";
    // cout<<"Message Type : " <<input.substr(MESSAGE_TYPE_INDEX,MESSAGE_TYPE_SIZE) + "\n";
    // cout<<"Payload Size : " <<input.substr(PAYLOAD_SIZE_INDEX,PAYLOAD_SIZE_SIZE) + "\n";
    // cout<<"RTC ID : " <<input.substr(RTC_ID_INDEX,RTC_ID_SIZE) + "\n";
    // cout<<"Sequence ID : " <<input.substr(SEQUENCE_ID_INDEX,SEQUENCE_ID_SIZE) + "\n";