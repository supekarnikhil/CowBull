#File:cowbull.py
from random import random

delimit = ' '
secret=[]
while True:
    x=int(random()*10)
    if secret.count(str(x))==0:
        secret.append(str(x))
    if len(secret)==4:
        break

print '\t\t',delimit.join(secret) #---- comment this line after completion

#--- function to find number of cows and bulls --------------------------
def findCB(user):
    bull=0
    cow=0
    for i in range(4):
        try:
            if secret.index(user[i]) == i:
                bull=bull+1
            if secret.index(user[i]) != i:
                cow=cow+1
        except ValueError:
            pass
    print '\t -------------------------'
    print '\t| Bull : ',bull,'\t Cow : ',cow, '|'
    print '\t -------------------------'
    return bull
#--- End of function -----------------------------------------------------
i=1
try:
    while i<11:
        user = list(raw_input("%d] Guess the 4-digit number(e.g. 1234) : " %i))
        if len(set(user))==4:
            i=i+1
            print '\t\t',delimit.join(user)
        if len(set(user))!=4:
            continue
    
        bull=findCB(user)
        if bull==4:
            print '\n\t   --------------------'
            print '\t   | Congratulations! |'
            print '\t   --------------------'
            break
        if i==11:
            print '\n\t\t--------------'
            print '\t\t| Game Over! |'
            print '\t\t--------------'
except KeyboardInterrupt:
    print 'Exiting...\n\nGood Bye!'
