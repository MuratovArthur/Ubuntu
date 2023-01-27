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
  std::cout << book << "\n";

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
