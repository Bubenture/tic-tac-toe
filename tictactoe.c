#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
  #define OS_TYPE 1
#elif __linux__
  #define OS_TYPE 0
#else
  #error "Неизвестная операционная система"
#endif

#define SIZE 3
char field[SIZE][SIZE];
char navigation, symbol0, symbol;
int game =-1, wins, wins0, order, mov, step = 0;

void Conclusion ();
void Empty();
void Game();
void Start();
void ManMove(char symbolmov);

void See(char symbolmov);
void See0();
void Win(char symbolmov);




int main() 
{  
while (navigation != '1')
{
    Empty();
    
    printf("\nPress Enter to start or enter 1 to exit\n"); 
    switch (navigation = getchar())
    {
    case '\n':
        if((game<0) ||(wins >0)||(wins0>0))
            {
                Start();
            } 
  
            Game();
        break;
    default:
        break;
    }
}
 printf("\033[2J\n");
}




void Game()//порядок хода
{ while (mov!=0)
    {
        if(order == 1) 
        {
            if(step%2==0)
            {
                ManMove(symbol);
            }
            else
            {
                ManMove(symbol0);
            }
        }
        else
        {
            if(step%2==0)
            {
                ManMove(symbol0);
            }
            else
            {
                ManMove(symbol);
            }
        }
    }

}

void ManMove(char symbolmov)// ход человека
{
   
       Conclusion();
    mark:     printf("Enter the coordinates of the cell where you want to go, write two numbers \"12\" row and column.\n");
        char coordinates[3];
        scanf("%s", coordinates);
        if((coordinates[0]-'0' > 2)||(coordinates[1]-'0'>2))
        { 
            mov = 0;
        }
        else
        {
            if( field[coordinates[0]-'0'][coordinates[1]-'0'] == ' ')
            {
            field[coordinates[0]-'0'][coordinates[1]-'0'] = symbolmov;
            Conclusion();
            step++;
            Win(symbolmov);
            }
            else
            {
                goto mark;
            }
        }
    
}

void Start()// настройка 
{
            printf("Player symbols are assigned one by one, in the first game you want to play with a cross? Write 1 - yes, 0 - no\n");
            scanf("%d", &symbol);
            if (symbol == 1)
            {
                symbol = 'X';
                symbol0 = 'O';
            }
            else
            {
                symbol0 = 'X';
                symbol = 'O';
            }
            printf("Priority of moves in turn, who goes first in the first game? Write 1 - yes, 0 - no\n");
            scanf("%d", &order);
            mov =1;
            game++;  
}

void Empty() // вывод пустых значений 
{
  for (int i = 0; i < SIZE; i++) 
  {
    for (int j = 0; j < SIZE; j++) 
    {
      field[i][j] = ' ';
    }
  }
  Conclusion ();
}

void Conclusion () // вывод таблицы
{  
    if(OS_TYPE == 1)
    {
        system("cls");
    }
     if(OS_TYPE == 0)
    {
         system("clear"); 
    }
  printf("\033[2J\n              TicTacToe\n\n    0   1   2\n  _____________\n");
  for (int i = 0; i < SIZE; i++) 
  {
    printf("%d |", i);
    for (int j = 0; j < SIZE; j++) 
    {
      printf(" %c |", field[i][j]);
    }
    if(i == 0)
    {
    printf("           %c   %c\n  -------------         _________\n",symbol,symbol0);
    }
    if(i == 1)
    {
    printf("       %d | %d | %d |\n  -------------         ---------\n", (game < 0) ? 0 : game, wins, wins0);
    }
  }
  printf("\n  -------------\n");
    
}






void Win(char symbolmov)//проверка
{
 int corner = 0;
          for (int i = 0; i < SIZE; i++) 
                {
                    corner = 0;
                    for (int j = 0; j < SIZE; j++) 
                    {
                        if(field[i][j]==symbolmov)
                        {
                        corner++;
                        }
                    }
                    if(corner==3)
                    {
                        See(symbolmov);
                    }
                }

          for (int j = 0; j < SIZE; j++)
                {
                      corner = 0;
                       for (int i = 0; i < SIZE; i++) 
                    {
                        if(field[i][j]==symbolmov)
                        {
                        corner++;
                        }
                    }
                     if(corner==3)
                    {
                        See(symbolmov);
                    }
                }
 corner = 0;
        for (int i = 0; i < SIZE; i++) 
                {
                    for (int j = 0; j < SIZE; j++) 
                    {
                        if((i == j)&&(field[i][j]==symbolmov))
                        {
                            corner++;
                        }
                    }
                }
 if(corner==3)
                    {
                        See(symbolmov);
                    }
                    else
                    {
                         corner = 0;
                    }
for (int i = 0; i < SIZE; i++) 
                {
                    for (int j = 0; j < SIZE; j++) 
                    {
                        if(((i + j)==2)&&(field[i][j]==symbolmov))
                        {
                            corner++;
                        }
                    }
                }
  if(corner==3)
    {
                        See(symbolmov);
                    }
                    else
                    {
                        int sum =0;
                        for (int i = 0; i < SIZE; i++) 
                        {
                            for (int j = 0; j < SIZE; j++) 
                            {
                                if(field[i][j] != ' ')
                                {
                                    sum++;
                                }
                            }
                        }  
                        if (sum ==9)
                        {
                        corner = 0;
                         See0();
                         }
                        
                    }

}

void See(char symbolmov)//выйгрыш
{
    game++;
    if(symbolmov == symbol)
    {
        wins++;
    }
    else
    {
        wins0++;
    }
    Conclusion ();
    printf("Win\n");
    char wait =getchar();
    Empty();
    Game();
}
void See0()//ничья
{
    game++;
    Conclusion ();
    printf("draw\n");
    char wait =getchar();
    Empty();
    Game();
}