# -*- coding: utf-8 -*-
# OS ex4 可变分区管理
# 1427405017  沈家赟

class Process:
    def __init__(self, id, base, limit):
        self.id = id
        self.base = base
        self.limit = limit


    def get_id(self):
        return self.id

    def get_base(self):
        return self.base
    def set_base(self, base):
        if base<0:
            print('Error: Invalid base')
            return False
        self.base = base
        return True

    def get_limit(self):
        return self.limit

    @staticmethod
    def print_meta():
        print('pid\t base\t limit')

    def print(self):
        print(self.id, '\t ', self.base, '\t ', self.limit)


class Memory:
    def __init__(self, size):
        self.size = size  # 系统内存容量为100kB
        self.processes = []

    def my_malloc(self, process_id, mem_j):
        self.processes.sort(key = lambda Process:Process.base)
        holes = []
        prev_ps = None
        # solution for holes between processes
        for ps in self.processes:
            if prev_ps != None:
                prev_ps_end = prev_ps.get_base() + prev_ps.get_limit()
                hole_limit = ps.get_base() - prev_ps_end
                if hole_limit > 0:  # if hole space exists
                    holes.append((prev_ps_end, hole_limit)) # keep {hole_base, hole_limit} in holes list
            prev_ps = ps
            if ps.get_id() == process_id:
                print('Error: Invalid Process ID:', process_id)
                return None

        # solution for last hole
        if prev_ps == None: # current process is the first
            holes.append((0, self.size))
        else:       # current process is the end process
            prev_ps_end = prev_ps.get_base() + prev_ps.get_limit()
            hole_limit = self.size - prev_ps_end
            if hole_limit > 0:  # if hole space exists
                holes.append((prev_ps_end, hole_limit))  # keep {hole_base, hole_limit} in holes li

        holes.sort(key = lambda hole:hole[1])   # 顺序排序holes
        canAllocate = False
        for hole in holes:
            if hole[1] >= mem_j:    # 最佳适配：取最小的能满足需求的hole（hole[1]即hole_limit）
                base = hole[0]      # hole[0]即hole_base
                canAllocate = True
                break
        if not canAllocate:
            totalspace = 0
            for hole in holes:
                totalspace += hole[1]
            if totalspace < mem_j:  # total hole space is not enough
                print('Error:my_malloc  Lack of Memory! pid:',process_id,'limit:',mem_j)
                return None
            # run compaction
            print('log:running compaction...')
            prev_ps = None
            for ps in self.processes:
                if prev_ps == None: # ps is the first ps
                    if ps.get_base() > 0:
                        ps.set_base(0)
                else:
                    ps.set_base(prev_ps.get_base() + prev_ps.get_limit())   # squeeze hole
                prev_ps = ps
            prev_ps_end = prev_ps.get_base() + prev_ps.get_limit()
            holes = [(prev_ps_end, self.size - prev_ps_end)]    # result: one large hole left
            base = prev_ps_end

        new_process = Process(process_id, base, mem_j)
        self.processes.append(new_process)
        print('Success:my_malloc  p_id:', process_id, ' base:', base, 'limit:', mem_j)
        return new_process

    def my_free(self, process_id):
        tar_ps = None
        for ps in self.processes:
            if ps.get_id() == process_id:   # search the element in list
                tar_ps = ps
                break

        if tar_ps == None:
            print('Error: Process does not exist! psid:',process_id)
            return
        self.processes.remove(tar_ps)       # remove target element from list
        print('Success:my_free  p_id:', process_id)

    def my_memlist(self):
        Process.print_meta()
        for ps in self.processes:
            ps.print()

# main
mem = Memory(100)   # init as 100kB
mem.my_malloc(1, 20)
mem.my_malloc(2, 15)
mem.my_malloc(3, 50)
mem.my_memlist()
mem.my_malloc(4, 30)    # memory is not enough
mem.my_free(2)
mem.my_malloc(4, 30)    # compaction will be applied
mem.my_memlist()