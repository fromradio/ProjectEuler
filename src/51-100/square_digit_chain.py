num = 10000000

o = ord('0')

def next(n):
	c =0
	for s in str(n):
		c += (ord(s)-o)**2
	return c

mark = [0 for i in range(0,num+1)]
print len(mark)
mark[1] = 1
mark[89] = 2

def iter(n):
	if n>num:
		return iter(next(n))
	if mark[n]:
		return mark[n]
	else:
		mark[n] = iter(next(n))
		return mark[n]
count = 0
for i in range(1,num):
	iter(i)
print len([i for i in mark if i == 2])

print count