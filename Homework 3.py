#Jacob Darabaris CS 101 Homework 3

import math

def findMax(aList):
        maxSoFar = aList[0]
        for item in aList[1:]:
            if item > maxSoFar:
                maxSoFar = item
        return maxSoFar

def findMin(aList):
    minSoFar = aList[0]
    for item in aList[1:]:
        if item < minSoFar:
            minSoFar = item
    return minSoFar

def computeRange (aList):
    return findMax(aList)-findMin(aList)

def computeMean(aList):
        total = 0.0
        n = len(aList)
        for i in range(n):
                total = total + aList[i]
        mean = total/n
        return mean

def computeMedian(aList):
        listCopy = aList[:]
        listCopy.sort()
        n = len(aList)
        midIdx = n/2
        if n%2 == 0:
                median = (listCopy[midIdx] + listCopy[midIdx - 1])/2.0
        else:
                median = listCopy[midIdx]
        return median

def computeMode(aList):
        aDict = {}
        for item in aList:
                if item in aDict:
                        aDict[item] = aDict[item] + 1
                else:
                        aDict[item] = 1
        maxValue = findMax(aDict.values())

        modeList = []
        for item in aDict:
                if aDict[item] == maxValue:
                        modeList.append(item)
        return modeList

        
def computeStdDev(aList):
        totall= 0.0
        N= len(aList)
        for i in range(N):
                fire = (aList[i]- computeMean(aList))**2 
                totall= totall + fire

        S = math.sqrt(1.0/(N-1)*totall)
        return S

def getUserChoice():
        print 'Choose a statistical measure'
        print 'a. Range'
        print 'b. Mean'
        print 'c. Median'
        print 'd. Mode' 
        print 'e. Standard Deviation'
        print 'q. Quit'
        choice = raw_input('Enter your choice: ')
        return choice

def main():
        inputFileName = raw_input('Enter the name of the input file: ')
        inputFile = open(inputFileName, 'r')
        items = []
        
        for line in inputFile:
                number = int(line)
                items.append(number)
        inputFile.close()
        
        choice = getUserChoice()
        while choice != 'q':
                if choice == 'a':
                        print 'The range is', findMax(items)-findMin(items)
                elif choice == 'b':
                        print 'The mean of the values is', computeMean(items)
                elif choice == 'c':
                        print 'The median of the values is', computeMedian(items)
                elif choice == 'd':
                        print 'The mode of the values is', computeMode(items)
                elif choice == 'e':
                        print 'The standard deviation of this collection is', computeStdDev(items)
                else: print 'Invalid choice. Try again!'
                choice = getUserChoice()                      
        print 'All done'
        

        
        
       

