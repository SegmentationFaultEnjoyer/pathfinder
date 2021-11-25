#include "../inc/pathfinder.h"

void priority_fix(const char *file){
    char *str = mx_file_to_str(file);
    char *error_msg;
    int iteration = 2;
    while(*str != '\n'){
        if(!mx_isdigit(*str)){
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
        str++;
        }
        str++;
    while(*str != '\0'){
        while(*str!= '-'){
            if(!mx_isalpha(*str)){
                error_msg = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
                mx_printerr(error_msg);
                exit(0);
            }
            str++;
        }
        str++;
        while(*str != ','){ 
            if(!mx_isalpha(*str)){
                error_msg = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
                mx_printerr(error_msg);
                exit(0);
            }
            str++;
        }
        str++;
        while(*str != '\n'){
            if(*str == '\0')
                break;
            if(!mx_isdigit(*str)){
                error_msg = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
                mx_printerr(error_msg);
                exit(0);
            }
            str++;
        }
        str++;
        iteration++;
    }
    }


