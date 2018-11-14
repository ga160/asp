#include "Tree.h"
#include "Compression.h"

void shuffle(int deck[], const int len) {
	int temp = 0;
	int randomIndex = 0;
	for (int i = 0; i < len; i++) {
		randomIndex = rand() % len;
		temp = deck[i];
		deck[i] = deck[randomIndex];
		deck[randomIndex] = temp;


	}
}

int main() {
	Tree<int> t;
	const int length = 10;
	int niz[length];
	for (int i = 0; i < length; i++)
		niz[i] = i;
	shuffle(niz, length);

	for (int i = 0; i < length; i++) {
		cout << niz[i];
		t.insertAVL(niz[i]);
	}
	cout << '\n';
	compressTest();

	system("PAUSE");


}