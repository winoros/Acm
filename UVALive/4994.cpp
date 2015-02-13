/*
 * =====================================================================================
 *
 *       Filename:  4994.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/13 22:16:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

using namespace std;

string str[10];
int a[10];

void MAIN() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		a[i] = i;
		cin >> str[i];
	}
	int minn = 100;
	do {
		string now = str[a[0]];
		for(int i = 0; i < n; ++i) {
			int len = min(now.size(), str[a[i]].size());
			for(int j = len; j >= 0; --j)
				if(now.substr(now.size()-j, now.size()) == str[a[i]].substr(0, j)) {
					now += str[a[i]].substr(j, str[a[i]].size());
					break;
				}
		}
		minn = min(minn, (int)now.size());
	} while(next_permutation(a, a+n));
	printf("%d\n", minn);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		printf("Case %d: ", i);
		MAIN();
	}
	return 0;
}
