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
}

List::~List(){
	Node * tem = head;
	for(int i = 0; i < size; i++){
		tem = tem->next;
		delete(tem->prev);
	}
	delete(tem);
}

void List::insert(int ind, Planet * x){
	int i = 0;
	Node * tem = head;
	Node * newNode = new Node(x);
	Node * current;
	size++;
	if (index >= size){
		while (tem->next != NULL){
			tem = tem->next;
		}
		tem->next = newNode;
		newNode->prev = tem;
		tail = newNode;
		return;
	}
	if (index == 0){
		newNode->next = tem;
		tem->prev = newNode;
		head = newNode;
	}
	while (i != index){
		tem = tem->next;
		i++;
	}
	if(i == index){
		current= tem->prev;
		current->next = newNode;
		newNode->prev = current;
		newNode->next = tem;
		tem->prev = newNode;
	}
	return;
}

Planet* List::read(int ind){
	int i = 0;
	Node * place = head;
	if (index >= size) return NULL;
	while (i != index){
		place = place->next;
		i++;
	}
	return place->x;
}

bool List::remove(int ind){
	size--;
	Node * temp = head;
	int i = 0;
	if (index == 0){
		head = temp->next;
		delete(temp);
		return true;
	}
	if (index == size){
		temp = tail;
		tail = tail->prev;
		delete (temp);
		return true;
	}
	while (i != index){
		temp = temp->next;
		i++;
	}
	if(i == index) {
		temp->prev = temp->next;
		temp->next = temp->prev;
		delete(temp);
		return true;
	}
	return false;
}

unsigned List::size(){
	return size;
}

