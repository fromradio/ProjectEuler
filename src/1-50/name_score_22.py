fp = open('../../data/22.data')

data = []
for line in fp:
	data = data + line.strip('"').split('","')

data.sort()
print data
print data[937]

count = 0
for i,d in zip(range(1,len(data)+1),data):
	score = 0
	for c in d:
		score += ord(c)-ord('A')+1
	count += i*score

print count