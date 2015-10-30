s = "acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb"
dict = set(["abbcbda","cbdaaa","b","dadaaad","dccbbbc","dccadd","ccbdbc","bbca","bacbcdd","a","bacb","cbc","adc","c","cbdbcad","cdbab","db","abbcdbd","bcb","bbdab","aa","bcadb","bacbcb","ca","dbdabdb","ccd","acbb","bdc","acbccd","d","cccdcda","dcbd","cbccacd","ac","cca","aaddc","dccac","ccdc","bbbbcda","ba","adbcadb","dca","abd","bdbb","ddadbad","badb","ab","aaaaa","acba","abbb"]);

indices = [0]

for i in range(1, len(s)+1):
	words = [s[j:i] for j in indices]
	#print words 
	for w in words:
		if w in dict:
			indices.append(i)
			break;

print indices 