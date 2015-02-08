/*===============================================================
*   
*   FILE NAME:  b.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       02/08/2015 14:56:01
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

int trie[1000100][30], tot, root;
bool flag[1000100];

void trie_init() {
	memset(trie[0], 0, sizeof trie);
	memset(flag, false, sizeof false);
	tot = root = 0;
}

int insert(char *str) {
	int *cur = &root, ret = 0;
	bool endd = false;
	for(char *p = str; *p; ++p) {
		cur = &trie[*cur][*p-'a'];
		if(*cur == 0) {
			endd = true;
			*cur = ++tot;
			memset(trie[tot], 0, sizeof trie[tot]);
			flag[tot] = 0;
		}
		if(!endd)
			++ret;
	}
	flag[*cur] = true;
	return ret;
}

char str[1000010];

void MAIN() {
	trie_init();
	int n;
	scanf("%d", &n);
	int ret = 0;
	while(n--) {
		scanf("%s", str);
		int len = strlen(str), ans = insert(str);
		if(ans == len)
			--ans;
		ret += ans+1;
	}
	printf("%d\n", ret);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		MAIN();
	}
	return 0;
}
