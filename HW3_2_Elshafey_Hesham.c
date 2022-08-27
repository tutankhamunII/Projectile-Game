/////////////////////////////////////////////////////////////////////////////////////////////////
// File: HW3_1_Elshafey_Hesham.c
// Author: Hesham Elshafey.
// 2/11/2022.
// This code will prompt user to enter information for
// number of students and will present these data along with the 
// average grade of each student and the class average on console.
////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#define NUM_GRADES  3
typedef struct student{
    char first_name[20]; // string to store first name
    char last_name[20];
    int grade [NUM_GRADES];
    double individual_average;
    double class_average;
    double sum; // variable to store sum grades of each student
    double sum2; // variable to store sum grades of all students
}student;

int main()
{
    student class[15];
    int array_iteration_variable = 0;
    int number_of_students = 0;
    int y = 0;
 

    printf("Enter number of students: ");
    scanf("%d",&number_of_students);

        while( number_of_students <=0 || number_of_students >= 100) // validation function to validate the number of students range.
        {
            printf("Write correct number of students between 0 and 100.\n");
            printf("Enter number of students:");
            scanf("%d", &number_of_students);
        }

        for( array_iteration_variable = 0; array_iteration_variable < number_of_students; array_iteration_variable ++)//four loop to acquire data from user.
        {
        printf("Student %d:\n", array_iteration_variable + 1);
        printf("First Name: ");
        scanf("%s",&class[array_iteration_variable].first_name); // user enters first name
        printf("Last Name: ");
        scanf("%s", class[array_iteration_variable].last_name); // user enters last name.

            for(y = 1; y<=NUM_GRADES; y++)
            {
            printf("grade %d for %s : ",y,class[array_iteration_variable].first_name); // prompting user to enter grades.
            scanf("%d",&class[array_iteration_variable].grade[y]);

                while(class[array_iteration_variable].grade[y] < 0 || class[array_iteration_variable].grade[y] > 100) // checking if the grade is in valid range.
                {
                    printf("Enter valid score.\n");
                    printf("grade %d for %s :",y,class[array_iteration_variable].first_name);
                    scanf("%d",&class[array_iteration_variable].grade[y]);
                }

       
            }
        printf("\n");
        
        
    }


        for(array_iteration_variable = 0; array_iteration_variable < number_of_students; array_iteration_variable ++)// for loop to present display the data.
        { 
        
            printf(
            "\nStudent %d info:\nStudent %d:   %s, %s.\nGrades:  ",
            array_iteration_variable + 1,
            array_iteration_variable + 1,
            class[array_iteration_variable].last_name,
            class[array_iteration_variable].first_name); // printing first and last name of the student.
            
            for(y = 1; y<=NUM_GRADES; y++)// for loop to print grades.
            {
            printf("    %d",class[array_iteration_variable].grade[y]);
            }

            class[array_iteration_variable].sum = 0;
            class[array_iteration_variable].class_average = 0;//intializing storing variables to zero.

                for( y = 1; y<=NUM_GRADES; y++)//for loop to calculate sum of the all entered grade per student.
                {
                class[array_iteration_variable].sum = class[array_iteration_variable].sum + class[array_iteration_variable].grade[y];
                }

                class[array_iteration_variable].individual_average = class[array_iteration_variable].sum / NUM_GRADES;//calculating average
                printf("\nAverage:     %.1lf", class[array_iteration_variable].individual_average);//displaying average.
                    
        }
            
        for( array_iteration_variable = 0; array_iteration_variable<= number_of_students; array_iteration_variable++)//for loop to calculate sum of students averages.
        { 
        class[array_iteration_variable].sum2 += class[array_iteration_variable].individual_average;
        }
                class[array_iteration_variable].class_average = class[array_iteration_variable].sum2;//calcuating average of averages.
                printf("\nclass average: %.1lf\n", class[array_iteration_variable].class_average);//displaying average or averages/         
                
   
   

    
    return 0;
}   