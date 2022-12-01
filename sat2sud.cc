#include <iostream>

using namespace std;

void decode( int x, int &a, int &b, int &c ) {
	a = ((x - 1) % 81) + 1;
	b = ((x - 1 - 81 * (a - 1)) % 9) + 1;
	c = (x - 1 - 81 * (a - 1) - 9 * (b - 1)) + 1;
}

int main() {


	return 0;
}
