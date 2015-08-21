def isPali(s):
	l = len(s)
	for i in range(0,l/2):
		if s[i]!=s[l-1-i]:
			return False
	return True

def iteration(s):
	m = int(s) + int(s[-1::-1])
	return str(m)

count = 0
def isLychrel(i):
	s = iteration(str(i))
	k = 1
	found = True
	while not isPali(s):
		if k >= 50:
			found = False
			break
		s = iteration(s)
		k += 1
	return not found

for i in range(1,10000):
	if isLychrel(i):
		count += 1
print count
