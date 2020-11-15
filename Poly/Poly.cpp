#include <stdio.h>
#include "Poly.h"
#include <string>
#include <iostream>

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
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}
PolyNode* Parse(string str, PolyNode* head) {
	string const delims{ "-+" };
	string const delims1{ "^" };
	string token[100];
	size_t beg, pos = 0;
	int i = 0;
	string coef;
	string exp;
	double coef_double;
	int exp_int;
	int count = 0;
	while ((beg = str.find_first_not_of(delims, pos)) != string::npos)
	{
		pos = str.find_first_of(delims, beg + 1);
		if (beg == 0) {
			token[i] = str.substr(beg, pos - beg);
		}
		else {
			token[i] = str.substr(beg - 1, pos - beg + 1);
		}
		i++;
	}
	pos = 0;
	i = 0;
	while (!token[i].empty()) {
		if ((pos = token[i].find(delims1)) != string::npos) {
			coef = token[i].substr(0, pos - 1);
			if (coef == "-") {
				coef_double = -1;
			}
			else if (coef == "+" || coef == "")
			{
				coef_double = 1;
			}
			else {
				coef_double = stod(coef);
			}

			exp = token[i].substr(pos + 1, token[i].size());

			if (exp == "-") {
				exp_int = -1;
			}
			else if (exp == "+" || exp == "")
			{
				exp_int = 1;
			}
			else {
				exp_int = stoi(exp);
			}
		}
		else if ((pos = token[i].find('x')) != string::npos) {
			coef = token[i].substr(0, pos);
			if (coef == "-") {
				coef_double = -1;
			}
			else if (coef == "+" || coef == " ")
			{
				coef_double = 1;
			}
			else {
				coef_double = stod(coef);
			}
			exp_int = 1;
		}
		else {
			coef_double = stod(token[i]);
			exp_int = 0;
		}
		head = AddNode(head, coef_double, exp_int);
		i++;
	}
	return head;
}
PolyNode* CreatePoly(char* expr) {
	PolyNode* head = new PolyNode();
	string str = expr;
	str = RemoveSpaces(expr);
	head = Parse(str, head);
	return head;
} //end-CreatePoly

/// -------------------------------------------------
/// Walk over the poly nodes & delete them
///
void DeletePoly(PolyNode* Poly) {
	// Fill this in
	PolyNode* p = NULL;
	while (Poly != NULL)
	{
		p = Poly->next;
		delete Poly;
		Poly = p;
	}
	Print(Poly);

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
		else if (p && coef == 0) {
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
} // end-AddNode

//-------------------------------------------------
// Adds two polynomials and returns a new polynomial that contains the result
// Computes: poly3 = poly1 + poly2 and returns poly3
//
PolyNode* Add(PolyNode* poly1, PolyNode* poly2) {
	// Fill this in
	PolyNode* poly3 = new PolyNode();
	poly3->coef = 0;
	poly3->exp = 0;
	poly3->next = NULL;
	PolyNode* ptr1 = poly1;
	PolyNode* ptr2 = poly2;
	int exp = 0;
	double coef = 0;
	while (ptr1->next && ptr2->next) {// ptr1->next != NULL  &&  ptr2 ->next != NULL

		if (ptr1->exp > ptr2->exp) {
			exp = ptr1->exp;
			coef = ptr1->coef;
			ptr1 = ptr1->next;
		}
		else if (ptr1->exp < ptr2->exp) {
			exp = ptr2->exp;
			coef = ptr2->coef;
			ptr2 = ptr2->next;
		}
		else {
			exp = ptr1->exp;
			coef = ptr1->coef + ptr2->coef;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		poly3 = AddNode(poly3, coef, exp);
	}
	while (ptr1 || ptr2)
	{
		if (ptr1 && !ptr2)
		{
			exp = ptr1->exp;
			coef = ptr1->coef;
			ptr1 = ptr1->next;
		}
		if (ptr2 && !ptr1)
		{
			exp = ptr2->exp;
			coef = ptr2->coef;
			ptr2 = ptr2->next;
		}
		if (ptr1 && ptr2) {

			if (ptr1->exp > ptr2->exp) {
				exp = ptr1->exp;
				coef = ptr1->coef;
				ptr1 = ptr1->next;
			}
			else if (ptr1->exp < ptr2->exp) {
				exp = ptr2->exp;
				coef = ptr2->coef;
				ptr2 = ptr2->next;
			}
			else {
				exp = ptr1->exp;
				coef = ptr1->coef + ptr2->coef;
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
		}
		poly3 = AddNode(poly3, coef, exp);

	}
	return poly3;
} //end-Add

//-------------------------------------------------
// Subtracts poly2 from poly1 and returns the resulting polynomial
// Computes: poly3 = poly1 - poly2 and returns poly3
//
PolyNode* Subtract(PolyNode* poly1, PolyNode* poly2) {
	// Fill this in
	PolyNode* poly = CreatePoly((char*)"-1");
	poly2 = Multiply(poly, poly2);
	return Add(poly1, poly2);
} //end-Substract

//-------------------------------------------------
// Multiplies poly1 and poly2 and returns the resulting polynomial
// Computes: poly3 = poly1 * poly2 and returns poly3
//
PolyNode* Multiply(PolyNode* poly1, PolyNode* poly2) {
	// Fill this in
	PolyNode* poly3 = new PolyNode();
	poly3->coef = 0;
	poly3->exp = 0;
	poly3->next = NULL;
	PolyNode* ptr1 = poly1;
	PolyNode* ptr2 = poly2;
	int exp = 0;
	double coef = 0;
	while (ptr1 != NULL) {
		while (ptr2 != NULL) {

			coef = ptr1->coef * ptr2->coef;
			exp = ptr1->exp + ptr2->exp;
			poly3 = AddNode(poly3, coef, exp);
			ptr2 = ptr2->next;
		}
		ptr2 = poly2;
		ptr1 = ptr1->next;
	}
	return poly3;
} //end-Multiply

//-------------------------------------------------
// Evaluates the polynomial at a particular "x" value and returns the result
//
double Evaluate(PolyNode* poly, double x) {
	// Fill this in
	PolyNode* p = poly;
	double sum = 0;
	while (p) {
		sum += pow(x, p->exp) * p->coef;
		p = p->next;
	}
	return sum;
} //end-Evaluate

//-------------------------------------------------
// Computes the derivative of the polynomial and returns it
// Ex: poly(x) = 3x^4 - 2x + 1-->Derivative(poly) = 12x^3 - 2
//
PolyNode* Derivative(PolyNode* poly) {
	// Fill this in
	PolyNode* p = poly;
	PolyNode* head = new PolyNode();
	while (p)
	{
		if (p->exp != 0)
		{
			head = AddNode(head, p->coef * p->exp, p->exp - 1);
		}
		p = p->next;
	}
	return head;
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
	char coordSystem[25][79];
	double y;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 79; j++)
		{
			coordSystem[i][j] = ' ';
		}
	}
	for (int i = x1; i <= x2; i++)
	{
		y = Evaluate(poly, i);
		if (13 - y > 25 || y >13)
			continue;
		coordSystem[13 - int(round(y))][40 + i] = '*';
	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 79; j++)
		{
			if (i == 13 && j == 40) {
				coordSystem[i][j] = '+';
			}
			else if (j % 5 == 0 && i == 13 && j != 40) {
				coordSystem[i][j] = '+';
			}
			else if (j % 5 != 0 && i == 13 && j != 40) {
				coordSystem[i][j] = '-';
			}
			else if (i % 5 == 3 && j == 40 && i != 13) {
				coordSystem[i][j] = '+';
			}
			else if (i % 5 != 3 && j == 40 && j != 13) {
				coordSystem[i][j] = '|';
			}
			
			cout << coordSystem[i][j];
		}
		cout << endl;
	}

} //end-Plot
