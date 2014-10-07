//
//  main.c
//  MathGame
//
//  Created by Taylor Ledingham on 2014-10-07.
//  Copyright (c) 2014 Taylor Ledingham. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int life;
    char playerName[50];
    int score;
    
}Player;

void randomizeNumbers(int *num1, int *num2);
Player initPlayer(int life1, char playerName1[], int score1);
int didPlayerWin () ;
void changePlayer();
void contGame();

Player currentPlayer;
Player player1;
Player player2;
Player winner;
char gameLoop = 'Y';



int main(int argc, const char * argv[]) {
    int isWinner=0;
    
    
    int num1;
    int num2;
    //int turn = 1;
    int answer;
    
    printf("Player 1 enter your name \n");
    player1 = initPlayer(3, fgets(player1.playerName, 50, stdin), 0);

     printf("Player 2 enter your name \n");
    player2 = initPlayer(3, fgets(player2.playerName, 50, stdin), 0);
    
   
    currentPlayer = player1;
    
    while (gameLoop == 'Y') {
        //game loop
        
        randomizeNumbers(&num1, &num2);
        
        
        printf("Player %s: What does %d plus %d equal? \n", currentPlayer.playerName, num1, num2);
        
        scanf("%d", &answer);
        
        if ((num1 + num2) == answer) {
            //they got the right answer
            printf("Right Answer! \n");
            if(strcmp(currentPlayer.playerName, player1.playerName) == 0)
            {
                player1.score++;
            }
            else if(strcmp(currentPlayer.playerName, player2.playerName) == 0) {
                player2.score++;
            }

            
            
        }
        else {
            //they got it wrong
            printf("Wrong Answer! \n");
            
            if(strcmp(currentPlayer.playerName, player1.playerName) == 0){
                player1.life--;
            }
            else if(strcmp(currentPlayer.playerName, player2.playerName)== 0) {
                player2.life--;
            }
            printf("Player 1's lives = %d, Player 2's lives = %d \n", player1.life, player2.life);
            
        }
        
        changePlayer();
        
        isWinner = didPlayerWin();
        if(isWinner == 1)
        {
        printf("Congrats Player %s, you won!! Your Score was: %d \n", winner.playerName, winner.score );
            contGame();
            
        }
    
        
    }
   // isWinner = didPlayerWin(&player1, &player2, &winner);
   // printf("Congrats Player%s, you won!! Your Score was: %d \n", winner.playerName, winner.life );
   // printf("Play Again? Type 'Y' to restart \n");
    
    
    return 0;
}

Player initPlayer(int life1, char playerName1[], int score1) {
    Player newPlayer;
    newPlayer.life = life1;
    strcpy(newPlayer.playerName, playerName1);
    newPlayer.score = score1;
    
    return newPlayer;
}

void changePlayer(){
    
    if(strcmp(currentPlayer.playerName, player1.playerName) == 0)
    {
    currentPlayer = player2;
    }
    else {
    currentPlayer =  player1;
    }
    
}
void randomizeNumbers(int *num1, int *num2) {
    
    
    *num1 = rand() % 20;
    *num2 = rand() % 20;

    
}



int didPlayerWin () {
    
    if(player1.life == 0) {
         winner = player2;
        return 1;
    }
    
    else  if (player2.life == 0){
         winner = player1;
        return 1;
    }
    
    else {
        return  0;
    }
    
}

void contGame() {
    
    printf("Play Again? Type 'Y' to restart  or 'N' to quit\n");
    fgets(&gameLoop, 1, stdin);
    
    
}
