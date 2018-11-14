#include "Compression.h"

char * convStr(std::string c)
{
	char * s = new char[c.length() + 1];
	for (int i = 0; i < c.length(); i++) s[i] = c[i];
	s[c.length()] = '\0';
	return s;
}

void RLECompress(std::string x, char * izlaz)
{
	char *poruka = convStr(x);
	char c = *poruka, *pointer;
	int broj;
	while (c) {
		broj = 0;
		if (c == *(++poruka)) {
			while (*poruka && c == *poruka && broj < 127) {
				broj++;
				poruka++;
			}
			*izlaz++ = (char)broj;
			*izlaz++ = c;
			c = *poruka;
		}
		else {
			pointer = izlaz++;
			while (*poruka && c != *poruka && broj < 127) {
				broj++;
				*izlaz++ = c;
				c = *poruka++;
			}
			if (!*poruka) {
				broj++;
				*izlaz++ = c;
				c = *poruka;
			}
			else poruka--;
			*pointer = (char)(-broj);

		}

	}
	*izlaz = 0;


}

void RLEDecompress(std::string x, char * izlaz)
{
	char *poruka = convStr(x);
	char c = *poruka;
	int i, n;
	while (*poruka) {
		if (*poruka > 0) {
			n = *poruka++;
			for (i = 0; i <= n; i++)
				*izlaz++ = *poruka;
			poruka++;
		}
		else{
			n = -*poruka++;
			for (i = 0; i < n; i++)
				*izlaz++ = *poruka++;
		}
	}
	*izlaz = 0;
}

void compressTest()
{
	string c = "ABABAA";
	char compressed[256];
	char decompressed[256];

	RLECompress(c, compressed);
	RLEDecompress(compressed, decompressed);

	cout << c << endl << compressed << endl << decompressed << endl;

}


