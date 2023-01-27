// Modern coding: We are going to center our code around types.
// Put different types in different files, and move the code to the type that
// they belong to (most)

// What is a type?
// simple view (old fashioned) : Type is defined by implementation.
// two things that have the same implementation, have the same type.
// In C if you define a type, you only define its implementation.

#include "phonebook.h"
#include <fstream>

int main(int argc, char * argv[]) {
  Name n("CATO");
  std::cout << n << "\n";

  n = Name("van-beethoven");
  std::cout << n << "\n";

  std::ifstream f("phonebook.txt");
  if (!f) {
    std::cout << "could not open the phonebook\n";
    return -1;
  }
  PhoneBook book;
  f >> book;
  std::cout << "Before normalization: \n";
  std::cout << book << "\n";
  book.checkandnormalize(std::cerr);
  std::cout << "\nAfter normalization: \n";
  std::cout << book;

  for (size_t i1 = 0; i1 != book.entries.size(); ++i1) {
    for (size_t i2 = i1 + 1; i2 != book.entries.size(); ++i2) {
      {
        if (book.entries[i1].secondname > book.entries[i2].secondname) {
          auto e = book.entries[i1];
          book.entries[i1] = book.entries[i2];
          book.entries[i2] = e;
        }
      }
    }
  }
  std::ofstream sorted( "sorted.txt" );
   if( !sorted ){
      std::cout << "could not open outputfile\n";
      return -1;
   }
   sorted << book;

  //std::cout << "After sorting: \n";
  //sorted << book;

  return 0;
}

#include "name.h"
#include <cctype> 

void Name::normalize( )
{
	n[0]=toupper(n[0]);
	for(int i=1; i<n.length();i++){
		n[i]=tolower(n[i]);
	}
}


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

 
