#include "../inc/pathfinder.h"

int get_island_coord(const char *island, char **arr, int size){
    for(int i = 0; i < size; i++){
        if((mx_strcmp(island, arr[i])) == 0)
            return i;
    }
    return -1;
}
