import math

limit = 3000L
# mlimit = int(math.pow(limit,1.0/3))




def cubeList(limit):
	return [x**3 for x in range(4500,10000)]
cubes = cubeList(limit)

def dictionary(i):
	si = str(i)
	d = {}
	for c in si:
		d.setdefault(c,0)
		d[c] += 1
	return d

def permu(i):
	si = str(i)
	n = len(si)
	c = [1]
	print c
	def impl(li,s,level):
		if level == n:
			if int(s) in cubes:
				c[0] += 1
		for i in range(0,n):
			if i not in li:
				impl(li+[i],s+si[i],level+1)
	impl([],'',0)
	return c

for i in cubes:
	c = 1
	for j in cubes:
		if j < i:
			continue
		if len(str(j)) > len(str(i)):
			break
		if i!= j:
			if dictionary(i)==dictionary(j):
				c+=1
	if c==5:
		print i

# print dictionary(41063625) == dictionary(56623104)
# print cubeList(limit)