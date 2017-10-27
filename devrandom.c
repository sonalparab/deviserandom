#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

// /dev/random

int rand(){
  int f = open("/dev/random","O_RDONLY",0555);
  void *b = malloc(sizeof(int));
  int num = read(f,b,8);
  return num;
}

int main(){
  printf("num: %d\n",rand());

}
