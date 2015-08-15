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
		dic.setdefault(n,0)
		dic[n] += 1
		return dic
	return impl(n,{})

def divisors(n,fac):
	ps = fac.keys()
	size_p = len(ps)
	def impl(i,l,result):
		if i == size_p:
			if l != n:
				result.append(l)
		else:
			r = 1
			for f in range(0,fac[ps[i]]+1):
				impl(i+1,l*r,result)
				r *= ps[i]
	result = []
	impl(0,1,result)
	return result

num = 28123
np = int(math.sqrt(num))
primes = primeList(np)
def abundant(n):
	f = factor(n,primes)
	divs = divisors(n,f)
	return sum(divs)>n

# f = factor(461,primes)
# print divisors(461,f)
ab = []
for i in range(12,num+1):
	if abundant(i):
		ab.append(i)
print ab
print len(ab)
non_ab = [True for i in range(0,num+1)]
for i in range(0,len(ab)):
	if 2*ab[i] > num:
		break
	print i
	for j in range(i,len(ab)):
		if ab[i]+ab[j]<=num:
			if ab[i]+ab[j] == 20161:
				print ab[i],ab[j]
			non_ab[ab[i]+ab[j]] = False
		else:
			break
non_ab[0] = False
l = []
for i,b in zip(range(0,num+1),non_ab):
	if b:
		l.append(i)
print l
print len(l)
print sum(l)