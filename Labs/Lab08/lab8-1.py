import random

number = random.randint(1, 100)
chances = 10 

print("Welcome to the rng number guessing minigame!")
print("Here's how you play! All you have to do is guess from a random number I have chosen a number between 1 and 100. Good luck! :)")

while chances > 0:
    guess = int(input(f"\nYou have {chances} chances left. Try a guess: "))
    difference = abs(guess - number)
    
    if guess == number:
        print("Not bad! You guessed the right number and won the minigame!")
        break
    else:
        if difference <= 5:
            print("Hot! You're very close!")
        elif difference <= 10:
            print("Warm! You're close!")
        elif difference <= 20:
            print("Cold! You're a bit far!")
        else:
            print("Freezing! You're WAY off!")
    
    chances -= 1

if chances == 0:
    print(f"\nWe're so sorry... You're out of chances. The correct number was {number}. Better luck next time!")
