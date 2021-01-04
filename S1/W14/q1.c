#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *source, char const *pattern, char const *replacement)
{
    char *substring;
    static char *last_source;
    static char *last_replacement;

    if(source != NULL && (substring = strstr(source, pattern)) == NULL) {
        last_source = source;
        return source;
    }

    if(source == NULL) {
        source = last_source;
        substring = strstr(last_replacement, pattern);
        if(substring == NULL) {
            return source;
        }
    }

    int pattern_len     = strlen(pattern);
    int replacement_len = strlen(replacement);
    int tail_len        = strlen(substring) + 1;
    last_replacement    = substring + replacement_len - 1;

    memcpy(substring + replacement_len, substring + pattern_len, tail_len * sizeof(char));
    memcpy(substring, replacement, replacement_len * sizeof(char));

    last_source = source;

    return source;
}

//For test only
int main(int argc, char const *argv[]) {
    char source[100] = "1223456789", pattern[10] = "2", replacement[10] = "123";
    replace(source, pattern, replacement); printf("%s\n", source); // 112323456789
    replace(source, pattern, replacement); printf("%s\n", source); // 11123323456789
    replace(NULL  , pattern, replacement); printf("%s\n", source); // 1112331233456789
    return 0;
}
