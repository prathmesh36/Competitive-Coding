#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define infinity numeric_limits<int>::max()
#define minusInf numeric_limits<int>::min()

int main() {
	int n,k;
	cin>>n>>k;
	k--;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		if(temp==1)
		{
			v.push_back(make_pair(i-k,i+k));
		}
	}
	int len=v.size();
	int count=0;
	double curLeft,curRight=0,bestRight;
	curLeft = numeric_limits<int>::min();

    for(int i=0;i<v.size();i++)
    {
      bestRight = minusInf;
      if(v[i].first > curRight) {
      //next left is disjoint set (the next sprinkler leaves a gap in between so its an invalid input)
        count = -1;
        break;
      }
      else if(v[i].second < curRight) {
      //this one is 'covered' by the previous sprinkler  (The sprinkler is of no use because the area which it cover is already covered by another sprinkler its is overlapped)
        continue;
      }
      else {
        int j;
        for(j=i;j<v.size();j++) {
          if(v[j].first > curRight) {                        //check if next sprinkler cover the same
            i = j-1;
            curRight = bestRight+1;
            break;
          }
          else {
          	if(v[j].second>bestRight)
		bestRight=v[j].second;
          }
        }
        if(j==v.size()) {
          if(bestRight < n-1){
            count=-1;
            break;
          }
          else {
            curRight = bestRight+1;
            count++;
            break;
          }
        }
        count++;
        if(bestRight >= n-1) break;
      }
	}
	cout<<count<<endl;
	return 0;
}


/* Efficient
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, k, p, prv[N];

int main() {

    scanf("%d %d", &n, &k);

    int last = -1, ans = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &p);
        if(p == 1) last = i;
        prv[i] = last;
    }

    for(int i = 0; i < n; ) {
        int take = prv[min(i + k - 1, n - 1)];
        if(take == -1 || take + k <= i) { printf("-1\n"); return 0; }
        i = take + k; ans++;
    }

    printf("%d\n", ans);

    return 0;

}
*/
