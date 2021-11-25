#ifndef HF
#define HF

#define INT_MAX 2147483647

#include "../libmx/inc/libmx.h"

enum vertex_status{ WHITE, GRAY, BLACK};

typedef struct s_graph
{   
    char *name;
    int distance;
    int index;
    int len;
    struct s_graph **pointers;
    
}              node;     


int **get_matrix(char *path, int *lines);
void get_visit_matrix(int **matrix, const int size);
void get_adj_list(int **matrix, const int size);
bool check_island(const char* island, char **arr, int size);
int get_island_coord(const char *island, char **arr, int size);
void file_validation(int amount_of_args, char *file_path);
void priority_fix(const char *file);
void close_res(int **matrix, const int lines);
void pathfinder(int **matrix, int size);
node **copy_path(node **path, int path_size);
void find_all_routes(node* beg, node* end, int **matrix, node **path, int size, int *path_amount, int *p_ind);
int *find_path(int size, int begin_index, int **matrix);
void print_result(node **path, const int size, int **matrix);
void swap(int *a, int *b);
void swap_pathes(node ***path1, node ***path2);
bool check_loop(node **path1, node **path2, int coord1, int coord2, int size1, int size2);
void sort_pathes(int size);
void print_all_routes(int **matrix, int size_p);

extern char **islands;
extern node **adj_list;
extern int **visit_matrix;
extern node ***pathes;
extern int *lens;

#endif
