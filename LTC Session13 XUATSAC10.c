#include <stdio.h>

int inputArray(int arr[])
{
    
    int n;
    
    printf("\nNhap so phan tu can nhap: ");
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nNhap phan tu thu %d: ", i + 1);
        
        scanf("%d", &arr[i]);
    }

    return n;
}

void printArray(int arr[], int n)
{
    
    printf("\nCac phan tu trong mang: ");
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

int insertElement(int arr[], int n, int pos, int value)
{
    if (pos < 0 || pos > n)
    {
        printf("\nVi tri khong hop le!\n");
        
        return n;
    }
    
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    
    arr[pos] = value;
    
    return n + 1;
}

void updateElement(int arr[], int n, int pos, int value)
{
    if (pos < 0 || pos >= n)
    {
        
        printf("\nVi tri cua phan tu ban can thay doi khong hop le!\n");
        
        return;
    }
    
    arr[pos] = value;
}

int deleteElement(int arr[], int n, int pos)
{
    if (pos < 0 || pos >= n)
    {
        
        printf("\nVi tri phan tu ban muon xoa khong hop le!\n");
        
        return n;
    }
    
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    
    return n - 1;
}

void sortArray(int arr[], int n, char choice)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((choice == 'a' && arr[i] > arr[j]) || (choice == 'b' && arr[i] < arr[j]))
            {
                int temp = arr[i];
                
                arr[i] = arr[j];
                
                arr[j] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    
    return -1;
}

int binarySearch(int arr[], int n, int value)
{
    
    int left = 0, right = n - 1;
    
    while (left <= right)
    {
        
        int mid = (left + right) / 2;
        
        if (arr[mid] == value)
            
            return mid;
        
        else if (arr[mid] < value)
            
            left = mid + 1;
        
        else
            
            right = mid - 1;
    }
    
    return -1;
}

int main()
{
    int arr[100], n = 0, choice, pos, value;

    do
    {
        printf("\n++++++++++++++++++++ MENU: ++++++++++++++++++++\n");
        
        printf("\n1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        
        printf("\n2. In ra gia tri cac phan tu dang quan ly\n");
        
        printf("\n3. Them mot phan tu vao vi tri chi dinh\n");
        
        printf("\n4. Sua mot phan tu o vi tri chi dinh\n");
        
        printf("\n5. Xoa mot phan tu o vi tri chi dinh\n");
        
        printf("\n6. Sap xep cac phan tu\n");
        
        printf("\na. Giam dan\n");
        
        printf("\nb. Tang dan\n");
        
        printf("\n7. Tim kiem phan tu nhap vao\n");
        
        printf("\na. Tim kiem tuyen tinh\n");
        
        printf("\nb. Tim kiem nhi phan\n");
        
        printf("\n8. Thoat\n");

        printf("\n++++++++++++++++++++++++++++++++++++++++++++++");
        
        printf("\nNhap lua chon cua ban: ");
        
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            
            n = inputArray(arr);
            
            break;

        case 2:
            
            printArray(arr, n);
            
            break;

        case 3:
            
            printf("\nNhap vi tri can chen: ");
            
            scanf("%d", &pos);
            
            printf("\nNhap gia tri phan tu can chen: ");
            
            scanf("%d", &value);
            
            n = insertElement(arr, n, pos, value);
            
            break;

        case 4:
            
            printf("\nNhap vi tri phan tu can sua: ");
            
            scanf("%d", &pos);
            
            printf("\nNhap gia tri moi: ");
            
            scanf("%d", &value);
            
            updateElement(arr, n, pos, value);
            
            break;

        case 5:
            
            printf("\nNhap vi tri phan tu can xoa: ");
            
            scanf("%d", &pos);
            
            n = deleteElement(arr, n, pos);
            
            break;

        case 6:           
    {
        char sortChoice;
        
        printf("\nNhap lua chon cua ban: \n\na. Sap xep giam dan\n\nb. Sap xep tang dan\n\n Lua chon cua ban: ");
        
        scanf(" %c", &sortChoice); 

        if (sortChoice == 'a')
        
        {
            sortArray(arr, n, 'b'); 
            
            printf("\nMang da duoc sap xep giam dan!\n");
        }
        
        else if (sortChoice == 'b')
        {
            sortArray(arr, n, 'a'); 
            
            printf("\nMang da duoc sap xep tang dan!\n");
        }
        
        else
        {
            printf("\nLua chon khong hop le, vui long nhap lai!\n");
        }
        
        break;
    }

        case 7:
            
            printf("\nNhap gia tri cua phan tu can tim: ");
            
            scanf("%d", &value);

            printf("\na. Tim kiem tuyen tinh\n");
            
            printf("\nb. Tim kiem nhi phan\n");
            
            printf("\nNhap lua chon cua ban: ");
       
            char searchChoice;
            
            scanf(" %c", &searchChoice); 

                if (searchChoice == 'a') 
                    {
                        pos = linearSearch(arr, n, value);
        
                        if (pos != -1)
                            {
                                printf("\nPhan tu %d da duoc tim thay tai vi tri %d!\n", value, pos);
                            }
            
                                else
                                    {
                                        printf("\nKhong tim thay phan tu %d trong mang!\n", value);
                                    }
                    }
    
            else if (searchChoice == 'b') 
            {       
                sortArray(arr, n, 'a');  
        
                pos = binarySearch(arr, n, value);
        
            if (pos != -1)
                {
                    printf("\nPhan tu %d da duoc tim thay tai vi tri %d!\n", value, pos);
                }
        
                    else
                        {
                            printf("\nKhong tim thay phan tu %d trong mang!\n", value);
                        }
            }
    
                else 
                    {
                        printf("\nLua chon khong hop le, vui long chon lai!\n");
                    }
            break;
        
        case 8:
            
            printf("\nThoat chuong trinh!\n\n");
            
            break;
            
        default:

            printf("\nLua chon khong hop le, vui long chon lai!\n\n");
        
        }
    
    } while (choice != 8);

    return 0;
}
