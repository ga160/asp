#pragma once
template <typename T>
class List {
	struct Node {
		T info;
		Node* next;

	};
	Node* first;
	Node* last;


public:
	List() { first = last = nullptr; }
	Node* getFirst() const { return first; }
	Node* getLast() const { return last; }
	bool isEmpty() const { return !first; }
	void insertFirst(T t) {
		Node* p = new Node;
		p->info = t;
		if (!last) last = p;
		else p->next = first;
		first = p;
	}
	void insertLast(T t) {
		Node* p = new Node;
		p->info = t;
		p->next = nullptr;
		if (!last) first = p;
		else last->next = p;
		last = p;
	}
	void invert() {
		Node* p = first;
		Node* q = nullptr;
		Node* r;
		while (p) {
			r = q;
			q = p;
			p = p->next;
			q->next = r;
		}
		first = q;
	}
	friend void concat(Node* list1, Node* list2) {
		if (!list1) {
			list1 = list2;
			return;
		}
		if (!list2) return;
		Node* p = list1;
		while (p->next) p = p->next;
		p->next = list2;
		
			
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
};