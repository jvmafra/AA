#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int vis[100001];
vector<int> adj[100001];

void DFS(int vertice) {
	vis[vertice] = 1;
	printf("%d ", vertice);
    
    for (int i=0; i<adj[vertice].size(); i++) {
    	int vizinho = adj[vertice][i];
        if (vis[vizinho] == 0) {
        	DFS(vizinho);
        }
    }
}

int main() {
     int n, u, v,m;
    scanf("%d", &n);
    scanf("%d", &m);
    
    for (int i=0;i< n-1;i++) {
        scanf("%d %d", &u, &v);      
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    DFS(1);
   
    return 0;
}
