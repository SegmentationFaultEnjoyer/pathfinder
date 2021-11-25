#include "../inc/pathfinder.h"

void print_all_routes(int **matrix, int size_p) {
	sort_pathes(size_p);
	for(int i = 0; i < size_p; i++) {
		print_result(pathes[i], lens[i], matrix);
	}
}

