//Jugador2 => ordenador
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N_C 7
#define N_F 7

void retardo();
int rand(void);

main()
{
      //i y meteficha acumulan los valores correspondientes para cada elemento de la matrizin
int matrizin[N_F][N_C]; //Los algoritmos funcionan solo en matrices cuadradas
int matrizsim[N_F][N_C]; //Es la matriz simetrica de matrizin
int matrizfic[N_F][N_C]; 
int jugador = 1; //jugador 1: *,1  jugador 2: +,-1
char ficha;
int i = 0, j = 0, k = 0;
int meteficha = 0, valor = 0;
int cuentahor1 = 0, cuentahor2 = 0;
int cuatro1 = 0, cuatro2 = 0, cuatro0 = 0;
int inicdiagf = 0, inicdiagc = 0;
int fils = 0, cols = 0;
int cuentadiag1 = 0, auxfils = 0;
int cuentadiag2 = 0;
int auxcols = 0;
int cuentatablas = 0;
int metefichaaux = 0, mauxb = 0, mauxc = 0;
int mauxd = 0, mauxe = 0;
int meteficha2 = 0;
int ensayo = 1;
int cuentapillin = 0;
int iaux = 0;
int marca = 0;
int alea = 0;
int cuentagana = 0;
int cuatraya = 0;
int operacion = 0;
int seguro = 0;

for (i = 0; i < N_F; i++) //Deficion original de matrizin (todo ceros)
{
    for (j = 0; j < N_C; j++)
    {
    matrizin[i][j] = 0;    
    }    
} 

printf("\n\n\n\n\n\n\t\t\t Bienvenido a las CUATRO EN RAYA"
"\n\n\t\t\tPulsa cualquier tecla para comenzar"
"\n\n\t\t\t(Recomendado maximizar la pantalla)");
_getch();
system("cls");

do //Ppio. del do... while----------------------------------------------------------------------
{
if (jugador == 1)
{
ficha = '*';
valor = 1;
}
else
{
ficha = '+';
valor = -1;
}
     
   //JUGADOR 1 o 2

system("cls");

//printf("Juega el jugador %d...", jugador);

printf("\n\n");
for (i = 0; i < N_F; i++) //Imprime matriz exterior
{
    printf("    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");//71+
    for (k = 0; k < 6; k++)
    {
        printf("    ");
        for (j = 0; j < N_C; j++)
        {
            if (matrizin [i][j]== 0)
            printf("+         ");    
            else if (matrizin [i][j]== 1)
            printf("+*********");
            else
            printf("+OOOOOOOOO");
        }
    printf("+");    
    putchar('\n');
    }
} 
printf("    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");//71+ 

fflush(stdin);  
if (jugador == 1) 
{ 
   do
   {
   printf("\n\n\t\tPor favor, introduce tu ficha (%c) en una de"
   "\n\t\tlas 7 columnas del tablero. Para ello, pulsa"
   "\n\t\tla tecla correspondiente de 1 a 7  ", ficha);
   scanf("%d", &meteficha);
   --meteficha; // Asi va de 0 a N_C
   fflush(stdin);
   }
   while ((meteficha >= 7) || (meteficha == -1)); 

    while (matrizin[0][meteficha] != 0) //Advierte de q la columna esta llena
    {
    printf("\n\nEsta columna esta llena, prueba en otra\n"); 
    scanf("%d", &meteficha);  
    --meteficha;   
    }
    seguro = meteficha;
}
else //Juega el ordenador*********************************************************************
//********************************************************************************************
{                              
                                                                
              //Ataque simple por parte del ordenador-----------------------------------------

jugador = 2;
valor = -1;
              
for (metefichaaux = 0; metefichaaux < N_C; metefichaaux++) //Ppio for. Busco un metefichaaux ganador
{
    for (iaux = N_F - 1; iaux >= 0; --iaux) //Adapto matrizin a cada posible metefichaaux
    {
        if (matrizin[iaux][metefichaaux] == 0)
        {
        matrizin[iaux][metefichaaux] = valor; 
        break;
        }   
    } //Ya tenemos iaux y metefichaaux supuestos
    
    for (cols = 0; cols <= 3; cols++) //Comprueba amenaza simple horizontal
    {
        if ((matrizin[iaux][cols] == -1) && (matrizin[iaux][cols+1] == -1) && (matrizin[iaux][cols+2] == -1) 
        && (matrizin[iaux][cols+3] == -1))
        {
        cuatro1 = 1;
        break;                           
        }      
    } //Termina la comprobacion de amenaza simple horizontal------------------------------------
    
    if ((iaux <= 3) && (matrizin[iaux][metefichaaux] == -1) //Comprueba amenaza simple vertical
    && (matrizin[iaux+1][metefichaaux] == -1) && 
    (matrizin[iaux+2][metefichaaux] == -1) && (matrizin[iaux+3][metefichaaux] == -1))
    cuatro1 = 1; //Termina la comprobacion de amenaza simple vertical
    
    auxfils = 0; //Comienza la comprobacion de amenaza por diagonales
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;
for (auxfils = (N_F - 4); auxfils <= (N_F - 1); auxfils++) //hago 4 veces
{
    fils = auxfils;
    cols = 0;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = 0; k < (auxfils + 1); k++) //hago 4 veces, 5 veces, 6 y 7
    { 
            //printf("\nfils = %d, cols = %d", fils, cols);
            if (matrizin[fils][cols] == -1) //gana jugador 1
             {  
             cuentadiag1++; 
                  if (cuentadiag1 >= 4)
                  {
                  cuatro1 = 1;
                  printf("\n\n dcha campo1, jugador1");
                  break;
                  }
             }
             else
             cuentadiag1 = 0; 
             
    cols++;
    fils--;   
    }    
}      

//printf("\n\nCampo 2:\n"); 
auxcols = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;   
for (auxcols = (N_C - 4); auxcols > 0; auxcols--) //hago 3 veces
{
    fils = N_C - 1;
    cols = 4 - auxcols;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = (auxcols + 3); k > 0; k--) //hago 6 veces, 5 veces y 4
    {
    //printf("\nfils = %d, cols = %d", fils, cols);
    if (matrizin[fils][cols] == -1) //gana jugador 1
             {  
             cuentadiag1++; 
                  if (cuentadiag1 >= 4)
                  {
                  cuatro1 = 1;
                  printf("\n\n dcha campo2, jugador1");
                  break;
                  }
             }
             else
             cuentadiag1 = 0;  
             
    cols++;
    fils--;  
    }    
}
        
     //4 en raya (diagonal \)--------------------------------------------------------------

//printf("\n\nmatrizsim es asi:\n\n");           
for (fils = 0; fils < N_F; fils++)
{
    for (cols = 0; cols < N_F; cols++)
    {
    matrizsim[fils][cols] = matrizin[fils][3 - (cols - 3)];    
    //printf("%d ", matrizsim[fils][cols]);    
    }    
putchar('\n');    
}       

//printf("\n\nCampo 1:\n");
auxfils = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;
for (auxfils = (N_F - 4); auxfils <= (N_F - 1); auxfils++) //hago 4 veces
{
    fils = auxfils;
    cols = 0;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;    
    for (k = 0; k < (auxfils + 1); k++) //hago 4 veces, 5 veces, 6 y 7
    { 
            //printf("\nfils = %d, cols = %d", fils, cols);
            if (matrizsim[fils][cols] == -1) //gana jugador 1
             {  
             cuentadiag1++; 
                  if (cuentadiag1 >= 4)
                  {
                  cuatro1 = 1;
                  printf("\n\n izda campo1, jugador1");
                  break;
                  }
             }
             else
             cuentadiag1 = 0; 
             
    cols++;
    fils--;   
    }    
}

if (cuatro1 == 1) //Ordenador ha ganado
goto ganaord; 
    
matrizin[iaux][metefichaaux] = 0; //Dejo matrizin como si no hubiera pasado nada
                              
} //Fin del for ------------------------------------------------------------------------------           
              
                                                                                              
             //ALGORITMOS DE DEFENSA----------------------------------------------------------                                                                                

jugador = 1;
valor = 1;                                                                                                                                                             

             //Algoritmo ante amenaza simple--------------------------------------------------

for (metefichaaux = 0; metefichaaux < N_C; metefichaaux++) //Ppio del for
{//printf("for1");
//_getch();
    for (iaux = N_F - 1; iaux >= 0; --iaux) //Adapto matrizin a otro movimiento de jugador1
    {
        if (matrizin[iaux][metefichaaux] == 0)
        {
        matrizin[iaux][metefichaaux] = valor; 
        break;
        }   
    } //Ya tenemos iaux y metefichaaux artificiales. Jugador1 ha tirado 2 veces seguidas
    
    for (cols = 0; cols <= 3; cols++) //Comprueba amenaza simple horizontal
    {
        if ((matrizin[iaux][cols] == 1) && (matrizin[iaux][cols+1] == 1) && (matrizin[iaux][cols+2] == 1) 
        && (matrizin[iaux][cols+3] == 1))
        {
        cuatro1 = 1;
        break;                           
        } 

       
    } //Termina la comprobacion de amenaza simple horizontal
    
    //printf("\ncuentahor1 = %d\n", cuentahor1);
    //_getch();
    
    if ((iaux <= 3) && (matrizin[iaux][metefichaaux] == 1) //Comprueba amenaza simple vertical
    && (matrizin[iaux+1][metefichaaux] == 1) && 
    (matrizin[iaux+2][metefichaaux] == 1) && (matrizin[iaux+3][metefichaaux] == 1))
    cuatro1 = 1; //Termina la comprobacion de amenaza simple vertical
    
    auxfils = 0; //Comienza la comprobacion de amenaza por diagonales
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;
for (auxfils = (N_F - 4); auxfils <= (N_F - 1); auxfils++) //hago 4 veces
{
    fils = auxfils;
    cols = 0;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = 0; k < (auxfils + 1); k++) //hago 4 veces, 5 veces, 6 y 7
    { 
            //printf("\nfils = %d, cols = %d", fils, cols);
            if (matrizin[fils][cols] == 1) //gana jugador 1
             {  
             cuentadiag1++; 
                  if (cuentadiag1 >= 4)
                  {
                  cuatro1 = 1;
                  printf("\n\n dcha campo1, jugador1");
                  break;
                  }
             }
             else
             cuentadiag1 = 0; 
             
             if (matrizin[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n dcha campo1, jugador2");
                  break;
                  }
             }
             else
             cuentadiag2 = 0;
             
    cols++;
    fils--;   
    }    
}      

//printf("\n\nCampo 2:\n"); 
auxcols = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;   
for (auxcols = (N_C - 4); auxcols > 0; auxcols--) //hago 3 veces
{
    fils = N_C - 1;
    cols = 4 - auxcols;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = (auxcols + 3); k > 0; k--) //hago 6 veces, 5 veces y 4
    {
    //printf("\nfils = %d, cols = %d", fils, cols);
    if (matrizin[fils][cols] == 1) //gana jugador 1
             {  
             cuentadiag1++; 
                  if (cuentadiag1 >= 4)
                  {
                  cuatro1 = 1;
                  printf("\n\n dcha campo2, jugador1");
                  break;
                  }
             }
             else
             cuentadiag1 = 0;  
             
    if (matrizin[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n dcha campo2, jugador2");
                  break;
                  }
             }
             else
             cuentadiag2 = 0;
    cols++;
    fils--;  
    }    
}
        
     //4 en raya (diagonal \)--------------------------------------------------------------

//printf("\n\nmatrizsim es asi:\n\n");           
for (fils = 0; fils < N_F; fils++)
{
    for (cols = 0; cols < N_F; cols++)
    {
    matrizsim[fils][cols] = matrizin[fils][3 - (cols - 3)];    
    //printf("%d ", matrizsim[fils][cols]);    
    }    
putchar('\n');    
}       

//printf("\n\nCampo 1:\n");
auxfils = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;
for (auxfils = (N_F - 4); auxfils <= (N_F - 1); auxfils++) //hago 4 veces
{
    fils = auxfils;
    cols = 0;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;    
    for (k = 0; k < (auxfils + 1); k++) //hago 4 veces, 5 veces, 6 y 7
    { 
            //printf("\nfils = %d, cols = %d", fils, cols);
            if (matrizsim[fils][cols] == 1) //gana jugador 1
             {  
             cuentadiag1++; 
                  if (cuentadiag1 >= 4)
                  {
                  cuatro1 = 1;
                  printf("\n\n izda campo1, jugador1");
                  break;
                  }
             }
             else
             cuentadiag1 = 0; 
             
             if (matrizsim[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n izda campo1, jugador2");
                  break;
                  }
             }
             else
             cuentadiag2 = 0;
             
    cols++;
    fils--;   
    }    
} //Termina la comprobacion de diagonales. Fin de defensa a amenaza simple----------
    
    
    if (cuatro1 == 1) //Transicion-------------------------------------------------
    {
    meteficha = metefichaaux;
    matrizin[iaux][metefichaaux] = 0; //Dejo matrizin como si no hubiera pasado nada
    goto salida;
    //retardo();
    //_getch();
    break;  
    }  
    
matrizin[iaux][metefichaaux] = 0; //Dejo matrizin como si no hubiera pasado nada
} // Fin del for
    
    //iaux tiene valor q sirve solo cuando ha habido cuatro1 == 1
                                
    //Defensa para 000**00---------------------------------------------------------------------
operacion = 1;
       for (fils = 6; fils >= 0; fils--)
       {
           for (cols = 0; cols <= 3; cols++) 
           {
               if ((matrizin[fils][cols] == 0) && (matrizin[fils][cols+1] == 1)
               && (matrizin[fils][cols+2] == 1) && (matrizin[fils][cols+3] == 0))
               {
               metefichaaux = marca = cols;  
               goto salida;
               }
           }  
               
       }  //Fin de defensa para 000**00---------------------------------------------------------       
                  
//Defensa para 00*0*00---------------------------------------------------------------------
operacion = 2;    
       for (fils = 6; fils >= 0; fils--)
       {
           for (cols = 0; cols <= 2; cols++) 
           {
               if ((matrizin[fils][cols] == 0) && (matrizin[fils][cols+1] == 1)
               && (matrizin[fils][cols+2] == 0) && (matrizin[fils][cols+3] == 1)
               && (matrizin[fils][cols+4] == 0))
               {
               metefichaaux = marca = cols + 2;  
               goto salida;
               }
           }  
               
       }  //Fin de defensa para 00*0*00---------------------------------------------------------       
                                    
                  
     //Fin de movimiento del ordenador si no hay amenaza simple---------------------------------

     //ATAQUE (excepto ataque simple)-----------------------------------------------------------
operacion = 3;
//Igualo matrizfic a matrizin

for (iaux = 0; iaux < 7; iaux++)
{
   for (cols = 0; cols < 7; cols++) 
   {
   matrizfic[iaux][cols] = matrizin[iaux][cols];    
   } 
}



if (cuatro1 == 0) //Estrategia grado 1 (a, b, c)
{        
   for (metefichaaux = 0; metefichaaux < 7; metefichaaux++) //a (mueve ordenador)
   {
       valor = -1;
       for (iaux = N_F - 1; iaux >= 0; --iaux) //Adapto matrizin
       {
         if (matrizfic[iaux][metefichaaux] == 0)
         {
         matrizfic[iaux][metefichaaux] = valor; 
         break;
         }   
       } //Ya tenemos iaux y metefichaaux artificiales. Matrizin adapatada
       
       for (mauxb = 0; mauxb < 7; mauxb++) //b (mueve jugador)
       {
           valor = 1;
           for (iaux = N_F - 1; iaux >= 0; --iaux) //Adapto matrizin
           {
               if (matrizfic[iaux][mauxb] == 0)
               {
               matrizfic[iaux][mauxb] = valor; 
               break;
               }   
           } //Ya tenemos iaux y metefichaaux artificiales. Matrizin adapatada
       
           for (mauxc = 0; mauxc < 7; mauxc++)//c (mueve ordenador y puede ganar)
           {
               valor = -1;
               for (iaux = N_F - 1; iaux >= 0; --iaux) //Adapto matrizin
               {
                   if (matrizfic[iaux][mauxc] == 0)
                   {
                   matrizfic[iaux][mauxc] = valor; 
                   break;
                   }   
               } //Ya tenemos iaux y metefichaaux artificiales. Matrizin adapatada
           
               for (k = 0; k < N_C; k++)//4 en raya horizontal
               {
                   if (matrizfic[iaux][k] == -1) //gana jugador 2
                   {  
                   cuentahor2++; 
                   if (cuentahor2 >= 4)
                   goto salida;
                   else
                   {
                   cuentahor2 = 0;
                   }                
                   }
               }
               
               //4en raya vertical
               if ((i <= 3) && (matrizin[iaux][mauxc] == -1) && (matrizin[iaux+1][mauxc] == -1) && 
               (matrizin[iaux+2][mauxc] == -1) && (matrizin[iaux+3][mauxc] == -1))
               goto salida;
               
               //4 en raya en diagonal
               
auxfils = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;
for (auxfils = (N_F - 4); auxfils <= (N_F - 1); auxfils++) //hago 4 veces
{
    fils = auxfils;
    cols = 0;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = 0; k < (auxfils + 1); k++) //hago 4 veces, 5 veces, 6 y 7
    { 
             if (matrizin[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n dcha campo1, jugador2");
                  goto salida;
                  }
             }
             else
             cuentadiag2 = 0;
             
    cols++;
    fils--;   
    }    
}      

//printf("\n\nCampo 2:\n"); 
auxcols = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;   
for (auxcols = (N_C - 4); auxcols > 0; auxcols--) //hago 3 veces
{
    fils = N_C - 1;
    cols = 4 - auxcols;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = (auxcols + 3); k > 0; k--) //hago 6 veces, 5 veces y 4
    {
    if (matrizin[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n dcha campo2, jugador2");
                  goto salida;
                  }
             }
             else
             cuentadiag2 = 0;
    cols++;
    fils--;  
    }    
}
        
     //4 en raya (diagonal \)--------------------------------------------------------------

//printf("\n\nmatrizsim es asi:\n\n");           
for (fils = 0; fils < N_F; fils++)
{
    for (cols = 0; cols < N_F; cols++)
    {
    matrizsim[fils][cols] = matrizin[fils][3 - (cols - 3)];    
    //printf("%d ", matrizsim[fils][cols]);    
    }    
putchar('\n');    
}       

//printf("\n\nCampo 1:\n");
auxfils = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;
for (auxfils = (N_F - 4); auxfils <= (N_F - 1); auxfils++) //hago 4 veces
{
    fils = auxfils;
    cols = 0;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;    
    for (k = 0; k < (auxfils + 1); k++) //hago 4 veces, 5 veces, 6 y 7
    {        
             if (matrizsim[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n izda campo1, jugador2");
                  goto salida;
                  }
             }
             else
             cuentadiag2 = 0;
             
    cols++;
    fils--;   
    }    
}      

//printf("\n\nCampo 2:\n");  
auxcols = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;     
for (auxcols = (N_C - 4); auxcols > 0; auxcols--) //hago 3 veces
{
    fils = N_C - 1;
    cols = 4 - auxcols;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = (auxcols + 3); k > 0; k--) //hago 6 veces, 5 veces y 4
    {         
    if (matrizsim[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n izda campo1, jugador1");
                  goto salida;
                  }
             }
             else
             cuentadiag2 = 0;
    cols++;
    fils--;  
    }    
}
                    
           matrizfic[iaux][mauxc] = 0; //Dejo matrizin como si no hubiera pasado nada    
           }//fin del tercer for, c
       
       matrizfic[iaux][mauxb] = 0; //Dejo matrizin como si no hubiera pasado nada    
       }//fin del segundo for, b
    
   matrizfic[iaux][metefichaaux] = 0; //Dejo matrizin como si no hubiera pasado nada    
   }//fin del primer for, a


//Igualo matrizfic a matrizin

for (iaux = 0; iaux < 7; iaux++)
{
   for (cols = 0; cols < 7; cols++) 
   {
   matrizfic[iaux][cols] = matrizin[iaux][cols];    
   } 
}
             
            
}//Final de la estrategia grado 1----------------------------------------------------------------


if (cuatro1 == 0) //Inicio estrategia grado 2 (a,b,c,d,e)
{
for (metefichaaux = 0; metefichaaux < 7; metefichaaux++) //a (mueve ordenador)
   {
   valor = -1;
   cuentagana = 0;
       for (iaux = N_F - 1; iaux >= 0; --iaux) //Adapto matrizin
       {
         if (matrizfic[iaux][metefichaaux] == 0)
         {
         matrizfic[iaux][metefichaaux] = valor; 
         break;
         }   
       } //Ya tenemos iaux y metefichaaux artificiales. Matrizin adapatada
                                  
/*   for (mauxb = 0; mauxb < 7; mauxb++) //b (mueve jugador)
   {
       valor = 1;
       for (iaux = N_F - 1; iaux >= 0; --iaux) //Adapto matrizin
       {
         if (matrizfic[iaux][mauxb] == 0)
         {
         matrizfic[iaux][mauxb] = valor; 
         break;
         }   
       } //Ya tenemos iaux y metefichaaux artificiales. Matrizin adapatada
*/       
       for (mauxc = 0; mauxc < 7; mauxc++) //c (mueve ordenador)
       {
           valor = -1;
           cuentagana = 0;
           for (iaux = N_F - 1; iaux >= 0; --iaux) //Adapto matrizin
           {
               if (matrizfic[iaux][mauxc] == 0)
               {
               matrizfic[iaux][mauxc] = valor; 
               break;
               }   
           } //Ya tenemos iaux y metefichaaux artificiales. Matrizin adapatada
       
       for (mauxd = 0; mauxd < 7; mauxd++) //d (mueve jugador)
       {
           vuelta:
           valor = 1;
           for (iaux = N_F - 1; iaux >= 0; --iaux) //Adapto matrizin
           {
               if (matrizfic[iaux][mauxd] == 0)
               {
               matrizfic[iaux][mauxd] = valor; 
               break;
               }   
           } //Ya tenemos iaux y metefichaaux artificiales. Matrizin adapatada
       
           for (mauxe = 0; mauxe < 7; mauxe++)//e (mueve ordenador y puede ganar)
           {
               valor = -1;
               for (iaux = N_F - 1; iaux >= 0; --iaux) //Adapto matrizin
               {
                   if (matrizfic[iaux][mauxe] == 0)
                   {
                   matrizfic[iaux][mauxe] = valor; 
                   break;
                   }   
               } //Ya tenemos iaux y metefichaaux artificiales. Matrizin adapatada
           
               for (k = 0; k < N_C; k++)//4 en raya horizontal
               {
                   if (matrizfic[iaux][k] == -1) //gana jugador 2
                   {  
                   cuentahor2++; 
                   if (cuentahor2 >= 4)
                   {
                   cuatraya = 1;
                   goto salida;
                   }
                   else
                   {
                   cuentahor2 = 0;
                   }                
                   }
               }
               
               //4en raya vertical
               if ((i <= 3) && (matrizin[iaux][mauxc] == -1) && (matrizin[iaux+1][mauxc] == -1) && 
               (matrizin[iaux+2][mauxc] == -1) && (matrizin[iaux+3][mauxc] == -1))
               {
               cuatraya = 1;
               goto salida;
               }
               
               //4 en raya en diagonal
               
auxfils = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;
for (auxfils = (N_F - 4); auxfils <= (N_F - 1); auxfils++) //hago 4 veces
{
    fils = auxfils;
    cols = 0;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = 0; k < (auxfils + 1); k++) //hago 4 veces, 5 veces, 6 y 7
    { 
             if (matrizin[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n dcha campo1, jugador2");
                  cuatraya = 1;
                  goto salida;
                  }
             }
             else
             cuentadiag2 = 0;
             
    cols++;
    fils--;   
    }    
}      

//printf("\n\nCampo 2:\n"); 
auxcols = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;   
for (auxcols = (N_C - 4); auxcols > 0; auxcols--) //hago 3 veces
{
    fils = N_C - 1;
    cols = 4 - auxcols;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = (auxcols + 3); k > 0; k--) //hago 6 veces, 5 veces y 4
    {
    if (matrizin[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n dcha campo2, jugador2");
                  cuatraya = 1;
                  goto salida;
                  }
             }
             else
             cuentadiag2 = 0;
    cols++;
    fils--;  
    }    
}
        
     //4 en raya (diagonal \)--------------------------------------------------------------

//printf("\n\nmatrizsim es asi:\n\n");           
for (fils = 0; fils < N_F; fils++)
{
    for (cols = 0; cols < N_F; cols++)
    {
    matrizsim[fils][cols] = matrizin[fils][3 - (cols - 3)];    
    //printf("%d ", matrizsim[fils][cols]);    
    }    
putchar('\n');    
}       

//printf("\n\nCampo 1:\n");
auxfils = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;
for (auxfils = (N_F - 4); auxfils <= (N_F - 1); auxfils++) //hago 4 veces
{
    fils = auxfils;
    cols = 0;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;    
    for (k = 0; k < (auxfils + 1); k++) //hago 4 veces, 5 veces, 6 y 7
    {        
             if (matrizsim[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n izda campo1, jugador2");
                  cuatraya = 1;
                  goto salida;
                  }
             }
             else
             cuentadiag2 = 0;
             
    cols++;
    fils--;   
    }    
}      

//printf("\n\nCampo 2:\n");  
auxcols = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;     
for (auxcols = (N_C - 4); auxcols > 0; auxcols--) //hago 3 veces
{
    fils = N_C - 1;
    cols = 4 - auxcols;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = (auxcols + 3); k > 0; k--) //hago 6 veces, 5 veces y 4
    {         
    if (matrizsim[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n izda campo1, jugador1");
                  cuatraya = 1;
                  goto salida;
                  }
             }
             else
             cuentadiag2 = 0;
    cols++;
    fils--;  
    }    
}
                    
           matrizfic[iaux][mauxe] = 0; //Dejo matrizin como si no hubiera pasado nada    
           }//fin del tercer for, c
       
       matrizfic[iaux][mauxd] = 0; //Dejo matrizin como si no hubiera pasado nada    
       }//fin del segundo for, b
    
   matrizfic[iaux][mauxc] = 0; //Dejo matrizin como si no hubiera pasado nada    
   }//fin del primer for, a

//matrizfic[iaux][mauxb] = 0; //Dejo matrizin como si no hubiera pasado nada    
//   }//fin del primer for, a
   
matrizfic[iaux][metefichaaux] = 0; //Dejo matrizin como si no hubiera pasado nada    
   }//fin del primer for, a
   
   
//Igualo matrizfic a matrizin

for (iaux = 0; iaux < 7; iaux++)
{
   for (cols = 0; cols < 7; cols++) 
   {
   matrizfic[iaux][cols] = matrizin[iaux][cols];    
   } 
}            
            
            
        
        
        
            











}//Fin estrategia grado 2





















     //Tablas entre jugador1 y ordenador
    

        if (matrizin[0][metefichaaux] != 0)
        {
            do
            {
            metefichaaux++;
                if (metefichaaux >= 7)
                metefichaaux = metefichaaux - 7;
                if (meteficha >= 14)
                goto tablas; 
            }while (matrizin[fils][metefichaaux] != 0);           
        }  
   
salida:
if (mauxd < 7)
{
cuentagana++; 
mauxd++;    

if ((cuentagana < 7) && (cuatraya == 1))
{
cuatraya = 0;      
goto vuelta;
}
}

if ((operacion == 3) && (cuentagana < 7))
{
    if ((ensayo <= 8) && (metefichaaux != marca)) //Pone la ficha encima de la de jugador1
   metefichaaux = seguro;                      
   else if (ensayo > 8) 
   {    
     alea = rand(); 

     if (alea <= 1638)
     alea = 0;
     else if (alea <= 6554)
     alea = 1;
     else if (alea <= 13107)
     alea = 2;
     else if (alea <= 19660)
     alea = 3;
     else if (alea <= 26213)
     alea = 4;
     else if (alea <= 30652)
     alea = 5;
     else 
     alea = 6;  
     
     metefichaaux = alea;  
   }          
}



cuatro1 = 0;  
jugador = 2;
valor = -1;
meteficha = metefichaaux;
i = iaux; //solo sirve si cuatro1 == 1
operacion = 0;
    
putchar('\a');    
    
    
 
}   //Termina de jugar el ordenador***********************************************************
//********************************************************************************************

    
//Solo necesito un valor para meteficha
    
for (i = N_F - 1; i >= 0; --i) //Adapto matrizin al nuevo movimiento
{
    if (matrizin[i][meteficha] == 0)
    {
    matrizin[i][meteficha] = valor; 
    break;
    }   
}    

        //i y meteficha son los valores de fila y columna del movim. actual, de jug1 o jug2

//meteficha = 0;

     //4 en raya (horizontal)--------------------------------------------------------------

for (k = 0; k < N_C; k++)
{
    if (matrizin[i][k] == 1) //gana jugador 1
    {  
    cuentahor1++; 
                  if (cuentahor1 >= 4)
                  cuatro1 = 1;
    }
    else
    cuentahor1 = 0;    
    
    if (matrizin[i][k] == -1) //gana jugador 2
    {  
    cuentahor2++; 
                  if (cuentahor2 >= 4)
                  cuatro2 = 1;
    }
    else
    cuentahor2 = 0;                
}

    //4 en raya (vertical)-------------------------------------------------------------------
    
//printf("\n\n   i = %d\n   meteficha = %d\n   matrizin = %d\n", i, meteficha, matrizin[i][meteficha]);
    
if ((i <= 3) && (matrizin[i][meteficha] == 1) && (matrizin[i+1][meteficha] == 1) && 
(matrizin[i+2][meteficha] == 1) && (matrizin[i+3][meteficha] == 1))
cuatro1 = 1;
else if ((i <= 3) && (matrizin[i][meteficha] == -1) && (matrizin[i+1][meteficha] == -1) && 
(matrizin[i+2][meteficha] == -1) && (matrizin[i+3][meteficha] == -1))
cuatro2 = 1;

        //4 en raya (diagonal /)--------------------------------------------------------------
        
//printf("\n\nCampo 1:\n");
auxfils = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;
for (auxfils = (N_F - 4); auxfils <= (N_F - 1); auxfils++) //hago 4 veces
{
    fils = auxfils;
    cols = 0;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = 0; k < (auxfils + 1); k++) //hago 4 veces, 5 veces, 6 y 7
    { 
            //printf("\nfils = %d, cols = %d", fils, cols);
            if (matrizin[fils][cols] == 1) //gana jugador 1
             {  
             cuentadiag1++; 
                  if (cuentadiag1 >= 4)
                  {
                  cuatro1 = 1;
                  printf("\n\n dcha campo1, jugador1");
                  break;
                  }
             }
             else
             cuentadiag1 = 0; 
             
             if (matrizin[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n dcha campo1, jugador2");
                  break;
                  }
             }
             else
             cuentadiag2 = 0;
             
    cols++;
    fils--;   
    }    
}      

//printf("\n\nCampo 2:\n"); 
auxcols = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;   
for (auxcols = (N_C - 4); auxcols > 0; auxcols--) //hago 3 veces
{
    fils = N_C - 1;
    cols = 4 - auxcols;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = (auxcols + 3); k > 0; k--) //hago 6 veces, 5 veces y 4
    {
    //printf("\nfils = %d, cols = %d", fils, cols);
    if (matrizin[fils][cols] == 1) //gana jugador 1
             {  
             cuentadiag1++; 
                  if (cuentadiag1 >= 4)
                  {
                  cuatro1 = 1;
                  printf("\n\n dcha campo2, jugador1");
                  break;
                  }
             }
             else
             cuentadiag1 = 0;  
             
    if (matrizin[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n dcha campo2, jugador2");
                  break;
                  }
             }
             else
             cuentadiag2 = 0;
    cols++;
    fils--;  
    }    
}
        
     //4 en raya (diagonal \)--------------------------------------------------------------

//printf("\n\nmatrizsim es asi:\n\n");           
for (fils = 0; fils < N_F; fils++)
{
    for (cols = 0; cols < N_F; cols++)
    {
    matrizsim[fils][cols] = matrizin[fils][3 - (cols - 3)];    
    //printf("%d ", matrizsim[fils][cols]);    
    }    
putchar('\n');    
}       

//printf("\n\nCampo 1:\n");
auxfils = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;
for (auxfils = (N_F - 4); auxfils <= (N_F - 1); auxfils++) //hago 4 veces
{
    fils = auxfils;
    cols = 0;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;    
    for (k = 0; k < (auxfils + 1); k++) //hago 4 veces, 5 veces, 6 y 7
    { 
            //printf("\nfils = %d, cols = %d", fils, cols);
            if (matrizsim[fils][cols] == 1) //gana jugador 1
             {  
             cuentadiag1++; 
                  if (cuentadiag1 >= 4)
                  {
                  cuatro1 = 1;
                  printf("\n\n izda campo1, jugador1");
                  break;
                  }
             }
             else
             cuentadiag1 = 0; 
             
             if (matrizsim[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n izda campo1, jugador2");
                  break;
                  }
             }
             else
             cuentadiag2 = 0;
             
    cols++;
    fils--;   
    }    
}      

//printf("\n\nCampo 2:\n");  
auxcols = 0;
k = 0;
cuentadiag1 = 0, cuentadiag2 = 0;
fils = 0;
cols = 0;     
for (auxcols = (N_C - 4); auxcols > 0; auxcols--) //hago 3 veces
{
    fils = N_C - 1;
    cols = 4 - auxcols;
    
    cuentadiag1 = 0;
    cuentadiag2 = 0;
    for (k = (auxcols + 3); k > 0; k--) //hago 6 veces, 5 veces y 4
    {
    //printf("\nfils = %d, cols = %d", fils, cols);
    if (matrizsim[fils][cols] == 1) //gana jugador 1
             {  
             cuentadiag1++; 
                  if (cuentadiag1 >= 4)
                  {
                  cuatro1 = 1;
                  printf("\n\n izda campo2, jugador1");
                  break;
                  }
             }
             else
             cuentadiag1 = 0;  
             
    if (matrizsim[fils][cols] == -1) //gana jugador 2
             {  
             cuentadiag2++; 
                  if (cuentadiag2 >= 4)
                  {
                  cuatro2 = 1;
                  printf("\n\n izda campo1, jugador1");
                  break;
                  }
             }
             else
             cuentadiag2 = 0;
    cols++;
    fils--;  
    }    
}

for (cols = 0; cols < N_C; cols++) //Termina en tablas----------------------------------------
{
    if (matrizin[0][cols] != 0)
    cuentatablas++;    
}
if (cuentatablas == N_C)
cuatro0 = 1;
cuentatablas = 0;

        // Se determina que jugador ha ganado-------------------------------------------------
        
if (cuatro1 == 1)
{
ganaord:
system("cls");
printf("\n\n\tFin de la partida.\n\n\t");
    if ((ensayo % 2) == 1)
    printf("Has ganado!\n");
    else
    printf("Has perdido!\n");
break;
}
else if (cuatro2 == 1)
{
printf("\n\n\n\n\tFin de la partida.\n\n\tHas perdido!\n");
break;
}
else tablas: if (cuatro0 == 1)
{
printf("\n\n\n\n\tHabeis quedado en tablas\n");
break;     
}

if (jugador == 1)
jugador = 2;
else
jugador = 1;

ensayo++;

}while (1); //Fin del do... while

printf("\n");
for (i = 0; i < N_F; i++) //Imprime matriz exterior
{
    printf("    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");//71+
    for (k = 0; k < 6; k++)
    {
        printf("    ");
        for (j = 0; j < N_C; j++)
        {
            if (matrizin [i][j]== 0)
            printf("+         ");    
            else if (matrizin [i][j]== 1)
            printf("+*********");
            else
            printf("+OOOOOOOOO");
        }
    printf("+");    
    putchar('\n');
    }
} 
printf("    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");//71+ 

printf("\n\n\n\t\t      Pulsa cualquier tecla para salir ");
_getch();




      
} //Fin del main-------------------------------------------------------------------------------

void retardo()
{
int avanza;
int primo;
int n;
int aver;     
while (avanza <= 50000)
      {
            while (avanza > n)
            {
                  if ((avanza % n != 0) && (avanza > n))
                  primo = 1;
                  else
                  {
                  primo = 0;
                  break;
                  }
                  n++;         
            }
            if ((primo == 1) && (avanza >= 49550))
            {
            aver = 1; //printf("\0");
            break;
            }           
      avanza++;
      n = 2;         
      }
}
