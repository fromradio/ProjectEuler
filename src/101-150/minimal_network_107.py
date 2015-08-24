# read data
with open('../../data/107.data') as fp:
	mat = []
	def transfer(i):
		if i=='-':
			return float('inf')
		else:
			return int(i)
	for line in fp:
		data = line.strip('\n').split(',')
		mat.append([transfer(x) for x in data])

# mat is the adjancent matrix
def PrimAlgo(mat):
	n = len(mat)
	C = [float('inf') for i in range(0,n)]
	E = ['f' for i in range(0,n)]
	F = {}
	Q = set(range(0,n))
	first = True
	while len(Q):
		if first:
			curr = 0
			Q.remove(0)
			F.setdefault(0,E[0])
			first = False
		else:
			curr = min(zip([C[i] for i in Q],Q),key = lambda x:x[0])
			curr = curr[1]
			Q.remove(curr)
			F.setdefault(curr,E[curr])
		print Q
		for i in range(0,n):
			if mat[curr][i]<float('inf'):
				if C[i] > mat[curr][i] and i in Q:
					C[i] = mat[curr][i]
					E[i] = [curr,mat[curr][i]]
				pass
	return F

def main():
	m = PrimAlgo(mat)
	s = 0
	for line in mat:
		s += sum([x for x in line if x != float('inf')])
	s /= 2
	k = 0
	for i in m:
		if m[i] != 'f':
			k += m[i][1]
	print k,s-k
	print m

if __name__ == '__main__':
	main()