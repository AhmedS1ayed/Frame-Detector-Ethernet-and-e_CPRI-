#include"./Header Files/Basic_Frame.h"
#include"./Header Files/ecpri_Frame.h"
#include"./Header Files/Ethernet_Frame.h"
#include"./Configration Files/Ecpri_Frame_config.h"

// Basic_Frame* Frame_type_object(Basic_Frame* input)
// {
//         if(input->Frame_type() == "e-CPRI")
//         {
//             ecpri_Frame* new_frame = new ecpri_Frame(input->get_Frame(),input->get_source(),input->get_destination(),input->get_type(),input->get_crc());
//             return new_frame;
//         }
//         else if(input->Frame_type() == "Ethernet")
//         {
//             return input;
//         }
// }

int main()
{
    Basic_Frame* a = new ecpri_Frame("FB555555555555D50000000000C1ECCD655507D9AEFE1002001480680180900000400101D10000100000FFFE7E040000000000000000000000000000000000000000000099AC762B");
    a->Print();
    //a = Frame_type_object(a);
    //a->Print();
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