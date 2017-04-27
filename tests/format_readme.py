import re
f = open('problem_names.txt')
lines = f.read().split('\n')
n = len(lines)/2
d = {}
for i in range(n):
	ID = int(lines[2*i].strip())
	a, b = re.split('[0-9][0-9]\.[0-9]%', lines[2*i+1])
	d[ID] = (a.strip(), b.strip())

#| 9  | [Palindrome Number][9_link] \[ [python][py]  [java][java]   [cpp][cpp] \]

for k in sorted(d.keys()):
	s = '[{}][{}_link]'.format(d[k][0], k)
	#print '|{:3} | {:50}  \[ [python][py]  [java][java]   [cpp][cpp] \]'.format(k, s)
	name = '-'.join(d[k][0].split())
	name = re.sub("[^a-zA-Z0-9\-]", "", name.lower())
	print '[{}_link]: https://leetcode.com/problems/{}/'.format(k, name)