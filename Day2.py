games = []
score_total = 0

file = open("RPS.txt", "r")
for game in file:
    games.append(game.split(" "))
file.close()

#figure out how to compare

#A beats Z, loses to Y, tie with X
    #1 - 3, 1 - 2, 1 - 1
#B beats X, loses to Z, tie with Y
    #2 - 1, 2 - 3, 2 - 2
#C beats Y, loses to X, tie with Z
    #3 - 2, 3 - 1, 3 - 3

#Y is draw
#X is loss
#Z is win

for i in range(len(games)):
    if games[i][0] == 'A':
        elf = 1
    elif games[i][0] == 'B':
        elf = 2
    elif games[i][0] == 'C':
        elf = 3
        
    #you need to lose
    if games[i][1] == 'X\n':
        if elf == 1:
            you = 3
        elif elf == 2:
            you = 1
        elif elf == 3:
            you = 2
        score_total += (you + 0)
    #draw
    elif games[i][1] == 'Y\n':
        you = elf
        score_total += (you + 3)
    #you need to win
    elif games[i][1] == 'Z\n':
        if elf == 1:
            you = 2
        elif elf == 2:
            you = 3
        elif elf == 3:
            you = 1
        score_total += (you + 6)

print(score_total)

