# Wordle word game & helper terminal applications.

## The Game

A very simplistic version of popular word game wordle
https://www.nytimes.com/games/wordle/index.html

```
cd game
make
./termindle
```
Follow the instructions on your terminal to play the game.

## The Helper

A tool that helps you win the game in as few guesses as possible. Uses letter frequencies in english language 
(https://en.wikipedia.org/wiki/Letter_frequency)
And the information revealed by previous guesses to calculate all possible answers and the optimal one.

cd helper
make
./helper
```
Guess a word in the game provided or the original version and insert the result back here in terminal.
Read the result and input into the game. (The best words have highest score). 

Going back and forth like this you should be able to guess the word with very few moves!
