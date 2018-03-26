//morgan
#include<iostream>
#include<vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
int k;

bool sortnu( const vector<string>& vec1, const vector<string>& vec2 ) {

    string str1=vec1[k-1].substr(vec1[k-1].find_first_not_of('0')), str2=vec2[k-1].substr(vec2[k-1].find_first_not_of('0'));
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
    if (n1<n2)
    {
        return true;
    }
    else if (n2<n1)
    {
        return false;
    }
    else
    {
    if(str1<str2)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
}

bool sorts( const vector<string>& vec1, const vector<string>& vec2 ) {
 return vec1[k-1] < vec2[k-1];
}

int main()
{
  int n;
  cin>>n;
  vector< vector<string> > s;
  string temp;
  getline(cin,temp);
  for(int i=0;i<n;i++)
  {
    string sentence;
    getline(cin,sentence);
    istringstream iss(sentence);
    s.push_back(vector<string>());
    copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(s[i]));
  }

  string r,c;
  cin>>k>>r>>c;

  if(c=="numeric")
  {
	sort(s.begin(),s.end(),sortnu);
  }
  else
  {
	sort(s.begin(),s.end(),sorts);
  }
  if(r=="true")
  {
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<s[i].size();j++)
			cout<<s[i][j]<<" ";
		cout<<endl;
	}
  }
  else
  {
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<s[i].size();j++)
			cout<<s[i][j]<<" ";
		cout<<endl;
	}
  }

}
