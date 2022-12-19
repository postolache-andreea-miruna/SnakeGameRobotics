# SnakeGameRobotics
Program in Arduino written for Unibuc FMI course: Introduction to robotics.



## Introduction

For matrix project I chose to do snake game, because I liked to play this game when I was little.

My game is inspired from the original snake and also from the game snake that can be found in "Brick Game 9999 in 1".

### How I built the game?

For snake game I let the player to choose one of the 3 difficulties for which it corresponds a map: 
- EASY,
<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/fd63454a412a468ebef797163da232a81cd7c0f1/materials/easyMatrix.png" width=50% height=50%>
- MEDIUM,
<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/fd63454a412a468ebef797163da232a81cd7c0f1/materials/mediumMatrix.png" width=50% height=50%> 
- HARD.
<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/fd63454a412a468ebef797163da232a81cd7c0f1/materials/hardMatrix.png" width=50% height=50%>

 Also the player can choose the speed (10 or 20 or 30) with which the snake will accelerate when its length is a multiple of 4.


## Game description

At the beggining of the game the snake has the length of 2 and it stays on first row and the head is on column 3.

The idea of the game is to eat as much as possible without the snake hit itself or the walls ( medium and hard difficulties).

After eating, the snake length will increase and also when the length is a multiple of 4 the snake will move faster.

The speed that it will move depends on the speed that was chosen by the player.

Based on the chosen speed and difficulty the score will increase differently.


## Instruction on how to play

For this game the player must use the joystick to make the snake to change its direction: up, down, left, right.

Also if the snake moves in a way, I can not make it to go in the oposite way with just one joystick move. 

Example: if the snake go up and if the player move the joystick down, then the snake does not change its direction.


## Used Components
- breadbord
- Arduino Uno
- 1 MAX7219 Driver
- 1 joystick
- 1 led matrix display (8x8)
- 1 16x2 LCD
- 1 buzzer
- 1 electrolytic capacitor of 10 μF
- 1 electrolytic capacitor of 50 μF
- 1 ceramic capacitor of 104 pF
- wires
- resistors


Picture setup

Video
