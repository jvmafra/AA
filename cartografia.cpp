#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
 
int dist[1000001];
vector<int> adj[1000001];
int INF = 1000000000;
 
void zeraDists(int n){
	for (int i=1; i <= n; i++){
    	dist[i] = INF;
    }	
}
 
pair<int,int> BFS(int vertice){
	int maiorDist = 0;
	int verticeMaiorDist;
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
	        	if (dist[vizinho] > maiorDist){
					maiorDist = dist[vizinho];
					verticeMaiorDist = vizinho;
					
				}
	        	fila.push(vizinho);
	        }
    	} 
    }
    
    return pair<int, int> (maiorDist, verticeMaiorDist);
 
}

int main(){
	int n, u, v;
	
    scanf("%d", &n);
 
    for (int i=0;i< n-1;i++) {
        scanf("%d %d", &u, &v);      
        adj[u].push_back(v);
        adj[v].push_back(u);
 
    }
    
    zeraDists(n);
		
    pair<int, int> firstBFS = BFS(1);
    
    int new_vertice = firstBFS.second;
    
    zeraDists(n);
    
    pair<int, int> SecBFS = BFS(new_vertice);
    
    printf("%d", SecBFS.first);
    
    return 0;
}
