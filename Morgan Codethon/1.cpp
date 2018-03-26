//morgan
#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int n,m,k,temp;
  cin>>n>>m>>k;
  vector<int> a;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    a.push_back(temp);
  }
  int max=m*k;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    if(temp*m*a[i]>max)
    {
      max=temp*m*a[i];
    }
  }
  cout<<max<<endl;
  return 0;
}
