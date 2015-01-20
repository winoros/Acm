/*
 * =====================================================================================
 *
 *       Filename:  1095.cpp
 *
 *    Description:  solve the 1095th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/9/1 3:10:28
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

int mod[7] = { 4123, 2134, 1342, 1243, 2341, 1234, 1324 };

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		char str[20];
		int cnt[10] = { 0 };
		scanf("%s", str);
		int len = strlen(str);
		for(int i = 0; i < len; i++)
			cnt[str[i]-'0']++;
		cnt[1]--, cnt[2]--, cnt[3]--, cnt[4]--;
		int k = 0;
		for(int i = 1; i <= 9; i++)
			for(int j = 0; j < cnt[i]; j++)
				k = (k*10 + i) % 7;
		k = k*10000 %7;
		for(int i = 1; i <= 9; i++)
			for(int j = 0; j < cnt[i]; j++)
				putchar(i+'0');
		printf("%d", mod[k]);
		while(cnt[0]--)
			putchar('0');
		puts("");
	}
	return 0;
}
