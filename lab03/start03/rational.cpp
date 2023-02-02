
#include "rational.h"

bigint gcd( bigint n1, bigint n2 )
{
	if(n1==0&&n2==0){
		std::runtime_error( "GCD: both arguments are zero" );
	}
	if(n1<0){
		n1=n1*(-1);
	}
	if(n2<0){
		n2=n2*(-1);
	}
	if(n1==0){
		return n2;
	}
	if(n2==0){
		return n1;
	}
	
	bigint r;
	while ((n1 % n2) > 0)  {
	    r = n1 % n2;
	    n1 = n2;
	    n2 = r;
	}
  	return n2;
}


void rational::normalize()
{
	if(denom==0){
		throw std::runtime_error( "rational: denom == 0" );
	}
	
	bigint gcd_num = gcd(num, denom);
	num=num/gcd_num;
	denom=denom/gcd_num;
	if((num<0&&denom<0)||(denom<0&&num>0)){
		num=num*(-1);
		denom=denom*(-1);
	}
}

double rational::approximation( ) const
{
   return num. approximation( ) / denom. approximation( ); 
}

rational rational::operator - ( ) const 
{
	rational res(0);
	res.num=num*(-1);
	res.denom=denom;
	return res;
}

rational rational::operator + ( const rational& r2 ) const 
{	
	rational res((num*r2.denom+r2.num*denom), denom*r2.denom);
	return res;
}

rational rational::operator - ( const rational& r2 ) const 
{
	rational res((num*r2.denom-r2.num*denom), denom*r2.denom);
	return res;
}

rational rational::operator * ( const rational& r2 ) const 
{
	rational res(num*r2.num, denom*r2.denom);
	return res;
}

rational rational::operator / ( const rational& r2 ) const 
{
	rational res(num*r2.denom, denom*r2.num);
	return res;
}

// Putting the full trust in our normalization:

bool rational::operator == ( const rational& r2 ) const
{
	if(num==r2.num&&denom==r2.denom){
		return true;
	}else{
		return false;
	}
}

bool rational::operator != ( const rational& r2 ) const
{
	if(num!=r2.num||denom!=r2.denom){
		return true;
	}else{
		return false;
	}
}

void rational::print( std::ostream& stream ) const 
{
	if(denom!=1){
		stream<<num<<"/"<<denom;
	}else{
		stream<<num;
	}
}


