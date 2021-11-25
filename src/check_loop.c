#include "../inc/pathfinder.h"

bool check_loop(node **path1, node **path2, int coord1, int coord2, int size1, int size2) {
	for(int i = size1 - 1, j = size2 - 1; i != coord1 && j != coord2; i--, j--) {
		if(path1[i]->index > path2[j]->index)
			return true;
	}
	return false;
}

