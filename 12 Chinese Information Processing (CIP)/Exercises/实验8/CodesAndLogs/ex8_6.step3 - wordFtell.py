# coding: utf-8
# get word and its index(ftell offset) in word-pageIndexes.csv
import time

t0 = time.clock()

csvFile = open("ex8_3.word-pageIndexes.csv", "r", encoding="UTF-8")
indexFile = open("wordLoc.index.csv", "w", encoding="UTF-8")

# startLoc = csvFile.tell()
# for line in csvFile:
#     line = line.strip('\n')
#     items = line.split(',')
#     indexFile.write(items[0]+str(startLoc)+"\n")
#     startLoc = csvFile.tell()

isWord = True
word = ''
startLoc = csvFile.tell()
count = 0
while True:
    ch = csvFile.read(1)
    if ch:
        if isWord:
            if ch == ',':
                isWord = False
            else:
                word += ch
        if ch == '\n':
            indexFile.write(word+","+str(startLoc)+"\n")
            count += 1
            if count % 1000 == 1:
                print("No. "+str(count)+"\t\t"+word+","+str(startLoc)+"\t\tElapse: "+str(time.clock() - t0)+"s")
            word = ''
            isWord = True
            startLoc = csvFile.tell()
    else:
        break

csvFile.close()
indexFile.close()