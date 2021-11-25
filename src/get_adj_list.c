#include "../inc/pathfinder.h"

node **adj_list;

void get_adj_list(int **matrix, const int size) {
    int temp_size = 0, k = 0;
    adj_list = malloc(sizeof(node*) * size);
    for (int i = 0; i < size; i++) {
        adj_list[i] = malloc(sizeof(node));
        adj_list[i]->name = islands[i];
        adj_list[i]->index = i;
        adj_list[i]->pointers = malloc(sizeof(node*) * size - 1);
    }
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(matrix[i][j] != 0) {
                adj_list[i]->pointers[k] = adj_list[j];
                k++; temp_size++;
            }
        }
        adj_list[i]->len = temp_size;
        k = 0; temp_size = 0;
    }
}
