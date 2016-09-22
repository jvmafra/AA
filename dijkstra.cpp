#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int vis[1000001];
int dist[1000001];
vector<pair<int,int> > adj[1000001];
int INF = 100000000;

void zeraDists(int n){
	for (int i=1; i <= n; i++){
    	dist[i] = INF;
    }	
}


int dijkstra(int init, int destino){
    priority_queue < pair<int,int>, vector<pair<int,int > >, greater<pair<int,int > > >   fila;
    fila.push(pair<int,int>(0, init));
    pair<int,int> par;
    dist[init] = 0;

    while(!fila.empty()){
        par = fila.top();
        int u = par.second;
        fila.pop();
        
        if (vis[u] == 0){
			vis[u] = 1;
			for (int i=0; i<adj[u].size(); i++) {
				int v = adj[u][i].second;
				int custo = adj[u][i].first;
				if (dist[v] > dist[u] + custo){
					dist[v] = dist[u] + custo;
					fila.push(pair<int,int>(dist[v], v));
				} 
				
			} 
			
		}
        
    }
    
    return dist[destino];

}


int main() {
     int n, u, v,m, w;
    scanf("%d %d", &n, &m);
    
    zeraDists(n);
    
    for (int i=0;i< m;i++) {
        scanf("%d %d %d", &u, &v, &w);      
        adj[u].push_back(pair<int, int>(w, v));
        adj[v].push_back(pair<int, int>(w, u));
        
    }
    
    int aux = dijkstra(5, 9);
    
    printf ("%d", aux);
   
    return 0;
}
