#include <iostream>
#include <string>

using namespace std;

void decode( int x, int &a, int &b, int &c ) {
	a = ((x - 1) % 81) + 1;
	b = ((x - 1 - 81 * (a - 1)) % 9) + 1;
	c = (x - 1 - 81 * (a - 1) - 9 * (b - 1)) + 1;
}

int main() {
	string line;
	cin >> line;
	if ( line.compare("UNSAT") == 0 ) {
		cerr << "no solution";
		return 0;
	}

	int board[9][9];
	int lit;
	bool pos;
	int var, a, b, c;
	while ( cin >> lit ) {
		if ( lit == 0 ) {
			break;
		}
		if ( lit < 0 ) {
			continue;
		}
		pos = lit > 0;
		var = pos ? var : -var;
		decode( var, a, b, c );
		if ( 1 <= a && a <= 9 &&
			 1 <= b && b <= 9 &&
			 1 <= c && c <= 9 ) {
			board[a - 1][b - 1] = c;
		}
	}

	for ( int i = 0; i < 9; i += 1 ) {
		int row = i * 9;
		for ( int j = 0; j < 3; j += 1 ) {
			int square = j * 3;
			if ( j ) {
				cout << ' ';
			}
			for ( int k = 0; k < 3; k += 1 ) {
				cout << board[row][square + k];
			}
		}
		cout << endl;
	}

	return 0;
}

