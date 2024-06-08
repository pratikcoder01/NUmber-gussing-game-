Library Inclusions: The program starts by including necessary libraries for input/output operations, random number generation, and creating delays for animations.
Screen Clearing Function: A clearScreen function uses ANSI escape codes to clear the console and reset the cursor, ensuring a clean display for each stage of the game.
Loading Animation: The loadingAnimation function displays a "Loading..." animation, adding a suspenseful delay by printing dots with pauses and clearing the screen between cycles.
Congratulatory Animation: The congratulationsAnimation function enhances user experience by displaying a congratulatory message one character at a time, creating a celebratory effect when the player guesses the number correctly.
Welcome and Instructions: The main function begins by showing a welcome message and game instructions, then prompts the user to select a difficulty level, setting the stage for the guessing game.
Game Logic: Based on the selected difficulty, the game generates a random number between 1 and 100. The player is given a limited number of attempts to guess this number, with feedback provided after each guess indicating whether the guess was too high or too low.
Game Loop and Exit: The game continues until the player either guesses the number correctly or runs out of attempts. If the player chooses to end the game, a thank you message is displayed, concluding the session. The loop ensures the player can play multiple rounds or exit as desired.




