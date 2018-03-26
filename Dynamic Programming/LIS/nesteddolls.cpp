#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 20005
#define MAX_M 10000
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
struct doll{
	int w, h;
};
doll D[MAX_N];
bool cmp(doll A, doll B){
	return A.w > B.w || (A.w == B.w&&A.h < B.h);
}
vector<int> LDS;
int search(int h){
	int L = 0, R = LDS.size() - 1;
	while (L < R){
		int mid = (L + R) / 2;
		if (LDS[mid] <= h)
			L = mid + 1;
		else
			R = mid;
	}
	return L ;
}
int main(){
	int n, t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &D[i].w, &D[i].h);
		sort(D, D + n, cmp);
		LDS.clear();
		LDS.push_back(D[0].h);
		for (int i = 1; i < n; i++){
			int pos = search(D[i].h);
			if (LDS[pos]>D[i].h)
				LDS[pos] = D[i].h;
			else
				LDS.push_back(D[i].h);
		}
		printf("%d\n", LDS.size());
	}
	return 0;
}
