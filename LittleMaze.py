'''
as the diagram below shows, here's a maze. the entrance is 1, the exit is 16.
When there's vertical or horizontal line between different numbers, it means they have connections between each other.
Now, you need to code to exit the proper way to get out from the maze.
1   2--3   4
|      |   |
5-- 6--7   8
|          |
9--10--11--12
|   |   |
13  14  15--16
'''

def connected( x, y ):
    if x > y:
        return connected( y, x )
    if (x,y) in ((1,5) ,(2,3) ,(3,7) ,(4,8) ,(5,6) ,(5,9) ,(6,7) ,(8,12),(9,10) ,(9,13) ,(10,11) ,(10,14) ,(11,12) ,(11,15) ,(15,16)):
        return True
    return False

def entrance():
    return 1
def exit():
    return 16

def leads_to_exit(comingfrom,cell):
    if cell==exit():
        return "{}".format(exit())
    for i in range(entrance(),exit()+1):
        if i == comingfrom:
            continue
        if not connected(cell,i):
            continue
        check = leads_to_exit(cell,i)
        if check!="":
            return "{}->{}".format(cell,check)
    return ''

check=leads_to_exit(0,entrance())
if check!="":
    print('Path found!',check)
else:
    print("path not found")
