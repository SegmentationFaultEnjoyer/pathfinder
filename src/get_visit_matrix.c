#include "../inc/pathfinder.h"

int **visit_matrix;

void get_visit_matrix(int **matrix, const int size) {
    visit_matrix = malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++){
        visit_matrix[i] = malloc(sizeof(int) * size);
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(matrix[i][j] != 0) {
                visit_matrix[i][j] = WHITE;
            }
            else   
                visit_matrix[i][j] = BLACK;
        }
    }
}

