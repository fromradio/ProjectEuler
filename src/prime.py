import operator

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

# problem 60

def pairSet():
	# 3 and 7 must be two of the 5 numbers
	pl = primeList(5000)
	num = 5000*5000
	bpl = primeList(num)
	# judge two prime numbers are pair
	def jp(p1,p2):
		if int(str(p1)+str(p2)) not in bpl:
			return False
		if int(str(p2)+str(p1)) not in bpl:
			return False
		else:
			return True
	# find all numbers be pair of 3 and 7
	l = []
	for p in pl:
		if jp(p,3) and jp(p,7):
			l.append(p)
	for n in l:
		for m in l:
			if jp(m,n):
				print m,n
	print l