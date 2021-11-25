#include "../inc/pathfinder.h"

void file_validation(int amount_of_args, char *file_path){
    char *error_msg;
    int res;
    char buf;
    if(amount_of_args != 2){
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
    int file = open(file_path, O_RDONLY);
    if(errno != 0){
        error_msg = mx_strjoin(mx_strjoin("error: file ", file_path), " does not exist\n");
        mx_printerr(error_msg);
        exit(0);
    }
    res = read(file, &buf, 1);
    if(errno != 0 || res < 1){
        error_msg = mx_strjoin(mx_strjoin("error: file ", file_path), " is empty\n");
        mx_printerr(error_msg);
        exit(0);
    }
    close(file);
}
