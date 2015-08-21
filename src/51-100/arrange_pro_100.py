import math
num = int(1e12)
# num = 115
# print num
dis = 50000000
# dis = 10
# squares = [x*x for x in range(num+1,int(ratio*num),2)]
nx = 707106
# print nx
# sqx = [x*x for x in range(nx,int(ratio*num),2)]

def isSquare(n):
	sn = math.sqrt(n)
	if int(sn)**2==n:
		return True
	if (int(sn)+1)**2==n:
		return True
	return False
i = num+1
while True:
	# x = (i*i+1)/2
	x = 1+2*(i*i-i)
	if isSquare(x):
		print (1+math.sqrt(x))/2
		break
	i += 1