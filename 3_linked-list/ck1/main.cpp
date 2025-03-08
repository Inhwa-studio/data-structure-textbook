#include <iostream>
#include <cstdlib> 
#include <ctime> 

#include "./include/linkedList.hpp"
#include "./include/poly.hpp"

int main() {
    srand(time(NULL));
    SinglyLinkedList<term> poly1 = create_poly();
    
    printf("poly1 \t\t = ");
    print_poly(poly1);
    
    SinglyLinkedList<term> poly2 = create_poly();
    
    printf("poly2 \t\t = ");
    print_poly(poly2);

    SinglyLinkedList<term> result = add_poly(poly1, poly2);
    
    printf("poly1 + poly2 \t = ");
    print_poly(result);

    return 0;
}
