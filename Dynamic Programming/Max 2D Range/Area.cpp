#include <iostream>
using namespace std;

int main() {
	int tc,b=1;
	cin>>tc;
	while(tc--)
	{
		int m,n,i,j,k,l;
		long long int money,smoney=0,area=0;
		cin>>n>>m>>money;
		long long int a[n][m];
		for(i=0;i<n;i++)for(j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(i>0)a[i][j]+=a[i-1][j];
			if(j>0)a[i][j]+=a[i][j-1];
			if(i>0 && j>0)a[i][j]-=a[i-1][j-1];
		}
		for(i=0;i<n;i++)for(j=0;j<m;j++)
		for(k=i;k<n;k++)for(l=j;l<m;l++)
		{
			int reqmoney;
			reqmoney=a[k][l];
			if(i>0)reqmoney-=a[i-1][l];
			if(j>0)reqmoney-=a[k][j-1];
			if(i>0 && j>0)reqmoney+=a[i-1][j-1];
			//cout<<i<<"/"<<j<<"/"<<k<<"/"<<l<<":"<<reqmoney<<"\n";
			if(reqmoney<=money)
			{
				if(((k-i+1)*(l-j+1))>area)
				{
						smoney=reqmoney;
						area=((k-i+1)*(l-j+1));
						//cout<<area<<" "<<smoney<<endl;
				}
				else if(((k-i+1)*(l-j+1))==area && reqmoney<smoney)
				{
						smoney=reqmoney;
						area=((k-i+1)*(l-j+1));
						//cout<<area<<"-"<<smoney<<endl;
				}
			}
			else
			{
				break;
			}

		}
		cout<<"Case #"<<b<<": "<<area<<" "<<smoney<<"\n";
		b++;
	}
	return 0;
}
