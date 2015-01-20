/*===============================================================
*   
*   FILE NAME:  1002.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       08/25/2014 03:31:21
*   EMAIL:      winoros@gmail.com
*   Description:solve the 1002th problem of Ural
*
*
================================================================*/
/* 最少用几个子串可以构造出母串，子串可重复利用 */
#include <bits/stdc++.h>

using namespace std;

int phone_num[110];
int num[50001][110];
int lenn[50001], len;
int tonum[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 1, 1, 5, 5, 6, 6, 0, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0 };
int dp[110], suf[110];
char str[50001][110];

bool check(int end, int pos) {
	if(end < lenn[pos]-1) return false;
	for(int i = end - lenn[pos] + 1, j = 0; i <= end; i++, j++) {
		if(phone_num[i] != num[pos][j]) 
			return false;
	}
	return true;
}
int main() {
	while(scanf("%s", str[0]) && str[0][0] != '-') {
		len = strlen(str[0]);
		for(int i = 0; i < len; i++)
			phone_num[i] = str[0][i] - '0';
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%s", str[i]);
			lenn[i] = strlen(str[i]);
			for(int j = 0; j < lenn[i]; j++)
				num[i][j] = tonum[str[i][j] - 'a'];
		}
		memset(dp, 0x3f, sizeof dp);
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < n; j++)
				if(check(i, j)) {
					if(i == lenn[j] - 1) 
						dp[i] = 1, suf[i] = j;
					else if(dp[i] > dp[i-lenn[j]]+1) {
						dp[i] = dp[i-lenn[j]]+1, suf[i] = j;
					}
				}
		}
		if(dp[len-1] > 100000)
			puts("No solution.");
		else {
			int now = len-1;
			stack<int> s;
			while(now >= 0) {
				s.push(suf[now]);
				now -= lenn[suf[now]];
			}
			printf("%s", str[s.top()]);
			s.pop();
			while(!s.empty()) {
				putchar(' ');
				printf("%s", str[s.top()]);
				s.pop();
			}
			puts("");
		}
	}
	return 0;
}
