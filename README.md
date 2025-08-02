# Snake-Game
a snake game project with c++, for Course fulfillment of the UofK,FMSI OP Course




# Snake game project 

# GitHub
https://github.com/mezo109/Snake-Game

# class food
contains 

-food coordinates variables and

- functions to generate random numbers between grid boundries


# class snake
contains

-snake coordinates variables

-two (one to one) arrays to save each part of snake tail coordinates

-varible indicating the length of the tail at the time

-two variables two swap between variables coordinates of different tails part as snake moves

# class game
inherited from food and snake classes with protection mode to avoid altering outside of class
contains

-enum object

-variable indicating the end of the game

-two obstcale arrays coordinates

-variable indicating the number of obstacles to appear at the moment

-score variable 

-bool print varible to make sure not to print a space if something was printed than in the same spot 

-function to get end of game value

-function to draw the grid and its contents by coordinates 

by using two nested loops outer loop to determine the row and inner ine to determine the spot in the row
,with conditinals to determine what to print in the spot and a print variable used to determine if something was printed in the spot or to print a space 


-function to receive input and enumerate it

with a one status to stop the game temporarily by not altering the coordinates

-then a function to manage logic of moving coordinates and generating random ones

start of setting tails parts coordinates from head coordinates to last rail part

then change coordinates of the head by using the status of enum dir 
and determine condtion of ending the game and if needed generate new postion

(since the rand function gives the same value for both obstacles and fruit duevto execution at thecsame time ,a change in obstacles mod function was made to make it different by a factor )

if lost the game or pressed x ,the gameover variable will be true and the loop if the game in main will stop and final session score will be printed 


(the grid x axis(horizontal) starts from coordinate 1 to width-1,since 0 and width are boundries;thats why the used random function and for obs[] it seems odd, the intiating come from adding 1(start of grid from left) and getting a random mod value between 0 and width-2)



# main function
a char variable to determine closure of game
and an object pointer to be used for setting the game

 has two nested loops
one for creating object game with initiated variables from start
then inner loop forexecuting the game as long as you don't lose or end it
if lost ,the object will be deleted 
and  a file is saved and added to it any score higher than 150
then the outer loop will determine if the game will be closed or restart the loop by user input if pressed x or other keys to restart a game session with a new object pointer with variables reset
(initiated the object using a pointers to get the possibility of deleting the old one initiate one with reset variables for each session)


