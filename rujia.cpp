#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int n, m;
std::vector<int> aux[1000001];
int atual, indice, numero;
bool espaco;

void zeraAdj(int n){
	
	for (int i = 1; i <= 1000001; i++){
		aux[i].clear();
	}
}

int main(){
	while (scanf("%d %d", &n, &m) != EOF) {
		
	zeraAdj(n);
	
	for (int i = 0; i < n; i++){
		scanf("%d ", &atual);
		aux[atual].push_back(i);
	}
	
	for (int i = 0; i < m; i++){
		if (i == m - 1) espaco = false;
		else espaco = true;
		scanf("%d %d", &indice, &numero);
		if (indice <= aux[numero].size()){
			if (espaco) printf("%d\n", aux[numero][indice -1] + 1);
			else printf("%d", aux[numero][indice -1] + 1);
			
		} else {
			if (espaco) printf("%d\n", 0);
			else printf("%d", 0);
			
		}
	}
	
	}
	return 0;
}
