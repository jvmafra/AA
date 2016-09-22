#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, n, alvo, m;

#define MAX 1000000000;

vector<int> lista;
int dp[1000001];

void zeraDP(){
	for (int a = 0; a < 1000001; a++){
		dp[a] = -1;
	}

}

int resposta(int alvo){
	int respAtual;
	if (alvo == 0) return 0;
	else if (dp[alvo] != -1) return dp[alvo];
	else {
 
		int ans = MAX;
		for (int z = 0; z < lista.size(); z++){
			m = lista[z];
			if (m <= alvo) {
				respAtual = resposta(alvo - m);
				if (respAtual + 1 < ans){
					ans = respAtual + 1;
				}
			}
				
		}
		dp[alvo] = ans;
		return ans;
			
 
		
	}

}

int main(){
	int atual, resp;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++){
		zeraDP();
		lista.clear();
		scanf("%d %d", &n, &alvo);
		
		for (int j = 0; j < n; j++){
			scanf("%d", &atual);
			lista.push_back(atual);
		}
		
		resp = resposta(alvo);
		printf("%d", resp);
		
	}
	
		
	return 0;
}

