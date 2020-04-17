# coding: utf-8
#
# @title: ex5_4 - CIP exercise
# @description: search with zimb.txt and index file zimb.idx
# @author: SHEN Jiayun
# @createDate: 2017/12/7
# @updateDate: 2017/12/29

def pyEncode(pystr):
    initialDict = {'N/A':0, 'b':1, 'c':2, 'ch':3, 'd':4, 'f':5, 'g':6,
               'h':7, 'j':8, 'k':9, 'l':10, 'm':11, 'n':12, 'p':13,
               'q':14, 'r':15, 's':16, 'sh':17, 't':18, 'w':19,
               'x':20, 'y':21, 'z':22, 'zh':23}
    finalDict = {'a':0, 'ai':1, 'an':2, 'ang':3, 'ao':4, 'e':5, 'ei':6,
               'en':7, 'eng':8, 'er':9, 'i':10, 'ia':11, 'ian':12, 'iang':13,
               'iao':14, 'ie':15, 'in':16, 'ing':17, 'iong':18, 'iu':19,
               'o':20, 'ong':21, 'ou':22, 'u':23, 'ua':24, 'uai':25,
             'uan':26, 'uang':27, 'ueng':28, 'ui':29, 'un':30, 'uo':31,
             'v':32, 'van':33, 've':34, 'vn':35}

    initialEncode = 0
    initialCount = 0
    if pystr[0] in initialDict:
        initialEncode = initialDict[pystr[0]]
        initialCount = 1
    elif pystr[0:1] in initialDict:
        initialEncode = initialDict[pystr[0:1]]
        initialCount = 2
    else:   # no initial
        initialEncode = 0
        initialCount = 0

    final = pystr[initialCount:]
    finalCount = len(pystr) - initialCount
    if finalCount > 0 and final in finalDict:
        finalEncode = finalDict[final]
    else:   # wrong final
        finalEncode = -10000

    return initialEncode*len(finalDict) + finalEncode


def pinyinToWords_indexVer(pinyin, pinyinList):
    words = None    # default as None object

    pinyinEncode = pyEncode(pinyin)
    if pinyinEncode >= 0:
        csvData = pinyinList[pinyinEncode]
        items = csvData.split(',')
        if 'N/A' in items:
            return words
        startLoc = int(items[0])
        wordsCount = int(items[1])
        file = open("zimb.txt", mode='r', encoding='UTF-16')
        file.seek(startLoc, 0)   # seek to currentPinyin's corresponding words startLoc
        words = file.read(wordsCount)
        file.close()
        return words

    # final process
    return words

idxFile = open("zimb.idx", mode="r", encoding="UTF-16")
pinyinList = []
for line in idxFile:
    line = line.strip('\n')
    pinyinList.append(line)
    # items = line.split(',')     # seperate csv format to get item values
idxFile.close()


while True:
    pinyin = input("Please input a pinyin\n")
    words = pinyinToWords_indexVer(pinyin, pinyinList)
    if words == None:
        print("Wrong pinyin!")
    else:
        print(words)




# def pinyinToWords_indexVer(pinyin):
#     idxFile = open("zimb.idx", mode="r", encoding="UTF-16")
#     words = None    # default as None object
#     for line in idxFile:
#         line = line.strip('\n')
#         items = line.split(',')     # seperate csv format to get item values
#         currentPinyin = items[0]
#         # if pinyin is found in index file
#         if currentPinyin == pinyin:
#             currentStartLoc = int(items[1])
#             currentWordsCount = int(items[2])
#             file = open("zimb.txt", mode='r', encoding='UTF-16')
#             file.seek(currentStartLoc, 0)   # seek to currentPinyin's corresponding words startLoc
#             words = file.read(currentWordsCount)
#             file.close()
#             break
#     # final process
#     idxFile.close()
#     return words
#
#
# # main func
# print("CIP ex5_4 - search zimb.txt with index")
#
# pinyin = input("Input pinyin:")
# words = pinyinToWords_indexVer(pinyin)
# if words == None:
#     print("Invalid pinyin: no corresponding words.")
# else:
#     print(words)
