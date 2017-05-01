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
		return "_{}_{}".format(str(self.ID).zfill(3), fn)

	def __str__(self):
		return '{}. {:60} {:10}'.format(self.ID, self.name, self.level)

def get_link(name):
	name = '-'.join(name.split())
	name = re.sub("[^a-zA-Z0-9\-]", "", name.lower())
	return 'https://leetcode.com/problems/{}/'.format(name)

def write_links(problems):
	f = open('links.txt', 'w')
	for p in problems:
		f.write(p.link + '\n')

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

def generate_python_files(problems, directory):
	for p in problems:
		fn = directory + '/{}.py'.format(p.filename())
		content = "# Author: Thong Le\n# Date: \n#\n# LeetCode {} - {}\n#\n".format(p.ID, p.name)
		content += "# Solution Approach: \n#\n#\n#\n"
		f = open(fn, 'w')
		f.write(content)

def generate_java_files(problems, directory):
	for p in problems:
		fn = directory + '/{}.java'.format(p.filename())
		content = "/* \n"
		content += "* Author: Thong Le\n* Date: \n*\n* LeetCode {} - {}\n*\n".format(p.ID, p.name)
		content += "* Solution Approach: \n*\n*\n*\n"
		content += "*/\n\n\n\n\n"
		content += "public class {} {{\n".format(p.filename())
		content += "\tpublic int function_name() {\n"
		content += "\t}\n}\n"
		f = open(fn, 'w')
		f.write(content)
	for p in problems:
		fn = directory + '/_{}_Test.java'.format(str(p.ID).zfill(3))
		content = "public class _{}_Test {{\n".format(str(p.ID).zfill(3))
		content += "\tpublic static void main (String[] args) {"
		content += "\n\t\t {} sol = new {}();\n".format(p.filename(), p.filename())
		content += "\t}\n"
		content += "}\n"
		f = open(fn, 'w')
		f.write(content)

def generate_cpp_files(problems, directory):
	for p in problems:
		fn = directory + '/{}.cpp'.format(p.filename())
		content = "/* \n"
		content += "*    Author: Thong Le\n*    Date: \n*   \n*    LeetCode {} - {}\n*\n".format(p.ID, p.name)
		content += "*    Solution Approach: \n*\n*\n*\n"
		content += "*/\n\n"
		content += "#include <iostream>\n#include <algorithm>\n#include <vector>\n#include <set>\n#include <unordered_map>\n\n"
		content += "using namespace std;\n\n"
		content += "class Solution {\n"
		content += "public:\n\n"
		content += "\tint func() {\n"
		content += "\t\treturn 0;\n"
		content += "\t}\n"
		content += "};\n\n\n"
		content += "int main() {\n"
		content += "\treturn 0;\n"
		content += "}\n"
		f = open(fn, 'w')
		f.write(content)

if __name__ == '__main__':
	problems = read_file('problems_rawdata.txt')
	#generate_python_files(problems, '../python')
	#generate_java_files(problems, '../java')
	#generate_cpp_files(problems, '../cpp')

	