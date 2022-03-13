# snakeGameDescription
This project is a description for snakeGame. (link: https://github.com/lusterofgem/snakeGame)<br>
Snake game is a classic minigame.<br>
When the snake eat a fruit, the snake will grow up.<br>
When the snake hit in the wall or itself, the snake will dead.<br>
The longer the snake grow, the more point player get.<br>
## Flow Chart
![image](diagram/snakeGameFlowChart.png)<br>
## Class Diagram
We use a sf::RenderWindow and three handler to run this game.<br>
We try to fit this game in model-view-control structure.<br>
sf::RenderWindow is the visible window, the main window of this game.<br>
Every handler have a thread, that means the game logic and render are seperate into different thread.<br>
That means if the render stuck a little bit, the game logic will keep running.<br>
GameHandler run the game logic, forward the snake, eat fruit, or detect if the snake is dead.<br>
EventHandler detect the window input, like hit exit button or press WASD, it will change the status of GameHandler.<br>
ViewHandler render the GameHandler status to the window.<br>
![image](diagram/snakeGameClassDiagram.png)<br>
