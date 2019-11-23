#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Welcome message
    std::cout << "\n\n************************************************************\n";
    std::cout << "You are a secret agent breaking into a level " << Difficulty <<" server room...\n";
    std::cout << "You must enter the correct code to continue...\n";
    std::cout << "************************************************************\n";

}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //defining our 3 number code
    auto const CodeA = rand() % Difficulty + Difficulty;
    auto const CodeB = rand() % Difficulty + Difficulty;
    auto const CodeC = rand() % Difficulty + Difficulty;

    auto const CodeSum = CodeA + CodeB + CodeC;
    auto const CodeProduct = CodeA * CodeB * CodeC;

    //display the sum and product of the code
    std::cout << "\n+ There are 3 numbers in the code.\n";
    std::cout << "+ The numbers in the code sum to: " << CodeSum;
    std::cout << "\n+ The numbers in the code multiply to: " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;

    //Get guess from the player
    std::cout << "\nEnter your 3 digit guess separated by spaces: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    auto GuessSum = GuessA + GuessB + GuessC;
    auto GuessProduct = GuessA * GuessB * GuessC;

    //Check if player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n***Well done, Agent!  You have extracted the file!  Keep Going!***";
        return true;
    }
    else
    {
        std::cout << "\n***Careful, Agent!  You Entered the wrong code.  Try again!***";
        return false;
    }
}

int main()
{
    auto LevelDifficulty = 1;
    auto const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)//Keep playing game until all levels are complete
    {
        srand(time(NULL));//random seed

        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear();//clear errors
        std::cin.ignore();//discards the buffer

        if (bLevelComplete)
        {
            LevelDifficulty++;
        }

    }

    std::cout << "\n***Well done, Agent!  Get out of there!!!***\n\n";
    return 0;
}

