import math

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

def countFraction(n):
	sq = int(math.sqrt(n))+1
	primes = primeList(sq)
	count = 0
	for i in range(2,n+1):
		fac = factor(i,primes)
		m = [True for x in range(1,i)]
		# for p in fac:
		# 	for k in range(1,i/p):
		# 		m[k*p] = False
		# count += sum(m)
		if i % 100000 == 0:
			print i
		# print i,m
	return count

# print countFraction(1000000)

def gcd(m,n):
	if n==0:
		return m
	return gcd(n,m%n)

def orderFraction(n):
	numer = 2
	de = 7
	c = 3.0/7
	for d in range(2,n+1):
		ub = int(c*d)
		bf = False
		if d == 7:
			continue
		while numer*d<ub*de:
			if gcd(ub,d) == 1:
				bf = True
				break
			else:
				ub -= 1
		if bf:
			numer = ub
			de = d
	return numer,de
# print orderFraction(1000000) 

def rangeFraction(n):
	count = 0
	for d in range(4,n+1):
		ub = d/2
		while ub*3>d:
			if gcd(ub,d) == 1:
				count += 1
			ub -= 1
	return count

print rangeFraction(12000)