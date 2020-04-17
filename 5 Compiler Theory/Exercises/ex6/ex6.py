# -*- coding:utf-8 -*-
# 编译原理 ex6 SLR
# 1427405017 沈家赟

class ActionEntry:
    def __init__(self, state, lookforward, action):
        self.state = int(state)  # state: mum
        self.lookforward = lookforward
        self.action = action

    def print(self):
        print(self.state, '\t\t', self.lookforward,'\t\t', self.action)

    @staticmethod
    def printMeta():
        print('state\tlookforward\taction')

class ActionList:
    def __init__(self, action_url):
        self.actions = []
        lines = open(action_url)
        for line in lines:
            line = line.strip('\n')
            parts = line.split(' ')
            action = ActionEntry(parts[0], parts[1], parts[2])
            self.actions.append(action)

    def getAction(self, state, lookforward):
        for entry in self.actions:
            if entry.state==state and entry.lookforward==lookforward:
                return entry.action     # !!注意：此处返回的是形如‘s1’的状态，非纯数字
        return None

    def print(self):
        print('*****************************')
        print('Action List:')
        ActionEntry.printMeta()
        for actionentry in self.actions:
            actionentry.print()

class RuleEntry:
    def __init__(self, id, left, right):
        self.id = int(id)        # 产生式序号
        self.left = left    # 左部
        self.right = right  # 右部

    def print(self):
        print(self.id, ' ', self.left, '->', self.right)

    @staticmethod
    def printMeta():
        print('id\t\tleft->right')

class RuleList:
    def __init__(self, rule_url):
        self.rules = []
        lines = open(rule_url)
        count = 0
        for line in lines:
            count += 1
            line = line.strip('\n')
            parts = line.split('->')
            rule = RuleEntry(count, parts[0], parts[1].split(' '))
            self.rules.append(rule)

    def getRule(self, rule_id):
        for rule in self.rules:
            if rule.id == rule_id:
                return rule     # here returns rule OBJECT
        return None

    def print(self):
        print('*****************************')
        print('Rule List:')
        RuleEntry.printMeta()
        for ruleentry in self.rules:
            ruleentry.print()

class GotoEntry:
    def __init__(self, state, nonterminal, dest_state):
        self.state = int(state)
        self.nonterminal = nonterminal
        self.dest_state = int(dest_state)

    def print(self):
        print(self.state, ' ', self.nonterminal, ' ', self.dest_state)

    @staticmethod
    def printMeta():
        print('state\t nonterminal\t dest_state')

class GotoList:
    def __init__(self, goto_url):
        self.gotos = []
        lines = open(goto_url)
        for line in lines:
            line = line.strip('\n')
            parts = line.split(' ')
            goto = GotoEntry(parts[0], parts[1], parts[2])
            self.gotos.append(goto)

    def getDest(self, state, nonterminal):
        for goto in self.gotos:
            if goto.state == state and goto.nonterminal == nonterminal:
                return goto.dest_state
        return None

    def print(self):
        print('*****************************')
        print('Goto List:')
        GotoEntry.printMeta()
        for gotoentry in self.gotos:
            gotoentry.print()

# main
# init: read files and build actions, rules and gotos
actions = ActionList('action.txt')
actions.print()
rules = RuleList('rule.txt')
rules.print()
gotos = GotoList('goto.txt')
gotos.print()

# input: type in phrase
# in_str = "id * id + id $"
# print('Eg. ', in_str)
in_str = input('Input Phrase (split with Space, finish with Enter)\n')
in_str_splits = in_str.split(' ')
# algorithm: SLR algorithm
slr_stack = []
slr_stack.append(0)
ip = 0      # 让ip指向输入串的第一个符号
# in_str = in_str[1:len(in_str)]
while True:
    s = slr_stack[-1]     # 令s是栈顶的状态
    a = in_str_splits[ip]                  # a是ip指向的符号
    action_str = actions.getAction(s, a)
    if action_str == None:
        print('Error: No corresponding action!')
        exit()
    if action_str[0] == 's':    # 1、若移进 - s为state
        slr_stack.append(a)     # a入栈
        state_id = int(action_str[1:len(action_str)])
        slr_stack.append(state_id)  # s入栈，即action_str所指的状态入栈
        ip += 1
        print('move in(a, state): ', a, ',', state_id)
    elif action_str[0] == 'r':  # 2、若规约A->β - r为rule
        rule_id = int(action_str[1:len(action_str)])
        rule = rules.getRule(rule_id)
        if rule == None:
            print('Error: No corresponding rule!')
            exit()
        beta_len = len(rule.right)
        for i in range(2*beta_len):
            slr_stack.pop()
        s_tmp = slr_stack[-1]   # s_tmp是现在的栈顶状态
        slr_stack.append(rule.left)     # 产生式左部A入栈
        goto_state_id = gotos.getDest(s_tmp, rule.left)
        if goto_state_id == None:
            print('Error: No corresponding goto!')
            exit()
        slr_stack.append(goto_state_id) # goto[s_tmp, A]入栈
        rule.print()    # 输出产生式A->β
    elif action_str == 'acc':   # 3、若接受
        print('Accept!')
        exit()
    else:
        print('Error!\n current stack(buttom -> top):')
        print(slr_stack)