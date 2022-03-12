import turtle

myTurtle = turtle.Turtle()
myWin = turtle.Screen()


def drawSpiral(myTurtle, lineLen):
    count = 0
    while count != 12:
        myTurtle.forward(lineLen)
        myTurtle.right(150)
        #drawSpiral(myTurtle, lineLen)
        count += 1


drawSpiral(myTurtle, 500)
myWin.exitonclick()
