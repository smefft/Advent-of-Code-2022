
elf_ranges = []

count = 0

cleaning = open("cleaning.txt", "r")
for num in cleaning:
    elf_ranges.append(num.split(","))
    count += 1
cleaning.close()

overlap = 0

for num in range(count):
    
    range1_ends = (elf_ranges[num][0]).split("-")
    range2_ends = (elf_ranges[num][1]).split("-")

    range1 = []
    range2 = []
    for num in range(int(range1_ends[0]), int(range1_ends[1])+1):
        range1.append(num)
    for num in range(int(range2_ends[0]), int(range2_ends[1])+1):
        range2.append(num)

    if (int(range2_ends[0]) in range1) or (int(range2_ends[1]) in range1):
        #print(range2_ends[0], range2_ends[1])
        overlap += 1
        #print("found in range 1")
    elif (int(range1_ends[0]) in range2) or (int(range1_ends[1]) in range2):
        #print(range1_ends[0], range1_ends[1])
        overlap += 1
        #print("found in range 2")

print(overlap)
                   

                   
