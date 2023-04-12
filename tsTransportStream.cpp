#include "tsTransportStream.h"
#include<iostream>
using namespace std;
//=============================================================================================================================================================================
// xTS_PacketHeader
//=============================================================================================================================================================================
void xTS_PacketHeader::Reset()
{
  //write me
}
int32_t xTS_PacketHeader::Parse(const uint8_t* Input)
{
  uint32_t temp = *((uint32_t*) Input);

  Sync_byte                     = Input[0];                  
  Transport_error_indicator     = Input[1] & 0b10000000;
  Transport_error_indicator     >>= 7;

  Payload_unit_start_indicator  = Input[1] & 0b01000000;
  Payload_unit_start_indicator  >>= 6;

  Transport_priority            = Input[1] & 0b00100000;
  Transport_priority            >>= 5;
           
  Packet_Identifier             = Input[1] & 0b00011111;      
  Packet_Identifier             <<= 8;
  Packet_Identifier             +=Input[2]; 

  Transport_scrambling_control  = Input[3] & 0b11000000;
  Transport_scrambling_control  >>= 6;


  Adaptation_field_control      = Input[3] & 0b00110000; 
  Adaptation_field_control      >>= 4;
  Continuity_counter            = Input[3] & 0b00001111; 

  //cout<< (long int)Packet_Identifier<<endl;



  //int32_t hi = 3;  
  return temp;  
}
void xTS_PacketHeader::Print() const
{
  printf("TS: SB=%d E=%d S=%d P=%d PID=%4d TSC=%d AF=%d CC= %d", Sync_byte, Transport_error_indicator, Payload_unit_start_indicator,
    Transport_priority, Packet_Identifier, Transport_scrambling_control, Adaptation_field_control, Continuity_counter);
}

//=============================================================================================================================================================================
