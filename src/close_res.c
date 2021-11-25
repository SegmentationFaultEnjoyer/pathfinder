#include "../inc/pathfinder.h"

void close_res(int **matrix, const int lines){
    for(int i = 0; i < lines; i++){
        free(matrix[i]);
        free(visit_matrix[i]);
        free(islands[i]);
        free(adj_list[i]);
        free(adj_list[i]->pointers);
        adj_list[i]->pointers = NULL;
        adj_list[i] = NULL;
        islands[i] = NULL;
        matrix[i] = NULL;
        visit_matrix[i] = NULL;
    }
    free(matrix);
    matrix = NULL;
    free(visit_matrix);
    visit_matrix = NULL;
    free(islands);
    islands = NULL;
    free(adj_list);
    adj_list = NULL;
}
