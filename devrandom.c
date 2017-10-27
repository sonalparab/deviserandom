#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

// /dev/random

int randnum(){ 
  int f = open("/dev/random",O_RDONLY);
  int *buff = malloc(sizeof(int));
  read(f, buff, sizeof(buff));
  int num = *buff;
  free(buff);
  close(f);
  return num;
}

int main(){
  /*printf("num: %d\n",randnum());
  printf("num: %d\n",randnum());
  printf("num: %d\n",randnum());
  printf("num: %d\n",randnum());
  */
  int nums[10];
  int i;
  for(i = 0; i < 10; i++){
    nums[i] = randnum();
    printf("num[%d] = %d\n",i,nums[i]);
  }
  
}
