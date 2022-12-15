directories = {}
sub_directories = {} #a:e
small_totals = 0

current_directory = ""

f = open("d7.txt", "r")

for line in f:
    command = line[:4]
    if command == "dir ":
        if line[4:-1] not in directories:
            directories[line[4:-1]] = 0
            #print(line[4:-1])
            #print("Added directory ", line[4:-1], ": ", directories[line[4:-1]])
        if current_directory != "":
            sub_directories[current_directory].append(line[4:-1])
            #print("Added sub-directory: ", current_directory, ": ", sub_directories[current_directory])
            
    elif command == "$ cd" and line[5:-1] != "..":
        #print(line[5:-1])
        current_directory = line[5:-1]
        sub_directories[current_directory] = []
        #print("Moving into new directory: ", current_directory, ": ", sub_directories[current_directory])
        
    elif command[0] != "$" and command[0] != "d":
        if current_directory != "":
            file = line.split(" ")
            directories[current_directory] += int(file[0])
            #print("Adding file size ", file[0], "to directory ", current_directory,
                  #". New total file size: ", directories[current_directory])
    
f.close()



#add the sub-directories of the sub-directories to their main directory
for main_directory in sub_directories:
    for sub_directory in sub_directories[main_directory]:
        if sub_directory in sub_directories:
            for i in sub_directories[sub_directory]:
                if i not in sub_directories[main_directory]:
                    sub_directories[main_directory].append(i)

for directory in directories: #a
    for main_directory in sub_directories: #a
        if main_directory == directory:
            for sub_directory in sub_directories[main_directory]: #e
                #print("BEFORE - Directory ", i, ": ", directories[i], " Sub-directory ",j, ": ", directories[j])
                directories[main_directory] += directories[sub_directory]
                #print("AFTER - Directory ", i, ": ", directories[i], " Sub-directory ",j, ": ", directories[j])

for i in directories:
    if directories[i] < 100000:
        #print(i, directories[i])
        small_totals += directories[i]
        
print(small_totals)
