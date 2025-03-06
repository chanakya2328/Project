#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playTruthOrDare() {
    char choice;
    int playerchoice;
    srand(time(NULL));
    char *truths[] = {
        "What is your biggest fear?",
        "What is your favourite food?",
        "What is your biggest regret?",
        "What is your favourite movie?"
    };
    char *dares[] = {
        "Sing a song in front of everyone.",
        "Do 10 push-ups.",
        "Tell a joke.",
        "Do an impression of your favorite celebrity."
    };
    int num_truths = sizeof(truths) / sizeof(truths[0]);
    int num_dares = sizeof(dares) / sizeof(dares[0]);

    printf("Welcome to Truth or Dare!\n");
    int validChoice = 0;

    do {
        printf("Choose truth (t) or dare (d): ");
        scanf(" %c", &choice);

        if (choice == 't' || choice == 'd') {
            validChoice = 1;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (!validChoice);

    if (choice == 't') {
        int index = rand() % num_truths;
        printf("**************************************************************************\n");
        printf("    YOUR TRUTH QUESTION IS ::: %s    \n", truths[index]);
        printf("**************************************************************************\n");

    } else if (choice == 'd') {
        int index = rand() % num_dares;
        printf("**************************************************************************\n");
        printf("    YOUR DARE QUESTION IS ::: %s    \n", dares[index]);
        printf("**************************************************************************\n");
    }
	printf("thanks for playing.   :) ");
   
	}


void guessTheNumber() {
    int randomNumber, guess, attempts = 0;
    char guessStr[10];  // Input string to store the guess
    srand(time(NULL));

    // Generate a random number between 1 and 10
    randomNumber = rand() % 10 + 1;

    printf("Welcome to the Guess the Number game!\n");
    printf("I'm thinking of a number between 1 and 10.\n");

    do {
        printf("Enter your guess: ");
        scanf("%s", guessStr);

        // Check if the input is numeric
        int validInput = 1;
        for (int i = 0; guessStr[i] != '\0'; i++) {
            if (!isdigit(guessStr[i])) {
                validInput = 0;
                break;
            }
        }

        if (!validInput) {
            printf("Invalid input! Please enter a numeric guess.\n");
            continue;
        }

        guess = atoi(guessStr);

        attempts++;

        if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("---------------------------------------------------------------------\n");
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            printf("---------------------------------------------------------------------\n");
            printf("\n thanks for playing   :)");
            break;
        }
    } while (1);
}

void rockPaperScissors() {
    int player_choice, computer_choice;
    int player_score = 0, computer_score = 0;
    const char *choice_name[] = {"Rock", "Paper", "Scissors"};

    srand(time(NULL));

    printf("Welcome to Rock-Paper-Scissors game!\n");

    do {
        printf("\nEnter your choice (1 for Rock / 2 for Paper / 3 for Scissors): ");
        scanf("%d", &player_choice);

        if (player_choice >= 1 && player_choice <= 3) {
            computer_choice = rand() % 3 + 1;

            printf("You choose %s and computer choose %s.\n", choice_name[player_choice - 1], choice_name[computer_choice - 1]);

            if (player_choice == computer_choice) {
                printf("It's a draw!\n");
            } else if ((player_choice == 1 && computer_choice == 3) ||
                       (player_choice == 2 && computer_choice == 1) ||
                       (player_choice == 3 && computer_choice == 2)) {
                printf("You win!\n");
                player_score++;
            } else {
                printf("Computer wins!\n");
                computer_score++;
            }

            printf("Your score: %d\nComputer score: %d\n", player_score, computer_score);

            printf("Do you want to play again? (1 for Yes / 0 for No): ");
            scanf("%d", &player_choice);
        }
		 if (player_choice>1){
		 
            printf("Invalid choice! Please restart the game.\n");
            exit(0);
        }
    } while (player_choice !=0);

    printf("Thanks for playing!\n");
    printf("-------------------------------------------------------------------------\n");
}

int main() {
    int main_choice;
    char ch,d,t;
    do {
        printf("Choose a game:\n");
        printf("|*****************************|\n");
        printf("|1. Truth or Dare!            |\n");
        printf("|-----------------------------|\n");
        printf("|2. Guess the Number!         |\n");
        printf("|-----------------------------|\n");
        printf("|3. Rock-Paper-Scissors!      |\n");
        printf("|-----------------------------|\n");
        printf("|4. Exit                      |\n");
        printf("|*****************************|\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &main_choice);
if(main_choice!=ch || main_choice!= d || main_choice!= t ){
		
        switch (main_choice) {
        	
            case 1:
                playTruthOrDare();
                break;
            case 2:
                guessTheNumber();
                break;
            case 3:
                rockPaperScissors();
                break;
            case 4:
            	printf("thanks for playing  :)");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
               exit(0); 
        }
}else{
		exit(0);
   	}
}
	 while (1);
    return 0;
}
