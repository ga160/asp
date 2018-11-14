#include <iostream>
#include "Stack.h"
#include "Queue.h"


using namespace std;

template <typename T>
class Tree {
	struct Node {
		bool postOrderFlag;
		T info;
		Node* right;
		Node* left;
		Node() {
			postOrderFlag = false;
			right = left = nullptr;
		}
		Node(T i) {
			info = i;
			postOrderFlag = false;
			right = left = nullptr;
		}
	};
	Node* root;



public:
	class Huffman {
		struct Character {
			int freq;
			char c;
			Character(int i = 0) { freq = i; c = '-'; };
			Character(int i, char ch) { freq = i; c = ch; };
		};

		Tree<Character> t;
		//Tree<Character>::Node n;

	public:
		void Huffman::sort(Node * c)
		{
			Node temp;
			int length = sizeof(c) / sizeof(Node);
			for (int i = 0; i < length - 1; i++)
				for (int j = i + 1; j<length; j++)
					if (c[i].info.freq < c[j].info.freq) {
						temp = c[i];
						c[i] = c[j];
						c[j] = temp;
					}
		}

		void Huffman::sHuffman(Character * c)
		{
			Tree<Node*> t;
			int length = sizeof(c) / sizeof(Character);
			Node *niz = new Node[length];
			for (int i = 0; i < length; i++) {
				niz[i].info = c[i];
				

			}






	};

	Tree() { root = nullptr; }
	
	Node* getRoot() const { return root; }
	//Node* find(T k) {}
	void preorder(void(*f)(Node*)) {
		Node* next;
		Stack<Node*> s(10);
		s.push(root);
		while (!s.empty()) {
			next = s.pop();
			while (next) {
				f(next);
				if (next->right)
					s.push(next->right);
				next = next->left;
			}


		}
	}
	void inorder(void(*f)(Node*)) {
		Node* next = root;
		Stack<Node*> s(10);
		while (true) {
			while (next) {
				s.push(next);
				next = next->left;
			}
			if (!s.empty()) {
				next = s.pop();
				f(next);
				next = next->right;
			}
			else break;
		}
	}
	void postorder(void(*f)(Node*)) {
		
		Node *next = root;
		Stack<Node*> s(15);
		while (next) {
			s.push(next);
			next = next->left;
		}
		while (!s.empty()) {
			next = s.pop();
			if (!next->postOrderFlag) {
				next->postOrderFlag = !(next->postOrderFlag);
				s.push(next);
				next = next->right;
				while (next) {
					s.push(next);
					next = next->left;
				
				}
			}
			else {
				next->postOrderFlag = !(next->postOrderFlag);
				f(next);
			}

		}
	
	
	}
	void levelOrder() {
		Node *next = root;
		Queue<Node*> q;
		q.insert(next);
		while (!q.isEmpty()) {
			next = q.get();
			cout << next->info;
			if (next->left) q.insert(next->left);
			if (next->right) q.insert(next->right);
		}


	}
	void insertAVL(int x) {
		Node* n = new Node(x);
		//n->info = x;
		if (!root) root = n;
		else {
			Node* curr = root;
			while (curr) {
				if (curr->info >= x) {
					if (!curr->left) {
						curr->left = n;
						curr = nullptr;
					}
					else curr = curr->left;

				}
				else if (curr->info <= x)
				{
					if (!curr->right) {
						curr->right = n;
						curr = nullptr;
					}
					else curr = curr->right;
				}
				else curr = nullptr;

			}
		}

	};
	friend void print(Node*n) { cout << n->info; }
	friend void del(Node*n) { delete n; }
	~Tree() {
		postorder(del);
	};


};