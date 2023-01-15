#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 200


char *ft_strchr(const char *s, int c) {
  while ((*s != '\0') && (*s != (char)c))
    s++;
  if (*s == (char)c)
    return ((char *)s);
  return ((char *)NULL);
}

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	i;
	unsigned int	y;

	new_str = malloc (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!new_str)
		return ((void *) NULL);
	i = 0;
	y = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[y] != '\0')
	{
		new_str[i] = s2[y];
		i++;
		y++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	new_n;
	char			*char_dest;
	char			*char_src;
	unsigned int	i;

	char_dest = (char *)dest;
	char_src = (char *)src;
	i = 0;
	new_n = (unsigned int)n;
	if (!dest && !src)
	{
		return (NULL);
	}
	while (i < new_n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (char_dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					n_new;

	d = dest;
	s = src;
	n_new = (int)n - 1;
	if (dest == src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	if (dest > src)
	{
		while (n_new != -1)
		{
			d[n_new] = s[n_new];
			n_new--;
		}
	}
	return (dest);
}



char	*ft_strdup(const char *s)
{
	char	*s_new;
	size_t	s_size;
	int		i;

	i = 0;
	s_size = ft_strlen(s) + 1;
	s_new = (char *)malloc(sizeof(*s_new) * s_size);
	if (!s_new)
		return (NULL);
	return ((char *)ft_memcpy(s_new, s, s_size));
}


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}




char *get_next_line(int fd) {
  //char *line;
  //char *buf;
  static char *storage;
  char *temp;
  static int last_line_end;
  static int read_bytes;
  size_t line_len;
  char *buf = malloc(200);
  char *buf_with_nul;

  

  storage = malloc(6 * sizeof(char));
  line_len = read(fd, buf, 6);
  
  printf("Line_len is : |%d|\n", line_len);
  temp = malloc((6 + line_len) * sizeof(char));
  printf("Sizeof temp is : |%d|\n", sizeof(temp));


  

  

  
  printf("Storage is : |%s|\n", storage);
  line_len = read(fd, buf, 6);
  printf("Buf content is : |%s|\n", buf);
  buf_with_nul = ft_strdup(buf);
  printf("line_len is : |%d|\n", line_len);
  ft_strlcpy(storage, buf, 6);
  printf("After memmove storage is : |%s|\n", storage);



      //if ((ft_strchr(buff, '\n') || (ft_strchr(buff, '\0') 
      //{
        
      //}
    
    
  return (storage);
}

int main(void) {
  int file_d;
  file_d = open("dict.txt", O_RDONLY);
  // printf("File name: %d", file_d);
  char *next_line;

  next_line = get_next_line(file_d);
  printf("this is the next line: |%s|\n", next_line);

  next_line = get_next_line(file_d);
  printf("this is the next line: |%s|\n", next_line);

  return 0;
}