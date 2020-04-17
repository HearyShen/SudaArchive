# coding: utf-8
# python version 3.5
#
# 1427405017
# 沈家赟
# 2017.11.2
#
# need to install pygame (to play mp3)
#  - pip install pygame

import pygame

# waitForPlay
# 自定义函数，实现pygame异步播放情况下，对音频播放服务的忙等延时，避免程序直接返回导致播放服务过早中止
def waitForPlay():
    while pygame.mixer.music.get_busy():
        pygame.time.delay(200)
    return


# loadAndPlay
# 自定义函数，实现加载并播放path下的file音频文件
def loadAndPlay(path, file):
    track = pygame.mixer.music.load(path+file)

    print("start play..."+file)
    pygame.mixer.music.play()
    waitForPlay()  # play函数异步播放，会立即返回，通过自定义waitForPlay函数实现完整播放
    pygame.mixer.music.stop()
    print("play end."+file)

    return

# Pinyin
# 自定义类，实现拼音输入码到对应字符的数据结构，是输入码映射表的条目类
class Pinyin:
    def __init__(self, inputCode, charLine):
        self.inputCode = inputCode
        self.charLine = charLine
        # self.chars = []
        # for ch in charLine:
        #     self.chars.append(ch)
        return

    def hasChar(self, char):
        if self.charLine == None:
            return False
        if self.charLine.find(char) >= 0:
            return True
        else:
            return False

    def getPinyin(self):
        return self.inputCode



# initPinyinList
# 自定义函数，实现对输入码映射表文件的读取，并在内存中建立输入码与汉字映射表数据结构
def initPinyinList(filename):
    file = open(filename, encoding='gb18030')
    pyList = []

    for line in file:
        line = line.strip('\n')
        if line.find(' ') > 0:  # 如果存在空格，此输入码有对应汉字字符
            [py, chLine] = line.split(' ')
        else:                   # 如果无空格，即此输入码无对应汉字字符
            py = line
            chLine = None
        pyList.append(Pinyin(py, chLine))
    return pyList


# -*- main func -*-
path = 'D:\\CHNsound\\'	# 此处无法包含中文路径
pygame.mixer.init()
pygame.time.delay(1000)			# init返回后，等待1000ms让mixer完成初始化，否则易出现前半段声音未被播放
print("pygame.mixer.init  done!")
print("local sound dirctory: "+path)

pyList = initPinyinList('汉字与拼音对照表.txt')

while True:
    words = input("请输入汉字(N/n结束)：")
    if words == 'N' or words == 'n':
        break

    playList = []
    for word in words:
        for py in pyList:
            if py.hasChar(word):
                pinyin = py.getPinyin()
                playList.append(pinyin)
                break

    # 连贯播放，免除边播放边查找带来的的耗时间隔
    for playEntry in playList:
        fname = playEntry + '.mp3'
        loadAndPlay(path, fname)