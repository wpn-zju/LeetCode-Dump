func cleanRoom(robot *Robot) {
    // serialize pair of row and column number as key
    visited := make(map[string]bool)
    // generate clockwise directions, order matters
    // order should match with robot direction
    rowDirs := []int{-1,0,1,0}
    colDirs := []int{0,1,0,-1}
    var backtrack func(row, column, direction int)
    backtrack = func(row, column, direction int){
        // no end condition, we DFS until all recursion is finished
        k := fmt.Sprintf("%d,%d",row,column)
        visited[k] = true
        robot.Clean()
        for i := 0; i < 4; i++{
            // use module otherwise newD could cause invalid index of Dirs
            newD := (i+direction) % 4
            newRow := row + rowDirs[newD]
            newCol := column + colDirs[newD]
            newK := fmt.Sprintf("%d,%d",newRow,newCol)
            if visited[newK] || !robot.Move() {
                robot.TurnRight()
                continue
            }
            // select current choice
            backtrack(newRow,newCol,newD)
            // once finished, revert
            // first back track
            robot.TurnRight()
            robot.TurnRight()
            robot.Move()
            // then return to previous direction
            // robot.TurnLeft();
            // robot.TurnLeft();
            robot.TurnRight()
            robot.TurnRight()
            
            robot.TurnRight()
        }
    }
    backtrack(0,0,0)
}