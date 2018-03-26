#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

long int money(int base)
{
	long int temp;
	temp=1000*(max(base,1)*max(base,1));
	return temp;
}

int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int n,b,i=0,j,temp,maxb=0,pos=0,first,k,diff=0,change;
		long int sum,mainsum;
		vector <int> build;
		vector <int> newbuild;
		scanf("%d%d",&n,&b);

		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			build.push_back(temp);
			if(temp>maxb)
			{
				maxb=temp;
				pos=i;
			}
		}

		if(pos==n/2 && n%2==0)
			pos--;

		if(pos<=n/2)
			first=maxb-pos;
		else
			first=maxb-(n-1-pos);

		k=first;
		//cout<<first<<"\n";
		for(i=0;i<n;i++)
		{
			if(build[i]>k)
			{
				if((build[i]-k)>diff)
					diff=build[i]-k;
			}
			if(n%2==1)
			{
				if(i<n/2)
					k++;
				else
					k--;
			}
			else
			{
				if(i<(n/2)-1)
					k++;
				else if(i>(n/2)-1)
					k--;
			}
		}


		first=first+diff;
		k=first;

		for(i=0;i<n;i++)
		{
			newbuild.push_back(k);
			if(n%2==1)
			{
				if(i<n/2)
					k++;
				else
					k--;
			}
			else
			{
				if(i<(n/2)-1)
					k++;
				else if(i>(n/2)-1)
					k--;
			}
		}

		mainsum=0;
		for(i=0;i<n;i++)
		{
			change=newbuild[i]-build[i];
			sum=0;
			k=b;
			for(j=0;j<change;j++)
			{
				sum=sum+money(k);
				k--;
			}
			mainsum=mainsum+sum;
		}
		cout<<mainsum;
		cout<<"\n";
	}

	return 0;
}
