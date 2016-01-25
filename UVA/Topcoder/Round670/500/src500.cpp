#include <bits/stdc++.h>
using namespace std;

#define MEM(arr,val)memset(arr,val, sizeof arr)


class Drbalance{
public:
	int lesscng(string s, int k) {
		int neg[s.size()];
		MEM(neg, 0);
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i > 0)
				neg[i] += neg[i-1];
			if (s[i] == '+')
				neg[i]++;
			if (s[i] == '-')
				neg[i]--;
			if (neg[i] < 0)
				cnt++;
		}
		if (cnt <= k)
			return 0;
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '+')
				continue;
			s[i] = '+';
			ans++;
			for (int j = i; j < s.size(); j++) {
				neg[j] += 2;
				if (neg[j] >= 0)
					cnt--;
			}
			if (cnt <= k)
				break;
		}
		return ans;
	}
};
