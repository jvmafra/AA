#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int vis[10001];
vector<int> adj[10001];
bool answer = true;


void DFS(int vertice, int pai = -1){
    vis[vertice] = 1;
    for (int i = 0; i < adj[vertice].size(); i++){
    	int vizinho = adj[vertice][i];
    	if (vis[vizinho] == 0){
    		DFS(vizinho, vertice);
    	}
    	else if (pai != vizinho){
    		answer = false;
    		break;
    	}
    	
    }

}


int main(){
	int n, m, u, v;
	
    scanf("%d %d", &n, &m);
    
    for (int i=0;i< m;i++) {
        scanf("%d %d", &u, &v);      
       	adj[u].push_back(v);
       	adj[v].push_back(u);
    }
    
    for (int j = 1; j <= n; j++){
    	if (vis[j] == 0) {
    		DFS(j);
    		if (answer == false) {
    			printf("NO");
    			break;
    		}
    	}
    }
    
    
    if (answer) printf ("YES");
    		
    
	
    return 0;
}
