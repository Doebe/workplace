#include <bits/stdc++.h>
using namespace std;

class Cdgame{
public:
	int rescount(vector <int> a, vector <int> b) {
		int ans = 0, l = a.size();
		int sum1 = 0, sum2 = 0;
		for (int j = 0; j < l; j++) {
			sum1 += a[j];
			sum2 += b[j];
		}
		map<int, int> m;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				int p = (sum1-a[i]+b[j]) * (sum2-b[j]+a[i]);
				m[p] = 1;
			}
		}
		return m.size();
	}

};
