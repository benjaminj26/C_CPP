/*
    Program for performing matrix operations such as addition, multiplication and transposing
    Author ; Benjamin Joseph
    Date : 21-09-2021
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mat_input(int r, int c,int mat[r][c])
{
    for(int i=0;i<r;i=i+1)
	{
		for(int j=0;j<c;j=j+1)
		{
			if(j==0)
				printf("\n");
			scanf("%d",&mat[i][j]);
		}
	}
    getchar();
}

void mat_add( int r1, int c1, int mat1[r1][c1], int mat2[r1][c1], int mat3[r1][c1])
{
    for(int i=0;i<r1;++i)
    {
        for(int j=0;j<c1;++j)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void mat_transpose(int r1, int c1,int mat1[r1][c1], int mat2[r1][c1])
{
    for(int i=0;i<r1;++i)
    {
        for(int j=0;j<c1;++j)
        {
            mat2[i][j]=mat1[j][i];
        }
    }
}

void mat_mul(int r1, int c1, int c2, int mat1[r1][c1], int mat2[c1][c2], int mat3[r1][c2])
{
    for(int i=0;i<r1;++i)
    {
        for(int j=0;j<c2;++j)
        {
            mat3[i][j]=0;
            for(int col1=0, row2=0; col1<c1 && row2<c1; ++col1, ++row2) 
                mat3[i][j]+=mat1[i][col1] * mat2[row2][j];    
        }
    }
}

void print_mat(int r, int c, int mat[r][c])
{
    for(int i=0; i<r; ++i)
    {
        for(int j=0; j<c; ++j)
            printf("%d\t",mat[i][j]);
        printf("\n");
    }
}

int main()
{
	int i,j,n,row1,column1,row2,column2;
	int operation;
    do
    {
        //Inputing the operation
        printf("1.Add\n2.Transpose\n3.Multiply\n4.Exit\nInput your choice: ");
        scanf("%d",&operation);
        if(operation == 1)
        {
            //Initializing the first matrix
            
            printf("Input the number of rows and columns of the first matrix: ");
            scanf("%d %d",&row1,&column1);
            int matrix1[row1][column1];
            printf("Input the elements of the first matrix(%d elements):\n",row1*column1);
	        mat_input(row1,column1,matrix1);
            
            //Initializing the second matrix
            
            printf("Input the number of rows and columns of the second matrix: ");
            scanf("%d %d",&row2,&column2);
            int matrix2[row2][column2];
            printf("Input the elements of the second matrix(%d elements):\n",row2*column2);
	        mat_input(row2,column2,matrix2);

            if(row1==row2 && column1==column2)
            {
                int matrix3[row1][column1];
                //Adding the two matrices
                mat_add(row1,column1,matrix1,matrix2,matrix3);
                printf("The sum of the two matrices is:\n");
                //Printing the sum
                print_mat(row1,row2,matrix3);
            }
            else 
                printf("\nOPERATION NOT POSSIBLE!!!!\n");
        }
        else if(operation == 2)
        {
            //Initializing the first matrix
            
            printf("Input the number of rows and columns of the first matrix: ");
            scanf("%d %d",&row1,&column1);
            int matrix1[row1][column1];
            printf("Input the elements of the first matrix(%d elements):\n",row1*column1);
	        mat_input(row1,column1,matrix1);
            int matrix2[row1][column1];
            //Getting the transpose
            mat_transpose(row1,column1,matrix1,matrix2);
            printf("The transpose of the matrix is:\n");
            //Printing the result
            print_mat(row1,column1,matrix2);
        }
        else if(operation == 3)
        {
            //Initializing the first matrix
            
            printf("Input the number of rows and columns of the first matrix: ");
            scanf("%d %d",&row1,&column1);
            int matrix1[row1][column1];
            printf("Input the elements of the first matrix(%d elements):\n",row1*column1);
	        mat_input(row1,column1,matrix1);
            
            //Initializing the second matrix
            
            printf("Input the number of rows and columns of the second matrix: ");
            scanf("%d %d",&row2,&column2);
            int matrix2[row2][column2];
            printf("Input the elements of the second matrix(%d elements):\n",row2*column2);
	        mat_input(row2,column2,matrix2);
            if(column1==row2)
            {
                int matrix3[row1][column2];
                //Multiplying the two matrices
                mat_mul(row1,column1,column2,matrix1,matrix2,matrix3);
                printf("The product of the two matrices is:\n");
                //Printing the product
                print_mat(row1,row2,matrix3);
            }
            else 
                printf("\nOPERATION NOT POSSIBLE!!!!\n");
        }
        else 
            exit(0);
    }while(1);
    return 0;
}