#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, days;
		scanf("%d %d", &n, &days);
		vector<int> sadness(n), lectures(n), startDay(n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &startDay[i], &lectures[i], &sadness[i]);
			startDay[i]--;
		}
		vector<pair<int, int> > persons;
		for (int i = 0; i < n; i++) {
			persons.push_back(make_pair(sadness[i], i));
		}
		sort(persons.rbegin(), persons.rend());
		vector<int> lecturesTaken(n);
		int cur_day = 0;
		set<int> daySet;
		for (int i = 0; i < days; i++) {
			daySet.insert(i);
		}
		for (auto it: persons) {
			int lec = lectures[it.second];
			for (int i = 0; i < lec; i++) {
				auto iter = daySet.lower_bound(startDay[it.second]);
				if (iter == daySet.end()) {
					break;
				} else {
					lecturesTaken[it.second]++;
				  daySet.erase(iter);
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (lectures[i] - lecturesTaken[i]) * (long long) sadness[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
