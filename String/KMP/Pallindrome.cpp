#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int b[100000];

void kmpPreprocess(string revs)
{
	int j=-1,i=0;
	b[0]=-1;
	int n=revs.length();
	while(i<n)
	{
		while(j>=0 && revs[i]!=revs[j]) j=b[j];
		i++;
		j++;
		b[i]=j;
	}
}

void kmpSearch(string s,string revs)
{
	int i=0,j=0;
	int n=s.length();
	while(i<n)
	{
		while(j>=0 && s[i]!=revs[j]) j=b[j];
		i++,j++;
	}
	//cout<<j<<n;
	string ans=s.substr(0,n-j);
	//cout<<ans<<endl;
	reverse(ans.begin(),ans.end());
	cout<<s<<ans<<endl;
}

int main() {
	string s,revs;
	while(cin>>s)
	{
		int n=s.length();
		revs=s;
		reverse(revs.begin(),revs.end());
		kmpPreprocess(revs);
		kmpSearch(s,revs);
	}
	return 0;
}
