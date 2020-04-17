# coding: utf-8
#
# @title: ex5_3 - CIP exercise
# @description: search with zimb.txt only
# @author: SHEN Jiayun
# @createDate: 2017/12/7
# @updateDate: 2017/12/7

def pinyinToWords(pinyin):
    file = open("zimb.txt", mode="r", encoding="UTF-16")
    words = None    # default as None object
    for line in file:
        line = line.strip('\n')
        idx = 0
        for ch in line:
            if ch.encode(encoding="UTF-8").isalpha():
                idx += 1
        # split retrieve pinyin
        currentPinyin = line[0:idx]
        if currentPinyin == pinyin:
            words = line[idx:len(line)]     # retrive words if find pinyin
            break
    # final process
    file.close()
    return words


# main func
print("CIP ex5_4 - search zimb.txt")

pinyin = input("Input pinyin:")
words = pinyinToWords(pinyin)
if words == None:
    print("Invalid pinyin: no corresponding words.")
else:
    print(words)
