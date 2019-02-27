#ifndef VECTOR_H
#define VECTOR_H

#include "Planet.h"

class Vector{
	private:
		int length;
	public:
        Planet ** planets = new Planet *[0];
        Vector();
        ~Vector();
        void insert(int index, Planet *p);
        Planet *read(int index);
        bool remove(int index);
        unsigned size();
};

#endif