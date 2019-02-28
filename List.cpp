#include "List.h"
#include "Planet.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Node::Node(Planet *x){
	this->x = x;
	this->prev = NULL;
	this->next = NULL;
}

List::List(){
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;
}

List::~List(){
	Node * tem = head;
	for(int i = 0; i < size()-1; i++){
		if(tem != tail) {
			tem = tem->next;
			delete tem->prev;
		} else break;
	}
	if(tem != NULL) delete tem;
}

void List::insert(int index, Planet * x){
	Node * newNode = new Node(x);
	if(size() == 0) {
		head = newNode;
		tail = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
		this->length++;
		return;
	}
	int i = 0;
	Node * tem = head;
	Node * current;
	if (index >= size()){
		while (tem->next != NULL){
			tem = tem->next;
		}
		tem->next = newNode;
		newNode->prev = tem;
		tail = newNode;
		this->length++;
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
		current = tem->prev;
		current->next = newNode;
		newNode->prev = current;
		newNode->next = tem;
		tem->prev = newNode;
	}
	else {
		current->next = tem;
		tem->prev = current;
		current->prev = NULL;
		head = current;
		this->length++;
		return;
	}
	this->length++;
	return;
}

Planet* List::read(int index){
	int i = 0;
	Node * place = head;
	if (index >= size()) return NULL;
	while (i != index){
		place = place->next;
		i++;
	}
	return place->x;
}

bool List::remove(int index){
	Node * temp = head;
	int i = 0;
	if (index == 0){
		head = temp->next;
		delete(temp);
		this->length--;
		return true;
	}
	if (index == size()-1){
		temp = tail;
		tail = tail->prev;
		delete temp;
		this->length--;
		return true;
	}
	while (i != index){
		temp = temp->next;
		i++;
	}
	if(i == index) {
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		this->length--;
		return true;
	}
	return false;
}

unsigned List::size(){
	return this->length;
}
