import math
import operator
fp = open('../../data/99.data')
data = []
for line in fp:
	data.append([int(i) for i in line.strip('\n').split(',')])

data = zip(range(1,len(data)+1),[i[1]*math.log(i[0]) for i in data])
m = max(data,key=operator.itemgetter(1))
print m