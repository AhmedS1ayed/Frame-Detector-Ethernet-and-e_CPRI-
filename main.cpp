#include"./Header Files/Basic_Frame.h"
#include"./Header Files/ecpri_Frame.h"
#include"./Header Files/Ethernet_Frame.h"
#include "./Header Files/Analyser.h"


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
}

int main()
{
    Analyser analyser;
    analyser.analyse("input_packets");

    return 0;
}