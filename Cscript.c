#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


unsigned int readI2CRegister16bit(int addr, int reg) {
  wiringPiI2CWrite(addr,reg);
  sleep(1);
  unsigned int t = wiringPiI2CReadReg8(addr,reg);
  return t;
}


void main(void) {
  int dID = 0x20;
  int fd;
  if((fd=wiringPiI2CSetup(dID))<0){
  printf("error opening i2c channel\n\r");
  }

  wiringPiI2CWrite(fd,6);




  unsigned int cap = readI2CRegister16bit(fd, 0); //read capacitance register
  printf ("Capacitance = ");
  printf("%u",cap);

  printf(", ");

  unsigned int temp = readI2CRegister16bit(fd, 5); //temperature register
  printf ("Temperature = ");
  printf("%u",temp);

  printf(", ");
  wiringPiI2CWrite(fd,3); //request light measurement 

  unsigned int light = readI2CRegister16bit(fd, 4); //read light register
  printf ("Temperature = ");
  printf("%u",light);
}