#include "../inc/pathfinder.h"

node ***pathes = NULL;
int *lens = NULL;

void pathfinder(int **matrix, int size) {
	int *distance;
	int path_amount;
	int p_ind;
	node **path = malloc(sizeof(node*) * size);
	for (int i = 0; i < size; i++) 
			path[i] = NULL;
	for(int i = 0; i < size; i++){
		distance = find_path(size, i, matrix);
		for(int j = 0; j < size; j++){ 
				adj_list[j]->distance = distance[j];
		}
		for(int j = i + 1; j < size; j++) {
			pathes = malloc(sizeof(node**) * size * size * size);
			lens = malloc(sizeof(int) * size);
			path_amount = 0; 
			p_ind = 0;
			find_all_routes(adj_list[i], adj_list[j], matrix, path, size, &path_amount, &p_ind);
			print_all_routes(matrix, path_amount);
			for (int k = 0; k < size; k++) 
				path[k] = NULL;
			get_visit_matrix(matrix, size);
			for(int k = 0; k < path_amount; k++) {
				free(pathes[k]);
				pathes[k] = NULL;
			}
			free(pathes);
			free(lens);
			lens = NULL;
			pathes = NULL;
		}
		free(distance);
		distance = NULL;
	}
	free(path);
	path = NULL;

}

