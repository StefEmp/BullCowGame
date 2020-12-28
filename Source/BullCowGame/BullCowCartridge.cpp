
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine (TEXT("Welcome to Bull Cows!"));
    PrintLine (TEXT("Guess the 4 letter word!")); // we have a magic number will need to create a variable to manage number difference later
    PrintLine (TEXT("Press enter to continue..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord = TEXT("cake"); // Move outside of this function so it's scope is outside this function
    
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
    
}