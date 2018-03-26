#include <iostream>
using namespace std;
int tc[21],n,TC,ans;
bool t[21],cp[21];
void backtrack(int label)
{
	long long int temp;
	if(label==n)
	{
		for(int i=0;i<n;i++)
		{
			if(t[i])
			{
				tmp=tmp+t[i]
			}
		}
		
		if(temp<=TC)
		{
			if(temp>ans)
			{
				ans=max(tmp,ans);
				for(int j=0;j<n;j++)
				{
					cp[j]=t[j];
				}
			}
		}
		return;
	}
	t[label]=true;
	backtrack(label+1);
	t[label]=false;
	backtrack(label+1);
}
int main() {
	while(cin>>TC)
	{
		int i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&tc[i]);
		}
		for(i=0;i<n;i++)
		{
			cp[i]=false;
		}
		backtrack(0);
		for(i=0;i<n;i++)
		{
			if(cp[i])
			{
				printf("%d ",tc[i]);
			}
		}
		printf("sum:%d\n",ans);

	}
	return 0;
}
