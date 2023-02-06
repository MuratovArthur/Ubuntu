#include <iostream>
#include "stack.h"


int main(){
	std::cout<<"Hello areke!\n";
	
	stack stk1;
	stack stk2(10);
	stack stk3 = {1, 2, 3, 4, 5};
	std::cout<<stk3.getLength()<<std::endl;
	
	stk2=stk3;
	stack stk4 = stk3;
	stk2.print(std::cout);
	stk3.push_back(10);
	stk4.print(std::cout);
	stk3.print(std::cout);
	stk4 = stk3;
	stk4.print(std::cout);
	
	
}
