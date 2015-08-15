import math
def path(m,n):
	if m==0:
		return 1
	elif n==0:
		return 1
	else:
		return path(m-1,n)+path(m,n-1)

def cnk(n,k):
	num = reduce(lambda x,y:x*y,range(n-k+1,n+1))
	kn = reduce(lambda x,y:x*y,range(1,k+1))
	return num/kn

def fastpath(n):
	for i in range(1,n+1):
		print cnk(n+i,i)
	return cnk(n+n,n)
	return reduce(lambda x,y:x+y,[cnk(n+i,i) for i in range(1,n)])
print fastpath(5)
print fastpath(20)