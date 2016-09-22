#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;



struct Aresta {
	int v1, v2, custo;
	
	bool operator < (const Aresta& a) const {
       return custo < a.custo;
    }
};

int uni[101];

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

vector<Aresta> arestas;

int main() {
	int cont = 0;
    int N, F, R, u, v, p;
	Aresta atual;
	Aresta aux;

    
	scanf("%d %d %d", &N, &F, &R);
		
	for (int i = 1; i <= N; i++) {
		uni[i] = i;
	}
		
	for (int i=0;i < F;i++) {
		scanf("%d %d %d", &u, &v, &p);
		if (u < v){
			atual.v1 = u;
			atual.v2 = v;
		} else {
			atual.v1 = v;
			atual.v2 = u;
		}
		atual.custo = p;
		arestas.push_back(atual);
	}
	
	
	std::sort(arestas.begin(), arestas.end());
	
	for (int i = 0; i < arestas.size() ; i++){
		aux = arestas[i];
		if (!isConnected(aux.v1, aux.v2)){
			connect(aux.v1, aux.v2);
			cont += aux.custo;
		} 
	}
	
	
	arestas.clear();
	
	for (int i=0;i < R;i++) {
		scanf("%d %d %d", &u, &v, &p);
		if (u < v){
			atual.v1 = u;
			atual.v2 = v;
		} else {
			atual.v1 = v;
			atual.v2 = u;
		}
		atual.custo = p;
		arestas.push_back(atual);
	}
	
	std::sort(arestas.begin(), arestas.end());
	for (int i = 0; i < arestas.size() ; i++){
		aux = arestas[i];
		if (!isConnected(aux.v1, aux.v2)){
			connect(aux.v1, aux.v2);
			cont += aux.custo;
		} 
	}
	
	printf("%d", cont);
		
    
    	
   
   
    return 0;
}
