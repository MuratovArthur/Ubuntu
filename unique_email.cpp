/*
**
** QWASAR.IO -- unique_email_addresses
**
** @param {std::vector<std::string>} param_1
**
** @return {int}
**
*/

#include <iostream>
#include <vector>
#include <string>

int unique_email_addresses(std::vector<std::string>& param_1)
{	
int result=0;
	for(int i=0; i<param_1.size(); i++){
	// for every email
      		bool domain_reached=false;
		for(int j=0; j<param_1[i].length();j++){
		
		//std::cout<<"i: "<<i<<", j: "<< j<<std::endl;
			  if(param_1[i][j]==64){
			    domain_reached=true;
			  }
			  if(param_1[i][j]==46&&domain_reached==false){
			  	int k;
			    for(k=j; k<param_1[i].length()-1;k++){
			      param_1[i][k]=param_1[i][k+1];
			    }
			    param_1[i][k]=0;
			    j--;
			    // std::cout<<"edited after comma: "<<param_1[i]<<std::endl;
			    param_1[i].resize(param_1[i].length()-1);
			  }
			  if(param_1[i][j]==43&&domain_reached==false){
			    int k=j;
			    int shift=0;
			    while(param_1[i][k]!=64){
			      k++;
			      shift++;
			    }
			   
			    	while(k<param_1[i].length()){
				    param_1[i][k-shift]=param_1[i][k];
				    k++;
				}
				param_1[i].resize(param_1[i].length()-shift);
				j--;
			      //std::cout<<"edited after plus: "<<param_1[i]<<std::endl;
			       
			  }
		}
       // std::cout<<"edited email: "<<param_1[i]<<std::endl;
    }
    for(int i=0; i<param_1.size(); i++){
    	bool unique=true;
    	for(int j=i+1; j<param_1.size(); j++){
    		//std::cout<<param_1[i].length()<<"->" << param_1[j].length()<<"->" <<std::endl;
    		if(param_1[i].compare(param_1[j])==0&&(i!=j)){
    			unique=false;
    			break;
    		}
    		//std::cout<<unique<<std::endl;
    	}
    	if(unique){
    		result++;
    	}
    }
    return result;
}


int main(){
	std::vector<std::string> test = {"test.email+alex@qwasar.io","test.e.mail+bob.cathy@qwasar.io","testemail+david@lee.tcode.com"};
	int res = unique_email_addresses(test);
	std::cout<<"res: "<<res<< std::endl;
	return 0;
}
