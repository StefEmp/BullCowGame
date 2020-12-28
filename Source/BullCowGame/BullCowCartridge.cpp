
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
   
//    const TCHAR HW[] = TEXT("cake");
//    PrintLine(TEXT("Character 1 of HW is: %c"), HW[1]);
//    PrintLine(TEXT("Character 4 of HW is: %c"), HW[3]);
//    HW;
}

void UBullCowCartridge:: EndGame()
{
    bGameOver = true;
    
    PrintLine(TEXT("\nPress enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if  (Guess == HiddenWord) 
    {
        PrintLine (TEXT("You have Won!"));
        EndGame();
        return;
    }
    //Check if Isogram

    
  
    if (Guess.Len() != HiddenWord.Len()) // Len = length so we are comparing the length of the user input with the hidden word
    {
        PrintLine (TEXT("Sorry, try guessing again \nYou have %i lives remaining"), Lives);
        PrintLine (TEXT("The hidden word is %i letters long"), HiddenWord.Len());      
        return; 
    }
    
    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("There are no repeating letters, guess again")); 
        return;
    }
    //remove a life
    PrintLine (TEXT("You have lost a life!"));         
    --Lives;   
    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    }
          
    //show the player Bulls and Cows
PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
}
    //check if lives > 0
    // if yes GuessAgain
    //Show Lives left
    //if no show GameOver and HiddenWord?
    //press enter to play again?
    //check user input
    //PlayAgain or Quit

bool UBullCowCartridge::IsIsogram(FString Word)
{
    // for each letter 
    // start at element [0]
    // compare against the next letter
    // until we reach [Word.Len() -1]
    // if any letters are the same return false.

    return true;
}