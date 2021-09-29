#include <string.h>
#include <ctype.h>
char *trim(char *dest)
{
  int end = strlen(dest) - 1;
  while(isspace(*(dest + end))) {
  	end--;
  }
  while(isspace(*dest)) {
  	dest++;
  }
  *(dest + end) = '\0';
  return dest;
}
