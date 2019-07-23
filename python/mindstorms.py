import turtle

def draw_square(brad):
    i = 0
    while i < 4:
        brad.forward(100)
        brad.right(90)
        i = i+1

def draw_shape():
    window = turtle.Screen()
    window.bgcolor("red")
    
    brad = turtle.Turtle()
    brad.shape("turtle")
    brad.color("yellow")
    brad.speed(10)
    
    total_turns = 36
    degree = 360/total_turns
   
    for turns in range(1,total_turns):
        brad.right(degree)
        draw_square(brad)

    window.exitonclick()

draw_shape()
