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

def squareList(num):
	n = int(math.sqrt(num)+1)
	return [x*x for x in range(1,n)]

def isRight(n,primes,squares):
	for s in squares:
		m = n-2*s;
		if m <= 0:
			return False
		if m in primes:
			return True

def main():
	num = 10000
	primes = primeList(num)
	squares = squareList(num)
	for i in range(3,num,2):
		if i in primes:
			continue
		if not isRight(i,primes,squares):
			print i
			break

if __name__=='__main__':
	main()