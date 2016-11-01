#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void sizechange(long size){
  if (size>1000){
    printf(" %.2f KB\n", size/1000.0);
  }else if(size>1000000){
    printf(" %.2f MB\n", size/1000000.0);
  }else if(size>1000000000){
    printf(" %.2f GB\n", size/1000000000.0);
  }else{
    printf(" %.2f B\n", size);
  }
}

char* readperm(int permissions){
  int new = permissions%512;
  int *x = &new;
  char *a = malloc(9);
  int i = 0;
  while (i < 9){
    a[i] = '-';
    i++;
  }
  i= 0;
  while(i<9){
    if(*x){
      a[i] = 'r';
    }
    i +=3;
    x += 3;
  }
  i = 1;
  x = &new;
  while (i<9){
    if(*x){
      a[i] = 'w';
    }
    i +=3;
    x += 3;
  }
  i = 2;
  x = &new;

  while (i<9){
    if(*x){
      a[i] ='x';
    }
    i+=3;
    x +=3;
  }
  i = 0;
  while(i<9){
    printf("%c",a[i]);
    i++;
  }
  printf("\n");
  return a;
}
int main(){
  struct stat n;
  stat("stat.c", &n);
  printf(" size - %d\n mode - %o\n time - %s\n new permissions %s\n",n.st_size, n.st_mode, asctime(gmtime(&(n.st_atime))), readperm(n.st_mode));
  sizechange(n.st_size);
  return 0;
}
