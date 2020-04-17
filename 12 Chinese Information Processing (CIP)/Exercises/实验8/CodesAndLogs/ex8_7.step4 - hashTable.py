# coding: utf-8
# hash words and store hash-index in hashList, then search word-index and indexed page ids with hash
import time

t0 = time.clock()

HASH_BOUND = 10000
indexFile = open("wordLoc.index.csv", "r", encoding="UTF-8")

hashList = [dict() for x in range(0, HASH_BOUND)]
count = 0
for line in indexFile:
    line = line.strip('\n')
    items = line.split(',')
    word = items[0]
    index = items[1]
    # hash word and store word-index to hashList
    wordHash = hash(word) % HASH_BOUND
    hashListEntry = hashList[wordHash]
    hashListEntry[word] = int(index)
    count += 1
    if count % 100000 == 1:
        print(str(count)+" words Hashed\t\tElapse: "+str(time.clock()-t0)+"s")

indexFile.close()
print(str(count)+" words Hashed\t\tElapse: "+str(time.clock()-t0)+"s")


while True:
    word = input("input a word\n")
    wordHash = hash(word) % HASH_BOUND
    hashListEntry = hashList[wordHash]
    try:
        index = hashListEntry[word]
    except KeyError:
        print("word not existed!")
        continue
    csvFile = open("ex8_3.word-pageIndexes.csv", "r", encoding="UTF-8")
    csvFile.seek(index)
    line = csvFile.readline()
    print(line)
    csvFile.close()


