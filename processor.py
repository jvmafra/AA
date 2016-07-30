import math

entrada = map(int, raw_input().split())
n = entrada[0]
h = entrada[1]
k = entrada[2]

lista = map(int, raw_input().split())

acum = 0
t = 0
for i in range(n):
	if (acum + lista[i] <= h):
		acum += lista[i]
	else:
		t += acum/k
		
		acum = lista[i] + (acum % k)
		if acum > h:
			t += 1
			acum = lista[i]


t += int(math.ceil(float(acum)/k))
	
	
print t


	
		
	
