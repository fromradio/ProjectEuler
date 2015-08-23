with open('../../data/102.data') as fp:
	def sgn(n):
		if n > 0:
			return 1
		elif n < 0:
			return -1
		else:
			return 0
	count = 0
	c = 0
	for line in fp:
		data = line.strip('\n').split(',')
		data = [int(i) for i in data]
		s1 = sgn(data[0]*data[3]-data[1]*data[2])
		s2 = sgn(data[2]*data[5]-data[3]*data[4])
		s3 = sgn(data[4]*data[1]-data[5]*data[0])
		if s1*s2==1 and s2*s3==1 and s1*s3==1:
			count += 1
		c += 1
	print count
