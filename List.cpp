#include "List.h"
#include <cstdlib>
#include <iostream>

Node::Node(Planet * x){
	this->x = x;
	this->prev = NULL;
	this->next = NULL;
}

List::List(){
	this->head = NULL;
	this->tail = NULL;
	this->len =0;
}

List::~List(){
	Node * tem = head;
	if(tem ==NULL) return;
	for(int i = 0; i < size; i++){
		if(tem->next != NULL){
			tem = tem->next;
			delete(tem->prev->x);
			delete(tem->prev);
		}
	}
	delete(tem->p);
	delete(tem);
}

void List::insert(unsigned int idx, Planet * x){
	unsigned int j = 0;
	Node * tem = head;
	Node * newNode = new Node(x);
	Node * current;
	len++;
	if (idx +1 >= len){
		while(tem-> next != NULL){
			tem = tem->next;
		}
		tem->next = newNode;
		newNode->prev = tem;
		tail = newNode;
		return;
	}
	if (idx == 0){
		newNode->next = tem;
		tem->prev = newNode;
		head = newNode;
	}
	if(j == idx){
		current= tem->prev;
		current->next = newNode;
		newNode->prev = current;
		newNode->next = tem;
		tem->prev = newNode;
	}
	if(len ==1){
		head = newNode;
		tail = newNode;
		return;
	}
	while (j != idx){
		tem = tem->next;
		j=j+1;
	}

	return;
}

Planet* List::read(unsigned int idx){
	unsigned int j = 0;
	Node * place = head;
	if (idx >= len) return NULL;
	while (j != idx){
		place = place->next;
		j++;
	}
	return place->x;
}

bool List::remove(int idx){
	Node * curr = head;
	if(idx >= len){
		return false;
	}
	len= len-1;
	unsigned int j = 0;
	if (idx == 0){
		head = curr->next;
		head->prev = NULL;
		delete(curr->x);
		delete(curr);
		return true;
	}
	if (idx == len){
		curr = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete (curr->x);
		delete (curr);
		return true;
	}
	while (j != idx){
		curr = curr->next;
		j=j+1;
	}
	if(i == idx) {
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		delete(curr->x);
		delete(curr);
		return true;
	}
	return false;
}

unsigned List::size(){
	return len;
}

