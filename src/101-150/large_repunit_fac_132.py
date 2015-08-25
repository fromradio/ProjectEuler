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

primes = primeList(1000000)
# print largePowerMod(1000,1000,10000000000)
# r = 0
# print largePowerMod(2,2,3)
# # problem 48
# for i in range(1,1001):
# 	r += largePowerMod(i,i,10000000000)
# print r
# print r%10000000000

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
