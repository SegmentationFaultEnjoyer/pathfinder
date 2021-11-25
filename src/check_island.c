#include "../inc/pathfinder.h"

bool check_island(const char* island, char **arr, int size){
    for(int i = 0; i < size; i++){
        if((mx_strcmp(island, arr[i])) == 0)
            return false;
    }
    return true;
}
