#ifndef STACK_H_
#define STACK_H_

#include <initializer_list>
#include <iostream>

class stack{
	int length;
	int* array;
	
public:
	// default constructor
	stack()
	:length(0),
	array(new int[0])
	{};
	
	// length-based constructor
	stack(int l)
	:length(l),
	array(new int[l])
	{};
	
	// length-based constructor
	stack(std::initializer_list<int> ilist)
	:length(ilist.size()),
	array(new int[ilist.size()])
	{
		
		int i=0;
		for(int val : ilist){
			array[i]=val;
			++i;
		}
	}
	
	// copy constructor
	stack(const stack& other_stack)
	:length(other_stack.length),
	array(new int[other_stack.length])
	{
		for(int i=0; i<length;i++){
			array[i]=other_stack.array[i];
		}
	}
	
	// assignment operator
	stack& operator=(const stack& some_stack){
		if(this == &some_stack){
			return *this;
		}
		
		length=some_stack.length;
		delete[] array;
		array = new int[length];
		for(int i=0; i<length; i++){
			array[i]=some_stack.array[i];
		}
		return *this;
	};

	
	// print function
	void print(std::ostream& out) const;
	
	// get the length of the stack
	int getLength() const;
	
	// push_back
	void push_back(int element);
	
	// pop
	void pop();
	
	~stack(){
		delete[] array;
	};
};

inline std::ostream& operator<< (std::ostream& out,const stack& some_stack){
	some_stack.print(out);
	return out;
};

#endif
