#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int dist[100001];

int INF = -1;

int proibidos[100001];

void zera(){
	for (int i = 1; i <= 100000; i++){
		proibidos[i] = 0;
		dist[i] = INF;
	}
}


int bfs(int a, int target){
	queue<int> fila;
    fila.push(a);
    dist[a] = 0;
    int atual;
    int aux;
 
    while(!fila.empty()){
        atual = fila.front();
        fila.pop();
        
        if (atual == target){
			return dist[atual];
		} else {
			
			int lista[4] = {atual + 1, atual - 1, atual * 2, atual * 3}; 
			for (int i = 0; i < 4; i++) {
				aux = lista[i];
				if (aux > 0 && aux <= 100000 && proibidos[aux] == 0 && dist[aux] == INF){
					dist[aux] = dist[atual] + 1;
					fila.push(aux);
				}
				
			}
			
			if (atual % 2 == 0 && proibidos[atual/2] == 0 && dist[atual/2] == INF && atual/2 > 0){
					dist[atual/2] = dist[atual] + 1;
					fila.push(atual/2);
			}
			
		}
       
    }
    
    return -1;
 



}

int main(){
	int O, D, K, pro, tentativas;
	
	while(1){
		scanf("%d %d %d", &O, &D, &K);
		
		if (O == 0 && D == 0 && K == 0){
			break;
		}
		zera();
		
		for (int i=0; i < K; i++){
			scanf("%d", &pro);
			proibidos[pro] = 1;
		}
		
		tentativas = bfs(O,D);
		
		printf("%d\n", tentativas);
		
	}
	
	return 0;
}
