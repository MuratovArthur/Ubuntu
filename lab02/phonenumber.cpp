
#include "phonenumber.h"

bool PhoneNumber::iswellformed( ) const 
{
	if(nr.length()<10||nr.length()>20||nr[0]!='+'){
		return false;
	}
	for(int i=1; i<nr.length();i++){
		if(isdigit(nr[i])==0){
			return false;
		}
	}
	return true;
}

 
