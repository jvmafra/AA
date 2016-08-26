#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int dist[100001];

int INF = 1000000000;

void zeraDists(){
	for (int i=1; i <= 100001; i++){
    	dist[i] = INF;
    }	
}

int inverte(int num){
	int new_num = 0;
	while (num > 0) {
		new_num = new_num*10 + (num % 10);
		num = num/10;
	}

	return new_num;

}

int bfs(int a, int target){
	queue<int> fila;
    fila.push(a);
    dist[a] = 0;
    int atual;
 
    while(!fila.empty()){
        atual = fila.front();
        fila.pop();
        
        if (atual == target){
			return dist[atual];
		} else {
			int invertido = inverte(atual);
			
			if (dist[atual + 1] == INF) {
				dist[atual + 1] = dist[atual] + 1;
				fila.push(atual + 1);
			}
			
			if (dist[invertido] == INF){
				dist[invertido] = dist[atual] + 1;
				fila.push(invertido);
			}
		}
       
    }
    
    return -1;
 



}

int main(){
	int consultas;
	int a, target, tentativas;
	scanf("%d", &consultas);
	
	for (int i = 0; i < consultas; i++){
		zeraDists();
		scanf("%d %d", &a, &target);
		tentativas = bfs(a, target);
		printf("%d\n", tentativas);
	}
	return 0;
}
