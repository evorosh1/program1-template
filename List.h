#ifndef HEADER_P1
#define HEADER_P1

#include "Planet.h"

class Node{
	public:
		Node(Planet *x);
		Planet *x;
		Node * next;
		Node * prev;
};

class List{
	private:
		unsigned int length;
		Node * head;
		Node * tail;
	public:	
		List();
		~List();
		void insert(int index, Planet * x);
		Planet* read(int ind);
		bool remove(int ind);
		unsigned size();
};

#endif