#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
using namespace std;


map<string, int> vis;
map<string, int> dist;
map<string, vector<string> > adj;
int INF = 100000000;

void zeraDists(){
	for(map<string, vector<string> >::iterator it = adj.begin(); it != adj.end(); ++it) {
	  dist[it->first] = INF;
	  vis[it->first] = 0;
	}	
}


int dijkstra(string init, string destino){
    queue<string> fila;
    fila.push(init);
    string atual;
    dist[init] = 0;

    while(!fila.empty()){
        atual = fila.front();
        fila.pop();
        
        if (vis[atual] == 0){
			vis[atual] = 1;
			for (int i=0; i<adj[atual].size(); i++) {
				string v = adj[atual][i];
				if (dist[v] > dist[atual] + 1){
					dist[v] = dist[atual] + 1;
					fila.push(v);
				} 
				
			} 
			
		}
        
    }
    
    return dist[destino];

}


int main() {
     int n, m;
     string u, v;
     char temp1[101], temp2[101];
    scanf("%d %d", &n, &m);
    
    zeraDists();
    
    for (int i=0;i< m;i++) {
        scanf("%100s %100s", &temp1, &temp1); 
        u = temp1;
        v = temp2; 
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    printf ("%d", dijkstra("Entrada", "*") + dijkstra("*", "Saida"));
   
    return 0;
}
