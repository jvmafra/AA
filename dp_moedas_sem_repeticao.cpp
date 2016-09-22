#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000000;
 
int valor, N, atual;

vector<int> moedas;

int dp[100001];

void zeraDP(){
	dp[0] = 0;
	for (int i = 1; i <= 100001; i++){
		dp[i] = INF;
	}
}


int calculaDP(){
	int m;
	for (int i = 0; i < N; i++){
		m = moedas[i];
		for (int v = valor; v >= 1; v--){
			if (m <= v){
				if (dp[v - m] + 1 < dp[v]){
					dp[v] = dp[v-m] + 1;
					if (v == valor) return 1;
				}
			}
		}
	}
 
 	return 0;
 
}
 
 
 int main(){
	 scanf("%d %d", &valor, &N);
	 
	 for (int i = 0; i < N; i++){
		 scanf("%d", &atual);
		 moedas.push_back(atual);
	 }
	 
	 zeraDP();
	 
	 int resp = calculaDP();
	 
	 if (resp == 0) printf("N");
	 else printf("S");
	 
	 
	 return 0;
 }
