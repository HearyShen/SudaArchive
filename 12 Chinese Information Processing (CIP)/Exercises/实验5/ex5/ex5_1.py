# coding: utf-8
#
# @title: ex5_1 - CIP exercise
# @description: read unicode file WINPY.TXT and generate zimb.txt
# @author: SHEN Jiayun
# @createDate: 2017/11/28
# @updateDate: 2017/11/29


# PinyinWords
# - records a word list to one pinyin
class PinyinWords:
    def __init__(self):
        self.pinyin = ''
        self.words = []

    def __init__(self, pinyin, word):
        self.pinyin = pinyin
        self.words = []
        self.words.append(word)

    def getPinyin(self):
        return self.pinyin

    def getWords(self):
        return self.words
    
    def addWord(self, word):
        # if exist, then return (do not append)
        for each in self.words:
            if each == word:
                return
        # if not exist, then append
        self.words.append(word)

    def toString(self):
        strLine = self.pinyin
        for word in self.words:
            strLine += word
        return strLine


# PinyinWordsList
# - records a list of PinyinWords instances
class PinyinWordsList:
    def __init__(self):
        self.pywList = []

    def insert(self, pyWords):
        self.pywList.append(pyWords)

    def insert(self, pinyin, word):
        # if exist corresponding pinyin, then add Word
        for pyWords in self.pywList:
            if pyWords.getPinyin() == pinyin:
                pyWords.addWord(word)
                return
        # if no exist pinyin, then create and append a new PinyinWords instance
        pyWords = PinyinWords(pinyin, word)
        self.pywList.append(pyWords)

    def display(self):
        for pyWds in self.pywList:
            print(pyWds.toString())

    def save(self, path):
        outFile = open(path, 'w', encoding='UTF-16')
        for pyWds in self.pywList:
            outFile.write(pyWds.toString() + '\n')

        outFile.close()


# main func
file = open("WINPY.TXT", encoding="utf-16")

pyWdsList = PinyinWordsList()
# traverse every line in WINPY file
for line in file:
    line = line.strip('\n')

    # split word and pinyin
    for char in line:
        if char.encode('UTF-8').isalpha():
            idx = line.find(char)   # find the index of fist alphabet
            break
    # retrieve word
    word = line[0:idx]
    if len(word) != 1:
        continue
    # retrieve pinyin(or pinyins)
    pinyin = line[idx:len(line)]
    # if exist multiple pinyins - split and insert
    if pinyin.find(' ') != -1:
        pinyinList = pinyin.split(' ')
        for eachPinyin in pinyinList:
            pyWdsList.insert(eachPinyin, word)
        continue
    # if exist only one pinyin - insert directly
    else:
        # insert the pinyin and word to PinyinWordsList instance
        pyWdsList.insert(pinyin, word)

# final output (to screen)
pyWdsList.display()
pyWdsList.save("zimb.txt")

# final processes
file.close()
