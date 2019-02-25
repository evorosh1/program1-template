#ifndef HEADER_P1
#define HEADER_P1

class List{
	private:
		unsigned int size;
		Node * head;
		Node * tail;
	public:	
		List();
		~List();
		void insert(int index, Planet * x);
		Planet* read(int ind);
		bool remove(int ind);
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
