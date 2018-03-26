#include <iostream>
using namespace std;

int main() {
	int n;
	while(scanf("%d",&n),n>0)
	{

		int x=2,y=1,i=0;
		int tempx=x*x,tempy=(y*y)+1;
		if(n==1)
		{
			cout<<"1 1"<<endl;
		}
		else
		{
			while(1)
			{
				if(n<=tempx || n<=tempy)
				{
					break;
				}
				if(i%2==0)
				{
					y=y+2;
				}
				else
				{
					x=x+2;
				}
				if(i%2==0){
					tempy=(y*y);
					tempx=(x*x)+1;
				}
				else
				{
					tempx=(x*x);
					tempy=(y*y)+1;
				}
				i++;
			}

			if(abs(tempx-n)==abs(tempy-n))
			{
				cout<<i+2<<" "<<i+2<<endl;
			}
			else if(abs(tempx-n)<abs(tempy-n))
			{
				cout<<i+2<<" "<<abs(tempx-n)+1<<endl;
			}
			else
			{
				cout<<abs(tempy-n)+1<<" "<<i+2<<endl;
			}
		}
	}
	return 0;
}
