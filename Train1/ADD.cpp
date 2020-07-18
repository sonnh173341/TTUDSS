#include <iostream>
using namespace std;

int main(){
	unsigned long long a, b;
	cin>>a>>b;
	unsigned long long a1 = a%10;
	unsigned long long a2 = (a-a1)/10;
	unsigned long long b1 = b%10;
	unsigned long long b2 = (b-b1)/10;
	if(a1+b1>=10){
		cout<<a2+b2+1<<a1+b1-10;
	}else{
		cout<<a2+b2<<a1+b1;
	}
	return 0;
}
