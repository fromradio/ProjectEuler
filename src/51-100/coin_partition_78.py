""" 
reference:
	pentagonal number thereom and partition

	p(n) = \sum_(k!=0) (-1)^(k-1)p(n-g_k)
	g_k = k*(3*k-1)/2
"""

def index(k):
	if k%2 == 0:
		return -1
	else:
		return 1

def g(k):
	return k*(3*k-1)/2

def main():
	l = [1,1]
	n = 2
	while True:
		i = 1
		p = 0
		while g(i)<=n:
			p += index(i)*l[n-g(i)]
			i += 1
		i = -1
		while g(i)<=n:
			p += index(i)*l[n-g(i)]
			i -= 1
		l.append(p)
		# print p
		n += 1
		if p % 1000000 == 0:
			break;
	print l[-1]
	print len(l)-1

main()