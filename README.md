# Wordle Game in C

## Description

This project is a simple command-line version of the popular word-guessing game **Wordle**, implemented in the C programming language. The objective of the game is for the player to guess a randomly selected five-letter word within six attempts. After each guess, the game provides feedback on each letter of the guessed word:
- **Green** indicates that the letter is correct and in the correct position.
- **Yellow** indicates that the letter is correct but in the wrong position.
- **Red** indicates that the letter is incorrect.

The game loads the possible words from a text file (`wordList.txt`), which contains over 100 five-letter words. The game ends when the player correctly guesses the word or exhausts all six attempts.

## Features

- **Random Word Selection:** A word is randomly selected from a predefined list of five-letter words stored in `wordList.txt`.
- **Colored Feedback:** Feedback is provided using ANSI color codes to indicate correct, misplaced, and incorrect letters.
- **File-Based Word List:** The game reads the list of possible words from an external file (`wordList.txt`), allowing easy customization of the word list.

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/your-username/wordle-game-in-c.git
   ```

2. **Navigate to the directory:**
   ```bash
   cd wordle-game-in-c
   ```

3. **Ensure you have a `wordList.txt` file with more than 100 five-letter words in the directory.**

4. **Compile the game using a C compiler:**
   ```bash
   gcc wordle.c -o wordle
   ```

## How to Play

1. **Run the game:**
   ```bash
   ./wordle
   ```

2. **Enter a five-letter word as your guess.**
   
3. **Receive feedback:**
   - Letters in **Green** are correct and in the correct position.
   - Letters in **Yellow** are correct but in the wrong position.
   - Letters in **Red** are incorrect.

4. **Continue guessing until you either correctly guess the word or run out of attempts.**

5. **If you guess the word, you win! If not, the correct word is revealed after six attempts.**

## Customizing the Word List

To customize the word list, simply edit the `wordList.txt` file. Each word should be five letters long and placed on a new line. The game will randomly select a word from this list each time it starts.

## License

This project is open-source and available under the MIT License.

## Contribution

Contributions are welcome! If you have any suggestions, feel free to fork the repository and submit a pull request.
