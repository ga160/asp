#pragma once
template <typename T>
class Queue {
	struct Node {
		T info;
		Node* next;

	};
	Node* first;
	Node* last;


public:
	Queue() { first = last = nullptr; }
	bool isEmpty() const { return !first; }
	void insert(T t) {
		Node* p = new Node;
		p->info = t;
		p->next = nullptr;
		if (!last) first = p; 
		else last->next = p;
		last = p;
	}
	T  get() {
		if (!first) throw underflow_error("Underflow");
		else {
			Node *p = first;
			T x = first->info;
			first = p->next;
			if (!first) last = first;
			delete p;
			return x;
		}
	}

	T* Min() {
		if (!first) throw underflow_error("Underflow");
		T* min = first;
		for (Node* curr = first; curr->next; curr = curr->next)
			if (curr->info < min->info)
				min = curr;
		
	}

	



};