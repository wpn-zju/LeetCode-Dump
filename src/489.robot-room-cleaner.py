# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
#class Robot:
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """

class Solution:
    count = 0
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """

        visit = set() 
        def clean(x, y , di, dj ):
            Solution.count += 1
            visit.add((x,y ))
            robot.clean()
            i = 0 
            while i < 4: 
                i +=1 
                robot.turnLeft() #  ( 1, 0 ) -> (0, 1 ) -> (-1 , 0)
                di , dj  = -dj , di 
                if (x + di ,y+dj) not in visit:
                    m = robot.move() 
                    if m: 
                        clean(x + di , y+dj , di , dj)
                        
                        # restore the location! 
                        robot.turnLeft()
                        robot.turnLeft()
                        robot.move()
                        robot.turnLeft()
                        robot.turnLeft() 
            # visit.remove((x, y ))
                    
        clean(0 , 0 , 1, 0  ) 
        print(Solution.count)