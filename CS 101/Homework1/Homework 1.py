# Mikas Darabaris CS 101 Homework 1
# To compute the trajectory of a shell launched by a Howitzer Gun.
import math
def computeShellHeight (distanceToTarget, angleInDegrees, shellVelocity):
    gravity = 32.17
    pi = 3.1415926
#Define the time of the flight.        
    time = (distanceToTarget)/ (shellVelocity * math.cos(angleInDegrees * (pi/180)))
#Define the height that the shell travels.
    shellHeight = (shellVelocity * math.sin(angleInDegrees * (pi / 180)) * time) - ((gravity * (time **2))/ (2))
    return shellHeight

def main():
    pi = 3.1415926
    gravity = 32.17
    print 'SHELL TRJAECTORY CALCULATOR'
    distanceToTarget = input ('Enter the distance to the target in feet (0 to quit): ')
    while   distanceToTarget != 0: 
            shellVelocity = input('Enter the velocity of the shell in feet per second: ')
            angleInDegrees = input('Enter the angle of the shell in degrees: ')
            shellHeight = computeShellHeight (distanceToTarget, angleInDegrees, shellVelocity)
            print 'The height of the shell at the distance of the target is %.1f' % shellHeight
            distanceToTarget = input ('\nEnter the distance to the target in feet (0 to quit): ')

    print ('All done')
