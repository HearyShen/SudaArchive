# -*- coding: utf-8 -*-
# ex1 产生式系统实验
# 1427405017
# 沈家赟

import copy

class Deduct:
    def __init__(self, t_conditions, t_results):
        self.conditions = t_conditions
        self.results = t_results

    def deduct(self, facts):
        for con in self.conditions:     # 匹配全部condition，产生式才能推导
            con_match = False
            for fact in facts:
                if(fact == con):
                    con_match = True
                    break
            if not con_match:
                return []
        return self.results


    def inv_deduct(self, facts):
        for con in self.results:     # 匹配全部condition，产生式才能推导
            con_match = False
            for fact in facts:
                if(fact == con):
                    con_match = True
                    break
            if not con_match:
                return []
        return self.conditions

# return True if fact is included in facts
# return False if fact is not included in facts
def ishave(fact, facts):
    for each in facts:
        if fact == each:
            return True
    return False

# decuct_list : 产生式对象的列表
# test_cons : 输入的条件
# inv : True则使用反向推导
def deduct_all(deduct_list, test_cons, inv):
    more = True
    while more:
        more = False
        for deductor in deduct_list:
            if inv:
                results = deductor.inv_deduct(test_cons)
            else:
                results = deductor.deduct(test_cons)
            if results != []:
                for result in results:
                    if not ishave(result, test_cons):
                        print(result)
                        test_cons.append(result)
                        more = True
                        # print(test_cons)


print('ex1 产生式实验')
url = 'rules.txt'
print('读取规则文件：',url)
file = open(url)
deduct_list = []       # 每一个产生式就是一个Deduct对象
for line in file:
    line = line.strip('\n')
    pre = line.split('->')
    conditions = pre[0].split('&')
    results = pre[1].split('&')
    t_deduct = Deduct(conditions, results)
    deduct_list.append(t_deduct)
    print(conditions,' -> ', results)
file.close()

# 输入推导条件
test_con = []
line = input('请输入推导条件（中文，空格隔开）：\n')
test_facts = line.split(' ')

# 正向推导
print('1） 正向推导...')
test_cons = copy.deepcopy(test_facts)
deduct_all(deduct_list, test_cons, False)

print('\n')

# 反向推导
print('2） 反向推导...')
test_cons = copy.deepcopy(test_facts)
deduct_all(deduct_list, test_cons, True)