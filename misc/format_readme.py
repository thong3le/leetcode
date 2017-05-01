import re

class Problem:
	def __init__(self, ID, name, link, level):
		self.ID = ID
		self.name = name
		self.link = link
		self.level = level
	def filename(self):
		fn = '_'.join(self.name.split())
		fn = re.sub("[^a-zA-Z0-9_]", "", fn.lower())
		return "_{}_{}".format(self.ID, fn)

	def __str__(self):
		return '{}. {:60} {:10}'.format(self.ID, self.name, self.level)

def get_link(name):
	name = '-'.join(name.split())
	name = re.sub("[^a-zA-Z0-9\-]", "", name.lower())
	return 'https://leetcode.com/problems/{}/'.format(name)

def write_readme(problems):
	for p in problems:
		description = '[{}][{}_link]'.format(p.name, p.ID)
		print '|{:3} | {:50}  \[ [python][py]  [java][java]   [cpp][cpp] \]'.format(p.ID, description)
	print '<!-- &#x1f512;   for the lock -->\n<!-- tiltle -->\n'
	for p in problems:
		print '[{}_link]: {}'.format(p.ID, p.link)

def read_file(filename):
	f = open(filename, 'r')
	lines = f.read().split('\n')
	n = len(lines)/2
	problems = []
	for i in range(n):
		ID = int(lines[2*i].strip())
		#print ID, lines[2*i+1]
		name, level = re.split('[0-9][0-9]\.[0-9]%', lines[2*i+1])
		name = name.strip()
		level = level.strip()
		link = get_link(name)
		problems.append(Problem(ID, name, link, level))
	return problems

def generate_files(problems, ext, directory):
	for p in problems:
		fn = directory + '/{}'.format(p.filename()) + ext
		content = ""
		f = open(fn, 'w')
		f.write(content)

if __name__ == '__main__':
	problems = read_file('solved_problems_rawdata.txt')
	f = open('links.txt', 'w')
	for p in problems:
		f.write(p.link + '\n')