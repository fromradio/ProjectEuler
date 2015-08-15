
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

num = 10000
mark = [False for i in range(0,num)]
mark[0] = True
mark[1] = True
primes = primeList(1000)
count = 0
for i in range(0,num):
	if not mark[i]:
		fac = factor(i,primes)
		divs = divisors(i,fac)
		j = sum(divs)
		facj = factor(j,primes)
		divsj = divisors(j,facj)
		if sum(divsj)==i:
			if i != j:
				count += i
				if j < num:
					count += j
		mark[i]=True
		if j < num:
			mark[j]=True
print count