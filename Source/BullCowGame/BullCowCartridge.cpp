
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine (TEXT("Welcome to Bull Cows!"));
    PrintLine (TEXT("Guess the 4 letter word!")); // we have a magic number will need to create a variable to manage number difference later
    PrintLine (TEXT("Press enter to continue..."));
    HiddenWord = TEXT("cake");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    
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