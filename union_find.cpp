#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
using namespace std;

int uni[100001];
set<int> s;

int getParent(int i){
	while (i != uni[i]){
		i = uni[i];
	}
	return i;
}

bool isConnected(int i, int j){
	return getParent(i) == getParent(j);
}

void connect(int i, int j){
	uni[getParent(i)] = getParent(j);
	
}

int main() {
    int n, u, v, m;

    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
    	uni[i] = i;
	}
    
    for (int i=0;i < m;i++) {
        scanf("%d %d", &u, &v);
        connect(u,v);
    }
    
    for (int i = 1; i <= n ; i++) 
    	s.insert(getParent(i));
    	
    printf("%d", s.size());
   
    return 0;
}


