#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replace(char *source, char *pattern, char *replacement)
{
  char *src_ptr;
  char *ptn_ptr;
  char *currentLoc;

  int replaceCount = 1;

  int src_len = strlen(source);
  int ptn_len = strlen(pattern);
  int rep_len = strlen(replacement);

  int ret_len = src_len + (ptn_len - rep_len) * replaceCount;
  char *ret_str = (char*)malloc(sizeof(char) * (ret_len + 1));
  char *ret_ptr = ret_str;
  int counter = 0;

  if (ret_str != NULL) {
    for(src_ptr = source ; currentLoc = strstr(src_ptr, pattern) ; src_ptr = currentLoc + ptn_len) {
      if(counter > 0) break;
      int skip_len = currentLoc - src_ptr;
      strncpy(ret_ptr, src_ptr, src_len);
      ret_ptr = ret_ptr + skip_len;
      strncpy(ret_ptr, replacement, rep_len);
      ret_ptr = ret_ptr + rep_len;
      counter++;
    }
    strcpy(ret_ptr, src_ptr);
  }
  return ret_str;
}

char *replaceAll(char *source, char *pattern, char *replacement)
{
  char *src_ptr;
  char *ptn_ptr;
  char *currentLoc;

  int replaceCount = 0;

  int src_len = strlen(source);
  int ptn_len = strlen(pattern);
  int rep_len = strlen(replacement);

  for (src_ptr = source; ptn_ptr = strstr(src_ptr, pattern); src_ptr = ptn_ptr + ptn_len) {
          replaceCount++;
      }

  int ret_len = src_len + (ptn_len - rep_len) * replaceCount;
  char *ret_str = (char*)malloc(sizeof(char) * (ret_len + 1));
  char *ret_ptr = ret_str;

  if (ret_str != NULL) {
    for(src_ptr = source ; currentLoc = strstr(src_ptr, pattern) ; src_ptr = currentLoc + ptn_len) {
      int skip_len = currentLoc - src_ptr;
      strncpy(ret_ptr, src_ptr, src_len);
      ret_ptr = ret_ptr + skip_len;
      strncpy(ret_ptr, replacement, rep_len);
      ret_ptr = ret_ptr + rep_len;
    }
    strcpy(ret_ptr, src_ptr);
  }
  return ret_str;
}

// For test only
int main(int argc, char * argv[]) {
  char a[50];
  char b[50];
  char c[50];

  scanf("%s", a);
  scanf("%s", b);
  scanf("%s", c);

  char *newstr = replace(a, b, c);
  if (newstr) {
      printf("%s\n", newstr);
      free(newstr);
  }
  else {
      fprintf(stderr, "Memory allocation error.\n");
      exit(-2);
  }
  return 0;
}
