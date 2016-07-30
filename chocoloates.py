def mdc(a,b):
	resto = a % b
	if (resto == 0):
		return b
	else:
		return mdc(b, resto)
	

entrada = map(int, raw_input().split())

N = entrada[0]
a = entrada[1]
b = entrada[2]
p = entrada[3]
q = entrada[4]

diva = N/a
divb = N/b
divab = N/((a*b)/mdc(a,b))

print (diva*p) + (divb*q) - (divab*min(p,q))
