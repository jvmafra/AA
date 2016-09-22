#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000001;

int N, n, valor, atual, m;

vector<int> moedas;

int dp[1000001];

void zeraDP(int v){
	dp[0] = 0;
	for (int i = 1; i <= v; i++){
		dp[i] = INF;
	}

}

int main(){
	scanf("%d", &N);

	for (int z = 0; z < N; z++){
		scanf("%d %d\n", &n, &valor);
		zeraDP(valor);
		moedas.clear();
		
		for (int j = 0; j < n; j++){
			scanf("%d", &atual);
			moedas.push_back(atual);
			
		}
		
		for (int i = 1; i <= valor; i++){
			for (int a = 0; a < n; a++){
				m = moedas[a];
				if (m <= i) dp[i] = min(dp[i], dp[i - m] + 1);
			}
		}
		
		printf("%d\n", dp[valor]);
	}
	
	return 0;
	
}
