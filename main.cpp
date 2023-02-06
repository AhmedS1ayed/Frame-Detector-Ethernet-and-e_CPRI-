#include"./Header Files/Basic_Frame.h"
#include"./Header Files/ecpri_Frame.h"
#include"./Header Files/Ethernet_Frame.h"

Basic_Frame* Frame_type_object(Basic_Frame* input)
{
        if(input->Frame_type() == "e-CPRI")
        {
            ecpri_Frame* new_frame = new ecpri_Frame(input->get_source(),input->get_destination(),input->get_type(),input->get_crc());
            return new_frame;
        }
        else if(input->Frame_type() == "Ethernet")
        {
            Ethernet_Frame* new_frame = new Ethernet_Frame(input->get_source(),input->get_destination(),input->get_type(),input->get_crc());
            return new_frame;
        }
}

int main()
{
    Basic_Frame a("0","0","0","0","0","0");
    a.Print();
    return 0;
}