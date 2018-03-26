#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,p,apart;
		cin>>n>>p;
		if(n<=2)
			printf("impossible");
		else if(p<=2)
			printf("impossible");
		else
		{
			if(p%2==0)
			{
				apart=(p-2)/2;
			}else
			{
				apart=(p-1)/2;
			}
			for(int i=0;i<n/p;i++)
			{
				for(int j=0;j<apart;j++)
					printf("a");
				if(p%2==0)
					printf("bb");
				else
					printf("b");
				for(int j=0;j<apart;j++)
					printf("a");
			}
		}
		printf("\n");

	}
	return 0;
}                       
