#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
 
int dist[51];
vector<int> adj[51];
int INF = 100;
 
 
void zeraDists(int n){
	for (int i=1; i <= n; i++){
    	dist[i] = INF;
    }	
}
 
void zeraAdj(int n){
	for (int i = 1; i <= n; i++){
		adj[i].clear();
	}
}
 
void BFS(int vertice){
    queue<int> fila;
    fila.push(vertice);
    dist[vertice] = 0;
    int atual;
 
    while(!fila.empty()){
        atual = fila.front();
        printf("%d ", atual);
        fila.pop();
        for (int i=0; i<adj[atual].size(); i++) {
        	int vizinho = adj[atual][i];
	        if (dist[vizinho] > dist[atual] + 1) {
	        	dist[vizinho] = dist[atual] + 1;
	        	fila.push(vizinho);
	        }
    	} 
    }
 
}

int main(){
	printf("Entrei");
	int n, u, v, m, p, cidade;
	int cont = 0;
	while(1){
    	scanf("%d %d %d %d", &n, &m, &cidade, &p);
 
    	if (n == 0 && m == 0 && cidade == 0 && p == 0){
    		break;
    	}
 
    	cont++;
    	printf("Teste %d\n", cont);
    	zeraDists(n);
    	zeraAdj(n);
 
    	for (int i=0;i< m;i++) {
        	scanf("%d %d", &u, &v);      
        	adj[u].push_back(v);
        	adj[v].push_back(u);
 
    	}
 
    	BFS(cidade);
 
    	for (int i = 1; i <= n; i++) {
    		if (dist[i] > 0 && dist[i] <= p){
    			printf("%d ", dist[i]);
    		}
    	}
 
    	printf("\n");
 
 
	}
 
 
    return 0;
}
