#include <time.h>
#include "./include/list.h"
#include "./include/poly.h"

int main(){
    srand(time(NULL));
    
    Node* poly1 = create_poly();
    Node* poly2 = create_poly();
    printf("poly1 : ");
    print_poly(poly1);
    printf("poly2 : ");
    print_poly(poly2);

    Node* poly3 = add_poly(poly1, poly2);

    printf("poly1 + poly2 = ");
    print_poly(poly3);

    clear(poly1);
    free(poly1);
    clear(poly2);
    free(poly2);
    clear(poly3);
    free(poly3);
    return 0;
}