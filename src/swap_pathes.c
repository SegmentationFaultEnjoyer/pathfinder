#include "../inc/pathfinder.h"

void swap_pathes(node ***path1, node ***path2) {
	node **temp = *path1;
	*path1 = *path2;
	*path2 = temp;
}

