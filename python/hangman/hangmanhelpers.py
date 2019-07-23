def noErrors(character, inputchars):
	if len(character) != 1:
		print("Please input only one character")
	elif character.isdigit():
		print("please input a letter")
	elif character in inputchars:
		print("You have already used this letter")
	else:
		return True
	return False

def chooseNewWord(words):
	return words[random.randint(0, len(words))]
