#include "tsCommon.h"
#include "tsTransportStream.h"

int main(int argc, char *argv[ ], char *envp[ ])
{
  // TODO - open file
  FILE * exFile = fopen("example_new.ts", "rb");
  if(!exFile){printf("Error open file");}


  uint8_t * buff = new uint8_t[xTS::TS_PacketLength];
  xTS_PacketHeader    TS_PacketHeader;

  int32_t TS_PacketId = 0;
  int cou = 0;
  //while(cou < 30)
  while(!feof(exFile))
  {
    cou++;
    // TODO - read from file
    //int size = fread(buff, 1, xTS::TS_PacketLength, exFile);

    TS_PacketHeader.Reset();
    TS_PacketHeader.Parse(buff);

    printf("%010d ", TS_PacketId);
    TS_PacketHeader.Print();
    printf("\n");

    TS_PacketId++;
  }
  printf("hii");
  return 0;
}