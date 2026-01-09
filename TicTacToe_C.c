#include<stdio.h>
#include<stdlib.h>

void displayBoard(char O_X[3][3])
{
    printf("\n");
    printf("    +-----+-----+-----+\n");
    for(int i=0;i<3;i++)
    {
        printf("    |  %c  |  %c  |  %c  |  %d\n", O_X[i][0], O_X[i][1], O_X[i][2],i);
        if(i < 2)
            printf("    +-----+-----+-----+\n");
    }
    printf("    +-----+-----+-----+\n");
    printf("      0     1     2\n\n");
}

void displayInstructions()
{
    printf("\n");
    printf("    +========================================+\n");
    printf("    |      TIC TAC TOE - Game Instructions   |\n");
    printf("    +========================================+\n");
    printf("    |  1. Enter positions in matrix format   |\n");
    printf("    |     (row column) starting from 0-2     |\n");
    printf("    |                                        |\n");
    printf("    |  2. First 3 moves: Place pieces       |\n");
    printf("    |     After that: Remove old, add new   |\n");
    printf("    |                                        |\n");
    printf("    |  3. Win: Get 3 in a row/column/       |\n");
    printf("    |     diagonal                          |\n");
    printf("    +========================================+\n\n");
}

int checkColumns(char O_X[3][3], char player)
{
    for(int i=0;i<3;i++)
        if(O_X[0][i]==player && O_X[1][i]==player && O_X[2][i]==player)
            return 1;
    return 0;
}

int checkRows(char O_X[3][3], char player)
{
    for(int i=0;i<3;i++)
        if(O_X[i][0]==player && O_X[i][1]==player && O_X[i][2]==player)
            return 1;
    return 0;
}

int checkDiagonals(char O_X[3][3], char player)
{
    if(O_X[0][0]==player && O_X[1][1]==player && O_X[2][2]==player)
        return 1;
    if(O_X[0][2]==player && O_X[1][1]==player && O_X[2][0]==player)
        return 1;
    return 0;
}

int checkWinner(char O_X[3][3], char player)
{
    return (checkColumns(O_X, player) || checkRows(O_X, player) || checkDiagonals(O_X, player));
}

void announceWinner(char player)
{
    printf("\n");
    printf("    +========================================+\n");
    printf("    |         PLAYER '%c' WINS!!!             |\n", player);
    printf("    +========================================+\n\n");
    int c;
    printf("    Press any key and Enter to exit: ");
    scanf("%d",&c);
    exit(0);
}

void getOInputInitial(char O_X[3][3], int O[8], int *O_element)
{
    while(1)
    {
        int x,y,i;
        printf("    [O] Enter position (row column): ");
        scanf("%d%d",&x,&y);
        
        if(x<0 || x>2 || y<0 || y>2)
        {
            printf("     Invalid position! Use 0-2 for row and column.\n");
            continue;
        }
        
        if(O_X[x][y]==' ')
        {
            O_X[x][y]='O';
            for(i=0;i<8;i++)
                if(O[i]==-1)
                    break;
            O[i]=x;
            O[i+1]=y;
            (*O_element)++;
            break;
        }
        else
            printf("     Position already occupied! Try again.\n");
    }
}

void getXInputInitial(char O_X[3][3], int X[8], int *X_element)
{
    while(1)
    {
        int x,y,i;
        printf("    [X] Enter position (row column): ");
        scanf("%d%d",&x,&y);
        
        if(x<0 || x>2 || y<0 || y>2)
        {
            printf("     Invalid position! Use 0-2 for row and column.\n");
            continue;
        }
        
        if(O_X[x][y]==' ')
        {
            O_X[x][y]='X';
            for(i=0;i<8;i++)
                if(X[i]==-1)
                    break;
            X[i]=x;
            X[i+1]=y;
            (*X_element)++;
            break;
        }
        else
            printf("     Position already occupied! Try again.\n");
    }
}

void getOMoveAfter3(char O_X[3][3], int O[8], int *O_element)
{
    while(1)
    {
        int x,y,i;
        printf("    [O] Enter position to REMOVE (row column): ");
        scanf("%d%d",&x,&y);
        
        for(i=0;i<8;i++)
            if(O[i]==x && O[i+1]==y)
                break;
        
        if(i<8)
        {
            O_X[x][y]=' ';
            printf("    [O] Enter NEW position (row column): ");
            scanf("%d%d",&x,&y);
            
            if(x<0 || x>2 || y<0 || y>2)
            {
                printf("     Invalid position!\n");
                continue;
            }
            
            if(O_X[x][y]==' ')
            {
                O_X[x][y]='O';
                O[i]=x;
                O[i+1]=y;
                (*O_element)++;
                break;
            }
            else
                printf("     Position already occupied!\n");
        }
        else
            printf("     Invalid position to remove! Try again.\n");
    }
}

void getXMoveAfter3(char O_X[3][3], int X[8], int *X_element)
{
    while(1)
    {
        int x,y,i;
        printf("    [X] Enter position to REMOVE (row column): ");
        scanf("%d%d",&x,&y);
        
        for(i=0;i<8;i++)
            if(X[i]==x && X[i+1]==y)
                break;
        
        if(i<8)
        {
            O_X[x][y]=' ';
            printf("    [X] Enter NEW position (row column): ");
            scanf("%d%d",&x,&y);
            
            if(x<0 || x>2 || y<0 || y>2)
            {
                printf("     Invalid position!\n");
                continue;
            }
            
            if(O_X[x][y]==' ')
            {
                O_X[x][y]='X';
                X[i]=x;
                X[i+1]=y;
                (*X_element)++;
                break;
            }
            else
                printf("     Position already occupied!\n");
        }
        else
            printf("     Invalid position to remove! Try again.\n");
    }
}

int main()
{
    int O_element=0, X_element=0, Last=0, O[8], X[8];
    char O_X[3][3];
    
    for(int i=0;i<8;i++)
    {
        O[i]=-1;
        X[i]=-1;
    }
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            O_X[i][j]=' ';
    
    displayInstructions();
    
    while(1)
    {
        displayBoard(O_X);
        
        if(checkWinner(O_X, 'O'))
            announceWinner('O');
        
        if(checkWinner(O_X, 'X'))
            announceWinner('X');
        
        if(O_element<3 && Last==0)
        {
            getOInputInitial(O_X, O, &O_element);
            Last=1;
        }
        else if(X_element<3 && Last==1)
        {
            getXInputInitial(O_X, X, &X_element);
            Last=0;
        }
        else if(O_element>=3 && Last==0)
        {
            getOMoveAfter3(O_X, O, &O_element);
            Last=1;
        }
        else if(X_element>=3 && Last==1)
        {
            getXMoveAfter3(O_X, X, &X_element);
            Last=0;
        }
    }
    
    return 0;
}
