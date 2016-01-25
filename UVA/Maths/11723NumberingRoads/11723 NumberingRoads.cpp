#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <queue>
#include <sstream>
#include <limits>
#include <algorithm>
using namespace std;

int main(){
	int n, i = 1;
	float r;
	while (true){
		scanf("%f %d", &r, &n);
		if (r == 0)
			break;
		int ans = (int)ceil((r-n)/n);
		if (ans > 26){
			cout << "Case " << i++ << ": impossible" << endl;
			continue;
		}
		cout << "Case " << i++ << ": " << ans << endl;
	}
}