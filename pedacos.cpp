#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

#define INF -40004;

int valor, m;

int dp[4001];
int pedacos[3];

void zeraDP(){
	dp[0] = 0;
	for (int i = 1; i <= 4000; i++){
		dp[i] = INF;
	}

}

int main(){
	scanf("%d %d %d %d", &valor, &pedacos[0], &pedacos[1], &pedacos[2]);

	zeraDP();
		
	for (int i = 1; i <= valor; i++){
		for (int j = 0; j < 3; j++){
			m = pedacos[j];
			if (m <= i) dp[i] = max(dp[i], dp[i - m] + 1);
		}
	}
		
	printf("%d\n", dp[valor]);
	
	return 0;
	
}
