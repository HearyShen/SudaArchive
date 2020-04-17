# encoding: UTF-8
# Linux ex4
# 沈家赟 1427405017
# 2017/4/29
# 正确的（合法的）IP地址、QQ号、带区号的电话号码、大写字母等。
import re

print('Linux ex4\n正则表达式验证实验\n')

demo_filename = "demo.txt"

# 将正则表达式编译成Pattern对象
pattern_IP = re.compile(r"^((25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]{1}[0-9]{1}|[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]{1}[0-9]{1}|[0-9])$")

pattern_QQ = re.compile(r'^[1-9]{1}[0-9]{4,11}$')

pattern_Tel = re.compile(r'^([0-9]{3,4}(-| | - )[0-9]{8})|(\([0-9]{3,4}\)[0-9]{8})$')

# in_str = input("please input:")

print('reading demo RegularExpression in file: ', demo_filename, '\n')
lines = open(demo_filename)
for line in lines:
    line = line.strip("\n")
    print(line)
    # 使用Pattern匹配文本，获得匹配结果，无法匹配时将返回None
    match_IP = pattern_IP.match(line)
    if match_IP:
        # 使用Match获得分组信息
        print('\tIP Matched!\n')
        continue

    match_QQ = pattern_QQ.match(line)
    if match_QQ:
        # 使用Match获得分组信息
        print('\tQQ Matched!\n')
        continue

    match_Tel = pattern_Tel.match(line)
    if match_Tel:
        # 使用Match获得分组信息
        print('\tTel Matched!\n')
        continue

    print("\tNot Match any pattern!\n")


lines.close()

