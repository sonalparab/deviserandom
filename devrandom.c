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

  //Generate random number array
  int nums[10];
  int i;
  printf("Generating random numbers:\n");
  for(i = 0; i < 10; i++){
    nums[i] = randnum();
    printf("\trandom %d: %d\n",i,nums[i]);
  }

  //Creating the file
  int r = open("randomnums",O_CREAT|O_WRONLY,0666);
  printf("\nWriting numbers to file...\n");
  //Write the numbers to the file
  write(r,nums,sizeof(nums));
  close(r);

  //Read the numbers from the file and put them in a new array
  int rnums[10];
  int rr = open("randomnums",O_RDONLY,0666);
  printf("\nReading numbers from file...\n\n");
  read(r,rnums,sizeof(rnums));

  //Print the numbers in the new array
  printf("Verification that written values were the same:\n");
  for(i = 0; i < 10; i++){
    printf("\trandom %d: %d\n",i,rnums[i]);
  }
  
  
}
