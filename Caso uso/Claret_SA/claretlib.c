#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "claretlib.h"
#define TAM 100

/**
*
*\brief Solicita un string que sea solo letras
*\param char* input Puntero pasado por parametro donde guardar la cadena despues de validada
*\param char* message Mensaje de solicitud para la cadena
*\param int lengthMin Minimo de caracteres que debe poseer la cadena
*\param int lengthMax maximo de acaracteres que debe poseer la cadena
*\return int  0 si OK -1 si no se pudo realizar
*/

int getString(char *input,char* message,int intMin,int intMax )
{
    char auxChar[4096];
    int retorno=-1;

    if(input!=NULL&& intMin>=0)
    {
        printf("%s",message);
        setbuf(stdin,NULL);
        gets(auxChar);
        if(strlen(auxChar)<intMax &&strlen(auxChar)>intMin )
        {
            strcpy(input,auxChar);
            retorno=0;
        }
        else
        {
            if(strlen(auxChar)<intMin || strlen(auxChar)>intMax)
            {
                printf("Error en el largo de la cadena\n");
            }
//            if()
//            {
//                printf("muy larg@\n");
//            }

            //printf( "%s",errorMessage);
        }
    }
    return retorno;

}

/**
*
*\brief Solicita un string que sea solo letras
*\param char* input Puntero pasado por parametro donde guardar la cadena despues de validada
*\param char* messageInput Mensaje de solicitud
*\param char* eMessage Mensage de error
*\param int lengthMin Minimo de caracteres que debe poseer la cadena
*\param int lengthMax maximo de acaracteres que debe poseer la cadena
*\return int  0 si OK -1 si no se pudo realizar
*/

int getLetters(char* input,char* messageInput,char* eMessage,int lengthMin,int lengthMax)
{
    int retorno=0;
    int i;
    int getstFlag=0;
    int strleng;
    char auxChar[4096];


    if(input!=NULL && lengthMin>0)
    {
        setbuf(stdin,NULL);
        getstFlag=getString(auxChar,messageInput,lengthMin,lengthMax);
        strleng=strlen(auxChar);

        for(i=0; i<strleng; i++)
        {
            if(getstFlag==-1)
                break;
            if(/*(strleng>lengthMin)&&*/(auxChar[i]>='a'&& auxChar[i]<='z')||(auxChar[i]>='A'&&auxChar[i]<='Z')||auxChar[i]==' ')
            {

                input[i]=auxChar[i];


            }
            else
            {
                printf("%s",eMessage);
                retorno=-1;
                break;

            }

        }
    }



    return retorno;
}

/**
*
*\brief Solicita un string que sea solo numeros
*\param char* input Puntero pasado por parametro donde guardar la cadena despues de validada
*\param char* messageInput Mensaje de solicitud
*\param char* eMessage Mensage de error
*\param int lengthMin Minimo de caracteres que debe poseer la cadena
*\param int lengthMax maximo de acaracteres que debe poseer la cadena
*\return int  0 si OK -1 si no se pudo realizar
*/

int getNumbers(char* input,char* messageInput,char* eMessage,int lengthMin,int lengthMax)
{
    int retorno=-1;
    int i;
    int getstFlag=0;
    int strleng;
    char auxChar[4096];


    if(input!=NULL && lengthMin>0)
    {
        setbuf(stdin,NULL);
        getstFlag=getString(auxChar,messageInput,lengthMin,lengthMax);
        strleng=strlen(auxChar);

        for(i=0; i<strleng; i++)
        {
            if(getstFlag==-1)
                break;
            if(/*(strleng>lengthMin)&&*/(auxChar[i]>='0'&& auxChar[i]<='9'))
            {

                strcpy(input,auxChar);
                retorno=0;

            }
            else
            {
                printf("%s",eMessage);
                break;

            }

        }
    }
    return retorno;
}

/**
*
*\brief Solicita un string que sea un mail, validando el formato
*\param char* input Puntero pasado por parametro donde guardar la cadena despues de validada
*\param char* messageInput Mensaje de solicitud
*\param char* eMessage Mensage de error
*\param int lengthMin Minimo de caracteres que debe poseer la cadena
*\param int lengthMax maximo de acaracteres que debe poseer la cadena
*\return int  0 si OK -1 si no se pudo realizar
*/
int getMail(char* input,char* messageInput,char* eMessage,int lengthMin,int lengthMax)
{
    int retorno=-1;
    int i;
    int getstFlag=0;
    int strleng;
    int countAt=0;
    int countDot=0;
    char auxChar[4096];


    if(input!=NULL && lengthMin>0)
    {
        setbuf(stdin,NULL);
        getstFlag=getString(auxChar,messageInput,lengthMin,lengthMax);
        strleng=strlen(auxChar);

        for(i=0; i<strleng; i++)
        {
            if(getstFlag==-1)
            {
                break;
            }
            if(/*(strleng>lengthMin)&&*/(auxChar[i]>='0'&& auxChar[i]<='9')||(auxChar[i]>='a'&& auxChar[i]<='z')||(auxChar[i]>='A'&&auxChar[i]<='Z')||(auxChar[i]=='@'|| auxChar[i]=='.'))
            {
                strcpy(input,auxChar);
                if(auxChar[i]=='@')
                {
                    countAt++;
                }
                if(auxChar[i]=='.')
                {
                    countDot++;
                }
            }
            else
            {
                printf("%s",eMessage);
                break;
            }
        }// END FOR
        if(countAt==1&&countDot>=1)
        {
            retorno=0;
        }
        else
        {
            printf("%s",eMessage);
        }
    }
    return retorno;
}

/**
*
*\brief Solicita un string que sea un telefono
*\param char* input Puntero pasado por parametro donde guardar la cadena despues de validada
*\param char* messageInput Mensaje de solicitud
*\param char* eMessage Mensage de error
*\param int lengthMin Minimo de caracteres que debe poseer la cadena
*\param int lengthMax maximo de acaracteres que debe poseer la cadena
*\return int  0 si OK -1 si no se pudo realizar
*/

int getPhone(char* input,char* messageInput,char* eMessage,int lengthMin,int lengthMax)
{
    int retorno=-1;
    int i;
    int getstFlag=0;
    int strleng;
    int countSymbol=0;
    char auxChar[4096];


    if(input!=NULL && lengthMin>0)
    {
        setbuf(stdin,NULL);
        getstFlag=getString(auxChar,messageInput,lengthMin,lengthMax);
        strleng=strlen(auxChar);

        for(i=0; i<strleng; i++)
        {
            if(getstFlag==-1)
            {
                break;
            }
            if(/*(strleng>lengthMin)&&*/(auxChar[i]>='0'&& auxChar[i]<='9')||(auxChar[i]=='-'))
            {
                strcpy(input,auxChar);
                if(auxChar[i]=='-')
                {
                    countSymbol++;
                }

            }
            else
            {
                printf("%s",eMessage);
                break;
            }
        }// END FOR
        if(countSymbol==1)
        {
            retorno=0;
        }
        else
        {
            printf("%s",eMessage);
        }
    }
    return retorno;
}

/**
*
*\brief Solicita un string que sea solo letras
*\param char* input Puntero pasado por parametro donde guardar la cadena despues de validada
*\param char* message Mensaje de solicitud
*\param char* errorMessage Mensage de error
*\param int lengthMin Minimo de caracteres que debe poseer la cadena
*\param int lengthMax maximo de acaracteres que debe poseer la cadena
*\return int  0 si OK -1 si no se pudo realizar
*/

int getInt(int* input,char message[], char errorMessage[],int lowLimitRange,int hiLimitRange)
{
    char aux[4096];
    int retorno=-1;
    int intAux;

    printf("%s", message);
    setbuf(stdin,NULL);
    gets(aux);

    if ( strcmp(aux,"0\0")==0)
    {
        intAux = atoi(aux);
        retorno = 0;
        *input = intAux;

    }
    else
    {
        intAux = atoi(aux);
        if(intAux != 0)
        {
            if(intAux >= lowLimitRange && intAux <= hiLimitRange )
            {
                retorno = 0;
                *input = intAux;
            }
            else
            {
                printf("%s", errorMessage);
            }
        }
        else
        {
            printf("%s", errorMessage);
        }

    }



    return retorno;

}



/**
*\brief Convierte en mayuscula la primera letra de cada nombre incluyendo nombre compuestos.
*\param struc array a utilizar
*\param Largo del array
*\return Devuelve 0 si termino OK o -1 si no pudo realizar la tarea.
*/

//int firstUpper(EAvion* struc, int cant)
//{
//    int i;
//    int j;
//    int retorno = -1;
//
//
//    if(struc != NULL && cant > 0 )
//    {
//        for (i=0;i<cant;i++)
//        {
//            for(j=0;j<strlen(struc[i].name);j++)
//            {
//                if(0 == j || struc[i].name[j]==' ')
//                {
//                    struc[i].name[j]=toupper(struc[i].name[j]);
//
//                }
//                if(struc[i].name[j]==' ')
//                {
//                    struc[i].name[j+1]=toupper(struc[i].name[j+1]);
//
//                }
//
//
//            }
//        }
//        retorno=0;
//    }
//    return retorno;
//    }



//int findEmptyUser(EUser* struc,int cant, int value,int printFull)
//{
//    int i;
//    int retorno=-1;
//    if(struc!=NULL && cant>0)
//    {
//        for (i=0; i<cant; i++)
//        {
//            if(struc[i].isEmpty==value)
//            {
//                retorno=i;
//                break;
//            }
//        }
//        if (retorno==-1 && printFull==1)
//            printf("No hay lugar");
//    }
//    return retorno;
//
//}

//int findEmptyc(Ecomment* struc,int cant, int value,int printFull)
//{
//    int i;
//    int retorno=-1;
//    if(struc!=NULL && cant>0)
//    {
//        for (i=0; i<cant; i++)
//        {
//            if(struc[i].isEmpty==value)
//            {
//                retorno=i;
//                break;
//            }
//        }
//        if (retorno==-1 && printFull==1)
//            printf("No hay lugar");
//    }
//    return retorno;
//
//}
/**
*\brief Recibe una puntero a char y pone la primer letra en mayusculas
*\param char* strToUpper Cadena a ser modificada
*\param int cant Tamaño de la cadena para ser recorrida
*\return si pudo realizar la tarea devuelve 0 si no -1
*/


int firstUpperString(char* strToUpper, int cant)
{
    int i;
//    int j;
    int retorno = -1;

    if(strToUpper != NULL && cant > 0 )
    {
        for (i=0; i<cant; i++)
        {
            if(0 == i /*|| strToUpper[i][j]==' '*/)
            {
                strToUpper[i]=toupper(strToUpper[i]);
            }
//            else if(strToUpper[i]==' ')
//            {
//                strToUpper[i+1]=toupper(strToUpper[i+1]);
//            }
        }
        retorno=0;
    }
    return retorno;
}
