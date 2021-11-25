#include "../inc/pathfinder.h"

int main(int argc, char *argv[]){
    file_validation(argc, argv[1]);
    priority_fix(argv[1]);
    int lines = 0;
    int **matrix = get_matrix(argv[1], &lines);
    get_adj_list(matrix, lines);
    get_visit_matrix(matrix, lines);
    pathfinder(matrix, lines);
    close_res(matrix, lines);
    return 0;
}

