k = int(raw_input())
n = 3
modulo = pow(2,31) - 1

resultado = 1

while(k > 0):
    if (k % 2 == 1):
      resultado = (resultado * n) % modulo

    n = (n**2) % modulo
    k = k/2

print resultado
	
