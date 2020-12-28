
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    //welcome player
    PrintLine (TEXT("Welcome to Bull Cows!"));
    PrintLine (TEXT("Guess the 4 letter word!")); // we have a magic number will need to create a variable to manage number difference later
    PrintLine (TEXT("Press enter to continue..."));

    SetupGame();//set up game
   

    //prompt player for guess
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