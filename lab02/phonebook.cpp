
#include "phonebook.h"

void PhoneEntry::print( std::ostream& out ) const 
{
	out << firstname << " "<< secondname<<" "<< number<<"\n";
}

void PhoneEntry::read( std::istream& in )
{
	in >> firstname>> secondname>> number;
}

void PhoneBook::read( std::istream& in ) 
{	
	PhoneEntry p;
	while(in>>p){
		entries.push_back(p);
		if(in){
			continue;
		}else{
			break;
		}
	}
}

void PhoneBook::print(std::ostream & out) const {
  for (int i = 0; i < entries.size(); i++) {
    out << entries[i];
  }
}

void PhoneBook::checkandnormalize( std::ostream& err )
{
	for(int i=0; i<entries.size();i++){
		if(entries[i].number.iswellformed()==false){
			err<<entries[i].number<<": number is invalid"<<"\n";
		}
		entries[i].firstname.normalize();
		entries[i].secondname.normalize();
	}
}


