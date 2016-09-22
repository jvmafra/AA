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
	int cont = 0;
    int n, u, v, m, p;
	Aresta atual;
	Aresta aux;
	vector<Aresta> arestas;
	vector<Aresta> arvore;
    
    while (1){
		scanf("%d %d", &n, &m);
		
		if (n == 0 && m == 0) break;
		
		cont++;
		
		arestas.clear();
		arvore.clear();
    
		for (int i = 1; i <= n; i++) {
			uni[i] = i;
		}
		
		for (int i=0;i < m;i++) {
			scanf("%d %d %d", &u, &v, &p);
			if (u < v){
				atual.v1 = u;
				atual.v2 = v;
			} else {
				atual.v1 = v;
				atual.v2 = u;
			}
			atual.peso = p;
			arestas.push_back(atual);
		}
		
		std::sort(arestas.begin(), arestas.end());
		
		
		
		printf("Teste %d\n", cont);
		
		for (int i = 0; i < arestas.size() ; i++){
			aux = arestas[i];
			if (!isConnected(aux.v1, aux.v2)){
				arvore.push_back(aux);
				connect(aux.v1, aux.v2);
				printf("%d %d\n", aux.v1, aux.v2);
			} 
		}
		printf("\n");
		
		
	}
    
    	
   
   
    return 0;
}
