file = open("in.txt")
text = file.read()
file.close()

out = open("vocabulary.txt", "w")
for line in text.split('\n'):
	if (len(line) != 1):
		out.write(line + '\n')
out.close()
