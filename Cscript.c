#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <stdlib.h>


unsigned int readI2CRegister16bit(int addr, int reg) {
  wiringPiI2CWrite(addr,reg);
  delay(20);
  unsigned int t = wiringPiI2CReadReg8(addr,reg);
  return t;
}


void main() {
  int dID = 0x20;
  int fd;
  if((fd=wiringPiI2CSetup(dID))<0){
  printf("error opening i2c channel\n\r");
  }

  wiringPiI2CWrite(dID,6);




  printf(readI2CRegister16bit(dID, 0)); //read capacitance register
  printf(", ");
  printf(readI2CRegister16bit(dID, 5)); //temperature register
  printf(", ");
  wiringPiI2CWrite(dID,3); //request light measurement 
  printf(readI2CRegister16bit(dID, 4)); //read light register
}