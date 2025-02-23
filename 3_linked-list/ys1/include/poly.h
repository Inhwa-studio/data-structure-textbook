#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* create_poly();
Node* add_poly(Node* poly1, Node* poly2);
void print_poly(Node* poly);