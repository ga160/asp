#pragma once
#include "Queue.h"
#include "Tree.h"

class Huffman {
	struct Character{
		int freq;
		char c;
		Character(int i = 0) { freq = i; c = '-'; };
		Character(int i, char ch) { freq = i; c = ch; };
	};
	
	Tree<Character> t;
	Tree<Character>::Node n;

public:
	void sort(Character * c);

	void sHuffman(Character *c);
	


};