#include <iostream>
using namespace std;

int main() {
	int a,b,bond,iodd,i;
	cin>>a>>b;
	if(b%2!=0)
	{
		b=b-1;
	}
	odd=b;
	bond=(odd-1)/2;
	for(i=bond;i>0;i--)
	{
		iodd=(i*2)+1;
		ans++;
		while((2*iodd)+2<=odd)
		{
		 ans++;
		}
	}
	return 0;
}
