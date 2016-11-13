#include <iostream>
using namespace std;

//Returns GCD of 2 numbers
inline int gcd(int a,int b){
	int temp;
	while(b!=0){
		temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}

int main(){
	int a=17,b=19;					//Small primes are used instead of actual big primes in this program
	int n=a*b;						//MUST be greater than 255 (Plain text is chars which can have a max value of 255)
	int z=(a-1)*(b-1);				//z represents (a-1)(b-1)

	cout<<"a:\t\t"<<a<<'\n';
	cout<<"b:\t\t"<<b<<'\n';
	cout<<"n=a*b:\t\t"<<n<<'\n';
	cout<<"(a-1)*(b-1):\t"<<z<<'\n';

	int x,y;						//The keys
	for(x=z-2;gcd(x,z)!=1;--x);		//Find x such that x and (a-1)(b-1) are relatively prime
	cout<<"x:\t\t"<<x<<'\n';
	for(y=2;x*y%z!=1;++y);			//Find y such that xy mod (a-1)(b-1) = 1
	cout<<"y:\t\t"<<y<<'\n';

	string msg;
	cout<<"Enter message to be encrypted:\n";
	cin>>msg;

	int i,j,len=msg.length();
	int m[len];						//Plain text
	int c[len];						//Cipher text

	//Encryption phase (c=m^x mod n)
	for(i=0;i<len;++i){
		m[i]=msg[i];

		c[i]=m[i]%n;
		for(j=1;j<x;++j)
			c[i]=c[i]*m[i]%n;
	}
	cout<<"Encrypted message:\n";
	for(i=0;i<len;++i)
		cout<<c[i]<<' ';
	cout<<'\n';

	//Decryption phase (m=c^y mod n)
	for(i=0;i<len;++i){
		m[i]=c[i]%n;
		for(j=1;j<y;++j)
			m[i]=m[i]*c[i]%n;

		msg[i]=m[i];
	}
	cout<<"Decrypted message:\n";
	cout<<msg<<'\n';

	return 0;
}