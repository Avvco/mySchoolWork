#include <string.h>
char *mystrcat(char *dest, char *src)
{
  strcat(dest, src);
  dest[strlen(dest)] = '\0';
  return dest;
}

char *mystrncat(char *dest, char *src, int n)
{
  char tmp[n];
  for(int i = 0 ; i < n ; i++) {
  	tmp[i] = src[i];
  }
  strcat(dest, tmp);
  dest[strlen(dest)] = '\0';
  return dest;
}
