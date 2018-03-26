#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int n;
	cout<<"PERFECTION OUTPUT\n";
	while(scanf("%d",&n),n)
	{
		int sum=1,i=2;
		if(n==1)
		{
			sum=0;
		}
		while(i<=sqrt(n))
		{
			if(n%i==0)
			{
				sum+=i;
				if(i!=(n/i))
				{
					sum+=(n/i);
				}
			}
			i++;
		}
		if(sum==n)
		{
			printf("%5d  PERFECT\n",n);
		}
		else if(sum>n)
		{
			printf("%5d  ABUNDANT\n",n);
		}
		else
		{
			printf("%5d  DEFICIENT\n",n);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
