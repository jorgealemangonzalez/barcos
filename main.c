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
void inicia_elmeu_taulell(char*** t,int dim)//t 3 dimensiones: 1ª 0-tablero disparos 1- tablero propio 2ªy3ª fila y columna
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
        if(x<dim && y<dim && x>=0 && y>=0 && t[0][x][y] != CASELLA_VAIXELL && !cercapos(x,y,t,dim)){
            t[0][x][y] = CASELLA_VAIXELL;
            printf("Barco colocado\n");
        }else
        {
            printf("No se puede colocar el barco en esa posición\n");
            i--;
        }
        imp_tab(t[0],dim);
    }
    for(i = 0 ; i < 3;++i)
    {
        printf("Introduzca la posicion superior izquierda del dragamines numero %d como: x ( espacio ) y \n",i+1);
        scanf("%d %d",&x,&y);
        x--;
        y--;
        printf("Introduzca la dirección (h/v)\n");
        scanf("\n%c",&dir);
        if(dir == 'h' && x < dim && y+1 < dim && t[0][x][y] != CASELLA_VAIXELL && x >= 0 && y>= 0 && !cercapos(x,y,t,dim) && !cercapos(x,y+1,t,dim))
        {
            t[0][x][y] = CASELLA_VAIXELL;
            t[0][x][y+1] = CASELLA_VAIXELL;
        }else 
        if(dir == 'v' && x+1 < dim && y < dim && t[0][x][y] != CASELLA_VAIXELL && x >= 0 && y>= 0 && !cercapos(x,y,t,dim) && !cercapos(x+1,y,t,dim))
        {
            t[0][x+1][y] = CASELLA_VAIXELL;
            t[0][x][y] = CASELLA_VAIXELL;
        }else
        {
            printf("La configuracion no es valida o el barco esta demasiado cerca de otro\n");
            --i;
        }
        imp_tab(t[0],dim);
    }
    for(i = 0 ; i < 2;++i)
    {
        printf("Introduzca la posicion superior izquierda del destructor numero %d como: x ( espacio ) y \n",i+1);
        scanf("%d %d",&x,&y);
        x--;
        y--;
        printf("Introduzca la dirección (h/v)\n");
        scanf("\n%c",&dir);
        if(dir == 'h' && x < dim && y+2 < dim && t[0][x][y] != CASELLA_VAIXELL && x >= 0 && y>= 0 && !cercapos(x,y,t,dim) && !cercapos(x,y+1,t,dim) && !cercapos(x,y+2,t,dim))
        {
            t[0][x][y] = CASELLA_VAIXELL;
            t[0][x][y+1] = CASELLA_VAIXELL;
            t[0][x][y+2] = CASELLA_VAIXELL;
        }else 
        if(dir == 'v' && x+2 < dim && y < dim && t[0][x][y] != CASELLA_VAIXELL && x >= 0 && y>= 0 && !cercapos(x,y,t,dim) && !cercapos(x+1,y,t,dim) && !cercapos(x+2,y,t,dim))
        {
            t[0][x+1][y] = CASELLA_VAIXELL;
            t[0][x+2][y] = CASELLA_VAIXELL;
            t[0][x][y] = CASELLA_VAIXELL;
        }else
        {
            printf("La configuracion no es valida o el barco esta demasiado cerca de otro\n");
            --i;
        }
        imp_tab(t[0],dim);
    }
    for(i = 0 ; i < 1;++i)
    {
        printf("Introduzca la posicion superior izquierda del portaaviones numero %d como: x ( espacio ) y \n",i+1);
        scanf("%d %d",&x,&y);
        x--;
        y--;
        printf("Introduzca la dirección (h/v)\n");
        scanf("\n%c",&dir);
        if(dir == 'h' && x < dim && y+3 < dim && x >= 0 && y>= 0 && t[0][x][y] != CASELLA_VAIXELL && !cercapos(x,y,t,dim) && !cercapos(x,y+1,t,dim) && !cercapos(x,y+2,t,dim) && !cercapos(x,y+3,t,dim))
        {
            t[0][x][y] = CASELLA_VAIXELL;
            t[0][x][y+1] = CASELLA_VAIXELL;
            t[0][x][y+2] = CASELLA_VAIXELL;
            t[0][x][y+3] = CASELLA_VAIXELL;
        }else 
        if(dir == 'v' && x+3 < dim && y < dim && x >= 0 && y>= 0 && t[0][x][y] != CASELLA_VAIXELL && !cercapos(x,y,t,dim) && !cercapos(x+1,y,t,dim) && !cercapos(x+2,y,t,dim) && !cercapos(x+3,y,t,dim))
        {
            t[0][x+1][y] = CASELLA_VAIXELL;
            t[0][x+3][y] = CASELLA_VAIXELL;
            t[0][x+2][y] = CASELLA_VAIXELL;
            t[0][x][y] = CASELLA_VAIXELL;
        }else
        {
            printf("La configuracion no es valida o el barco esta demasiado cerca de otro\n");
            --i;
        }
        imp_tab(t[0],dim);
    }
}
int cercapos(int x , int y , char*** t,int dim){//saber si al rededor de una posicion hay un barco y donde esta 
    int pos = 0;
    if(x>0 && (t[0][x-1][y] == CASELLA_VAIXELL) )
        pos = ARRIBA;
    if(x < dim-1 && (t[0][x+1][y] == CASELLA_VAIXELL))
        pos = ABAJO;
    if(y>0 && (t[0][x][y-1] == CASELLA_VAIXELL))
        pos = IZQUIERDA;
    if(y < dim-1 && (t[0][x][y+1] == CASELLA_VAIXELL))
        pos = DERECHA;
    
    //printf("%d %d %d %d %d",y,dim,b,x,b || (t[0][x][y+1] == CASELLA_VAIXELL));
    return pos;
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
    t[0][0][0] = CASELLA_VAIXELL;
    t[0][2][2] = CASELLA_VAIXELL;
    t[0][4][4] = CASELLA_VAIXELL;
    t[0][8][8] = CASELLA_VAIXELL;
    //Dragamines
    t[0][0][3] = CASELLA_VAIXELL;
    t[0][0][4] = CASELLA_VAIXELL;
    t[0][5][0] = CASELLA_VAIXELL;
    t[0][6][0] = CASELLA_VAIXELL;
    t[0][7][5] = CASELLA_VAIXELL;
    t[0][7][6] = CASELLA_VAIXELL;
    //Destructor
    t[0][2][4] = CASELLA_VAIXELL;
    t[0][2][5] = CASELLA_VAIXELL;
    t[0][2][6] = CASELLA_VAIXELL;
    t[0][1][dim-1] = CASELLA_VAIXELL;
    t[0][2][dim-1] = CASELLA_VAIXELL;
    t[0][3][dim-1] = CASELLA_VAIXELL;
    //Portaavions
    t[0][dim-1][0] = CASELLA_VAIXELL;
    t[0][dim-1][1] = CASELLA_VAIXELL;
    t[0][dim-1][2] = CASELLA_VAIXELL;
    t[0][dim-1][3] = CASELLA_VAIXELL;
    
    imp_tab(t[0],dim);
}
int dispara(char fila, int col, char*** t, int dim)
{
    int f = (int)(fila)-(int)('A');
    if(t[0][f][col] == CASELLA_VAIXELL_TOCAT || t[0][f][col] ==  CASELLA_AIGUA_TOCADA) //Para esto le tenemos que pasar el tablero tambien del que esta tirando , ahora mismo esta mal
        return REPETIT;
    else if(t[0][f][col] == CASELLA_AIGUA){
        return AIGUA;
    }else
        if(t[0][f][col] == CASELLA_VAIXELL)
        {
            int ptr;
            int cerca = cercapos(f,col,t,dim);
            if(cerca == IZQUIERDA || cerca == DERECHA)
            {
                bool alive = false;  // Era el ultimo trozo por matar del barco ?

                for(ptr  = col-1;ptr >= 0 && !(t[0][f][ptr]==CASELLA_AIGUA) && !alive;--ptr)
                {
                    if(t[0][f][ptr] == CASELLA_VAIXELL && t[0][f][ptr] != CASELLA_VAIXELL_TOCAT)
                        alive = true;
                }
                for(ptr = col+1; ptr < dim && !(t[0][f][ptr] == CASELLA_AIGUA) && !alive; ++ptr)
                {
                    if(t[0][f][ptr] == CASELLA_VAIXELL && t[0][f][ptr] != CASELLA_VAIXELL_TOCAT)
                        alive = true;
                }
                if(alive){
                    return TOCAT;
                }else   return  ENFONSAT;
                
            }
            else
            { // CASO ARRIBA Y ABAJO Y TAMBIEN CUANDO EL BARCO ES DE SOLO UNA CASILLA
                bool alive = false;  // El barco seguira vivo ?
                
                for(ptr  = f - 1;ptr >= 0 && !(t[0][ptr][col]==CASELLA_AIGUA) && !alive;--ptr)
                {
                    if(t[0][ptr][col] == CASELLA_VAIXELL && t[0][ptr][col] != CASELLA_VAIXELL_TOCAT)
                        alive = true;
                }
                for(ptr = f+1; ptr < dim && !(t[0][ptr][col] == CASELLA_AIGUA) && !alive; ++ptr)
                {
                    if(t[0][ptr][col] == CASELLA_VAIXELL && t[0][ptr][col] != CASELLA_VAIXELL_TOCAT)
                        alive = true;
                }
                if(alive){
                    return TOCAT;
                }else   return  ENFONSAT;
               
            }
        }else return ERROR;
}
int main(int argc, char** argv) {
    srand(time(NULL)); // Para los numeros aleatorios
    int opc=0,dim = 0,players; // dim longitud lateral de la tabla
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
                while(dim < 8 || dim > 10){
                    printf("Introduzca la medida de la longitud de uno de los lados del tablero:\n");
                    scanf("%d",&dim);
                    if(dim < 8 || dim > 10)printf("Dimension no valida\n");
                }
                
                //Habrá que tener en cuenta si ya hay un juego a mitad
                
                p1 = (char***)malloc(2*sizeof(char**));
                p2 = (char***)malloc(2*sizeof(char**));
                int i;
                for(i = 0 ; i < 2 ; ++i)
                {
                    p1[i] = (char**)malloc(dim*sizeof(char*));
                    p2[i] = (char**)malloc(dim*sizeof(char*));
                }
                for(i = 0 ; i < dim ; ++i)
                {
                    p1[0][i] = (char *)malloc(dim*sizeof(char));
                    p1[1][i] = (char *)malloc(dim*sizeof(char));
                    p2[0][i] = (char *)malloc(dim*sizeof(char));
                    p2[1][i] = (char *)malloc(dim*sizeof(char));
                }
                //inicia_taulell_fix(p1,dim);
                printf("Introduzca el numero de jugadores\n");
                scanf("%d",&players);
                
                switch (players){
                    case 0:
                        break;
                    case 1:
                    {
                        //printf("LEN: %d\n",dim);
                        //inicia_elmeu_taulell(p1,dim); // YA FUNCIONA COMENTADO PARA NO TENER CREARLO CADA VEZ AL PROBAR LAS SIGUIENTES COSAS
                        inicia_taulell_fix(p1,dim);
                        inicia_taulell_fix(p2,dim);
                        
                        int turn = 1,points1 = 0, points2 = 0,BA1 = 10,BA2 = 10;//Turno del jugador nº , Puntuacion de jugador 1(suma de resultados de lanzamientos) , puntuacion jugador 2 , Barcos Activos jugador 1 , Barcos Activos jugador 2
                        int L1 = 0, L2 = 0;//lanzamientos del jugador 1 y del jugador 2
                        char f;//fila
                        int c ; //columna
                        int intellif=-1,intellic=-1,dir=-1; // Memoria para tiradas de la maquina dir vendra dado por los enumerandos de posicion según donde fue la posocion anterior tocada
                        while(BA1 && BA2)//Mientras haya barcos activos de los dos
                        {
                            //A JUGAR
                            if(turn == 1){
                                printf("-----------------¡¡ Es tu turno !!-----------------\n\n");
                                imp_tab(p1[1],dim);
                                f = 0;
                                while(!(f>='A' &&  f < 'A'+dim))
                                {
                                    printf("Fila donde quiere lanzar la bomba\n");
                                    scanf("\n%c",&f);
                                    if(!(f>='A' && f < 'A'+dim))
                                        printf("Fila fuera de rango\n");
                                }
                                c = -1;
                                while(!(c > 0 && c <= dim))
                                {
                                    printf("Columna donde quiere lanzar la bomba\n");
                                    scanf("%d",&c);
                                    //printf("C:  %d\n",c);
                                    //printf("HOLA\n");
                                    //ESTO SI SE IMPRIME, ¿ PORQUE DA RUN FAILED ? , DESCARGAR CYWIN DEBUGGER
                                    if(!(c > 0 && c <= dim))
                                        printf("Columna fuera de rango\n");
                                    
                                }
                                L1++;
                                c--;
                                int result = dispara(f,c,p2,dim);
                                if(result == ERROR)
                                    printf("Ha habido un error en el lanzamiento\n");
                                else
                                    points1 += result-1;
                                switch(result){
                                    case REPETIT:
                                    {
                                        printf("Bomba repetida , se te restara 1 punto\n");
                                        turn = 2;
                                        break;
                                    }
                                    case TOCAT:{
                                        printf("Barco tocado, puedes volver a tirar \n");
                                        p1[1][f-'A'][c] = CASELLA_VAIXELL;
                                        p2[0][f-'A'][c] = CASELLA_VAIXELL_TOCAT;
                                        break;
                                    }
                                    case ENFONSAT:{
                                        printf("BARCO HUNDIDO !!! , puedes volver a tirar\n");
                                        p1[1][f-'A'][c] = CASELLA_VAIXELL;
                                        p2[0][f-'A'][c] = CASELLA_VAIXELL_TOCAT;
                                        BA2--;
                                        break;
                                    }
                                    case AIGUA:{
                                        printf("Agua ! \n");
                                        p1[1][f-'A'][c] = CASELLA_AIGUA;
                                        p2[0][f-'A'][c] = CASELLA_AIGUA_TOCADA;
                                        turn = 2;
                                        break;
                                    }
                                }
                            }else //LE TOCA A LA MAQUINA
                            {
                                //INTELIGENCIA DE LA MAQUINA:
                                //Tira una bomba en una casilla aleatoria que no sea agua
                                //Si acierta tira una bomba a una contigua que no haya sido disparada ya
                                int ran; // numero aleatorio usado para las tiradas NO "Inteligentes"
                                         // Usaremos la función rand()para generar un nº aleatorio y el módulo para acotarlo en nuestro rango
                                printf("-----------------¡¡ Turno de la maquina !!-----------------\n\n");
                                
                                //ESTO SI NO HAY GUARDADA NINGUNA INFORMACION DE LA TIRADA ANTERIOR
                                int f=intellif , c=intellic ;//Tirada inteligente segun tirada anterior
                                
                                if(f == -1)
                                    f= rand()%dim , c=rand()%dim ;
                                
                                while(p2[1][f][c] != CASELLA_BUIDA) //Mientras no encuentre una casilla donde todavia no haya tirado 
                                    f= rand()%dim , c=rand()%dim ;
                                L1++;
                                printf("%d",f);
                                int result = dispara((char)(f)+'A',c,p1,dim);
                                
                                if(result == ERROR)
                                    printf("Ha habido un error en el lanzamiento\n");
                                else
                                    points2 += result-1;
                                switch(result){
                                    case REPETIT:
                                    {
                                        printf("Bomba repetida , se te restara 1 punto\n");
                                        intellif=-1,intellic=-1,dir=-1; 
                                        turn = 2;
                                        break;
                                    }
                                    case TOCAT:{
                                        printf("Barco tocado, puedes volver a tirar \n");
                                        p2[1][f][c] = CASELLA_VAIXELL;
                                        p1[1][f][c] = CASELLA_VAIXELL_TOCAT;
                                        //si acertamos tiraremos bombas inteligentemente cerca
                                        if(dir == -1)//si todavia no sabemos la orientacion del barco
                                        {
                                            //predeterminadamente suponemos que el varco esta en vertical
                                            intellic = c;
                                            if(f > 0)
                                            {
                                                intellif = f-1;
                                                dir=ABAJO;
                                            }else {
                                                intellif = f+1;
                                                dir=ARRIBA;
                                            }
                                        }else
                                        {
                                            switch(dir){
                                                case ARRIBA:{
                                                    
                                                    if(f<dim){
                                                        intellif = f+1;
                                                    }else{
                                                        int i;
                                                        for(i=f-1;i>0&&p2[1][i][c]==CASELLA_VAIXELL;--i);
                                                        intellif = i;
                                                    }
                                                }
                                                case ABAJO:{
                                                    if(f>0){
                                                        intellif = f-1;
                                                    }else{
                                                        int i;
                                                        for(i=f+1;i<dim-1&&p2[1][i][c]==CASELLA_VAIXELL;++i);
                                                        intellif = i;
                                                    }
                                                }
                                                case DERECHA:{
                                                    if(c>0){
                                                        intellic = c-1;
                                                    }else{
                                                        int i;
                                                        for(i=c+1;i<dim-1&&p2[1][f][i]==CASELLA_VAIXELL;++i);
                                                        intellic = i;
                                                    }
                                                }
                                                case IZQUIERDA:{
                                                    if(c<dim){
                                                        intellic = c+1;
                                                    }else{
                                                        int i;
                                                        for(i=c-1;i>0&&p2[1][f][i]==CASELLA_VAIXELL;--i);
                                                        intellic = i;
                                                    }
                                                }
                                            }
                                        }
                                        break;
                                    }
                                    case ENFONSAT:{
                                        printf("BARCO HUNDIDO !!! , puedes volver a tirar\n");
                                        p2[1][f][c] = CASELLA_VAIXELL;
                                        p1[0][f][c] = CASELLA_VAIXELL_TOCAT;
                                        intellif=-1,intellic=-1,dir=-1; 
                                        BA1--;
                                        break;
                                    }
                                    case AIGUA:{
                                        printf("Agua ! \n");
                                        p2[1][f][c] = CASELLA_AIGUA;
                                        p1[1][f][c] = CASELLA_AIGUA_TOCADA;
                                        //DESAROOLLAR INTELIGENCIA DEL FALLO , DONE TIRAR AHORA VOY POR AQUI------------------------------------------------------------------------------------
                                        turn = 1;
                                        break;
                                    }
                                
                                }
                                
                                imp_tab(p2[1],dim);
                            }
                        }
                        
                        break;
                    }
                    case 2:
                        break;
                    default:
                    {
                        printf("Opcion no valida\n");
                        break;
                    }
                }
            }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                {
                    printf("Opcion no valida\n");
                    break;
                }
        }
    }
    
    free(p1);
    free(p2);
    return (EXIT_SUCCESS);
}