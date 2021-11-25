#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd){
    if(buf_size < 1)
        return -2;
    char buf = delim;
    char *temp = NULL;
    int res, len = 0;
    bool was_del = false;
    while((res = read(fd, &buf, 1)) > 0){
        if(errno != 0)
            return -2;
        if(buf == delim){
            was_del = true;
            break;
        }
        else{
            temp = mx_realloc(temp, sizeof(char) * (len + 1));
            temp[len] = buf;
            len++;
        }
    }
    if(!was_del)
        return -1;
    *lineptr = mx_realloc(*lineptr, sizeof(char) * (len + 1));
    mx_memset(*lineptr, '\0', mx_strlen(*lineptr));
    if(temp)
        mx_strcpy(*lineptr, temp);
    free(temp);
    temp = NULL;
    (*lineptr)[len] = '\0'; 
    return len;
}
