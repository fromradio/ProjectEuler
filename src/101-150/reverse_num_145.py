num = 10000000

# n[0] + n[d-1] is odd
# 		n[0] cannot be 0
# 		n[0] + n[d-1] < 10:
# 			8+7+6+5+4+3+2+1 (36)
# 			odd: (<10)
# 				4(1) + 4(2) + 3(3) + 3(4) + 2(5) + 2(6) + 1(7) + 1(8) = 20
# 			even:
# 				4(1) + 3(2) + 
#		> 10:
# 			1(2)+1(3)+2(4)+2(5)+3(6)+3(7)+4(8)+4(9)
# 		
# 		n[0] + n[d-1] > 10:
# 			1,2; 1,4; 1,6; 1,8; 3,2; 3,4; 3,6; 5,2; 5,4; 7,2
# 			3,8; 5,6; 5,8; 7,4; 7,6; 7,8; 9,2; 9,4; 9,6; 9,8
# if n[1] + n[d-2] is even(must be < 10):
#			5(0) + 4(1) + 4(2) + 3(3) + 3(4) + 2(5) + 2(6) + 1(7) + 1(8) = 25
# 			5 for odd
# 
# 		n[0] + n[d-1] > 10
# 		n[2] + n[d-3] > 10
# else:
# 		n[0] + n[d-1] < 10
# 		n[2] + n[d-3] < 10

# four digits
# 	first case: 20*20
# 	second case:
# 		2009+9002

count = 0
for dig in range(1,10):
	if dig % 4 == 1:
		# middle is the odd one, thus no such numbers
		continue
	elif dig % 4 == 2:
		count += 20*(30**(dig/2-1))
	elif dig % 4 == 3:
		count += 20*5*(20**(dig/4))*(25**(dig/4))
	else:
		count += 20*(30**(dig/2-1))

print count

# def isOddDigit(n):
# 	sn = str(n)
# 	for c in sn:
# 		if (ord(c)-48)%2==0:
# 			return False
# 	return True

# def reverseNum(n):
# 	return int(str(n)[::-1])

# count = 0
# for i in range(1,num):
# 	if str(i)[-1] == '0':
# 		continue
# 	if isOddDigit(i+reverseNum(i)):
# 		print i
# 		count += 1

# print count