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
	def impl(n,l):
		if n == 1:
			return l
		for p in primes:
			if n%p == 0:
				l.append(p)
				# dic.setdefault(p,0)
				# dic[p] += 1
				return impl(n/p,l)
		# dic.setdefault(n,1)
		# dic[n] += 1
		l.append(n)
		return l
	return impl(n,[])

def analyze(n,fac):
	# def impl(l,m,c,result):
	# 	if not l:
	# 		if c != 1:
	# 			m.append(c)
	# 		r = n-sum(m)+len(m)
	# 		print m
	# 		# if r== 12000:
	# 		# 	print m
	# 		result.append(r)
	# 	else:
	# 		impl(l[1:],m+[l[0]],result)
	# 		impl(l[1:],m+[c*l[0]],1,result)
	# 		impl(l[1:],m,c*l[0],result)
	def impl(l,m,result):
		if not l:
			r = n-sum(m)+len(m)
			# print m
			result.append(r)
		else:
			for i in range(0,len(m)):
				mm = [t for t in m]
				mm[i] *= l[0]
				impl(l[1:],mm,result)
			impl(l[1:],m+[l[0]],result)
	pass
	if len(fac) == 1:
		return []
	else:
		result = []
		impl(fac,[],result)
		return set(result)

"""
	p1^n1*p2^n2*...*pk^nk
"""
def main():
	limit = 12000
	try_limit = limit*2
	d = {}
	np = int(math.sqrt(try_limit))+1
	primes = primeList(100)
	m = 2
	i = 4
	while True:
		fac = factor(i,primes)
		l = analyze(i,fac)
		s = set(l)
		for item in s:
			if item not in d:
				if m == item:
					m += 1
					while m in d:
						m += 1
				if item <= limit:
					d[item] = i
		# print fac
		if m>= limit:
			break
		i += 1
		pass
	fac = factor(8,primes)
	l = analyze(8,fac)
	all_set = set(d.values())
	test = [d[i] for i in range(1,limit+1)]
	print d
	print sum(all_set)
	# fac = factor(70,primes)
	# analyze(70,fac)

	# print fac

if __name__ == '__main__':
	main()