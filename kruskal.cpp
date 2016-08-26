#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;



struct Aresta {
	int v1, v2, peso;
	
	 bool operator < (const Aresta& a) const {
        return peso < a.peso;
    }
};

int uni[100001];

int getParent(int i){
	while (i != uni[i]){
		i = uni[i];
	}
	return i;
}

bool isConnected(int i, int j){
	return getParent(i) == getParent(j);
}

void connect(int i, int j){
	uni[getParent(i)] = getParent(j);
	
}


int main() {
    int n, u, v, m, p;
	Aresta atual;
	Aresta aux;
	vector<Aresta> arestas;
	vector<Aresta> arvore;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
    	uni[i] = i;
	}
    
    for (int i=0;i < m;i++) {
        scanf("%d %d %d", &u, &v, &p);
        atual.v1 = u;
        atual.v2 = v;
        atual.peso = p;
        arestas.push_back(atual);
    }
    
    std::sort(arestas.begin(), arestas.end());
    
    
    
    for (int i = 0; i < arestas.size() ; i++){
		aux = arestas[i];
		if (!isConnected(aux.v1, aux.v2)){
			arvore.push_back(aux);
			connect(aux.v1, aux.v2);
		} 
	}
	
	for (int i = 0; i < arvore.size(); i++){
		 printf("%d - %d - %d\n", arvore[i].v1, arvore[i].v2, arvore[i].peso);
	
	}
    	
   
   
    return 0;
}
