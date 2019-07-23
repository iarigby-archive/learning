import random
from datetime import datetime

def printWord(list):
	print("Your Progress:")
	for letter in list:
		print(letter, end = '')
	print('\n')

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

def newGame(words):
	word = chooseNewWord(words)

	needtowin = 0
	lives = 10
	inputchars = list()
	userchars = list()
	chars = list(word)

	for i in range(0,len(chars)):
		if (chars[i] == ' '):
			userchars.append(' ')
		else:
			userchars.append('_')
			needtowin = needtowin + 1

	while (needtowin > 0) & (lives > 0):
		character = input("Enter a character: ")
		if(noErrors(character, inputchars)):
			if character in chars:
				print("Correct!\n")
				while (character in chars):
					indx = chars.index(character)
					userchars[indx] = character
					chars[indx] = '-'
					needtowin = needtowin - 1
				printWord(userchars)
			else:
				lives = lives - 1
				print("the letter is not there:( " + str(lives) + " lives remaining\n")
			inputchars.append(character)
			
	if needtowin > 0:
		print("you lost:( the word was " + word)
		return 0
	else:
		print("you win!")
		return 1		

file = open("vocabulary.txt")
text = file.read()
words = text.split('\n')
file.close()

wantsToPlay = True
wins = 0
playedgames = 0
scores = open("scores.txt", "a")
while (wantsToPlay):
	if newGame(words) == 1:
		wins = wins + 1
	playedgames = playedgames + 1
	print("you have played " + str(playedgames) + " games and won " + str(wins))
	decision = input("Type 'yes' if you want to play a new game: ")
	if (decision != "yes"):
		wantsToPlay = False
		savescore = input("You finished game, want to save high score? type yes: ")
		if(savescore == "yes"):
			name = input("Enter your name: ")
			scores.write(name + "\t" + str(wins) + "\t" + datetime.today().ctime())