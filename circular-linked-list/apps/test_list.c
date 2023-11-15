#include "circ_list.h"

#include <stdio.h>

int main() {

    CircList* L = CircList_create();

    // CircList_add_first(L, 2);
    // CircList_add_first(L, 3);
    // CircList_add_first(L, 5);
    // CircList_add_first(L, 7);
    // CircList_add_first(L, 9);

    CircList_add_last(L, 2);
    CircList_add_last(L, 3);
    CircList_add_last(L, 6);
    CircList_add_last(L, 7);
    CircList_add_last(L, 9);

    CircList_print(L);
    CircList_print_v2(L);
    CircList_inverted_print(L);
    CircList_inverted_print_v2(L);

    CircList_destroy(&L);

    return 0;
}