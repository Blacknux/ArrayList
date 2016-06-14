#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "claretlib.h"
#include "ArrayList.h"
#include "Employee.h"


eEmployee* loadEmployee(int* id);


int main()
{
    ArrayList* arrayListC=al_newArrayList();
    int id=arrayListC->size+1;
   int option;
   char continueDo='s';


   do
   {
       getInt(&option,"######CASO DE USO ARRAYLIST###\n\n1-Agregar un empleado\n2-Print Lista de empleados\n3- Delete \n4-Agregar usuario eligiendo el legajo\n10-Salir\noption:","Opcion no valida\n",1,10);
       switch(option)
       {
       case 1:
           al_add(arrayListC,(void*)loadEmployee(&id));
           acomodarIndices(arrayListC);

        break;
       case 2:
           PrintEmployees(arrayListC);
        break;
       case 3:
        deleteEmployee(arrayListC);
        acomodarIndices(arrayListC);
        break;
       case 4:
           insertEmployee(arrayListC,&id);
           acomodarIndices(arrayListC);

        break;

        case 10:
            continueDo='n';
        break;
        default:
        break;
       }


   }while(continueDo!='n');

    return 0;
}

eEmployee* newEmployee(int id, char name[],char lastName[],float salary)
{
    eEmployee* returnAux = NULL;
    eEmployee* pEmployee = malloc(sizeof(eEmployee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->salary = salary;
        pEmployee->isEmpty = 0;
        returnAux = pEmployee;
    }

    return returnAux;

}


eEmployee* loadEmployee(int* id)
{
    eEmployee* returnAux=NULL;
    char name[20];
    char lastName[20];
    float salary;

    if(getString(name,"Ingrese el nombre:",1,20)!=-1&&getString(lastName,"Ingrese apellido: ",1,20)!=-1)
    {
        printf("Ingrese el sueldo: ");
        scanf("%f",&salary);
        returnAux=newEmployee(id,name,lastName,salary);

    }
    return returnAux;

}

void printEmployee(eEmployee* employee)
{
    printf("\Numero de empleado:%d\nNombre:%s\nApellido:%s\nSuelod:%2.f\n",employee->id,employee->name,employee->lastName,employee->salary);
}

void PrintEmployees(ArrayList* list)
{
    int i;
    for(i=0;i<list->size;i++)
    {
        printEmployee(*((list->pElements)+i));
    }
}

int deleteEmployee(ArrayList* pList)
{
    int option;
    char continueDo='s';
    int indexAux;
    eEmployee* mostrar=NULL;
    do
    {
        system("cls");
        getInt(&option,"##DELETE##\n1-Dar de baja un empleado\n2-Dar de baja un empleado y mostrar datos eliminados\n3-Volver al menu principal\nOption:","",1,3);
        switch(option)
        {
        case 1:
            getInt(&indexAux,"ingrese el legajo del usuario a eliminar","Error usuario no existente",0,pList->size);
            pList->remove(pList,indexAux-1);
            printf("Usuario eliminado");
            break;
        case 2:
             getInt(&indexAux,"ingrese el legajo del usuario a eliminar","Error usuario no existente",0,pList->size);
            mostrar=(eEmployee*)pList->pop(pList,indexAux-1);
            printf("Usuario eliminado");
            printEmployee(mostrar);
            system("pause");
            break;
        case 3:
            continueDo='n';
            break;
        default:
            break;

        }

    }while(continueDo!='n');
}

void acomodarIndices(ArrayList* pList)
{
    int i;
    eEmployee* aux;
    for (i=0;i<pList->size;i++)
        {
            aux=*((pList->pElements)+i);
            aux->id=i+1;
        }
}


int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((eEmployee*)pEmployeeA)->salary > ((eEmployee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((eEmployee*)pEmployeeA)->salary < ((eEmployee*)pEmployeeB)->salary)
    {
        return -1;
    }
    return 0;


}

void insertEmployee(ArrayList* pList,int* id)
{
    int indexAux;

    getInt(&indexAux,"Ingrese el id con el que quiere forzar el ingreso del empleado: ","Error",0,pList->size);
    pList->push(pList,indexAux-1,loadEmployee(&id));


}
