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
}

List::~List(){
	Node * tem = head;
	for(int i = 0; i < size(); i++){
		tem = tem->next;
		delete(tem->prev);
	}
	delete(tem);
}

void List::insert(int index, Planet * x){
	int i = 0;
	Node * tem = head;
	Node * newNode = new Node(x);
	Node * current;
	cout << "1" << endl;
	if (index > size()){
		while (tem->next != NULL){
			tem = tem->next;
		}
		tem->next = newNode;
		newNode->prev = tem;
		tail = newNode;
		return;
	}
	cout << "2" << endl;
	if (index == 0){
		cout << "a" << endl;
		newNode->next = tem;
		cout << "b" << endl;
		tem->prev = newNode;
		cout << "c" << endl;
		head = newNode;
		cout << "d" << endl;
	}
	cout << "3" << endl;
	while (i != index){
		tem = tem->next;
		i++;
	}
	cout << "4" << endl;
	if(i == index){
		current = tem->prev;
		current->next = newNode;
		newNode->prev = current;
		newNode->next = tem;
		tem->prev = newNode;
	}
	cout << "5" << endl;
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
	this->length--;
	Node * temp = head;
	int i = 0;
	if (index == 0){
		head = temp->next;
		delete(temp);
		return true;
	}
	if (index == size()){
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
	return this->length;
}