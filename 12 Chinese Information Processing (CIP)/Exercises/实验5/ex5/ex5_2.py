# coding: utf-8
#
# @title: ex5_2 - CIP exercise
# @description: read zimb.txt and generate index file zimb.idx {pinyin,startLoc,wordsCount}
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
        finalEncode = -1

    return initialEncode*len(finalDict) + finalEncode




# main func
file = open("zimb.txt", 'r', encoding="utf-16")
idxFile = open("zimb.idx", 'w', encoding="utf-16")

indexList = ['N/A\n' for x in range(24*36)]  # init a definite len list for install index data

pinyin = ''
startLoc = 0
wordsCount = 0
while True:
    char = file.read(1)
    if char:
        if char.encode('UTF-8').isalpha():
            pinyin += char
            startLoc = file.tell()
        elif char == '\n':
            # Here, pinyin, startLoc, wordsCount are all prepared
            pinyinEncode = pyEncode(pinyin)
            # store CSV to indexList
            if pinyinEncode >= 0:
                indexList[pinyinEncode] = str(startLoc) + "," + str(wordsCount)+"\n"
            print(pinyin+','+str(pinyinEncode) + ','+str(startLoc) + "," + str(wordsCount)+"\n")
            # reset for next line
            pinyin = ''
            startLoc = 0
            wordsCount = 0

        else:
            wordsCount += 1
    else:
        break

idxFile.writelines(indexList)


# wordsCount = 0
# alphaList = []
# while True:
#     char = file.read(1)
#     if char:
#         # encounter pinyin alphabet
#         if char.encode("UTF-8").isalpha():
#             alphaList.append(char)
#             startLoc = file.tell()
#         # encounter newline character
#         elif char == '\n':
#             # construct a csv format string: "pinyin,startLoc,wordsCount"
#             idxLine = ""
#             for alpha in alphaList:
#                 idxLine += alpha
#             idxLine += ','
#             idxLine += str(startLoc)
#             idxLine += ','
#             idxLine += str(wordsCount)
#
#             # write csv format string to idx file
#             print(idxLine + "\t\t" + str(file.tell()))
#             idxFile.write(idxLine + '\n')
#
#             # reset counters and buffers
#             wordsCount = 0
#             alphaList.clear()
#         # encounter Chinese word
#         else:
#             wordsCount += 1
#     else:
#         break


# wordsCount = 0
# alphaList = []
# while True:
#     char = file.read(1)
#     if char:
#         # encounter pinyin alphabet
#         if char.encode("UTF-8").isalpha():
#             alphaList.append(char)
#             startLoc = file.tell()
#         # encounter newline character
#         elif char == '\n':
#             # construct a csv format string: "pinyin,startLoc,wordsCount"
#             idxLine = ""
#             for alpha in alphaList:
#                 idxLine += alpha
#             idxLine += ','
#             idxLine += str(startLoc)
#             idxLine += ','
#             idxLine += str(wordsCount)
#
#             # write csv format string to idx file
#             print(idxLine + "\t\t" + str(file.tell()))
#             idxFile.write(idxLine + '\n')
#
#             # reset counters and buffers
#             wordsCount = 0
#             alphaList.clear()
#         # encounter Chinese word
#         else:
#             wordsCount += 1
#     else:
#         break

# final process
file.close()
idxFile.close()

