#include "Huffman.h"

void Huffman::sort(Character * c)
{
	Character temp;
	int length = sizeof(c) / sizeof(Character);
	for (int i = 0; i < length - 1; i++)
		for (int j = i + 1; j<length; j++)
			if (c[i].freq > c[j].freq) {
				temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
}

void Huffman::sHuffman(Character * c)
{
	
	sort(c);

		
			
}
