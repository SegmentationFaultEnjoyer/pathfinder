#include "../inc/pathfinder.h"

node **copy_path(node **path, int path_size) {
	node **copy_path = malloc(sizeof(node*) * path_size);
	for(int i = 0; i < path_size; i++) {
		copy_path[i] = malloc(sizeof(node));
		copy_path[i]->distance = path[i]->distance;
		copy_path[i]->index = path[i]->index;
		copy_path[i]->len = path[i]->len;
		copy_path[i]->name = path[i]->name;
		copy_path[i]->pointers = path[i]->pointers;
	}
	return copy_path;
}

