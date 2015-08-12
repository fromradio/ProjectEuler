def digit(n):
	i = 1
	l = 1
	limit = 0
	count = 0
	resi = n-1
	while True:
		
		# limit += 9*i*l
		if resi >= 9*i*l:
			count += 9*i
			resi -= 9*i*l
			l += 1
			i *= 10
		else:
			# find n
			# print count+resi/l+1,resi,l, count
			return int(str(count+resi/l+1)[resi%l])

if __name__ == '__main__':
	print digit(1)*digit(10)*digit(100)*digit(1000)*digit(10000)*digit(100000)*digit(1000000)
