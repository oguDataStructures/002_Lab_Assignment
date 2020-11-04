#include <stdio.h>
#include "PolyNode.h"
#include "Poly.h"

void Test1();
void Test2();
void Test3();

int main() {
	Test1();
	Test2();
	Test3();

	return 0;
} // end-main

/// ---------------------------------------------------------
/// Test1
/// 
void Test1() {
	printf("%40s", "******TEST1******\n");

	PolyNode* poly = NULL;
	printf("Initial poly: "); Print(poly);

	poly = AddNode(poly, -2, 5);
	printf("Adding -2x^5: "); Print(poly);

	poly = AddNode(poly, 4.4, 7);
	printf("Adding 4.4x^7: "); Print(poly);

	poly = AddNode(poly, 2, 3);
	printf("Adding 2x^3: "); Print(poly);

	poly = AddNode(poly, 1, 4);
	printf("Adding x^4: "); Print(poly);

	poly = AddNode(poly, 4, 4);
	printf("Adding 4x^4: "); Print(poly);

	poly = AddNode(poly, 2, 5);
	printf("Adding 2x^5: "); Print(poly);

	poly = AddNode(poly, -4.4, 7);
	printf("Adding -4.4x^7: "); Print(poly);

	poly = AddNode(poly, -2, 3);					//BURADA PATLIYOR 1
	printf("Adding -2x^3: "); Print(poly);

	poly = AddNode(poly, -5, 4);
	printf("Adding -5x^4: "); Print(poly);

} // end-Test1

///----------------------------------------------------------------
/// Test2: Creates several poly's from expressions
///
void Test2() {
	printf("%40s", "******TEST2******\n");

	PolyNode *poly = CreatePoly((char *)"-x^3  -  6x^2 + 4x + 22");
	printf("[-x^3  -  6x^2 + 4x + 22]: "); Print(poly);
	DeletePoly(poly);

	poly = CreatePoly((char*)"-x^2 +x  -  5");
	printf("[-x^2 +x  -  5]: "); Print(poly);
	DeletePoly(poly);

	poly = CreatePoly((char*)"2.3x^4 + 5x^3 - 2.6x - 4");
	printf("[2.3x^4 + 5x^3 - 2.6x - 4]: "); Print(poly);
	DeletePoly(poly);

	poly = CreatePoly((char*)"-4.5x^10 - 45.44");
	printf("[-4.5x^10 - 45.44]: "); Print(poly);
	DeletePoly(poly);

	poly = CreatePoly((char*)"x^6 + 24.6x^4 - x^3 - 61.3x^1 + 4.2");
	printf("[x^6 + 24.6x^4 - x^3 - 61.3x^1 + 4.2]: "); Print(poly);
	DeletePoly(poly);

	poly = CreatePoly((char*)" -x^34+x^20 -34.3x^5  +   x -  55");
	printf("[ -x^34+x^20 -34.3x^5  +   x -  55]: "); Print(poly);
	DeletePoly(poly);

	poly = CreatePoly((char*)"x^6 + 24.6x^4 - x^3 - 61.3x + 4.2");
	printf("[x^6 + 24.6x^4 - x^3 - 61.3x + 4.2]: "); Print(poly);
	DeletePoly(poly);

	poly = CreatePoly((char*)"-33");
	printf("[-33]: "); Print(poly);
	DeletePoly(poly);
} //end-Test2

///----------------------------------------------------------------
/// Creates two polys and adds them up
///
void Test3() {
	printf("%40s", "******TEST3******\n");

	PolyNode *poly1 = CreatePoly((char*)"-x^3  -  6x^2 + 4x + 22");
	printf("%25s", "Poly1[-x^3-6x^2+4x+22]: "); Print(poly1);

	PolyNode *poly2 = CreatePoly((char*)"-x^2 +x  -  5");
	printf("%25s", "Poly2[-x^2+x-5]: "); Print(poly2);

	PolyNode *poly3 = Add(poly1, poly2);
	printf("------------------------------------------------------- +\n");
	printf("%25s", "Poly1+Poly2: "); Print(poly3);

	DeletePoly(poly1);
	DeletePoly(poly2);
	DeletePoly(poly3);
} //end-Test3


