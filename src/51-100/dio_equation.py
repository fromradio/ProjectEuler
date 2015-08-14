# x*x-D*y*y = 1
import math

def fail_try():
	limit = 1000

	# y_lim = int(math.sqrt(2*limit))
	y_lim = limit*10

	print y_lim
	l = [-1 for i in range(0,limit+1)]
	for y in range(1,y_lim+1):
		# if y%2 == 1:
		t = y * y
		i = 1
		D = (t*i+2)*i
		while D<=limit:
			x = t*i+1
			if D>0:
				if l[D] == -1 or l[D]>x:
					l[D] = x
				# print x,y,D
			i+=1
			D = (t*i+2)*i
		i = 1
		D = (t*i-2)*i
		while D<=limit:
			x = t*i-1
			if D>0:
				if l[D] == -1 or l[D]>x:
					l[D] = x
				# print x,y,D
			i+=1
			D = (t*i-2)*i
		if y%2 == 0:
			t = y*y/2
			i = 1
			D = (t*i+2)*i/2
			while D<=limit:
				x = t*i+1
				if D > 0:
					if l[D] == -1 or l[D]>x:
						l[D] = x
					# print x,y,D
				i+=1
				D = (t*i+2)*i/2
			i = 1
			D = (t*i-2)*i/2
			while D<=limit:
				x = t*i-1
				if D > 0:
					if l[D] == -1 or l[D]>x:
						l[D] = x
					# print x,y,D
				i+=1
				D = (t*i-2)*i/2
	print l

	for y in range(1,y_lim+1):
		t = y*y+2
		for yt in range(1,y/13):
			if t%(yt*yt)==0:
				D = t/(yt*yt)
				x = t-1
				if D>limit:
					continue
				if l[D] == -1 or l[D]>x:
					l[D] = x
		t = y*y-2
		for yt in range(1,y/13):
			if t%(yt*yt)==0:
				D = t/(yt*yt)
				x = t+1
				if D>limit:
					continue
				if l[D] == -1 or l[D]>x:
					l[D] = x
		if y%2 == 0:
			t = y*y/2+2
			for yt in range(1,y/26):
				if t%(yt*yt)==0:
					D = t/(yt*yt*2)
					x = t-1
					if D>limit:
						continue
					if l[D]==-1 or l[D]>x:
						l[D]=x
			t = y*y/2-2
			for yt in range(1,y/26):
				if t%(yt*yt) == 0:
					D = t/(yt*yt*2)
					x = t+1
					if D>limit:
						continue
					if l[D] == -1 or l[D]>x:
						l[D]=x

	print l
	m=-1
	ind = -1
	for item in zip(l,range(0,limit+1)):
		if m < item[0]:
			m = item[0]
			ind = item[1]
	print m,ind

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

def another_try(limit,y_limit):
	primes = primeList(y_limit)
	c = 0
	d = {}
	def factor(n):
		def impl(n,dic):
			if n == 1 or n==0:
				return dic
			for p in primes:
				if n%p ==0:
					dic.setdefault(p,0)
					dic[p] += 1
					return impl(n/p,dic)
			dic.setdefault(n,0)
			dic[n] += 1
			return dic
		dic = {}
		return impl(n,dic)
	def tranverse(num,pl,limit):
		d[num] = 1
		if num<limit:
			if pl:
				tranverse(num*pl[0],pl,limit)
				tranverse(num,pl[1:],limit)
	l = [-1 for i in range(0,limit+1)]
	def analyze(n,method = 1):
		d = factor(n)
		dl = []
		for item in d:
			if d[item]%2 == 0:
				for i in range(0,d[item]/2):
					dl.append(item)
		if n == 650:
			print method
		def impl(t,li):
			if not li:
				r = n/(t*t)
				if r <= limit:
					if method == 1:
						if r <= 0:
							return
						if l[r]==-1 or l[r]>n-1:
							l[r] = n-1
					elif method == 2:
						if r <= 0:
							return
						if l[r]==-1 or l[r]>n+1:
							l[r] = n+1
				if r<= limit*2:
					if method == 3:
						if r % 2 == 0:
							r = r/2
							if r==13:
								print n,t
							if r <= 0:
								return
							if l[r]==-1 or l[r]>n-1:
								l[r] = n-1
					elif method==4:
						if r % 2 == 0:
							r = r/2
							if r==4:
								print r,n,t
							if r <= 0:
								return
							if l[r]==-1 or l[r]>n+1:
								l[r] = n+1
			else:
				impl(t*li[0],li[1:])
				impl(t,li[1:])
		impl(1,dl)
	for y in range(1,y_limit):

		analyze(y*y+2,1)
		analyze(y*y-2,2)
		if y%2 == 0:
			t = y*y/2
			analyze(t+2,3)
			analyze(t-2,4)
	print l
	m=-1
	ind = -1
	for item in zip(l,range(0,limit+1)):
		if m < item[0]:
			m = item[0]
			ind = item[1]
	print m,ind

def main():
	# fail_try()
	another_try(1000,1000000)

if __name__ == '__main__':
	main()