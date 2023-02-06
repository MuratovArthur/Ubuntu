#include "stack.h"


int stack::getLength() const{
	return length;
};


void stack::print(std::ostream& out) const{
	out<<"{";
	for(int i=0; i<length; i++){
		out<<array[i];
		if(i!=length-1){
		out<<", ";
		}
	}
	out<<"}\n";
}

void stack::push_back(int element){	
	int* array_ptr = array;
	int* array_r = new int[++length];
	int i;
	for(i=0; i<length-1;i++){
		array_r[i]=array[i];
	}
	array_r[i]=element;
	array=array_r;
	delete[] array_ptr;
};

void stack::pop(){
	--length;
	
};
