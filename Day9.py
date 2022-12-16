#Day 9 - tracking how 9 knots move based on how the head is moved
#count how many unique positions the tail lands on

import math

directions = [] #Up, Down, Left, or Right
movements = [] #Number to move in direction

#populate lists with directions from file
f = open("d9.txt", "r")
for line in f:
    directions.append(line[0])
    movements.append(int(line[2:].strip()))
f.close()


#FUNCTION moves rope one knot at a time based on previous knot's position
#returns updated rope
def moveRope(rope, head):           
    for num in range(len(rope)): #set knot and check for head and tail
        knot = rope[num]
        if num != 0:
            prevKnot = rope[num-1]
        else:
            prevKnot = head

        #move each knot based on previous knot's position
        knot = checkKnot(prevKnot[0]-knot[0], prevKnot[1]-knot[1], knot)
    return rope

#FUNCTION checks if knot or tail is being pulled by the previous knot
#returns new knot coordinates
def checkKnot(row_diff, col_diff, knot):
    if abs(row_diff) > 1: #if head and tail are more than one row apart
        if col_diff == 0: #same column
            #move up or down
            knot[0] += move(row_diff)
        else: #not same column, move both
            #move diagonal
            knot[0] += move(row_diff)
            knot[1] += move(col_diff)
    elif abs(col_diff) > 1: #if head and tail are more than one column apart
        if row_diff == 0: #same row
            #move right or left
            knot[1] += move(col_diff)
        else: #not the same row
            #move diagonal
            knot[0] += move(row_diff)
            knot[1] += move(col_diff)
    return knot
        
#FUNCTION returns -1 or 1 to move column or row up, down, left, or right
def move(difference):
    if difference < 0:
        return -1
    elif difference > 0:
        return 1



#MAIN program
head = [15, 15] #[row][column]
tail = [15, 15] #[row][column]
#all knots start at the same coordinates
rope = [[15,15], [15,15], [15,15], [15,15], [15,15], [15,15], [15,15], [15,15], tail] #9 knots, tail is knot 9

tail_spots = [] #tracks what coordinates the tail has been on
tail_spots.append([15,15])

index = 0
for direction in directions:
    if direction == 'U': #head moves row up
        for i in range(movements[index]): #update head, rope, and tail
            head[0] -= 1
            rope = moveRope(rope, head)
            tail = rope[8]
            
            #check if coordinate has been touched by tail before
            if tail not in tail_spots:
                tail_spots.append([tail[0], tail[1]])
            
    elif direction == 'D': #row down
        for i in range(movements[index]):
            head[0] += 1
            rope = moveRope(rope, head)
            tail = rope[8]
                
            if tail not in tail_spots:
                tail_spots.append([tail[0], tail[1]])
            
    elif direction == 'L': #column left
        for i in range(movements[index]):
            head[1] -= 1
            rope = moveRope(rope, head)
            tail = rope[8]
            
            if tail not in tail_spots:
                tail_spots.append([tail[0], tail[1]])
            
    elif direction == 'R': #column down
        for i in range(movements[index]):
            head[1] += 1
            rope = moveRope(rope, head)
            tail = rope[8]
            
            if tail not in tail_spots:
                tail_spots.append([tail[0], tail[1]])
    index+=1

print(len(tail_spots))

print("Head final: ", head[0], head[1])
print("Tail final: ", tail[0], tail[1])



