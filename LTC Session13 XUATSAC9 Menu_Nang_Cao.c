#include <stdio.h>

void createMatrix(int rows, int cols, int matrix[rows][cols])
{
    for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
                {
                    printf("\nHang [%d] cot [%d]: ", i, j);

                    scanf("%d", &matrix[i][j]);
                }
        }
}

void printMatrix(int rows, int cols, int matrix[rows][cols])
{
    printf("\nMatrix ban nhap la:\n\n");
    
    for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
                {
                    printf("%d ", matrix[i][j]);
                }

            printf("\n\n");
        }
}

void elementOnTheBoundaryOfTheMatrix(int rows, int cols, int matrix[rows][cols]) 
{
    printf("\nCac phan tu nam tren bien cua Matrix:\n\n");
    
    for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
                {
                    if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
                        {
                            printf("%d ", matrix[i][j]);
                        }
                            else
                                {
                                    printf("  ");
                                }
                }

                printf("\n\n");
        }
}

void printElementOnCornerOfTheMatrix(int rows, int cols, int matrix[rows][cols])
{
    printf("\nCac phan tu o goc cua Matrix la:\n\n");
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if ((i == 0 && j == 0) || (i == 0 && j == cols - 1) || (i == rows - 1 && j == 0) || (i == rows - 1 && j == cols - 1))
                {
                    printf("%d ", matrix[i][j]);
                }
            
                else
                    {
                        printf("  "); 
                    }
        }
        
        printf("\n"); 
    
    }
}

void elementOnTheMainAndSecondaryDiagonal(int rows, int cols, int matrix[rows][cols])
{
    printf("\nCac phan tu nam tren duong cheo chinh va cheo phu cua Matrix:\n\n");
    
    printf("Duong cheo chinh:\n\n");
    
    for (int i = 0; i < rows && i < cols; i++)
    {
        printf("  %d ", matrix[i][i]);
    }

    printf("\n\nDuong cheo phu:\n\n ");
    
    for (int i = 0; i < rows && i < cols; i++)
    {
        printf(" %d ", matrix[i][cols - i - 1]);
    }

    printf("\n");
}

void printPrimeElements(int rows, int cols, int matrix[rows][cols])
{
    printf("\nCac phan tu la so nguyen to trong Matrix (theo ma tran):\n\n");
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            
            int num = matrix[i][j];
            
            int isPrime = 1;

            if (num < 2)
                {
                    isPrime = 0; 
                }
            
                else
                    {
                        for (int k = 2; k * k <= num; k++)
                            {
                                if (num % k == 0)
                                    {
                                        
                                        isPrime = 0;
                                        
                                        break;
                                    }
                            }
                    }

            if (isPrime)
                
                printf("%d ", num);
            
                else
                
                    printf("x "); 
        }
        
        printf("\n"); 
    }
}


int main()
{
    int rows, cols, choice;
    
    printf("\nNhap vao so hang, so cot cho Matrix: ");
    
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    do
    {
        printf("\nMENU:\n");
        
        printf("\n1. Nhap gia tri cac phan tu cua mang\n");
        
        printf("\n2. In gia tri cac phan tu cua mang theo ma tran\n");
        
        printf("\n3. In ra cac phan tu o goc theo ma tran\n");
        
        printf("\n4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        
        printf("\n5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        
        printf("\n6. In ra cac phan tu la so nguyen to theo ma tran\n");
        
        printf("\n7. Thoat\n");
        
        printf("\nNhap lua chon cua ban: ");
        
        scanf("%d", &choice);

        switch (choice)
        {
        
        case 1:
            
            createMatrix(rows, cols, matrix);
            
            break;

        case 2:
            
            printMatrix(rows, cols, matrix);
            
            break;

        case 3:
            
            printElementOnCornerOfTheMatrix(rows, cols, matrix);
            
            break;

        case 4:
            
            elementOnTheBoundaryOfTheMatrix(rows, cols, matrix);
            
            break;

        case 5:
            
            elementOnTheMainAndSecondaryDiagonal(rows, cols, matrix);
            
            break;
        case 6:
            
            printPrimeElements(rows, cols, matrix);
            
            break;

        case 7:
            
            printf("\nThoat chuong trinh!\n\n");
            
            break;

        default:
            
            printf("\nLua chon khong hop le, vui long chon lai!\n");
        }
    
    } while (choice != 7);

    return 0;
}