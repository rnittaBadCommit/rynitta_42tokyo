#include <stdio.h>

int main()
{
  printf("[% 20.5u]\n", 20);
  printf("[%+20.5u]\n", 20);
  printf("[%020.5d]\n", 20);
  printf("[%20.5d]\n", 20);
  printf("[%.5d]\n", 20);
  printf("[%3.5d]\n", 20);

  printf("%#.2x\n", 1);
  printf("%#.2x\n", 100);
  printf("%#.2x\n", 1000);
  printf("%#10.2x\n", 1);
  printf("%#10.2x\n", 100);
  printf("%#10.2x\n", 1000);
}
