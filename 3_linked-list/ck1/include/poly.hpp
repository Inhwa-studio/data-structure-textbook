#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.hpp"

struct  term {
  int coefficient;
  int order;
};

SinglyLinkedList<term> create_poly();

const SinglyLinkedList<term> add_poly(SinglyLinkedList<term>& poly1, SinglyLinkedList<term>& poly2);

void print_poly(SinglyLinkedList<term>& poly);