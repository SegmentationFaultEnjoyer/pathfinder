#include "../inc/pathfinder.h"

void find_all_routes(node* beg, node* end, int **matrix, node **path, int size, int *path_amount, int *p_ind) {
	int index = 0;
	for (int  i = 0; i < size; i++) {
		if (path[i] == NULL) {
			index = i;
			if(malloc_size(path[index]) != 0){
				free(path[index]);
				path[index] = NULL;
			}
			path[index] = malloc(sizeof(node));
			path[index] = end;
			break;
		}
	}
	if (end == beg) {
		pathes[*(p_ind)] = copy_path(path, index + 1);
		lens[*(p_ind)] = index + 1;
		(*path_amount)++;
		(*p_ind)++;
		return;
	}
	node **temp = path[index]->pointers;
	for (int j = 0; j < size; j++) {
		if (temp[j] == NULL) break;
		if (end->distance - matrix[end->index][temp[j]->index] == temp[j]->distance) {
			visit_matrix[end->index][temp[j]->index] = GRAY;
			visit_matrix[temp[j]->index][end->index] = GRAY;
			if (index + 2 < size && path[index + 2] != NULL && path[index + 1] != NULL) {
				
				visit_matrix[path[index + 2]->index][path[index + 1]->index] = WHITE;
				visit_matrix[path[index + 1]->index][path[index + 2]->index] = WHITE;
				path[index + 2] = NULL;
			}
			if (index + 1 < size && path[index + 1] != NULL) {
				path[index + 1] = NULL;
			}	
				
			find_all_routes(beg, temp[j], matrix, path, size, path_amount, p_ind);
					
		}
	}
}

