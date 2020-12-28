
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Debug Line (we can turn this on and off for testing) The * is used to reference to where the HiddenWord is stored in memory
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    
   
  
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else   //else checking PlayerGuess
    {
        ProcessGuess(Input);
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
    Lives = HiddenWord.Len(); 
    bGameOver = false;
   
    PrintLine (TEXT("Welcome to Bull Cows!"));
    PrintLine (TEXT("You have %i lives."), Lives); 
    PrintLine (TEXT("Guess the %i letter word!"), HiddenWord.Len()); 
    PrintLine (TEXT("Type in your guess.\nPress enter to continue..."));
    //bGameOver = false;
}

void UBullCowCartridge:: EndGame()
{
bGameOver = true;
PrintLine(TEXT("Press enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if  (Guess == HiddenWord) 
        {
            PrintLine (TEXT("You have Won!"));
            EndGame();
        }
        else
        {
            PrintLine (TEXT("You have lost a life!"));         
            PrintLine (TEXT("%i"), --Lives);         
            
            if (Lives > 0)
            {
                if (Guess.Len() != HiddenWord.Len()) // Len = length so we are comparing the length of the user input with the hidden word
                {
                    PrintLine (TEXT("Sorry, try guessing again \n You have %i lives remaining"), Lives);         
                }
            }
            else
            {
                PrintLine(TEXT("You have no lives left!"));
                EndGame();
            }
        }
}