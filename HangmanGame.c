#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WRONG_ATTEMPTS 5 // maximum wrong attempts allowed

int main() {
    char word[100], guess[100], hidden[100]; // arrays to store the word, the user's guess, and the hidden word
    int len, i, wrong_attempts = 0, found = 0; // variables to store the length of the word, the index, wrong attempts, and whether the word has been found or not

    printf("Enter a word: ");
    scanf("%s", word); // get the word from the user

    len = strlen(word); // calculate the length of the word

    for(i = 0; i < len; i++) {
        if(isalpha(word[i])) { // check if the character is an alphabet
            hidden[i] = '_'; // replace with underscore
        } else {
            hidden[i] = word[i]; // leave other characters as they are
        }
    }

    hidden[i] = '\0'; // add null character to mark the end of the string

    printf("The word is: %s\n", hidden); // display the hidden word

    while(wrong_attempts < MAX_WRONG_ATTEMPTS && !found) {
        printf("Enter a letter: ");
        scanf(" %c", &guess[0]); // get the user's guess

        for(i = 0; i < len; i++) {
            if(tolower(word[i]) == tolower(guess[0])) { // check if the guessed letter matches the word
                hidden[i] = word[i];
                found = 1; // set flag to indicate that the letter is found
            }
        }

        if(!found) { // if the guessed letter is not found
            printf("Wrong guess! You have %d attempts left.\n", MAX_WRONG_ATTEMPTS - wrong_attempts - 1);
            wrong_attempts++;
        } else {
            printf("Good guess! The word is now: %s\n", hidden);
        }

        found = 0; // reset the flag
    }

    if(wrong_attempts == MAX_WRONG_ATTEMPTS) { // if the user has used all attempts
        printf("Sorry, you ran out of attempts. The word was %s.\n", word);
    } else { // if the user has guessed the word
        printf("Congratulations, you have guessed the word %s!\n", word);
    }

    return 0;
}

