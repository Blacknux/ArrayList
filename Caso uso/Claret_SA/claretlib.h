//#ifndef __CLARETCOMMENT
//#define __CLARETCOMMENT
//typedef struct
//{
//    int userId;
//    char comment[1500];
//    int id;
//    int contLike;
//    int isEmpty;
//
//}Ecomment;
//#endif // __EARRAY
//
//
//#ifndef __CLARETUSER
//#define __CLARETUSER
//typedef struct
//{
//    char name[20];
//    char nick[20];
//    int userId;
//    char password[50];
//    char mail[50];
//    int isEmpty;
//} EUser;
//#endif // __EARRAY


#ifndef CLARETLIB_INCLUDED
#define CLARETLIB_INCLUDED
int getString(char *input,char* message,int intMin,int intMax );
int getLetters(char* input,char* message,char* eMessage,int lengthMin,int lengthMax);
int getNumbers(char* input,char* message,char* eMessage,int lengthMin,int lengthMax);
int getMail(char* input,char* messageInput,char* eMessage,int lengthMin,int lengthMax);
int getInt(int* input,char message[], char errorMessage[],int lowLimitRange,int hiLimitRange);
int firstUpperString(char* strToUpper, int cant);

void prueba(void);

/** ARRAY FUNCTIONS*/






#endif // CLARETLIB_INCLUDED
