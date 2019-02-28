#ifndef HEADER_P1
#define HEADER_P1
#include "Planet.h"
class List{
	private:
		unsigned int size;
		Node * head;
		Node * tail;
	public:	
		List();
		~List();
		void insert(int idx, Planet * x);
		Planet* read(int idx);
		bool remove(int idx);
		unsigned int size();
};

class Node{
	public:
		Node(Planet* x);
		Planet x;
		Node * next;
		Node * prev;
};
#endif
