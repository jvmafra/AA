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
 
int BFS(int vertice){
	int maior = 0;
    queue<int> fila;
    fila.push(vertice);
    dist[vertice] = 0;
    int atual;
 
    while(!fila.empty()){
        atual = fila.front();
        fila.pop();
        for (int i=0; i < adj[atual].size(); i++) {
        	int vizinho = adj[atual][i];
	        if (dist[vizinho] > dist[atual] + 1) {
	        	dist[vizinho] = dist[atual] + 1;
	        	if (dist[vizinho] > maior){
					maior = dist[vizinho];
				}
	        	fila.push(vizinho);
	        }
    	} 
    }
    
    return maior;
 
}

int main(){
	int n, u, v;
	
	int aux;
	int max = 0;
	
    scanf("%d", &n);
 
    for (int i=0;i< n-1;i++) {
        scanf("%d %d", &u, &v);      
        adj[u].push_back(v);
        adj[v].push_back(u);
 
    }
		
    for (int i = 1; i <= n; i++) {
		zeraDists(n);
    	aux = BFS(i);
    	
    	if (aux > max) {
			max = aux;
		}
    }
    printf("%d", max);
    
    return 0;
}
