import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
	
	static int[] d = new int[100001];
	static int[] r = new int[100001];
	static List<List<Integer>> adj;
	static List<Integer> aux = new ArrayList<>();
	
	
	static void dfs(int vertice, int pai){
		d[vertice] = r[vertice];
		
		for (Integer vizinho : adj.get(vertice)) {
			if (pai != vizinho){
				dfs(vizinho, vertice);
				d[vertice] += d[vizinho];
			}
		}
	}

	public static void main(String[] args) {
		int N;
	  	int u;
	  	int v;
	  	int z;
	  	
	    Scanner scanner = new Scanner(System.in);  
	    N = scanner.nextInt();
	    
	    adj = new ArrayList<List<Integer>>(N+1);
	    for (int i = 0; i < N+1; i++) {
			adj.add(new ArrayList<Integer>(2));
		}
	    
	    
	    for (int i = 0; i < N-1; i++) {
			u = scanner.nextInt();
			v = scanner.nextInt();
			z = scanner.nextInt();
			
			adj.get(u).add(v);
			adj.get(v).add(u);
			
			if (z == 2){
				r[u] = 1;
				r[v] = 1;
			}
			
		}
	    
	    dfs(1, -1);
	   
	    for (int i = 1; i <= N; i++) {
	    	if (r[i] == 1 && d[i] == 1){
	    		aux.add(i);
	    	}
			
		}
	    
	    int  tamanho = aux.size();
	    System.out.println(tamanho);
	    
	    String output = "";
	    for (int i = 0; i < tamanho; i++) {
	    	if (i !=  - 1){
	    		output += aux.get(i) + " ";
	    	} else {
	    		output += aux.get(i);
	    	}
		}
	    
	    if (tamanho > 0) System.out.println(output);

	}

}