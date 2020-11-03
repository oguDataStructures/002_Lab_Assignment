#include <stdio.h>
#include<string>
#include "Poly.h"
#pragma warning(disable : 4996)
using namespace std;

//-------------------------------------------------
// Creates a polynomial from an expression.
// Returns a pointer to the first PolyNode in the list (head of the list)
//
// Expression will be of the following sort:
// Ex1: 2.3x^4 + 5x^3 - 2.64x - 4
// Ex2: -4.555x^10 - 45.44
// Ex3: x^6 + 2x^4 - x^3 - 6.3x + 4.223 
// Ex4: 34
// Ex5: -x+1
// Ex6: -3x^4    +   4x
// Ex7: -2x  - 5
//

void removeSpaces(char* str) {
	// To keep track of non-space character count 
	int count = 0;

	// Traverse the given string. If current character 
	// is not space, then place it at index 'count++' 
	for (int i = 0; str[i]; i++)
		if (str[i] != ' ')
			str[count++] = str[i]; // here count is 
								   // incremented 
	str[count] = '\0';
}
void Parse(char* str) {
	int count = 0;
	int i = 0;
	int* size = new int[100];
	char* token = strtok(str, "^");
	PolyNode node;
	node.exp = 0;
	if (*token == 'x') {
		node.coef = 1;
	}
	else {
		node.coef = stod(strtok(str, "x"));
	}
	while (token != NULL) {
		node.exp += atoi(token);
		token = std::strtok(NULL, " ");
	}

}
PolyNode* CreatePoly(char* expr) {
	return NULL;
} //end-CreatePoly

/// -------------------------------------------------
/// Walk over the poly nodes & delete them
///
void DeletePoly(PolyNode* poly) {
	// Fill this in
} // end-DeletePoly

//-------------------------------------------------
// Adds a node (coefficient, exponent) to poly. If there already 
// is a node with the same exponent, then you simply add the coefficient
// to the existing coefficient. If not, you add a new node to polynomial
// Returns a pointer to the possibly new head of the polynomial.
//
PolyNode* AddNode(PolyNode* head, double coef, int exp) {
	// Fill this in
	PolyNode* node = new PolyNode();
	node->coef = coef;
	node->exp = exp;
	node->next = NULL;
	PolyNode* p = head;
	PolyNode* q = NULL;

	while (p != NULL && exp > p->exp) {
		q = p;
		p = p->next;
	}
	if (q == NULL) {
		node->next = head;
		head = node;
	}
	else {
		node->next = q->next;
		q->next = node;
	}
	return head;
} // end-AddNode

//-------------------------------------------------
// Adds two polynomials and returns a new polynomial that contains the result
// Computes: poly3 = poly1 + poly2 and returns poly3
//
PolyNode* Add(PolyNode* poly1, PolyNode* poly2) {
	// Fill this in
	return NULL;
} //end-Add

//-------------------------------------------------
// Subtracts poly2 from poly1 and returns the resulting polynomial
// Computes: poly3 = poly1 - poly2 and returns poly3
//
PolyNode* Subtract(PolyNode* poly1, PolyNode* poly2) {
	// Fill this in
	return NULL;
} //end-Substract

//-------------------------------------------------
// Multiplies poly1 and poly2 and returns the resulting polynomial
// Computes: poly3 = poly1 * poly2 and returns poly3
//
PolyNode* Multiply(PolyNode* poly1, PolyNode* poly2) {
	// Fill this in
	return NULL;
} //end-Multiply

//-------------------------------------------------
// Evaluates the polynomial at a particular "x" value and returns the result
//
double Evaluate(PolyNode* poly, double x) {
	// Fill this in
	return 0;
} //end-Evaluate

//-------------------------------------------------
// Computes the derivative of the polynomial and returns it
// Ex: poly(x) = 3x^4 - 2x + 1-->Derivative(poly) = 12x^3 - 2
//
PolyNode* Derivative() {
	// Fill this in
	return NULL;
} //end-Derivative

//-------------------------------------------------
// Plots the polynomial in the range [x1, x2].
// -39<=x1<x2<=39
// -12<=y<=12
// On the middle of the screen you gotta have x & y axis plotted
// During evaluation, if "y" value does not fit on the screen,
// then just skip it. Otherwise put a '*' char depicting the curve
//
void Plot(PolyNode* poly, int x1, int x2) {
	// Fill this in	
} //end-Plot

//-------------------------------------------------
// Prints a polynomial in a nicely formatted manner
//
void Print(PolyNode* poly) {
	if (poly == NULL) { printf("<NULL>\n"); return; }

	printf("<");
	PolyNode* p = poly;
	while (p != NULL) {
		if (p->exp == 0) {
			printf("%+-3.1f", p->coef);

		}
		else if (p->exp == 1) {
			if (p->coef == 1.0) printf("+x ");
			else if (p->coef == -1.0) printf("-x ");
			else printf("%+-3.1fx ", p->coef);

		}
		else {
			if (p->coef == 1.0) printf("+x^%-2d ", p->exp);
			else if (p->coef == -1.0) printf("-x^%-2d ", p->exp);
			else printf("%+-3.1fx^%-2d ", p->coef, p->exp);
		} //end-else

		p = p->next;
	} // end-while

	printf(">\n");
} //end-Print	
