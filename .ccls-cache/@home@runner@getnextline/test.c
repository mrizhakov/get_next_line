#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void) {

  char *buf = "i love to return new lines\nnot really";
  char *result;
  
  

  result = ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n'));


  printf("new line is at index: |%d|\n", result);



  return 0;
}