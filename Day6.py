
file = open("d6.txt", "r")
characters = ""
sequence = []
count = 0
doubles = 0

for char in file:
    characters = char
file.close()

for i in range(len(characters)):
    if i < 14:
        sequence.append(characters[i])
        print(sequence[i])
    else:
        #TODO check for repeating characters
        for j in range(14):
            if sequence.count(sequence[j]) > 1:
                doubles = 1

        if doubles == 0:
            print("Number of chars before non repeating sequences: ", i)
            i=len(characters)-1
        if doubles > 0:
            doubles = 0
            
        del(sequence[0]) #remove first character
        sequence.append(characters[i]) #add to the end

      
        
   
