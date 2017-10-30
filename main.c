#include <stdio.h>

/**
 * This program multiplies two small mattrices of integers together
 * so long as the multiplication is possible. The matrices are entered
 * by the user.
 *
 * Reference: http://www.programmingsimplified.com/c-program-multiply-matrices
 * @return the return code. 0 for success, !0 for failure
 *
 * TODO: Break this program into functions with a matrix.c and .h file
 */
int main()
{
    // Needed variables and 2D arrays
    int m1, m2, n1, n2, c, d, k, matrix1[10][10], matrix2[10][10], result[10][10];
    int sum = 0;

    // handle entering the first matrix
    printf("Enter the number of rows and columns of the first matrix\n");
    printf("This program handles up to a 10 rows and 10 columns\n");
    scanf("%d%d", &m1, &n1);
    printf("You entered a size of %d rows and %d columns", m1, n1);

    if (m1 <= 10 && n1 <= 10)
    {
        printf("\nEnter the elements of matrix\n");
        for (c = 0; c < m1; c++)
        {
            for (d = 0; d < n1; d++)
            {
                scanf("%d", &matrix1[c][d]);
            }
        }
        printf("\nThe entered matrix is: \n");
        for (c = 0; c < m1; c++)
        {
            for (d = 0; d < n1; d++)
            {
                printf("%d\t", matrix1[c][d]);
            }
            printf("\n");
        }
    } else {
        printf("The row and column sizes cannot exceed 10.");
        return 1;
    }

    //handle entering the second matrix
    printf("Enter the number of rows and columns of the second matrix\n");
    printf("This program handles up to a 10 rows and 10 columns\n");
    scanf("%d%d", &m2, &n2);
    printf("You entered a size of %d rows and %d columns", m2, n2);

    // Check if the two matrices can be multiplied together
    if (n1 != m2) {
        printf("These two matrices cannot be multiplied together");
        return 1;
    } else {
        if (m2 <= 10 && n2 <= 10)
        {
            printf("\nEnter the elements of matrix\n");
            for (c = 0; c < m2; c++)
            {
                for (d = 0; d < n2; d++)
                {
                    scanf("%d", &matrix2[c][d]);
                }
            }
            printf("\nThe entered matrix is: \n");
            for (c = 0; c < m2; c++)
            {
                for (d = 0; d < n2; d++)
                {
                    printf("%d\t", matrix2[c][d]);
                }
                printf("\n");
            }
        } else {
            printf("The row and column sizes cannot exceed 10.");
            return 1;
        }

        // multiply the two matrices together and print the result
        for (c = 0; c < m1; c++) {            // Go through all rows of the first matrix
            for (d = 0; d < n2; d++) {        // Go through every column of the second matrix
                for (k = 0; k < m2; k++) {    // For the number of rows in the second matrix
                    sum = sum + matrix1[c][k] * matrix2[k][d];
                }
                // The accumulation of the multiplications is the value of the c,d entry in the result matrix
                result[c][d] = sum;
                sum = 0; // reset accumulator
            }
        }

        printf("The result of the matrix multiplication: \n");
        for (c = 0; c < m1; c++) {
            for(d = 0; d < n2; d++) {
                printf("%d\t",result[c][d]);
            }
            printf("\n");
        }
    }



    return 0;
}