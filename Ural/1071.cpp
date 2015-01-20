/*
 * =====================================================================================
 *
 *       Filename:  1071.cpp
 *
 *    Description:  solve the 1071th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/9/4 19:54:07
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

bool check(int a, int b, int base) {
	int mod_1, mod_2;
	bool ok = false;
	for(; a && b; ) {
		mod_1 = a%base, mod_2 = b%base;
		a/=base, b/=base;
		while(mod_1 != mod_2 && b)
			mod_2 = b%base, b/=base;
		ok = false;
		if(mod_1 == mod_2)
			ok = true;
	}
	if(!a && ok)
		return true;
	else 
		return false;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = 2; i <= a; i++)
		if(check(b, a, i)) {
			printf("%d\n", i);
			return 0;
		}
	puts("No solution");
	return 0;
}
