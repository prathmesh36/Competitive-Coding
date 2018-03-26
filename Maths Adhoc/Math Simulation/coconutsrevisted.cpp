#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main() {
	int n;
	while(scanf("%d",&n),n>=0)
	{
		int temp,flag=1,i,ans=0;
		for(i=2;i<=sqrt(n);i++)
		{
			temp=n;
			int j;
			for(j=0;j<i;j++)
			{
				if(temp%i==1)
				{
					temp--;
					temp=temp-(temp/i);
				}
				else
				{
					break;
				}
			}
			if(j==i)
			{
				if(temp!=0 && temp%i==0)
				{
					ans=max(ans,i);
					flag=0;
				}

			}
		}
		if(n==3)
		{
			printf("3 coconuts, 2 people and 1 monkey\n");
		}
		else
		{
			if(flag==0)
			{
				printf("%d coconuts, %d people and 1 monkey\n",n,ans);
			}else
			{
				printf("%d coconuts, no solution\n",n);
			}
		}
	}
	return 0;
}
