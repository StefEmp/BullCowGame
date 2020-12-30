
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/HiddenWordList.txt");
    FFileHelper::LoadFileToStringArray(Words, *WordListPath);
    SetupGame();
    PrintLine(TEXT("The number of possible words is %i"), Words.Num());
    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Debug Line (we can turn this on and off for testing) The * is used to reference to where the HiddenWord is stored in memory
    for (int32 Index = 0; Index < 5; Index++)
    {
        PrintLine(TEXT("%s"), *Words[Index]);
    }

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
        PrintLine(TEXT("No repeating letters guess again!")); 
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
  
bool UBullCowCartridge::IsIsogram(FString Word) const
{

    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        for(int32 Comparison = Index +1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
        }
    }

    return true;
}