# ex2_15  A*算法解决15数码问题
# 1427405017
# 沈家赟
import copy
import time

class Node:
    def __init__(self, chess):
        self.a = chess
        self.d = 0
        self.w = 0
        self.f = self.d + self.w

    def print(self):
        print('**************************')
        for line in self.a:
            print(line)
        print('f=',self.f, ' [ d=',self.d,' w=',self.w,']')

    def move(self, direction):
        row0 = 0
        col0 = 0
        for i in range(16):
            row0 = int(i / 4)
            col0 = i % 4
            if self.a[row0][col0] == 0:
                break
        if direction == 'up':
            if (row0 - 1) < 0:
                return None
            self.a[row0][col0], self.a[row0 - 1][col0] \
                = self.a[row0 - 1][col0], self.a[row0][col0]
            return self.a
        elif direction == 'down':
            if (row0 + 1) > 3:
                return None
            self.a[row0][col0], self.a[row0 + 1][col0] \
                = self.a[row0 + 1][col0], self.a[row0][col0]
            return self.a
        elif direction == 'left':
            if (col0 - 1) < 0:
                return None
            self.a[row0][col0], self.a[row0][col0 - 1] \
                = self.a[row0][col0 - 1], self.a[row0][col0]
            return self.a
        elif direction == 'right':
            if (col0 + 1) > 3:
                return None
            self.a[row0][col0], self.a[row0][col0 + 1] \
                = self.a[row0][col0 + 1], self.a[row0][col0]
            return self.a
        pass

    # return True if sub is in chesslist
    def onlist(self, chesslist):
        for each in chesslist:
            if self.a == each.a:
                return each
        return False

    # return w的估价值
    def cacu_heru(self, end):
        count = 0
        for i in range(16):
            row = int(i / 4)
            col = i % 4
            if self.a[row][col] != end.a[row][col] and self.a[row][col] != 0:
                count += 1
        self.w = count
        return count

    def set_f(self, d, w):
        self.d = d
        self.w = w
        self.f = d + w
        return self.f

    def get_f(self):
        return self.f

# main
open = []
closed = []
# start = Node([[1,0,2,3],[4,5,6,7],[8,9,10,11],[12,13,14,15]])
start = Node([[1,2,3,4],[5,6,15,7],[8,9,10,11],[12,13,14,0]])
end = Node([[1,2,3,4],[5,6,0,7],[8,9,10,11],[12,13,14,15]])
open.append(start)

t0 = time.clock()
extend_count = 0    # 扩展节点数
node_count = 1      # 生成节点数(包含开始节点)
success = False
while open != []:
    n = open[0]
    n.print()
    print('扩展节点：', extend_count, ' 生成节点:', node_count)
    open = open[1:len(open)]
    # 当前状态n与目的状态匹配，则成功
    if n.a == end.a:
        success = True
        break
    tmplist = []

    up = copy.deepcopy(n)
    if up.move('up') != None:
        tmplist.append(up)

    down = copy.deepcopy(n)
    if down.move('down') != None:
        tmplist.append(down)

    left = copy.deepcopy(n)
    if left.move('left') != None:
        tmplist.append(left)

    right = copy.deepcopy(n)
    if right.move('right') != None:
        tmplist.append(right)

    # 没有任何子状态，则continue
    if len(tmplist) == 0:
        continue
    extend_count += 1   # 有子状态，则扩展个数+=1
    # node_count += len(tmplist)  # 有子状态。则生成节点数+=子状态数
    d = n.d + 1
    for sub in tmplist:
        # 计算子状态sub的估价函数值
        w = sub.cacu_heru(end)
        f = sub.set_f(d, w)
        # 子状态sub不在open或closed表中
        if not (sub.onlist(open)!=False or sub.onlist(closed)!=False):
            # 将子状态sub加入open表中
            open.append(sub)
            node_count+=1
        # 子状态sub在open表中
        if sub.onlist(open)!=False:
            tar = sub.onlist(open)
            if f < tar.get_f():
                tar.set_f(d, w)
        # 子状态sub在closed表中
        if sub.onlist(closed) != False:
            tar = sub.onlist(closed)
            if f < tar.get_f():
                tar.set_f(d, w)
        closed.append(n)
    # 根据估价函数值，从小到大重新排列open表
    open.sort(key = lambda Node:Node.f)
if success:
    print('Success!')
else:
    print('failure')
print('耗时（真实CPU时间）：', time.clock() - t0, 'sec.')
print('扩展节点数：', extend_count)
print('生成节点数：', node_count)