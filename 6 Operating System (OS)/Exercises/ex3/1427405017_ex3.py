# -*- coding: utf-8 -*-
# ex3: comparing process schedule algorithms
# python3 script
# 1427405017 Jiayun Shen

import copy
import queue

class Process:
    def __init__(self, line):
        attr = line.split('\t')
        self.name = attr[0]
        self.arrival = int(attr[1])
        self.burst = int(attr[2])
        self.priority = int(attr[3])

    def show(self):
        print(' ', self.name,'      ', self.arrival,'      ', self.burst,'      ', self.priority)

    def getName(self):
        return self.name

    def getBurst(self):
        return self.burst

    def getArrival(self):
        return self.arrival

    def getPriority(self):
        return self.priority

    def decsBurst(self, slice=1):
            self.burst -= slice


class PsSchedule:
    psList = []
    titleList = []
    ps_count = 0
    def __init__(self, url):
        file = open(url)

        titleline = file.readline()     # first title line
        titleline.strip('\n')
        colnames = titleline.split('\t')
        for colname in colnames:
            self.titleList.append(colname)
        print()

        for line in file:
            #print(line, end='')
            line.strip('\n')
            ps_t = Process(line)
            self.psList.append(ps_t)
            self.ps_count += 1
            #ps_t.show()
        file.close()

    def show(self):
        for colname in self.titleList:
            print(' ', colname, end='')
        #print()
        for ps in self.psList:
            ps.show()

    def unFinish(self, tasks):
        for task in tasks:
            if task.getBurst() > 0:
                return True
        return False

    def FCFS(self):     # FCFS: first-come first-served
        tasks = copy.deepcopy(self.psList)
        gantt = []

        clock = 0
        while self.unFinish(tasks):
            minArrival = 999999
            selected_idx = 0
            idx = 0
            for task in tasks:
                currentArrival = task.getArrival()
                if currentArrival < minArrival and tasks[idx].getBurst() > 0 and tasks[idx].getArrival()<=clock:
                    # find the first-come and unfinished process
                    minArrival = currentArrival
                    selected_idx = idx
                idx += 1

            if minArrival <= clock:
                for i in range(tasks[selected_idx].getBurst()):     # non-preemptive (finish the whole process)
                    gantt.append(tasks[selected_idx].getName())
                    tasks[selected_idx].decsBurst()
                    clock += 1
            else:
                gantt.append('NOP')
                clock += 1

        print("FCFS's gantt chart:", gantt)

        print("FCFS's response time:")
        responseTimeList = self.cacuResponseTime(gantt)
        idx = 0
        sum = 0
        for Tresponse in responseTimeList:
            sum += Tresponse
            print(' ', self.psList[idx].getName(), ': ', Tresponse)
            idx += 1
        print(' average: ', sum/idx)

        print("FCFS's waiting time:")
        waitingTimeList = self.cacuWaitingTime(gantt)
        idx = 0
        sum = 0
        for Twaiting in waitingTimeList:
            sum += Twaiting
            print(' ', self.psList[idx].getName(), ': ', Twaiting)
            idx += 1
        print(' average: ', sum / idx)

        print("FCFS's turnaround time:")
        turnaroundTimeList = self.cacuTurnaroundTime(gantt)
        idx = 0
        sum = 0
        for Tturnaround in turnaroundTimeList:
            sum += Tturnaround
            print(' ', self.psList[idx].getName(), ': ', Tturnaround)
            idx += 1
        print(' average: ', sum / idx)
        
        return

    def SJF(self):      # SJF: shortest-job first
        tasks = copy.deepcopy(self.psList)
        gantt = []

        clock = 0
        while self.unFinish(tasks):
            minBurst = 999999
            selected_idx = 0
            idx = 0
            for task in tasks:
                currentBurst = task.getBurst()
                if currentBurst < minBurst and tasks[idx].getBurst() > 0 and tasks[idx].getArrival()<=clock:
                    # find the fvalid, unfinished shortest-job process
                    minBurst = currentBurst
                    selected_idx = idx
                idx += 1

            if tasks[selected_idx].getArrival() <= clock:
                for i in range(tasks[selected_idx].getBurst()):     # non-preemptive (finish the whole process)
                    gantt.append(tasks[selected_idx].getName())
                    tasks[selected_idx].decsBurst()
                    clock += 1
            else:
                gantt.append('NOP')
                clock += 1
        print("SJF's gantt chart:", gantt)

        print("SJF's response time:")
        responseTimeList = self.cacuResponseTime(gantt)
        idx = 0
        sum = 0
        for Tresponse in responseTimeList:
            sum += Tresponse
            print(' ', self.psList[idx].getName(), ': ', Tresponse)
            idx += 1
        print(' average: ', sum / idx)

        print("SJF's waiting time:")
        waitingTimeList = self.cacuWaitingTime(gantt)
        idx = 0
        sum = 0
        for Twaiting in waitingTimeList:
            sum += Twaiting
            print(' ', self.psList[idx].getName(), ': ', Twaiting)
            idx += 1
        print(' average: ', sum / idx)

        print("SJF's turnaround time:")
        turnaroundTimeList = self.cacuTurnaroundTime(gantt)
        idx = 0
        sum = 0
        for Tturnaround in turnaroundTimeList:
            sum += Tturnaround
            print(' ', self.psList[idx].getName(), ': ', Tturnaround)
            idx += 1
        print(' average: ', sum / idx)
        return

    def PR(self):       # PR: Priority Scheduling
        tasks = copy.deepcopy(self.psList)
        gantt = []

        clock = 0
        while self.unFinish(tasks):
            maxPriority = -1
            selected_idx = 0
            idx = 0
            for task in tasks:
                currentPriority = task.getPriority()
                if currentPriority > maxPriority and tasks[idx].getBurst() > 0 and tasks[idx].getArrival() <= clock:
                    # find the valid, unfinished max-priority process
                    maxPriority = currentPriority
                    selected_idx = idx
                idx += 1

            if tasks[selected_idx].getArrival() <= clock:
                gantt.append(tasks[selected_idx].getName())
                tasks[selected_idx].decsBurst()
            else:
                gantt.append('NOP')

            clock += 1
        print("PR's gantt chart:", gantt)

        print("PR's response time:")
        responseTimeList = self.cacuResponseTime(gantt)
        idx = 0
        sum = 0
        for Tresponse in responseTimeList:
            sum += Tresponse
            print(' ', self.psList[idx].getName(), ': ', Tresponse)
            idx += 1
        print(' average: ', sum / idx)

        print("PR's waiting time:")
        waitingTimeList = self.cacuWaitingTime(gantt)
        idx = 0
        sum = 0
        for Twaiting in waitingTimeList:
            sum += Twaiting
            print(' ', self.psList[idx].getName(), ': ', Twaiting)
            idx += 1
        print(' average: ', sum / idx)

        print("PR's turnaround time:")
        turnaroundTimeList = self.cacuTurnaroundTime(gantt)
        idx = 0
        sum = 0
        for Tturnaround in turnaroundTimeList:
            sum += Tturnaround
            print(' ', self.psList[idx].getName(), ': ', Tturnaround)
            idx += 1
        print(' average: ', sum / idx)
        return

    def RR(self, slice=1):       # RR: round-robin scheduling
        gantt = []
        tasks = copy.deepcopy(self.psList)
        taskqueue = queue.Queue()
        clock = 0
        while tasks:    # while tasks is not empty, traverse to build task queue
            for task in tasks:
                if task.getArrival() <= clock:
                    taskqueue.put(copy.deepcopy(task))
                    tasks.remove(task)
                    #continue
            clock += 1

        while not taskqueue.empty():    ## while taskqueue is not empty, apply RR
            #selected_task = taskqueue.get()
            task = taskqueue.get()
            for i in range(slice):
                if task.getBurst() > 0:
                    gantt.append(task.getName())
                    task.decsBurst()
            if task.getBurst() > 0:
                taskqueue.put(task)
        print("RR's gantt chart:", gantt)

        print("RR's response time:")
        responseTimeList = self.cacuResponseTime(gantt)
        idx = 0
        sum = 0
        for Tresponse in responseTimeList:
            sum += Tresponse
            print(' ', self.psList[idx].getName(), ': ', Tresponse)
            idx += 1
        print(' average: ', sum / idx)

        print("RR's waiting time:")
        waitingTimeList = self.cacuWaitingTime(gantt)
        idx = 0
        sum = 0
        for Twaiting in waitingTimeList:
            sum += Twaiting
            print(' ', self.psList[idx].getName(), ': ', Twaiting)
            idx += 1
        print(' average: ', sum / idx)

        print("RR's turnaround time:")
        turnaroundTimeList = self.cacuTurnaroundTime(gantt)
        idx = 0
        sum = 0
        for Tturnaround in turnaroundTimeList:
            sum += Tturnaround
            print(' ', self.psList[idx].getName(), ': ', Tturnaround)
            idx += 1
        print(' average: ', sum / idx)
        return

    def cacuResponseTime(self, gantt):
        responseTimeList = []
        for ps in self.psList:
            idx = 0
            for slice in gantt:
                if slice == ps.getName():   # find process's first running time
                    break
                idx += 1
            Tresponse = idx-ps.getArrival()
            responseTimeList.append(Tresponse)
            #print(ps.getName(), Tresponse)
        return responseTimeList

    def cacuWaitingTime(self, gantt):
        waitingTimeList = []

        Tend = 0
        for ps in self.psList:
            Tstart = 0
            for slice in gantt:
                if slice == ps.getName():  # find process's first running time
                    break
                Tstart += 1
            idx = 0
            for slice in gantt:
                if slice == ps.getName():
                    Tend = idx+1
                idx += 1
            Twaiting = Tend - Tstart - ps.getBurst()
            waitingTimeList.append(Twaiting)
        return waitingTimeList

    def cacuTurnaroundTime(self, gantt):
        turnaroundTimeList = []
        Tend = 0
        for ps in self.psList:
            idx = 0
            for slice in gantt:
                if slice == ps.getName():
                    Tend = idx + 1
                idx += 1
            Tturnaround = Tend - ps.getArrival()
            turnaroundTimeList.append(Tturnaround)
        return turnaroundTimeList


# main program
print("ex3: comparing process schedule algorithms\n","file: python3 script\n", "1427405017   Jiayun Shen\n")
fileurl = 'job1.txt'
print('analyzing process samples in: ', fileurl)
ps_sche = PsSchedule(fileurl)
ps_sche.show()
print()
ps_sche.FCFS()
print()
ps_sche.SJF()
print()
ps_sche.PR()
print()
print('RR slice = 1')
ps_sche.RR(1)
print()
print('RR slice = 2')
ps_sche.RR(2)
print()
print('RR slice = 3')
ps_sche.RR(3)
print()

