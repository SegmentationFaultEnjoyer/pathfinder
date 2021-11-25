#include "../inc/libmx.h"

void mx_clear_list(t_list **list){
    int len = mx_list_size(*list);
    for (int i = 0; i < len; i++) {
        mx_pop_front(list);
    }
}

