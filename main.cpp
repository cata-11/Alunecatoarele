#include <graphics.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int pX = getmaxwidth()/4+50;
int pY = getmaxheight()/4-50;
int L = pX/3-15;
int matrix[6][6];
int mi = 3, mj = 3;
bool END = false;

void title()
{
    setbkcolor(BLACK);
    setfillstyle(SOLID_FILL,YELLOW);
    bar(getmaxx()/4,20,getmaxx()-getmaxx()/4,107);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,8);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(WHITE);
    outtextxy(getmaxx()/2,80," ALUNECATOARELE ");
}
void table()
{
    for(int j = 0; j < L*5; j+=L)
    {
        for(int i = 0; i < L*5; i+=L)
        {
            line(pX+i,pY+j,pX+L+i,pY+j);
            line(pX+i,pY+j,pX+i,pY+L+j);
        }
    }
    line(pX+(L*5),pY,pX+(L*5),pY+(L*5));
    line(pX,pY+(L*5),pX+(L*5),pY+(L*5));
}
void piesaRED(int i, int j) /// PC = RED = 1
{
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,COLOR(255,0,0)); //red
    circle(pX+L*i-L/2,pY+L*j-L/2,30);
    floodfill(pX+L*i-L/2,pY+L*j-L/2,YELLOW);
}
void piesaYELLOW(int i, int j) /// YOU = YELLOW = 2
{
    setcolor(RED);
    setfillstyle(SOLID_FILL,YELLOW);
    circle(pX+L*i-L/2,pY+L*j-L/2,30);
    floodfill(pX+L*i-L/2,pY+L*j-L/2,RED);
}
void deletePIESA(int i, int j) /// EMPTY = 0
{
    setfillstyle(SOLID_FILL,BLACK);
    setcolor(BLACK);
    circle(pX+L*i-L/2,pY+L*j-L/2,35);
    floodfill(pX+L*i-L/2,pY+L*j-L/2,BLACK);
}
void matriX()
{
    for(int i=1; i<=5; i++)
        for(int j=1; j<=5; j++)
            if(i%2!=0 && j%2==0 || i%2==0 && j%2!=0)
                matrix[i][j] = 2;
            else
                matrix[i][j] = 1;
    matrix[mi][mj] = 0;

    /*
    for(int i=1; i <= 5; i++)
    {
    for(int j=1; j<=5; j++)
        printf("%d ",matrix[i][j]);
    printf("\n");
    }
    */
}
void piese()
{
    int k=0,w;

    for(int i = 1; i <= 5; i++)
    {
        k++;
        w=0;
        for(int j = 1; j <= 5; j++)
        {
            w++;
            if(matrix[k][w]==1)
            {
                piesaRED(i,j);
            }
            else if(matrix[k][w]==2)
            {
                piesaYELLOW(i,j);
            }
        }
    }
}
void movePC()
{
    int key;

    key = rand()%4;

    if(key == 0 && matrix[mi][mj+1]==1)
    {
        matrix[mi][mj]=1;
        piesaRED(mi,mj);
        mj++;
        matrix[mi][mj]=0;
        deletePIESA(mi,mj);
    }
    else if(key == 1 && matrix[mi][mj-1]==1)
    {
        matrix[mi][mj]=1;
        piesaRED(mi,mj);
        mj--;
        matrix[mi][mj]=0;
        deletePIESA(mi,mj);
    }
    else if(key == 2 && matrix[mi+1][mj]==1)
    {
        matrix[mi][mj]=1;
        piesaRED(mi,mj);
        mi++;
        matrix[mi][mj]=0;
        deletePIESA(mi,mj);
    }
    else if(key == 3 && matrix[mi-1][mj]==1)
    {
        matrix[mi][mj]=1;
        piesaRED(mi,mj);
        mi--;
        matrix[mi][mj]=0;
        deletePIESA(mi,mj);
    }
    else movePC();
}
void moveYou()
{
    char key;
    do
    {
        key=(char)getch();
        switch(key)
        {
        case KEY_UP:
            if(matrix[mi][mj+1]==2)
            {
                matrix[mi][mj]=2;
                piesaYELLOW(mi,mj);
                mj++;
                matrix[mi][mj]=0;
                deletePIESA(mi,mj);
                delay(200);
                if(matrix[mi][mj+1]==1 || matrix[mi][mj-1]==1
                        || matrix[mi+1][mj]==1 || matrix[mi-1][mj]==1)
                    movePC();
                else
                {
                    END = !END;
                    setcolor(WHITE);
                    outtextxy(getmaxx()/2,getmaxy()/2," You Win =) ");
                }
            }
            break;
        case KEY_DOWN:
            if(matrix[mi][mj-1]==2)
            {
                matrix[mi][mj]=2;
                piesaYELLOW(mi,mj);
                mj--;
                matrix[mi][mj]=0;
                deletePIESA(mi,mj);
                delay(200);
                if(matrix[mi][mj+1]==1 || matrix[mi][mj-1]==1
                        || matrix[mi+1][mj]==1 || matrix[mi-1][mj]==1)
                    movePC();
                else
                {
                    END = !END;
                    setcolor(WHITE);
                    outtextxy(getmaxx()/2,getmaxy()/2," You Win =) ");
                }
            }
            break;
        case KEY_LEFT:
            if(matrix[mi+1][mj]==2)
            {
                matrix[mi][mj]=2;
                piesaYELLOW(mi,mj);
                mi++;
                matrix[mi][mj]=0;
                deletePIESA(mi,mj);
                delay(200);
                if(matrix[mi][mj+1]==1 || matrix[mi][mj-1]==1
                        || matrix[mi+1][mj]==1 || matrix[mi-1][mj]==1)
                    movePC();
                else
                {
                    END = !END;
                    setcolor(WHITE);
                    outtextxy(getmaxx()/2,getmaxy()/2," You Win =) ");
                }
            }
            break;
        case KEY_RIGHT:
            if(matrix[mi-1][mj]==2)
            {
                matrix[mi][mj]=2;
                piesaYELLOW(mi,mj);
                mi--;
                matrix[mi][mj]=0;
                deletePIESA(mi,mj);

                delay(500);
                if(matrix[mi][mj+1]==1 || matrix[mi][mj-1]==1
                        || matrix[mi+1][mj]==1 || matrix[mi-1][mj]==1)
                    movePC();
                else
                {
                    END = !END;
                    setcolor(WHITE);
                    outtextxy(getmaxx()/2,getmaxy()/2," You Win =) ");
                }
            }
        }
        if(matrix[mi+1][mj]!=2 && matrix[mi-1][mj]!=2
                && matrix[mi][mj+1]!=2 && matrix[mi][mj-1]!=2)
        {
            END = !END;
            delay(200);
            setcolor(WHITE);
            outtextxy(getmaxx()/2,getmaxy()/2," You Lose =( ");
        }
    }
    while(key!='x' && key!='X');
}
int main()
{
    initwindow(getmaxwidth(),getmaxheight(),"Alunecatoarele");

    title();
    matriX();
    table();
    piese();

    while(!END)
    {
        moveYou();
    }

    return 0;
}
