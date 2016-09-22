def resposta(alvo):
 
	if alvo == 0: return 0
	elif dp[alvo] != -1: 
		return dp[alvo]
	else:
 
		ans = 1000000000
		for m in lista:
			if m <= alvo:
				if resposta(alvo-m) + 1 < ans:
					ans = resposta(alvo-m) + 1
 
		dp[alvo] = ans
		return ans

N = int(raw_input())

for i in range(N):
	dp = [-1] * 100000
	n, alvo = map(int, raw_input().split())
	lista = map(int, raw_input().split())
	print resposta(alvo)
