def spiral(n):
	count = 1
	base = 3
	for i in range(3,n+1,2):
		count += (4*base+(i-1)*6)
		base += (3*(i-1)+i+1)
	return count
print spiral(1001)