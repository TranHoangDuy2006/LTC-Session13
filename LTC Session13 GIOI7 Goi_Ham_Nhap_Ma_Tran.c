#include <stdio.h>

void createMatrix(int rows, int cols, int matrix[rows][cols]) 
{
    printf("\nNhap cac phan tu cho Matrix:\n");
    
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("\nCot [%d] hang [%d]: ", i, j);
            
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) 
{
    printf("\nMatrix ban vua nhap la:\n\n");
    
    for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
                {
                     printf("%d ", matrix[i][j]);
                }
        
        printf("\n");
        
        }
}

int main () 
{
    int rows, cols;

    printf("\nNhap so hang cho Matrix: ");
    
    scanf("%d", &rows);
    
    printf("\nNhap so cot cho Matrix: ");
    
    scanf("%d", &cols);

    int matrix[rows][cols];

    createMatrix(rows, cols, matrix);
    
    printMatrix(rows, cols, matrix);

    printf("\n");

    return 0;
}
