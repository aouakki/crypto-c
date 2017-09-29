#include<stdio.h>
#include<stdlib.h>


typedef unsigned long int Huge ; 
Huge dd=0 ;
Huge ee= 0 ; 
Huge nn = 0 ; 

static Huge modexp(Huge a , Huge b , Huge n ) {

	Huge y =1 ; 
	while ( b!= 0 ){
		if(b != 0 ) {

			y =(y*a)%n ; }
		a = (a*a)%n ; 
		b=b>>1 ; 

	}
	return y ; 

}
static gcd ( Huge a, Huge b )
{
	Huge c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

void GetKeys(Huge P,Huge Q){

	Huge n = P*Q ; 
	Huge phi = (P-1)*(Q-1); 
	Huge e = 2;
	// calcul de e 
	while(gcd(e,phi) != 1 && e<phi) {
		e++ ; 
	} 
	//calcul de d 
	Huge d = 2 ;
	while(d < phi && (e*d)%phi != 1 ){
	d++; 
	}
	printf("d %li \n" ,d ); 
	printf("e %li \n" ,e ); 
	ee =e ; 
	dd=d ;
	nn =n ;  
}

Huge rsa_crypt(Huge e,Huge n,Huge m){
	return  modexp(m,e,n) ; 
}

Huge rsa_decrypt(Huge d , Huge c,Huge n){
return modexp(c,d,n) ; 

}
int main (){
	Huge p = 31 ;
	Huge q = 137 ;
	GetKeys(p,q) ;

printf("message chif %li \n" , rsa_crypt(ee,nn,3333) ); 

printf("message dechif %li \n" ,rsa_decrypt(dd,2519,nn) ); 
	return 0 ;
}

