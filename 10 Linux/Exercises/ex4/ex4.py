# encoding: UTF-8
# 正确的（合法的）IP地址、QQ号、带区号的电话号码、大写字母等。
import re
 
# 将正则表达式编译成Pattern对象
pattern = re.compile(r'\d{3,4}|-\d{8}')

pattern_IP = re.compile(r'([0-9]{1,3}\.){3}[0-9]{1,3}')

pattern_QQ = re.compile(r'[1-9]{1}[0-9]{4,11}')

pattern_Tel = re.compile(r'([0-9]{3,4}-[0-9]{8})|(\([0-9]{3,4}\)[0-9]{8})')

in_str = input("please input:")
 
# 使用Pattern匹配文本，获得匹配结果，无法匹配时将返回None
match = pattern_Tel.match(in_str)
 
if match:
    # 使用Match获得分组信息
    print(match)
    print(match.group())
    print('Matched!')
else:
    print('Not Match!')


