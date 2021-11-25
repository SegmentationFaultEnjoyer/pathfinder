#include "../inc/pathfinder.h"

void print_result(node **path, const int size, int **matrix){
	mx_printstr("========================================\n");
	mx_printstr(mx_strjoin(mx_strjoin("Path: ", path[size - 1]->name), mx_strjoin(" -> ", path[0]->name)));
	mx_printstr("\nRoute: ");
	for(int i = size - 1; i >= 0; i--) {
		mx_printstr(path[i]->name);
		if(i != 0) mx_printstr(" -> ");
	}
	mx_printstr("\nDistance: ");
	int it = 0, len = 0;
	for(int i = size - 1; i > 0; i--, it++) {
		if(it > 0) mx_printstr(" + ");
		mx_printint(matrix[path[i]->index][path[i - 1]->index]);
		len += matrix[path[i]->index][path[i - 1]->index];
		if(it > 0 && i == 1) {
			mx_printstr(" = ");
			mx_printint(len);
		}
	}
	mx_printstr("\n========================================\n");
}

