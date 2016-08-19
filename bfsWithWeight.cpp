#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int vis[10000];
vector<pair<int,int> > adj[100001];

void BFS(int init){
    queue<pair<int,int> > fila;
    fila.push(pair<int,int>(init,0));
    pair<int,int> par;

    while(!fila.empty()){
        par = fila.front();
        vis[par.first] = 1;
        printf("%d ", par.first);
        fila.pop();
        for (int i=0; i<adj[par.first].size(); i++) {
	        if (vis[adj[par.first][i].first] == 0) {
	        	fila.push(adj[par.first][i]);
	        }
    	} 
    }

}


int main() {
     int n, u, v,m, w;
    scanf("%d", &n);
    scanf("%d", &m);
    
    for (int i=0;i< m;i++) {
        scanf("%d %d %d", &u, &v, &w);      
        adj[u].push_back(pair<int, int>(v, w));
        adj[v].push_back(pair<int, int>(u, w));
        
    }
    
    BFS(1);
   
    return 0;
}


