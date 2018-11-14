#pragma once

template<typename T>
class Stack {
	int top, length;
	T *niz;

public:
	bool empty() const {
		return !top;
	}
	Stack(int size) {
		length = size;
		niz = new T[length];
		top = 0;
	}
	void push(T t) {
		if (top==length) throw overflow_error("Overflow");
		niz[top++] = t;
	}
	T pop() {
		if (!top) throw underflow_error("Underflow");
		return niz[--top];
	}
	/*T top() const {
		if (!top) throw underflow_error("Underflow");
		return niz[top]; }*/


};