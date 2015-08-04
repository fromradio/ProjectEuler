def fab():
	l = [1,1]
	a = 2
	while len(str(a)) < 3:
		l.append(a)
		a = l[-1]+l[-2]
	print len(l)+1

def main():
	fab()

if __name__ == '__main__':
	main()