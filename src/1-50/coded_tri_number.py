
fp = open('../../data/42.data')

for line in fp:
	data = line.strip('"').split('","')

l = []
tn = [n*(n+1)/2 for n in range(1,21)]
def count(word):
	num = 0
	for c in word:
		num += (ord(c)-ord('A')+1)
	return num
cc = 0
for word in data:
	n = count(word)
	if n in tn:
		cc += 1

# print max(l)
print tn[-1]
print count('SKY')
print cc