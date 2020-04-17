# coding: utf-8
# clean and collect all English words and their pageIDs from seperated content text files
import re
import time
import threading
import multiprocessing

indexLock = threading.RLock()
wordDictLock = threading.RLock()
logFileLock = threading.RLock()

class SearchXMLThread(threading.Thread):
    def __init__(self, ID):
        threading.Thread.__init__(self)
        self.ID = ID

    def run(self):
        global wordDict
        global index
        global MAX_INDEX
        global t0
        global indexLock
        global wordDictLock
        global logFile
        global logFileLock

        while True:
            indexLock.acquire()
            curIndex = index
            index += 1
            indexLock.release()

            if curIndex > MAX_INDEX:
                break

            xmlFilePath = "F:\\Pages\\" + str(curIndex) + ".txt"
            try:
                file = open(xmlFilePath, "r", encoding="UTF-8")
            except FileNotFoundError:
                continue

            for line in file:
                line = line.strip("\n")
                words = re.split(r'\s|,|;|:|\*|\n|\t|\[|\]|<|>|\(|\)|_|-|=|\.|\?|\\|/|\+|!|@|#|\$|%|\^|&|\||\'|\"|\{|\}|[0-9]', line)

                for word in words:
                    if re.match(r"([a-z]|[A-Z]])+", word):
                        wordDictLock.acquire()
                        if word not in wordDict:
                            wordDict[word] = set()
                        wordDict[word].add(int(curIndex))
                        # wordDict.add(word+","+str(curIndex))     # store csv format word,pageIndex in set
                        wordDictLock.release()
            file.close()

            if curIndex % 1000 == 1:    # avoid print log to frequently
                logStr = "Thread "+str(self.ID)+"\t\t"+"traversed pageid"+str(curIndex)+"\t\t"+"\t\t"+"Elapse: "+str(time.clock() - t0)+"s"
                print(logStr)
                logFileLock.acquire()
                logFile.write(logStr+"\n")
                logFileLock.release()

        return


xmlPath = "F:\\simplewiki-latest-pages-articles.xml"
outDir = "F:\\Pages\\"


t0 = time.clock()
wordDict = dict()
logFile = open("ex8_3.log.txt", "w", encoding="UTF-8")


index = 1
MAX_INDEX = 512947
# MAX_INDEX = 211016
# MAX_INDEX = 20
MAX_THREAD_COUNT = 8

threads = []
for threadCount in range(MAX_THREAD_COUNT):
    searchThread = SearchXMLThread(threadCount+1)
    threads.append(searchThread)
    searchThread.start()

for thread in threads:
    thread.join()

logStr = "Retrieving finished in "+str(time.clock()-t0)+"s"+"\t\t"+str(len(wordDict))+" words collected"
print(logStr)
logFile.write(logStr+"\n")
logFile.close()

t1 = time.clock()

outFile = open("ex8_3.word-pageIndexes.csv", "w", encoding="UTF-8")
for word in wordDict:
    csvStr = word
    for index in wordDict[word]:
        csvStr += ","+str(index)
    outFile.write(csvStr+"\n")

outFile.close()

print("writing out to file finished in "+str(time.clock()-t1)+"s")


while True:
    word = input("input a word\n")
    t1 = time.clock()
    # print("page id set:")
    try:
        print(wordDict[word])
    except KeyError:
        print("word not existed")
    finally:
        print("\tsearch time: "+str(time.clock() - t1)+"s")