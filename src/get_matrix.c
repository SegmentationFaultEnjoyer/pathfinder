#include "../inc/pathfinder.h"

char **islands = NULL;

int **get_matrix(char *path, int *lines){
    char *str = mx_file_to_str(path);
    char *error_msg;
    char *f_isl;
    char *s_isl;
    int size = mx_atoi(str), isl_len = 0, isl_count = 0, line, row, iteration = 2;
    long long sum_len = 0, dist = 0;
    bool was_ins = false;
    if(*str == '\n'){
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }
    while(*str != '\n'){ //first line check
        if(!mx_isdigit(*str)){
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
        str++;
    }
    str++;
    *lines = size;
    int **matrix = malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++){
        matrix[i] = malloc(sizeof(int) * size);
        for(int j = 0; j < size; j++){
            matrix[i][j] = 0;
        }
    }
    islands = malloc(sizeof(char*) * size);
    while(*str != '\0'){
        while(str[isl_len] != '-'){ //first island
            if(!mx_isalpha(str[isl_len])){
                error_msg = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
                mx_printerr(error_msg);
                exit(0);
            }
            isl_len++;
        }
        f_isl = mx_strndup(str, isl_len);
        if(check_island(mx_strndup(str, isl_len), islands, isl_count)){
            if(isl_count < size)
                islands[isl_count] = mx_strndup(str, isl_len);
            else{
                mx_printerr("error: invalid number of islands\n");
                exit(0);
                }
            was_ins = true;
            line = isl_count;
            isl_count++;
        }
        if(!was_ins && iteration != 2){
            line = get_island_coord(f_isl, islands, isl_count);
        }
        was_ins = false;
        if(str[isl_len + 1] == '-'){
            error_msg = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
            mx_printerr(error_msg);
            exit(0);
        }
        str += (isl_len + 1) * sizeof(char);
        isl_len = 0;

        while(str[isl_len] != ','){ //second island
            if(!mx_isalpha(str[isl_len])){
                error_msg = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
                mx_printerr(error_msg);
                exit(0);
            }
            isl_len++;
        }
        s_isl = mx_strndup(str, isl_len);
        if(mx_strcmp(f_isl, s_isl) != 0){ //самоцикл проверка
            if(check_island(mx_strndup(str, isl_len), islands, isl_count)){
                if(isl_count < size)
                    islands[isl_count] = mx_strndup(str, isl_len);
                else{
                    mx_printerr("error: invalid number of islands\n");
                    exit(0);
                }
                was_ins = true;
                row = isl_count;
                isl_count++;
            }
            if(!was_ins && iteration != 2){
                row = get_island_coord(s_isl, islands, isl_count);
            }
            was_ins = false;
            str += (isl_len + 1) * sizeof(char);
           
            isl_len = 0;
        }
        else{
            error_msg = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
            mx_printerr(error_msg);
            exit(0);
        }
        dist = mx_atoi(str);
        if(dist == 0) {
            error_msg = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
            mx_printerr(error_msg);
            exit(0);
        }
        while(*str != '\n'){ //distance check
            if(!mx_isdigit(*str)){
                error_msg = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
                mx_printerr(error_msg);
                exit(0);
            }
            str++;
        }
        str++;
        if(matrix[line][row] != 0 && matrix[row][line] != 0){
            mx_printerr("error: duplicate bridges\n");
            exit(0);
        }
        else{
            matrix[line][row] = dist;
            matrix[row][line] = dist;
            sum_len += dist;
        }
        iteration++;
    }
    if(sum_len > INT_MAX){
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(0);
    }
    if(isl_count != size) {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
    return matrix;
}
