def largePowerMod(base, e, d):
	r = 1
	for i in range(0,e):
		r = (r*base)%d
	return r


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



# solution for problem 48:
def Problem48():
	r = 0
	# problem 48
	for i in range(1,1001):
		r += largePowerMod(i,i,10000000000)
	print r
	print r%10000000000

def Problem132():
	primes = primeList(1000000)
	n = int(1e9)
	count = 0
	s = 0
	def gcd(m,n):
		if n==0:
			return m
		else:
			return gcd(n,m%n)

	print gcd(15,20)
	for p in primes:
		if p==2 or p==3 or p==5:
			continue
		g = gcd(n,p-1)
		if g != 0:
			if largePowerMod(10,g,p)==1:
				s += p
				count += 1
				print p,g,largePowerMod(10,g,p)
		if count >= 40:
			break
	print s
	print count

def Problem133():
	primes = primeList(100000)
	primes.remove(3)
	summation = 0
	for p in primes:
		l = p-1
		# only 2 and 5 are factors
		fac2 = 0
		div = 2
		while 1:
			if l%div == 0:
				fac2 += 1
				div *= 2
			else:
				break
		fac5 = 0
		div = 5
		while 1:
			if l%div == 0:
				fac5 += 1
				div *= 5
			else:
				break
		if fac2==0 and fac5==0:
			continue
		else:
			found = False
			for i in range(0,fac2+1):
				for j in range(0,fac5+1):
					r = (2**i)*(5**j)
					if largePowerMod(10,r,p)==1:
						# print p
						found = True
						summation += p
						break
					pass
				if found:
					break
	print sum(primes)-summation+3


def Problem129():
	# 10^n=1(mod 9p)
	primes = set(primeList(int(1e6)))
	primes.remove(2)
	primes.remove(5)
	primes.remove(7)
	for p in primes:
		pass
	pass
def main():
	Problem129()

if __name__ == '__main__':
	main()