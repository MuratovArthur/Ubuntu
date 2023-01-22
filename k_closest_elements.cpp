#include <iostream>
#include <vector>

/*
	Extreme cases:
	1. x < array[0]
		all elements from 0 to k
	2. x > array[length]
		all elements from length-k to length
	
	General case:
	array[x]<x<array[length]
	1. x in array	
		push x to result
		for i < k:
			int l=1, r=1;
			if((array[in_pos-l]-x)<=(array[in_pos+r]-x))
				push array[in_pos-1],
				l++;
				
			else -> push array[i+1], r++;
				
	2. x is not in array
		push last element smaller than x to result
		for i < k:
			if((array[i-1]-x)<=(array[i+1]-x)) -> push array[i-1]
			else -> push array[i+1]
		
	
*/

std::vector<int> find_k_closest_elements(std::vector<int>& param_1, int& param_2, int& param_3)
{
	std::vector<int> result;
  	int k=param_2;
  	int x=param_3;
  	int left=0;
  	int right=param_1.size()-1;
  	int avg=(left+right)/2;;
  	while(left<=right){
  		//std::cout<<"left: "<<left<< ", right: "<<right<<", avg: "<<avg<<std::endl;
  		if(param_1[avg]==x||avg==0||avg==param_1.size()-1){
  			break;
  		}
  		if(param_1[avg]>x){
  			right = avg-1;
  		}else if(param_1[avg]<x){
  			left = avg+1;
  		}
  		avg=(left+right)/2;
  	}
  	int initial_position=avg;
  	//std::cout<<"in pos: "<< initial_position<<std::endl;
  	
  	int pushed=0;
  	if(initial_position==0)
  	{
  		for(int i=0;i<k;i++){
  			result.push_back(param_1[i]);
  			pushed++;
  		}
  	}
  	else if(initial_position==param_1.size()-1)
  	{
  		for(int i=param_1.size()-k;i<param_1.size();i++){
  			result.push_back(param_1[i]);
  			pushed++;
  		}
  	}
  	else{
  		result.push_back(param_1[initial_position]);
  		//std::cout<<"what is pushed: " << param_1[initial_position]<<std::endl;
  		pushed++;
  		int l=1;
  		int r=1;
  		while(pushed!=k){
  			//std::cout<<"left value: "<<param_1[initial_position-l]<<" middle value: "<<param_1[initial_position]<<" right value: "<<param_1[initial_position+r]<<std::endl;
  			//std::cout<<"diff: "<<(param_1[initial_position-l]-x)*(-1)<<", "<<param_1[initial_position+r]-x<<std::endl;
  			if((param_1[initial_position-l]-x)*(-1)<=(param_1[initial_position+r]-x)){
  				result.push_back(param_1[initial_position-l]);
  				//std::cout<<"what is pushed: " << param_1[initial_position-l]<<std::endl;
  				pushed++;
  				l++;
  				if(l>initial_position){
  					//std::cout<<"left limit reached"<<std::endl;
  					break;
  				}
  			}else if((param_1[initial_position-l]-x)*(-1)>(param_1[initial_position+r]-x)){
  				result.push_back(param_1[initial_position+r]);
  				//std::cout<<"what is pushed: " << param_1[initial_position+r]<<std::endl;
  				pushed++;
  				r++;
  				if(r+initial_position>=param_1.size()){
  					//std::cout<<"rigth limit reached"<<std::endl;
  					break;
  				}
  			}
		}
		if(l>initial_position){
			
			for(int i=initial_position+r; pushed<k; i++){
				result.push_back(param_1[i]);
				//std::cout<<"what is pushed after: " << param_1[i]<<std::endl;
				pushed++;
			}
		}else if(r+initial_position>=param_1.size()){
			for(int i=initial_position-l; pushed<k; i--){
				result.push_back(param_1[i]);
				//std::cout<<"what is pushed after: " << param_1[i]<<std::endl;
				pushed++;
			}
		}
		for(int i=0; i<k;i++){
	  		for(int j=0; j<k-1;j++){
	  			if(result[j]>result[j+1]){
	  				int temp = result[j];
	  				result[j]=result[j+1];
	  				result[j+1]=temp;
	  			}
	  		}
	  	}
  	}
  	
  	
  	
  return result;
}


int main(){
	std::vector<int> numbers={1, 2, 3, 3, 6, 6, 7, 7, 9, 9};
	int k=8;
	int x=8;
	std::vector<int> result = find_k_closest_elements(numbers, k, x);
	//std::cout<<"Printing result: "<<std::endl;
	for(int i=0; i<result.size();i++){
	    	std::cout<<result[i]<<std::endl;
   	}
	return 0;
}
