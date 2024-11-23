import random

words = ["spare", "spark", "start", "smart", "store", "stone"]
chosen_word = random.choice(words)  
guessed_word = ["-"] * len(chosen_word)  
chances = 3  
guessed_letters = []  

print("Welcome to the Hangman game!")
print("All you have to do is guess the word letter by letter.")

while chances > 0:
    print("\nWord: " + "".join(guessed_word))
    print(f"Guessed letters: {', '.join(guessed_letters)}")
    guess = input(f"You have {chances} chances left. Enter a letter: ").lower()

    if len(guess) != 1 or not guess.isalpha():
        print("Your input is not valid... Please guess a single letter.")
        continue

    if guess in guessed_letters:
        print("Hold on. You already guessed that letter!")
        chances -= 1
        continue

    guessed_letters.append(guess)

    if guess in chosen_word:
        print("Good guess!")
        for i in range(len(chosen_word)):
            if chosen_word[i] == guess:
                guessed_word[i] = guess
    else:
        print("Wrong guess!")
        chances -= 1

    if "".join(guessed_word) == chosen_word:
        print(f"Congratulations! You guessed the word: {chosen_word}")
        break

if chances == 0:
    print(f"\n We are sorry but you ran out of chances... The correct word was: '{chosen_word}'.")
