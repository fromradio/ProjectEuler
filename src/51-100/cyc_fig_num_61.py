
tris = [n*(n+1)/2 for n in range(1,500)]
tris = [n for n in tris if n>=1000 and n<10000]

sqs = [n**2 for n in range(1,400)]
sqs = [n for n in sqs if n>=1000 and n<10000]

pens = [n*(3*n-1)/2 for n in range(1,500)]
pens = [n for n in pens if n>=1000 and n<10000]

hexs = [n*(2*n-1) for n in range(1,400)]
hexs = [n for n in hexs if n>=1000 and n<10000]

heps = [n*(5*n-3)/2 for n in range(1,400)]
heps = [n for n in heps if n>=1000 and n<10000]

octs = [n*(3*n-2) for n in range(1,400)]
octs = [n for n in octs if n>=1000 and n<10000]

nums = [tris,sqs,pens,hexs,heps,octs]

def order(n):
	l = []
	def impl(li,level):
		if level == n:
			l.append(li)
		for i in range(0,n):
			if i not in li:
				impl(li+[i],level+1)
	impl([],0)
	return l
t = 6
orders = order(t)
for o in orders:
	pairs = nums[0]
	for k  in range(0,t):
		if k == 0:

			pairs = [(i,j) for i in nums[o[0]] for j in nums[o[1]] if str(i)[2:]==str(j)[0:2]]
		elif k == t-1:
			pairs = [i for i in pairs if str(i[-1])[2:]==str(i[0])[0:2]]
		else:
			kk = o[(k+1)%t]
			pairs = [i+(j,) for i in pairs for j in nums[kk] if str(i[k])[2:] == str(j)[0:2]]
	if pairs:
		print o,pairs,sum(pairs[0])
