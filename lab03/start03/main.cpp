
#include "rational.h"

void compare( const rational& r1, const rational& r2 )
{
   std::cout << r1 << " equal to " << r2 << "?\n";
   if( r1 != r2 ){
      std::cout << "no!\n";
   }else{
      std::cout << "yes!\n";
   }
}

int main( int argc, char* argv [ ] )
{
   if( !bigint::testmachine( )){
      throw std::runtime_error( "bigint cannot work on this computer" ); 
   }

  
   rational rrr( bigint( "44444444444444444444444444" ), 
                 bigint( "-55555555555555555555555555" ));
  
  // std::cout << rrr << "\n";
   
    
   /*
   bigint a = 5;

   rational r = rational(1,6);
   r = r * 2; 
   std::cout << r << "\n";    // prints 1/3
   r = -r ;    
   std::cout << r << "\n";
   r = r / 3;      // prints -1/3. 
   std::cout << r << "\n";  // prints -1/9. 
   r = r-1;
   std::cout << r << "\n";  // prints -1/9. 
   */
   
   rational r5(-10);
   std::cout << -r5 << "\n";

   rational r6(10, -8);
   std::cout << -r6 << "\n";

   rational r7(-10, -8);
   std::cout << -r7 << "\n";


   rational r1( 2, 6 );
   rational r2( 4, 3 ); 
   rational r3( 5,6 );
   rational r4( 1, 2 );
   
 

   compare( r1 + r2,   r2 + r1 );  
   compare( r1 * ( r2 + -r3 ),   r2 * r1 - r1 * r3 );

   // add more tests. 
   return 0;
}

