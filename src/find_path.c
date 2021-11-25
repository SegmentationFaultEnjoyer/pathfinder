#include "../inc/pathfinder.h"

int *find_path(int size, int begin_index, int **matrix){
	int *distance = malloc(sizeof(int) * size);
	int vertex[size];
	int temp, minindex, min;
	for (int i = 0; i < size; i++) {
		distance[i] = INT_MAX;
		vertex[i] = 1;
	}
	distance[begin_index] = 0;

	do {
		minindex = INT_MAX;
		min = INT_MAX;
		for (int i = 0; i < size; i++) { 
			if ((vertex[i] == 1) && (distance[i] < min)) { 
				min = distance[i];
				minindex = i;
			}
		}
		

		if (minindex != INT_MAX) {
			for (int i = 0; i < size; i++) {
				if (matrix[minindex][i] > 0) {
					temp = min + matrix[minindex][i];
					if (temp < distance[i])
						distance[i] = temp;
				}
			}
			vertex[minindex] = 0;
		}
	} while (minindex < INT_MAX);
	return distance;
}

