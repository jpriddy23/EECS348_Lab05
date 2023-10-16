#include <stdio.h>
#include <string.h>

// Creating a function to calculate the average of the monthly sales
float findAverage(float sales[], int size) {
    float total = 0.0;

    // Finding the sum of all sales
    for (int i = 0; i < size; i++) {
        total += sales[i];
    }

    // Returns the average by dividing the total by the number of months
    return total / size;
}

// Creating a function to find the min and max sales
void findMinMax(float sales[], int size, float *min_sales, float *max_sales, int *min_index, int *max_index) {
    // Creating min and max values and their indices
    *min_sales = sales[0];
    *max_sales = sales[0];
    *min_index = 0;
    *max_index = 0;

    // Loop through the sales data to find the min and max
    for (int i = 1; i < size; i++) {
        if (sales[i] < *min_sales) {
            // Updating min value and its index
            *min_sales = sales[i];
            *min_index = i;
        }
        if (sales[i] > *max_sales) {
            // Updating max value and its index
            *max_sales = sales[i];
            *max_index = i;
        }
    }
}

// Creating a function to print the sales report
void salesReport(char *months[], float sales[], int size) {
    printf("Monthly sales report for 2022:\n");
    printf("Month         Sales\n");

    // Loop through the months and sales data and print them
    for (int i = 0; i < size; i++) {
        printf("%-12s $%.2f\n", months[i], sales[i]);
    }
}

// Creating a function to find and print the six month moving average
void sixMonthAverage(char *months[], float sales[], int size) {
    printf("\nSix-Month Moving Average Report:\n");
    
    // Loop through the months to find moving averages
    for (int i = 0; i < size - 5; i++) {
        float sum = 0;

        // Find the sum of sales over 6 months
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }

        // Find the average over 6 months
        float average = sum / 6;

        // Print the moving average along with the months
        printf("%-12s - %-12s $%.2f\n", months[i], months[i + 5], average);
    }
}

// Creating a function to sort the sales data in descending order
void salesDescending(char *months[], float sales[], int size) {
    // Using the selection sort algorithm to sort sales and their months in descending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (sales[i] < sales[j]) {
                // Swap sales values
                float temp_sales = sales[i];
                sales[i] = sales[j];
                sales[j] = temp_sales;
                // Swap month names
                char *temp_month = months[i];
                months[i] = months[j];
                months[j] = temp_month;
            }
        }
    }
}

int main() {
    float sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67,
        60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};

    char *months[12] = {"January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    int size = 12;
    float min_sales, max_sales, average;
    int min_index, max_index;

    // Find the min and max sales and their indices
    findMinMax(sales, size, &min_sales, &max_sales, &min_index, &max_index);

    // Find the average of the sales
    average = findAverage(sales, size);

    // Print the monthly sales report
    salesReport(months, sales, size);

    printf("\nSales summary:\n");
    
    // Print the minimum and maximum sales and their months
    printf("Minimum sales: $%.2f (%s)\n", min_sales, months[min_index]);
    printf("Maximum sales: $%.2f (%s)\n", max_sales, months[max_index]);
    
    // Print the average sales
    printf("Average sales: $%.2f\n", average);

    // Find and print the six month moving average report
    sixMonthAverage(months, sales, size);

    // Sort the sales data in descending order and print it
    salesDescending(months, sales, size);

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month         Sales\n");

    for (int i = 0; i < size; i++) {
        // Print the sorted month names and sales
        printf("%-12s $%.2f\n", months[i], sales[i]);
    }

    return 0;
}
