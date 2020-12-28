
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Debug Line (we can turn this on and off for testing) The * is used to reference to where the HiddenWord is stored in memory
    
    PrintLine (TEXT("Welcome to Bull Cows!"));
    PrintLine (TEXT("Guess the %i letter word!"), HiddenWord.Len()); 
    PrintLine (TEXT("Press tab to use the terminal!"));
    PrintLine (TEXT("Type in your guess and press enter..."));
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    
    
    //checking PlayerGuess

    if ( Input == HiddenWord) 
    {
       PrintLine (TEXT("You have won!"));
    }

    else
    {
        {
            if (Input.Len() != HiddenWord.Len()) // Len = length so we are comparing the length of the user input with the hidden word
            {
                PrintLine (TEXT("The Hidden Word is %i characters long! Try again..."), HiddenWord.Len());
            }

            PrintLine (TEXT("You have lost!"));
            
        }
    }
    //Check if Isogram
    //prompt to guess again
    //check if right number of characters
    //prompt to guess again
    //remove a life
    //check if lives > 0
    // if yes GuessAgain
    //Show Lives left
    //if no show GameOver and HiddenWord?
    //press enter to play again?
    //check user input
    //PlayAgain or Quit
}

void UBullCowCartridge:: SetupGame() 
{
    HiddenWord = TEXT("cake"); 
    Lives = 4; 
}