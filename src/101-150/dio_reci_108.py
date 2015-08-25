def primeList(num):
	# 
	cons = [True for i in range(0,int(num)+1)]
	cons[0] = False
	cons[1] = False
	p = 2
	while p*p <= num:
		k = p*p
		while k <= num:
			cons[k] = False
			k += p
		i = p+1
		while True:
			if cons[i]:
				p = i
				break
			i += 1
	l = []
	for i in range(2,int(num)+1):
		if cons[i]:
			l.append(i)
	return l

def factor(n,primes):
	def impl(n,dic):
		if n == 1:
			return dic
		for p in primes:
			if n%p == 0:
				dic.setdefault(p,0)
				dic[p] += 1
				return impl(n/p,dic)
		dic.setdefault(n,1)
		dic[n] += 1
		return dic
	return impl(n,{})

primes = primeList(1000)

print factor(50,primes)
for i in range(3,1000000):
	f = factor(i,primes)
	s = 1
	for p in f:
		s*=(2*f[p]+1)
	# print s
	if (s/2+1) > 1000:
		print i
		break