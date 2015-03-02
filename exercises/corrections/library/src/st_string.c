#include "st_string.h"

/* str_len : compute the lenght of str */
int str_len(const char str[]) {
        for(int i = 0; str[i++] != '\0'; )
                ;
        
        return i;
}

/* str_cmp : compare to strings */
int str_cmp(const char *p, const char *t) {
        for ( ; *p == *t; p++, t++)
                if (*p == '\0')
                        return 0;

        return *p - *t;
}

/* str_cpy : copy t in p */
int str_cpy(char *p, const char *t) {
        while ((*p++ = *t++) != '\0')
                ;

        return 1;
}

