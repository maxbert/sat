#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void sizechange(int size){
  if (size>1000){
    printf("%d KB\n", size/1000.0);
  }else if(size>1000000){
    printf("%d MB\n", size/1000000.0);
  }else if(size>1000000000){
    printf("%d GB\n", size/1000000000.0);
  }else{
    printf("%d B\n", size);
  }
}

int main(){
  struct stat n;
  stat("stat.c", &n);
  printf(" size - %d\n mode - %o\n time - %s\n",n.st_size, n.st_mode, asctime(gmtime(&(n.st_atime))));
  return 0;
}
