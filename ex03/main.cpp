#include <iostream>
#include "Point.hpp"

static void runTest(const char *label, Point const a, Point const b, Point const c, Point const p)
{
	std::cout << label << ": " << (bsp(a, b, c, p) ? "inside" : "outside") << std::endl;
}

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	runTest("inside (2,2)", a, b, c, Point(2.0f, 2.0f));
	runTest("outside (8,8)", a, b, c, Point(8.0f, 8.0f));
	runTest("on edge (5,0)", a, b, c, Point(5.0f, 0.0f));
	runTest("on vertex (0,0)", a, b, c, Point(0.0f, 0.0f));

	return (0);
}
