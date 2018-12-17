//
//  GameOfCraps.c
//  Chapter9PolynomialSolver
//
//  Created by Nicholas Morris on 17/12/18.
//  Copyright © 2018 Nicholas Morris. All rights reserved.
//

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>




int roll_dice(void);
bool play_game(void);



int main(void){
    //Seed the random generator
    //printf("test");
    srand((unsigned)time(NULL));
    while(play_game());
    return 0;
}


//create two random numbers and return the sum
int roll_dice(void){
    int a,b;
    a = (rand()%6)+1;
    b = (rand()%6)+1;
    int sum = a+b;
    return sum;
    
}

bool play_game(void){
    int roll;
    bool game_over;
    int replay;
    int point;
    int wins = 0, losses = 0;
    //Set the first roll to be the point
    
    bool play_again = true;
    
    //While the user wants to play
    while(play_again){
        roll = roll_dice();
        game_over = false;
        play_again = true;
        point = roll;
        //Check win and loss conditions
        printf("\nYou rolled: %d\n", roll);
        sleep(1);
        if(roll == 7 || roll == 11){
            printf("You win!\n");
            wins += 1;
            game_over = true;
        }
        else if(roll == 2 || roll == 3 || roll == 12){
            printf("You lose!\n");
            wins += 1;
            game_over = true;
        }
        //The player has not won or loss on first roll
        else{
            sleep(1);
            printf("Your point is %d\n", point);
        }
        
        //Keep rolling until game is won/loss
        while(!game_over){
            roll = roll_dice();
            sleep(1);
            printf("You rolled %d\n", roll);
            sleep(1);
            //Loss condition
            if(roll == 7){
                printf("You lose!\n");
                losses +=1 ;
                game_over = true;
            }
            //Win condition
            else if(roll == point){
                printf("You win!\n");
                wins += 1;
                game_over = true;
            }
            
        }
        //Check gameover statement. If it passes the while statement this will trigger
        if(game_over){
            printf("Play again? ");
            replay = getchar();
            if(replay == 10){
                replay = getchar();
            }
            replay = toupper(replay);
            //If user wants to play again
            if(replay == 'Y'){
                play_again = true;
            }
            //User does not want to play again, print wins and losses and exit while loop
            else{
                printf("Thanks for playing!\n Wins: %d Losses: %d\n", wins,losses);
                play_again = false;
            }
            
        }
        
    }
    return 0;
}
