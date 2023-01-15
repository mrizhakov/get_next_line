#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

# define BUFFER_SIZE 100
    
char *return_new_line(char *storage, int *lines_returned) 
{
  static int index_read;
  static int previous_index_read;
  char       *new_line;
  int        i;

  i = 0;
  if (storage[index_read] == '\0')
    return (NULL);
  if (storage[index_read] == '\n' || storage[index_read] == '\0')
  {
    index_read++;
    previous_index_read = index_read;
  }
  while (storage[index_read] != '\n' && storage[index_read] != '\0')
    {
      index_read++;
      i++;
    }
  if (storage[index_read] == '\n' || storage[index_read] == '\0')
    {
      new_line = malloc((index_read - previous_index_read + 2) * sizeof(char));
      (*lines_returned)++;
      new_line[i + 1] = '\0';
      i = 0;
      while(previous_index_read != index_read)
        {
          new_line[i] = storage[previous_index_read];
          previous_index_read++;
          i++;
        }
      new_line[i] = storage[previous_index_read];
      previous_index_read = index_read;
      return (new_line); 
    }
  else
    return (NULL);
}

char *append_to_storage(int fd, char *storage, int *new_lines_read, int *end_of_file) 
{
  size_t  line_len;
  int     i;
  char    *buf = malloc(BUFFER_SIZE + 1);
  
  i = 0;
  line_len = read(fd, buf, BUFFER_SIZE);
  if (line_len != BUFFER_SIZE)
    (*end_of_file)++;
  //printf("Buf length is |%d|, line_len is |%d| \n", ft_strlen(buf), line_len);
  while (i != line_len)
    {
      if (buf[i] == '\n' || line_len != BUFFER_SIZE)  //(buf[i] == '\n' || buf[i] == '\0') 
        {
          (*new_lines_read)++;  
       //(*new_lines_read)++;// have to increment new_lines_read by 1 and be able to return it by reference
        }
      i++;
    }
  //snippet of code to return NULL in case we reached \0 (the end of the file)
  buf[line_len] = '\0';
  if (!ft_strjoin(storage, buf))
    printf("strjoin failed \n");
  storage = ft_strjoin(storage, buf);
	free(buf);
  return (storage);
}

char *get_next_line(int fd)
{
  static char  *storage;
  static int   lines_returned;
  static int   new_lines_read;
  static int   end_of_file;
  char         *new_string;
  
  if (!storage)
  {
	storage = malloc(sizeof(char));
	storage[0] = '\0';
  storage = append_to_storage(fd, storage, &new_lines_read, &end_of_file);
  //printf("First run - > New_lines_read is |%d|, Lines_returned is |%d|, end_of_file is |%d| \n", new_lines_read, lines_returned, end_of_file);
  }
  

  while ((end_of_file < 1) || (new_lines_read != lines_returned))
    {
  while (new_lines_read <= lines_returned)
      storage = append_to_storage(fd, storage, &new_lines_read, &end_of_file);
      //printf("Loop -> New_lines_read is |%d|, Lines_returned is |%d|, end_of_file is |%d| \n", new_lines_read, lines_returned, end_of_file);
      //printf("Storage contains |%s| \n", storage);
  if (new_lines_read > lines_returned)
        {
          new_string = return_new_line(storage, &lines_returned);
          //printf("Lines_returned is |%d|\n", lines_returned);
          return (new_string);
        }       
      }
  if (end_of_file == 1)
    new_string = NULL;
  return (new_string); 
}

int main(void) 
{
  int file_d;
  file_d = open("dict.txt", O_RDONLY);
  char *read_bytes;
 
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  read_bytes = get_next_line(file_d);
  printf("%s", read_bytes);
  
  return 0;
}