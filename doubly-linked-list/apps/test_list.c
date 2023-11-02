#include <stdio.h>
#include "list.h" 

int main() {
    List* L2 = List_create();

    List_add_first(L2, 10);
    List_add_first(L2, 4);
    List_add_first(L2, 0);
    List_add_first(L2, 25);
    List_print(L2);
    List_inverted_print(L2);

    List_destroy(&L2);

    return 0;
}