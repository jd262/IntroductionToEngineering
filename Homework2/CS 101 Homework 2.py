#Jacob Darabaris ~ CS 101 Homework 2 

#Function 1
def getOperation():
        print '+: Add two numbers'
        print '-: Subtract two numbers'
        print '*: Multiply two numbers'
        print '/: Divide two numbers'
        print 'q: Quit'
        choice = raw_input('Enter your operation : ')
        
        return choice

#Function 2
def computeResult (operation, operand1, operand2):
        if (operation == '+' ):
                result = (operand1 + operand2)
               
        if (operation == '-' ):
                result = (operand1 - operand2)
                
        if (operation == '*'):
                result = (operand1 * operand2)
                
        if (operation == '/'):
                if (operand2 == 0):
                        result = 0                       
                else:
                        result = (operand1 / operand2)
                        
        return result
                
#Function 3
def main():
        choice = getOperation()
        while (choice != 'q'):
                operand1 = input('Enter a number: ')
                operand2 = input('Enter another number: ')
                result = computeResult (choice, operand1, operand2)
                print operand1, choice, operand2, '=', result
                choice = getOperation()
                
        print 'All done'
              
