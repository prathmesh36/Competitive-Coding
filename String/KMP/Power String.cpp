#include <iostream>
#include<cstring>
using namespace std;
int b[1000005];

int preprocess(string s)
{
	int n=s.length(),i=0,j=-1;
	b[0]=-1;
	while(i<n)
	{
		while(j>=0 && s[i]!=s[j]) j=b[j];
		i++;
		j++;
		b[i]=j;
	}
	return j;
}

int main() {
	string s;
	while(cin>>s)
	{
		if(s==".")
		break;
		int t= preprocess(s);
		/*int flag=1,pos=-1,flag2=0;
		for(int i=s.length()-1;i>0;i--)
		{
			cout<<b[i]<<" ";
			if(b[i]==1)
			{
				flag=0;
				pos=i-1;
				//break;
			}
			if(flag==1)
			{
				if(b[i+1]-b[i]!=1)
				{
				flag2=1;
				//break;
				}
			}
		}
		cout<<endl;
		if(s.length()==2)
		{
			if(s[0]==s[1])
			cout<<"2\n";
			else
			cout<<"1\n";
		}
		else
		{
			if(flag2==0)
			{
				if(s.length()%(pos)==0)
				cout<<s.length()/(pos)<<endl;
				else
				cout<<"1\n";
			}else
			{
				cout<<"1\n";
			}
			memset(b,-1,sizeof(b));
		}*/
		int n=s.length();
		//cout<<t<<" "<<n<<" ";
		if(n%(n-t)==0)
		{
			cout<<n/(n-t)<<endl;
		}else
		{
			cout<<"1"<<endl;
		}
	}
	return 0;
}
