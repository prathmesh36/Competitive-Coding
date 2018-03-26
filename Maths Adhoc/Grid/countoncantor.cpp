#include <iostream>
using namespace std;

int main() {
	int n;
	while(cin>>n)
	{
		int i=2,lim=1;
		if(n==1)
		{
			cout<<"TERM 1 IS 1/1"<<endl;
		}
		else
		{
		while(1)
		{
				lim=lim+i;
				if(n<=lim)
				{
					if(i%2==0)
					lim=lim-(i-1);
					break;
				}
				i++;
			}
			cout<<"TERM "<<n<<" IS "<<1+abs(lim-n)<<"/"<<i-abs(lim-n)<<endl;
		}
	}
	return 0;
}
