#include <iostream>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,ans=0,temp;
    cin>>n>>m;
    ans=n-1;
    if((n-1)%2==0)
    {
    temp=(n-1)/2;
    ans+=m-temp;
    ans+=m-temp;
    ans+=n-3;
    }
    else
    {
    temp=((n-1)/2)+1;
    ans+=m-temp;
    ans+=m-temp+1;
    ans+=n-3;
    }
    if(n==1)
    cout<<"0"<<endl;
    else if(n==2)
    cout<<m<<endl;
    else
    cout<<ans<<endl;

  }
  return 0;
}
