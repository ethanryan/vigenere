#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])

{
    //note: main declared with two arguments above:
    //1) argc is the number of strings that make up the command line (including the program name),
    //2) argv is an array that contains those strings

    //printf("first of all, argc is %i \n", argc);
    //printf("second of all, keyword is %s \n", keyword);

    //If your program is executed:
    //without any command-line arguments,
    //with more than one command-line argument,
    //or with one command-line argument that contains any non-alphabetical character,
    //your program should print an error (of your choice) and exit immediately,
    //with main returning 1 (thereby signifying an error).

    if (!argv[1] || argc > 2)
    {
        printf("Must have an argv[1], and argc must be less than 1! \n\n");
        return 1;
    }

    string keyword = argv[1]; //string keyword is the string in the second position of the argv array (ex: 'baz')
    //(the first position, or 0 index, is './vigenere')...
    printf("keyword is: %s \n", keyword);

    int length_of_keyword = strlen(keyword);

    //first loop over keyword is for validation...
    if (keyword)
    for (int i = 0; i < length_of_keyword; i++) //loop over the length of our argv[1] string...
    {
        //printf("argv[1][i] is: %c \n", argv[1][i]);
        if ( isalpha(keyword[i]) == 0 ) //isalpha returns 0 if parameter isn't an alphabetical character...
        {
            printf("keyword[i] is: %c \n\n", keyword[i]);
            printf("String must only contain letters! \n\n");
            return 1;
        }
    }

    //once above validations passed, below will ask for and encrypt user input...

    printf("plaintext: ");

    string plaintext_input = get_string();

    //printf("ciphertext: \n\n");
    printf("ciphertext: ");

    int length_of_plaintext_input = strlen(plaintext_input);

    int j = 0;

    //second loop over keyword is for encryption...
    if (keyword)
    for (int i = 0; i < length_of_plaintext_input; i++) //loop over the length of our keyword string...
    //everything below is within this if statement...
    {
        char character = plaintext_input[i];
        //printf("character is: %c \n", character);

        //if the character is alpha and is lowercase...
        if islower( character )
        {
            if (j == length_of_keyword)
            {
                //printf("resetting j to 0!!! \n");
                j = 0; //resetting j to 0, so it wraps back to 0 when it reaches last letter of plaintext_input...
            }

            char current_cipher = keyword[j];
            if isupper(current_cipher)
            {
                current_cipher = tolower(current_cipher); //adding this to pass: encrypts "BaRFoo" as "CaQGon" using "BaZ" as keyword
            }
            //printf("current_cipher is: %c \n", current_cipher);

            int new_character = (( (character - 97 + current_cipher - 97) % 26) + 97); //<<<<<<<<------------WORKS!!!!!!!
            //printf("new_character as decimal is: %d \n", new_character);
            //printf("new_character as character is: %c \n", new_character);
            //printf("%c \n", new_character);
            printf("%c", new_character);

            j++; //adding to j here, within if statement, so ONLY if character is alpha...
        }

        //else if the character is alpha and is uppercase...
        else if isupper( character )
        {
            //printf("%c", character); //else, its not a letter, so just print it... not adding to j.......

            if (j == length_of_keyword)
            {
                //printf("resetting j to 0!!! \n");
                j = 0; //resetting j to 0, so it wraps back to 0 when it reaches last letter of plaintext_input...
            }

            char current_cipher = keyword[j];
            //printf("current_cipher is: %c \n", current_cipher);

            int new_character = (( (character - 65 + current_cipher - 65) % 26) + 65); //<<<<<<<<------------WORKS!!!!!!!
            //printf("new_character as decimal is: %d \n", new_character);
            //printf("new_character as character is: %c \n", new_character);
            //printf("%c \n", new_character);
            printf("%c", new_character);

            j++; //adding to j here, within if statement, so ONLY if character is alpha...
        }
        else
        {
            //printf("%c is not a letter!!!", character); //else, its not a letter, so just print it...
            printf("%c", character); //else, its not a letter, so just print it... not adding to j.......
        }
    }
    printf("\n");
    return 0;
}

//note: ASCII decimals via: http://www.asciichart.com/
