
#include "poly.hpp"

SinglyLinkedList<term> create_poly(){
  SinglyLinkedList<term> poly;

  int maxOrder = rand() % (10 - 5 + 1) + 5;

  int coefficient = rand() % 10 + 1;   // 1 to 9
  coefficient *= (rand() % 2) * 2 - 1; // sign

  term term1 = {coefficient, maxOrder};

  poly.insert_last(term1);

  for (int ii = maxOrder - 1; ii >= 0; ii--){
      if (rand() % 2 == 1){
          coefficient = rand() % 10 + 1;
          coefficient *= (rand() % 2) * 2 - 1;
          term term2 = {coefficient, ii};
          poly.insert_last(term2);
      } 
  }
  return poly;
}



const SinglyLinkedList<term> add_poly(SinglyLinkedList<term>& poly1, SinglyLinkedList<term>& poly2){
  SinglyLinkedList<term> result;

  int length1 = poly1.get_length();
  int length2 = poly2.get_length();

  int idx1 = 0;
  int idx2 = 0;
  while (idx1 < length1 && idx2 < length2) {
    term term1 = poly1.get_entry(idx1);
    term term2 = poly2.get_entry(idx2);

    if (term1.order > term2.order) {
      result.insert_last(term1);  // Add term from poly1
      ++idx1;
    } 
    else if (term1.order < term2.order) {
      result.insert_last(term2);  // Add term from poly2
      ++idx2;
    } 
    else {
      // Add coefficients if exponents match
      int sumCoeff = term1.coefficient + term2.coefficient;
      if (sumCoeff != 0) {  // Avoid adding zero terms
        result.insert_last({sumCoeff, term1.order});
      }
      ++idx1;
      ++idx2;
    }
  }

  while (idx1 < length1) {
    result.insert_last(poly1.get_entry(idx1));
    ++idx1;
  }

  while (idx2 < length2) {
    result.insert_last(poly2.get_entry(idx2));
    ++idx2;
  }

  return result;
}



void print_poly(SinglyLinkedList<term>& poly) {
  if (poly.is_empty()) {
    printf("0\n");
    return;
  }

  for (int ii = 0; ii < poly.get_length(); ++ii) {
      term currentTerm = poly.get_entry(ii);

      // Print the coefficient (handle sign separately)
      if (ii == 0) {
        // First term: Print coefficient normally
        printf("%d", currentTerm.coefficient);
      } else {
        // Subsequent terms: Print with appropriate sign
        if (currentTerm.coefficient > 0){
          printf(" + %d", currentTerm.coefficient);
        }
        else{
          printf(" - %d", -currentTerm.coefficient);  // Print negative coefficients correctly
        }
      }

      // Print the exponent part
      if (currentTerm.order > 1){
        printf("x^%d", currentTerm.order);
      }
      else if (currentTerm.order == 1){
        printf("x");
      }
  }
  printf("\n");  // Print a newline at the end
}