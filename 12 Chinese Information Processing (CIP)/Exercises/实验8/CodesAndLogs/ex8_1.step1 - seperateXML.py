# coding: utf-8
# retrieve pages and store seperately from a large pages.xml
import time
import xml.etree.ElementTree as ETree

xmlPath = "F:\\simplewiki-latest-pages-articles.xml"
outDir = "F:\\Pages\\"


t0 = time.clock()
logFile = open("ex8_1.log.txt", "w", encoding="UTF-8")
file = open(xmlPath, "r", encoding="UTF-16")
findPage = False
pageCount = 0
for line in file:
    # secure bound(pre-search counted 211016 <page>s)
    # if pageCount > 212000:
    # if pageCount > 5:
    #     break

    if findPage:
        pageContent += line
        # outPageFile.write(line)
        if "</page>" in line:
            findPage = False
            xmlTree = ETree.fromstring(pageContent)
            outPageFile = open(outDir + str(xmlTree.find("id").text) + ".txt", "w", encoding="UTF-8")
            textContent = xmlTree.find("revision/text").text
            if textContent == None:
                textContent = ''
            outPageFile.write(textContent)
            outPageFile.close()
            # print("Finish Page "+str(pageCount))
    else:
        if "<page>" in line:
            pageContent = line
            findPage = True
            pageCount += 1
            # outPageFile = open(outDir + "page." + str(pageCount) + ".xml", "w", encoding="UTF-8")
            # outPageFile.write(line)
            if pageCount % 10000 == 1:
                logStr = "Finished pages: "+str(pageCount)+"\t\tElapse: "+str(time.clock()-t0)+"s"
                print(logStr)
                logFile.write(logStr+"\n")
        else:
            continue

file.close()

logStr = "Page Total Count: "+str(pageCount)+"\t\tElapse: "+str(time.clock()-t0)+"s"
print(logStr)
logFile.write(logStr+"\n")
logFile.close()