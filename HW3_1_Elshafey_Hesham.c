/////////////////////////////////////////////////////////////////////////////////////////////////
// File: HW3_1_Elshafey_Hesham.c
// Author: Hesham Elshafey.
// 2/11/2022.
//This is a game where you try to throw a ball on a
// table. The player must choose a velocity and angle,
// and the output is a trace of the ball's path.
////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>


const int MAX_TABLE_HEIGHT = 15;
const int MIN_TABLE_HEIGHT = 2;
const int MAX_TABLE_START = 75;
const int MIN_TABLE_START = 10;
const int FIELD_HEIGHT = 30;
const int FIELD_WIDTH = 80;
const double ACCELERATION_DUE_TO_GRAVITY = 9.80665;
const int time_time = 10;


int main (){

    srand(time(NULL));
    int table_height = rand() % (MAX_TABLE_HEIGHT - MIN_TABLE_HEIGHT) + MIN_TABLE_HEIGHT;
    int table_position = rand() % (MAX_TABLE_START - 4) + MIN_TABLE_START; // Functions to randomize the table hight and position within the playing field.

    
    double x = 0; //variable used to iterate through time in projectile calculations.

    int a = 0; // Varbiables used to iterate through the 2D array.
    int b = 0;

    int c = 0;//variable used to print the left legs of the table. It is incremented in a way that prints | specific times to be equal to the table height.
    int u = 0;//variable used to print the right legs of the table. It is incremented in a way that prints | specific times to be equal to the table height.
    int p = 0;
    int i = 0; // variable use to break the while loop once the projectile hits the table top and promote the end of the program.
    
    double angle_in_radian = 0;
    double angle_in_degree = 0;
    int integer_y = 0; // Variable used to store the conversion of ball_y from float to integer.
    int integer_x = 0; // Variable used to store the conversion of ball_x from float to integer.
    double ball_y = 0; // Vertical distance.
    double ball_x = 0; // Horizontal distance.
    double user_velocity = 0;
    double intial_x_velocity = 0;
    double intial_y_velocity = 0;
    char array [FIELD_WIDTH + 1000][FIELD_WIDTH + 1000];
    
     //Iterating through 2D array to save specific character at specific array element spaces.
    for (a = 0; a <= FIELD_HEIGHT; a++)
    {
        for (int b =0; b <= FIELD_WIDTH; b++)
        {
            //Checking if the array is at the corners and save "+" character if true.
            if ((a == 0 &&((b == 0) || b == FIELD_WIDTH))
            || (a == FIELD_HEIGHT && (b == 0 || b == FIELD_WIDTH))) 
            {
                array[a][b] = '+';
            }
            //Checking if the array is at the top or bottom frame of the box and save "-" character if true. 
            else if (a == 0 || a == FIELD_HEIGHT)
            {
                array[a][b] = '-';
            }
            //Checking if the array is at the right or left frame of the box and save "|" character if true.
            else if (b == 0 || b == FIELD_WIDTH)
            {
                array[a][b] = '|';
            }//Checking if the array is at left leg of the table and save "|" if true.
            else if ( b == table_position && a != FIELD_HEIGHT && b != FIELD_WIDTH && a != 0 && b != 0 && u < table_height && a < (table_height +1))
            {
                array[a][b] = '|';
                u++; 
            }
            //Checking if the array is at right leg of the table and save "|" if true.
            else if ( b == table_position + 4 && a != FIELD_HEIGHT && b != FIELD_WIDTH && a != 0 && b != 0 && c < table_height && a < (table_height +1))    
            {
                array[a][b] = '|';
                c++;
            }
            //Checking if the array is at top of the table and save "=" if true.
            else if ( (b == table_position || b == table_position + 1 || b == table_position + 2 || b == table_position +3 || b == table_position + 4) 
            && a != FIELD_HEIGHT && b != FIELD_WIDTH && a != 0 && b != 0 && p < table_height && a ==(table_height +1))
            {
                array[a][b] = '=';
            }
              //saves " " in everywhere expect the already saved spaces for all the previous characters.
              else 
              {
            
                  array[a][b] = ' ';
              }
        }
    }
   
    for (a = 30; a >= 0; a--)
    {
        for ( b = 0; b <= FIELD_WIDTH; b++)
        { 
            printf("%c" , array[a][b]);
        }
    printf("\n");
    }
    while(i==0)
    {
        u = 0; //Resetting the table-leg-printing variables.
        c = 0;

        printf("Enter Velocity, Angle: ");
        scanf("%lf, %lf", &user_velocity, &angle_in_degree);//Acquiring the velocity and angle from the user.

        if ( user_velocity == 0 && angle_in_degree ==0)//Quiting the whole program if the user entered non-numerical characters in the input.
        {
            printf("Goodbye!");
            return 0;
        }
        while (user_velocity <0 || angle_in_degree <0 || angle_in_degree >90)//validating if the velocity and angle are in correct format and promopt user to input again if not so.
        {
            printf("Velocity and angle must be >0 and angle must be <90, please enter you data again.\n");
            printf("Enter Velocity, Angle: ");
            scanf("%lf, %lf", &user_velocity, &angle_in_degree);
        }
        
        angle_in_radian = angle_in_degree * M_PI / 180; //converting degrees to rad.
        intial_x_velocity = user_velocity * cos(angle_in_radian); //horizontal velocity.
        intial_y_velocity = user_velocity * sin(angle_in_radian); //vertical velocity.
        
            //This loop iterate throught the array by very small increments in time, calculate x and y distances, and then check conditions to assign appropriate.
            for(x = 0 ; x <= time_time ; x+=0.01 )
            {
                ball_y = (intial_y_velocity * x) -(0.5 * ACCELERATION_DUE_TO_GRAVITY * pow( x , 2 ));
                ball_x = intial_x_velocity * x;
                integer_y = (int)(ball_y + 0.5); 
                integer_x = (int)(ball_x + 0.5); 
                
                if ((integer_y == 0 && (integer_x == 0 || integer_x == FIELD_WIDTH)) || (integer_y == FIELD_HEIGHT && (integer_x == 0 || integer_x == FIELD_WIDTH)))
                {
                array[integer_y][integer_x] = '+';
                }
                else if ((integer_x == table_position || integer_x == table_position + 1 || integer_x == table_position + 2 || integer_x == table_position +3 || integer_x == table_position + 4)
                 && integer_y != FIELD_HEIGHT && integer_x != FIELD_WIDTH && integer_y != 0 && integer_x != 0 && p < table_height && integer_y == (table_height +1))
                {
                    array[integer_y][integer_x] = '*'; //replacing the top of the table with * at the spots the projectile hits the = characters.
                    i ++; //The i will be incrementing if the projectile hits the top of the table. Then the program will exit after printing the whole array.
                }
                    else if (integer_y == 0 || integer_y == FIELD_HEIGHT)
                {
                    array[integer_y][integer_x] = '-';
                } 
                else if (integer_x == 0 || integer_x == FIELD_WIDTH)
                {
                    array[integer_y][integer_x] = '|';
                }
                else if ( integer_x == table_position && integer_y != FIELD_HEIGHT && integer_x != FIELD_WIDTH && integer_y != 0 && integer_x != 0 && u < table_height && integer_y <  (table_height +1))
                {
                    array[integer_y][integer_x] = '|';
                    u++; 
                }
                else if ( integer_x == table_position + 4 && integer_y != FIELD_HEIGHT && integer_x != FIELD_WIDTH && integer_y != 0 && integer_x != 0 && c < table_height && integer_y <  (table_height +1))    
                {
                    array[integer_y][integer_x] = '|';
                    c++;
                }
                else
                {  
                    array[integer_y][integer_x]= '.';//saving projectile motion "." character.
                }
                
            }
            for (a = 30; a >= 0; a--)//nested loops to print the array with the projectile dots included.
            {
                for ( b = 0; b <= FIELD_WIDTH; b++)
                { 
                    printf("%c" , array[a][b]);
                }
            printf("\n");   
            }
  
        user_velocity = 0;//resetting velocity to zero.
        angle_in_degree = 0;//resetting angle to zero.
        //as long as the projectile didn't hit the table, velocity and angel are resetted and the user is promopted to input another velocity and angle.   
   }
 
    printf("you won!\n");     
    return 0;

}