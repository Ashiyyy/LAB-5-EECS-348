#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Maxfield Freeman - 3109451
//10-12-24
//Lab 6, Sales Report

//Function initialization
float maximum(float sales[], float size);
float minimum(float sales[], float size);
float average(float sales[], float size);


//Maximum function
float maximum(float sales[], float size){
    float max = sales[0]; //Current value is start of array
    //If current value smaller than array value, current value = array value
    for (int i = 0; i < size; i++){
        if (max < sales[i]){
            max = sales[i];
        }
    }
    return max;
}

//Minimum function
float minimum(float sales[], float size){
    float min = sales[0]; //Current value is start of array
    //If current value larger than array value, current value = array value
    for (int i = 0; i < size; i++){
        if (min > sales[i]){
            min = sales[i];
        }
    }
    return min;
}

//Average function
float average(float sales[], float size){
    float avg;
    for (int i = 0; i < size; i++){
        avg = (avg + sales[i]); //Add up all values
    }
    avg = (avg / size); //Divide value by length of array
    return avg;
}


//Main
int main() {

    //Sales array
    float sales[12];
    //Months array
    char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// User input rather than file
    //Input setup
    for (int i = 0; i< 12; i++){
        printf("Please enter your ");
        printf("%s", months[i]);
        printf(" sales: ");

        while (scanf("%f", &sales[i]) == 0){
            while (getchar() != '\n'); //Clears input buffer
            printf("Enter a valid January sales: ");
        }
    }
//


/*File input
    //Input setup
    FILE *input_file = fopen("input_file.txt", "r");
    char* file_line = " ";
    for (int i = 0; i < 12; i++){
        fgets(file_line, 100, input_file);
        sales[i] = atof(file_line);
    }
    fclose(input_file);
File input*/



//6-month average arrays
    float jj[6]; //Average from jan-june
    for (int i = 0; i < 6; i++){
        jj[i] = sales[i];
    }
    float avg_jj = average(jj, 6);

    float fj[6]; //Average feb-july
    for (int i = 1; i < 7; i++){
        fj[i-1] = sales[i];
    }
    float avg_fj = average(fj, 6);

    float ma[6]; //Average march-aug
    for (int i = 2; i < 8; i++){
        ma[i-2] = sales[i];
    }
    float avg_ma = average(ma, 6);

    float as[6]; //Average april-sep
    for (int i = 3; i < 9; i++){
        as[i-3] = sales[i];
    }
    float avg_as = average(as, 6);

    float mo[6]; //Average may-oct
    for (int i = 4; i < 10; i++){
        mo[i-4] = sales[i];
    }
    float avg_mo = average(mo, 6);

    float jn[6]; //Average june-nov
    for (int i = 5; i < 11; i++){
        jn[i-5] = sales[i];
    }
    float avg_jn = average(jn, 6);

    float jd[6]; //Average july-dec
    for (int i = 6; i < 12; i++){
        jd[i-6] = sales[i];
    }
    float avg_jd = average(jd, 6);



//Highest to Lowest section
    //variable setup
    float sort[12];
    char sort_months[12][12];
    float temp_max;
    float temp_values[12];
    for (int i = 0; i < 12; i++){ //temp_values = sales array
        temp_values[i] = sales[i];
    }
    //Find maximum, add to "sort", remove maximum from "temp_array", do it (the size of the) array times
    for (int i = 0; i < 12; i++){
        temp_max = maximum(temp_values, 12);
        sort[i] = temp_max;
        for (int x = 0; x < 12; x++){
            if (temp_values[x] == temp_max){
                temp_values[x] = 0;
                temp_max = 0;
                break;
            }
        }
    }
    //Sorts months for "sort_months"
    for (int i = 0; i < 12; i ++){
        for (int x = 0; x < 12; x ++){
            if (sort[i] == sales[x]){
                strcpy(sort_months[i], months[x]);
                break;
            }
        }
    }


//Input file open to WRITE
//FILE *output_file = fopen("output_file.txt", "w");

//Monthly sales printing
    printf("\n");
    printf("\n");
    printf("Monthly Sales Report for 2024: ");
    printf("\n");
    printf("\n");
    for (int i = 0; i < 12; i++){
        printf("%s", months[i]);
        printf("\t");
        //March-April-June need an extra tab for formatting
        if ((i == 0) | (i == 2) | (i == 3) | (i == 5) | (i == 6) | (i == 7) | (i == 9)){
            printf("\t");
        }
        //May needs 2 extra tabs for formatting
        if (i == 4){
            printf("\t");
            printf("\t");
        }
        printf("%f\n", sales[i]);
    }

//Sales summary
    //Minimum and Maximum variables
    float min = minimum(sales, 12);
    float max = maximum(sales, 12);
    int min_month;
    int max_month;
    for (int i = 0; i < 12; i++){
        if (min == sales[i]){
            min_month = i;
        }
        if (max == sales[i]){
            max_month = i;
        }
    }

    //printing
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Sales Summary Report: ");
    printf("\n");
    printf("\n");
    printf("Minimum sales: ");
    printf("\t");
    printf("%f", min);
    printf("\t");
    printf(months[min_month]);
    printf("\n");
    printf("Maximum sales: ");
    printf("\t");
    printf("%f", max);
    printf("\t");
    printf(months[max_month]);
    printf("\n");
    printf("Average sales: ");
    printf("\t");
    printf("%f", average(sales, 12));

//Six-month moving average
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Six-Month Moving Average Report: ");
    printf("\n");
    printf("\n");
    printf("January-June: ");
    printf("\t");
    printf("\t");
    printf("%f", avg_jj);
    printf("\n");
    printf("February-July: ");
    printf("\t");
    printf("\t");
    printf("%f", avg_fj);
    printf("\n");
    printf("March-August: ");
    printf("\t");
    printf("\t");
    printf("%f", avg_ma);
    printf("\n");
    printf("April-September: ");
    printf("\t");
    printf("%f", avg_as);
    printf("\n");
    printf("May-October: ");
    printf("\t");
    printf("\t");
    printf("%f", avg_mo);
    printf("\n");
    printf("June-November: ");
    printf("\t");
    printf("\t");
    printf("%f", avg_jn);
    printf("\n");
    printf("July-December: ");
    printf("\t");
    printf("\t");
    printf("%f", avg_jd);

//Sales, Highest to Lowest;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Sales report (highest to lowest): ");
    printf("\n");
    printf("\n");

    for (int i = 0; i < 12; i++){
        printf("%s", sort_months[i]);
        printf("\t");
        printf("\t");
        printf("\t");
        printf("%f", sort[i]);
        printf("\n");
    }

//File output close
//    fclose(output_file);


    return 0;
}