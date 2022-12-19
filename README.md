# Snake Game 🐍🐍🐍
Program in Arduino written for Unibuc FMI course: Introduction to robotics.


<details><summary><h1>📚 Task Requirements 📚</h1></summary><br/>

This project contains two parts: menu and main game - Snake.

- Menu Requirements

	- Intro message

	- Start Game

		- while playing show details

		- screen upon game endind with input in order to move on

		- informs the player whn highscore is achieved

		- enter name for highscore

	- Highscore: top 5 in eeprom with name and score

	- Settings:

		- Starting difficulty

		- LCD contrast control (eeprom)

		- LCD brightness control (eeprom)

		- Matrix brightness control (eeprom)

		- Sound control on/off (eeprom)

		- Reset high scores button in settings

	- About: 

		- github user

		- developer name

		- game name

	- How to play: short description

	- Navigation style: different "picture" on the matrix for each menu category

- Game Requirements
	
	- Sounds upon interaction (eating, collision)

	- Make sense on a 8x8 matrix

	- Difficulty progresses

	- Reasonables game length

	- no bugs

</details>

# Documentation ✒️

<details><summary><h2>🎬 Introduction 🎬</h2></summary><br/>

For matrix project I chose to do snake game, because I liked to play this game when I was little 👧.

My game is inspired from the original snake and also from the game snake that can be found in "Brick Game 9999 in 1".

### How I built the game?

Thinking steps:

- I want a snake game with 3 types of difficulty and 3 types of speeds.

- I want that my snake to pass through "matrix walls"

- I want that my snake to increase in length while eating. (when the length is a multiple of 4 the sanke move faster with speed value)

- I want that my snake to die when hitting itself or the walls (medium and hard difficulty).

- I want to increase the score different based on difficulty and speed that was chosen.


So I let the player to choose one of the 3 difficulties for which it corresponds a map: 
- EASY 😊,
<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/fd63454a412a468ebef797163da232a81cd7c0f1/materials/easyMatrix.png" width=30% height=30%>

- MEDIUM 😐,
<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/fd63454a412a468ebef797163da232a81cd7c0f1/materials/mediumMatrix.png" width=30% height=30%> 

- HARD 😯.
<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/fd63454a412a468ebef797163da232a81cd7c0f1/materials/hardMatrix.png" width=30% height=30%>

 Also the player can choose the speed (10 or 20 or 30) with which the snake will accelerate when its length is a multiple of 4.

 
</details>



<details><summary><h2>🎮 Game description 🎮</h2></summary><br/>

At the beggining of the game the snake has the length of 2 and it stays on first row and the head is on column 3.

The idea of the game is to eat 🍴 as much as possible without the snake hit itself or the walls ( medium and hard difficulties).

After eating, the snake length will increase and also when the length is a multiple of 4 the snake will move faster.

The speed that it will move depends on the speed that was chosen by the player.

Based on the chosen speed and difficulty the score will increase differently:
 

|Speed/Difficulty| Easy  | Medium | Hard |
|:---            | :---: | :----: | ---: |
|10              | + 1   | + 2    | + 3  |
|20              | + 2   | + 3    | + 4  |
|30              | + 3   | + 4    | + 5  |

</details>


<details><summary><h2>🎮 Instruction on how to play 🎮</h2></summary><br/>

For this game the player must use the joystick to make the snake to change its direction: up, down, left, right.

Also if the snake moves in a way, the player can not make it to go in the oposite way with just one joystick move. 

Example: if the snake go up and if the player move the joystick down, then the snake does not change its direction.
</details>



<details><summary><h2>🔌Used Components🔌</h2></summary><br/>

- breadbord

- Arduino Uno

- 1 MAX7219 Driver

- 1 joystick 🕹️

- 1 led matrix display (8x8)

- 1 16x2 LCD

- 1 buzzer

- 1 electrolytic capacitor of 10 μF

- 1 electrolytic capacitor of 50 μF

- 1 ceramic capacitor of 104 pF

- wires

- resistors

</details>

<details><summary><h2>📷 Pictures setup 📷</h2></summary><br/>

1. Up View
<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/d0310ed8651a35bc93e173043e3ed77a8f9e00a7/materials/setup1up.jpg" width=50% height=50%>

2. Side View
<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/d0310ed8651a35bc93e173043e3ed77a8f9e00a7/materials/setup2side.jpg" width=50% height=50%>
</details>

<details><summary><h2>⛓️ Connections ⛓️</h2></summary><br/>

- Matrix Common Cathod

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/a9754a096874029d0d95e6474ce6ebd501884944/Matrix/commonCathod.png" width=50% height=50%>


- Driver

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/a9754a096874029d0d95e6474ce6ebd501884944/Matrix/Driver.png" width=50% height=50%>


- How to connect Matrix to Driver

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/a9754a096874029d0d95e6474ce6ebd501884944/Matrix/matrixToDriver.png" width=50% height=50%>


- How to connect Driver to Arduino

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/a9754a096874029d0d95e6474ce6ebd501884944/Matrix/DriverArduino.png" width=50% height=50%>


- How to connect LCD to Arduino

<img src="https://github.com/postolache-andreea-miruna/IntroductionToRobotics/blob/306fd6581a411fb0410732c41ad6df798d0b594d/Homework5/lcdconect.png" width=50% height=50%>

</details>


<details><summary><h2>🎮 Game Menu 🎮</h2></summary><br/>

- Start Game

- High Score

- Settings

	- Difficulty

	- LCD contrast

	- LCD bright

	- Matrix bright

	- Sounds

	- Reset HS 

	- Speed

	- Back to menu
 
- About

- How to play

## EEPROM

<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/9a4252a5e2106c914e764ddb02c3213340dcc4a4/materials/eeprom.png" width=100% height=100%>

## Menu informations

### Main Menu

After the greeting message that appears on the lcd and the greeting picture on the matrix dissapear on the lcd will appear the main menu.

In the main menu the player have to move with the joystick up or down in order to navigate through the main menu.

To acces a part of the main menu, the player must move the joystick to the right:

In the case of:
- Start Game the game will start

- High Score it will display top 5 players, it will be initialized with the default 5 names saved in eeprom ("NNNN").
 The player must move the joystick up or down. After the top is desplayed an exit message and the player can move the joystick to the left to enter in the main menu.

- Settings it will enter in the settings menu that will be shown later in this documentation

- About it will display the informations that can be accessed if the player move the joystick up or down:

	- github user

	- developer name

	- game name
After that is desplayed an exit message and the player can move the joystick to the left to enter in the main menu.

- How to play it will display the instructions that can be accessed if the player move the joystick up or down.
After that is desplayed an exit message and the player can move the joystick to the left to enter in the main menu.

### Settings Menu

If the player entered in settings menu, than to navigate through this menu she/he need to move the joystick up or down.

To acces a part of it (except "Reset HS" and "Back to menu"), the player must move the joystick to right.

In the case of "Reset HS" the player just need to press the joystick and the action of reseting the High Scores is done.

In the case of "Back to menu" the player just need to move the joystick to the left to go back to main menu.

For 
	- Difficulty,

	- LCD contrast,

	- LCD bright,

	- Matrix bright,

	- Sounds,

	- Speed

when the player access one of this part, she/he needs to move the joystick up or down and press when the player want to save that value.

Also, if the player just want to look on the value that was saved and she/he does not want to modify it, the player must move the joystick to left after she/he watching.



## Pictures for each category:

1. Intro message:

<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/109c6ce8ed2d055325cbea4da60bb3ed90f4321e/materials/greeting.png" width=30% height=30%>

2. Start Game:

<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/109c6ce8ed2d055325cbea4da60bb3ed90f4321e/materials/game.png" width=30% height=30%>

3. Highscore:

<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/109c6ce8ed2d055325cbea4da60bb3ed90f4321e/materials/crown.png" width=30% height=30%>

4. Settings:

<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/109c6ce8ed2d055325cbea4da60bb3ed90f4321e/materials/setting.png" width=30% height=30%>

5. About:

<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/109c6ce8ed2d055325cbea4da60bb3ed90f4321e/materials/about.png" width=30% height=30%>

6. How to play:

<img src="https://github.com/postolache-andreea-miruna/SnakeGameRobotics/blob/109c6ce8ed2d055325cbea4da60bb3ed90f4321e/materials/howToPlay.png" width=30% height=30%>

</details>

<details><summary><h2>🐛 Bug 🐛</h2></summary><br/>

Sometimes when the player takes an action with the joystick (up/down/left/right/press) it will not work at first try.
</details>



## [Code](https://github.com/postolache-andreea-miruna/SnakeGameRobotics/tree/main/GoodSnakeGame)

## How it works

## [Video](https://youtu.be/-DTUhpgvS4s)
