#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
int main(){
  struct stat n;
  stat("stat.c", &n);
  printf(" size - %d\n mode - %o\n time - %s\n",n.st_size, n.st_mode, asctime(gmtime(&(n.st_atime))));
  return 0;
}
