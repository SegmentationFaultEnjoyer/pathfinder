#include "../inc/pathfinder.h"

void sort_pathes(int size) {
	bool was_swap = true;
	while(was_swap) {
		was_swap = false;
		for(int i = 1; i < size; i++) {
			for(int j = lens[i] - 1, k = lens[i - 1] - 1; j >= 0 || k >= 0; j--, k--) {
				if(j >= 0 && k >= 0) {
					if(pathes[i][j]->index < pathes[i - 1][k]->index ) {
						if(!check_loop(pathes[i], pathes[i - 1], j, k, lens[i], lens[i - 1])) {
							swap_pathes(&(pathes[i]), &(pathes[i - 1]));
							swap(&(lens[i]), &(lens[i - 1]));
							was_swap = true;
							break;
						}

					}
				}
			}
		}
	}
}

