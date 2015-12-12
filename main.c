/*
 * File:   main.c
 * Author: aleix gh
 *
 * Created on 28 de octubre de 2015, 15:29
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vaixells.h"

// X FILA Y COLUMNA peta cuando metemos un 8

void imp_tab(char **t,int dim)
{
    int i , j;
    char lin = 'A';
    printf("   ");
    for(i = 0 ; i < dim; ++i)
        printf("%d ",i+1);
    printf("\n");
    for(i = 0 ; i < dim; ++i, ++lin)
    {
        printf("%c  ",lin);
        for(j = 0 ; j<dim; ++j )
        {
            printf("%c ",t[i][j]);
            
        }
        printf("\n");
    }
    printf("\n");
}
void inicia_elmeu_taulell(char*** t,int dim)
{
    
    printf("Va a diseñar su tablero\n");
    int i , j,x,y;
    for(i = 0 ; i < dim ; ++i){
        for(j = 0 ; j < dim ; ++j)
        {
            t[0][i][j] = CASELLA_AIGUA;
            t[1][i][j] = CASELLA_BUIDA;
        }
    }
    char dir;
    for(i = 0 ;i<4;++i)
    {
        printf("Introduzca la posicion del submarino numero %d como: x ( espacio ) y \n",i+1);
        
        scanf("%d%d",&x,&y);
        x--;
        y--;
        if(x<dim && y<dim && x>=0 && y>=0 && !cercapos(x,y,t)){
            t[1][x][y] = CASELLA_VAIXELL;
            printf("Barco colocado\n");
        }else
        {
            printf("No se puede colocar el barco en esa posición\n");
            i--;
        }
        imp_tab(t[1],dim);
    }
    for(i = 0 ; i < 3;++i)
    {
        printf("Introduzca la posicion superior izquierda del dragamines numero %d como: x ( espacio ) y \n",i+1);
        scanf("%d %d",&x,&y);
        x--;
        y--;
        printf("Introduzca la dirección (h/v)\n");
        scanf("\n%c",&dir);
        if(dir == 'h' && x < dim && y+1 < dim && x >= 0 && y>= 0 && !cercapos(x,y,t,dim) && !cercapos(x,y+1,t,dim))
        {
            t[1][x][y] = CASELLA_VAIXELL;
            t[1][x][y+1] = CASELLA_VAIXELL;
        }else 
        if(dir == 'v' && x+1 < dim && y < dim && x >= 0 && y>= 0 && !cercapos(x,y,t,dim) && !cercapos(x+1,y,t,dim))
        {
            t[1][x+1][y] = CASELLA_VAIXELL;
            t[1][x][y] = CASELLA_VAIXELL;
        }else
        {
            printf("La configuracion no es valida o el barco esta demasiado cerca de otro\n");
            --i;
        }
        imp_tab(t[1],dim);
    }
    for(i = 0 ; i < 2;++i)
    {
        printf("Introduzca la posicion superior izquierda del destructor numero %d como: x ( espacio ) y \n",i+1);
        scanf("%d %d",&x,&y);
        x--;
        y--;
        printf("Introduzca la dirección (h/v)\n");
        scanf("\n%c",&dir);
        if(dir == 'h' && x < dim && y+2 < dim && x >= 0 && y>= 0 && !cercapos(x,y,t,dim) && !cercapos(x,y+1,t,dim) && !cercapos(x,y+2,t,dim))
        {
            t[1][x][y] = CASELLA_VAIXELL;
            t[1][x][y+1] = CASELLA_VAIXELL;
            t[1][x][y+2] = CASELLA_VAIXELL;
        }else 
        if(dir == 'v' && x+2 < dim && y < dim && x >= 0 && y>= 0 && !cercapos(x,y,t,dim) && !cercapos(x+1,y,t,dim) && !cercapos(x+2,y,t,dim))
        {
            t[1][x+1][y] = CASELLA_VAIXELL;
            t[1][x+2][y] = CASELLA_VAIXELL;
            t[1][x][y] = CASELLA_VAIXELL;
        }else
        {
            printf("La configuracion no es valida o el barco esta demasiado cerca de otro\n");
            --i;
        }
        imp_tab(t[1],dim);
    }
    for(i = 0 ; i < 1;++i)
    {
        printf("Introduzca la posicion superior izquierda del portaaviones numero %d como: x ( espacio ) y \n",i+1);
        scanf("%d %d",&x,&y);
        x--;
        y--;
        printf("Introduzca la dirección (h/v)\n");
        scanf("\n%c",&dir);
        if(dir == 'h' && x < dim && y+3 < dim && x >= 0 && y>= 0 && !cercapos(x,y,t,dim) && !cercapos(x,y+1,t,dim) && !cercapos(x,y+2,t,dim) && !cercapos(x,y+3,t,dim))
        {
            t[1][x][y] = CASELLA_VAIXELL;
            t[1][x][y+1] = CASELLA_VAIXELL;
            t[1][x][y+2] = CASELLA_VAIXELL;
            t[1][x][y+3] = CASELLA_VAIXELL;
        }else 
        if(dir == 'v' && x+3 < dim && y < dim && x >= 0 && y>= 0 && !cercapos(x,y,t,dim) && !cercapos(x+1,y,t,dim) && !cercapos(x+2,y,t,dim) && !cercapos(x+3,y,t,dim))
        {
            t[1][x+1][y] = CASELLA_VAIXELL;
            t[1][x+3][y] = CASELLA_VAIXELL;
            t[1][x+2][y] = CASELLA_VAIXELL;
            t[1][x][y] = CASELLA_VAIXELL;
        }else
        {
            printf("La configuracion no es valida o el barco esta demasiado cerca de otro\n");
            --i;
        }
        imp_tab(t[1],dim);
    }
}
int cercapos(int x , int y , char*** t,int dim){//saber si al rededor de una posicion hay un barco     ERROR NO FUNCIONA BIEN
    bool b = false;
    if(x>0)
        b = b || (t[1][x-1][y] == CASELLA_VAIXELL);
    if(x < dim-1)
        b = b || (t[1][x+1][y] == CASELLA_VAIXELL);
    if(y>0)
        b = b || (t[1][x][y-1] == CASELLA_VAIXELL);
    if(y < dim-1)
        b = b || (t[1][x][y+1] == CASELLA_VAIXELL);
    
    return (t[1][x][y] == CASELLA_VAIXELL)||b;
}
void inicia_taulell_fix(char*** t,int dim)//inicializa los dos tableros de un jugador a . y ?
{
    int i,j;
    for(i = 0 ; i < dim ; ++i){
        for(j = 0 ; j < dim ; ++j)
        {
            t[0][i][j] = CASELLA_AIGUA;
            t[1][i][j] = CASELLA_BUIDA;
        }
    }
    //SUBMARINOS
    t[1][0][0] = CASELLA_VAIXELL;
    t[1][2][2] = CASELLA_VAIXELL;
    t[1][4][4] = CASELLA_VAIXELL;
    t[1][8][8] = CASELLA_VAIXELL;
    //Dragamines
    t[1][0][3] = CASELLA_VAIXELL;
    t[1][0][4] = CASELLA_VAIXELL;
    t[1][5][0] = CASELLA_VAIXELL;
    t[1][6][0] = CASELLA_VAIXELL;
    t[1][7][5] = CASELLA_VAIXELL;
    t[1][7][6] = CASELLA_VAIXELL;
    //Destructor
    t[1][2][4] = CASELLA_VAIXELL;
    t[1][2][5] = CASELLA_VAIXELL;
    t[1][2][6] = CASELLA_VAIXELL;
    t[1][1][dim-1] = CASELLA_VAIXELL;
    t[1][2][dim-1] = CASELLA_VAIXELL;
    t[1][3][dim-1] = CASELLA_VAIXELL;
    //Portaavions
    t[1][dim-1][0] = CASELLA_VAIXELL;
    t[1][dim-1][1] = CASELLA_VAIXELL;
    t[1][dim-1][2] = CASELLA_VAIXELL;
    t[1][dim-1][3] = CASELLA_VAIXELL;
    
    imp_tab(t[1],dim);
}
int main(int argc, char** argv) {
    int opc=0,len,players; // len longitud lateral de la tabla
    char ***p1,***p2;//Tableros para player 1 y 2
                     //primer indice tablero tuyo = 0 , tablero de bombas lanzadas = 1
                     //las otras dos dimensiones son el tablero
    while(opc != 4)
    {
        printf("---------MENU----------\n\n");
        printf("1. Crear un nou joc \n");
        printf("2. Carregar un joc emmagatzemat\n");
        printf("3. Veure podium\n");
        printf("4. Sortir\n");
        scanf("%d", &opc);
        switch(opc)
        {
            case 1:
            {
                printf("Introduzca la medida de la longitud de uno de los lados del tablero:\n");
                scanf("%d",&len);
                p1 = (char***)malloc(2*sizeof(char**));
                p2 = (char***)malloc(2*sizeof(char**));
                int i;
                for(i = 0 ; i < 2 ; ++i)
                {
                    p1[i] = (char**)malloc(len*sizeof(char*));
                    p2[i] = (char**)malloc(len*sizeof(char*));
                }
                for(i = 0 ; i < len ; ++i)
                {
                    p1[0][i] = (char *)malloc(len*sizeof(char));
                    p1[1][i] = (char *)malloc(len*sizeof(char));
                    p2[0][i] = (char *)malloc(len*sizeof(char));
                    p2[1][i] = (char *)malloc(len*sizeof(char));
                }
                //inicia_taulell_fix(p1,len);
                printf("Introduzca el numero de jugadores\n");
                scanf("%d",&players);
                
                switch (players){
                    case 0:
                        break;
                    case 1:
                    {
                        inicia_elmeu_taulell(p1,len);
                        imp_tab(p1[1],len);
                        break;
                    }
                    case 2:
                        break;

                }
            }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
        }

    }
    return (EXIT_SUCCESS);
}