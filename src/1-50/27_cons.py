def digit(n):
	i = 1
	l = 1
	limit = 0
	count = 0
	resi = n
	while True:
		count += 9*i
		# limit += 9*i*l
		if resi > 9*i*l:
			l += 1
			i *= 10
			resi -= 9*i*l
		else:
			# find n
			return int(str(count+resi/l)[resi%l])
