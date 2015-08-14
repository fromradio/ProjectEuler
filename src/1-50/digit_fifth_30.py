
def fifth_power(n):
	return n*n*n*n*n

count = 0
for num in range(10,354294):
	resi = num
	sum = 0
	while resi != 0:
		d = resi%10
		resi = (resi-d)/10
		sum += fifth_power(d)
	if sum == num:
		count += num

print count