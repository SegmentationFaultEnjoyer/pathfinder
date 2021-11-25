#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c){
    if(s == NULL)
        return NULL;
    int am = mx_count_words(s, c);
    int j = 0;
    char **r = malloc(sizeof(char*) * am);

    for (int i = 0; i < am; i++) {
        int wl = 0;
        int start = 0;

        for (; s[j]; j++) {
            if (s[j] != c) {
                wl += 1;

                if (start == 0)
                    start = j;
            }
            else if (s[j] == c && wl)
                break;
        }

        char* new_word = mx_strnew(wl);

        for (int k = 0, m = start; m < j; k++, m++)
            new_word[k] = s[m];

        r[i] = new_word;
    }

    r[am] = NULL;
    
    return r;
}


