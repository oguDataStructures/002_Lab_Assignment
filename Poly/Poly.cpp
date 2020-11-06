#include <stdio.h>
#include "Poly.h"
#include <string>
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
string RemoveSpaces(string str) {
	int i = 0, j = 0;
	while (str[i]) {
		if (str[i] != ' ') {
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';

	return str;
}
void Parse(string str) {
	/*int i = 0;
	const char ch1 = '+';
	const char ch2 = '-';
	string bos_deneme;
	string cpy = str;
	int pos1 = 0;
	int pos2 = 0;
	pos1 = cpy.find(ch1);
	pos2 = cpy.find(ch2);
	PolyNode node;
	node.coef = 0;
	node.exp = 0;
	node.next = NULL;
	int coef = 0, exp = 0;
	while (cpy.length() != 0) {
		if (pos1 < pos2) {
			bos_deneme = cpy.substr(0, pos1);
			cpy.erase(0, pos1);
			pos1 = cpy.find(ch1);
		}
		else {
			if (pos2 == 0) {
				continue;
			}
			bos_deneme = cpy.substr(0, pos2);
			cpy.erase(0, pos2);
			pos2 = cpy.find(ch2);
		}
	}*/

}
PolyNode* CreatePoly(char* expr) {
	string str = expr;
	str = RemoveSpaces(expr);
	Parse(str);
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
	bool flag = false;

	while (p != NULL && exp < p->exp) {
		q = p;
		p = p->next;
	}
	if (q == NULL) {
		if (p != NULL && p->exp == exp) {
			p->coef = p->coef + coef;
			if (p->coef == 0) {
				head = p->next;
			}
			delete node;
			return head;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}
	else {
		if (p != NULL && p->exp == exp) {
			p->coef = p->coef + coef;
			if (p->coef == 0) {
				q->next = p->next;
			}
			delete node;
			return head;
		}
		else
		{
			node->next = q->next;
			q->next = node;
		}
	}

	return head;
	return NULL;
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
PolyNode* Derivative(PolyNode* poly) {
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
