/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : STRINGS.C                                              -
 - MODULE          : Module containing specific strings operations          -
 - PROGRAM         : Int2Txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.1.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01st July, 1998                                        -
 ----------------------------------------------------------------------------

*/
/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : strchange                                                  |
|  Description : Inserts a string inside other at a specified position      *
*  Input       : str_final --> output string                                |
|                str_inicial --> initial string                             *
*                str_in --> string to insert                                |
|                ponto --> point to insert                                  *
*  Return      : str_final --> output string                                |
|                                                                           *
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void strchange(char str_final[200],char str_inicial[200],char str_in[200],int ponto)
  {
  int i, ponto2, tamanho;

  for(i=0;i<ponto;i++)
    {
    str_final[i] = str_inicial[i];
    }
  str_final[ponto] = '\0';
  strcat(str_final,str_in);
  tamanho = strlen(str_final);
  ponto2 = tamanho;
  for(i=ponto-1+strlen(str_in); i<=strlen(str_inicial);i++)
    {
    str_final[ponto2] = str_inicial[i];
    ponto2++;
    }
  } // strchange

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : strfind                                                    |
|  Description : Finds a specified character in a string                    *
*  Input       : string --> string to search in                             |
|                caracter --> char to search                                *
*                inicio --> string to insert                                |
|  Return      : position on string where is char or -1 if not found        *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
int strfind(char *string, char caracter,int inicio)
  {
  int i;

  for(i=inicio;string[i];i++)
    {
    if (string[i] == caracter)
      return i;
    }
  return(-1);
  } // strfind

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : find_and_change                                            |
|  Description : Finds a specified character and change it for other        *
*  Input       : string_final --> output string                             |
|                string_inicial --> input string                            *
*                make --> change some characters                            |
|  Return      : string_final --> output string                             *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void find_and_change(char string_final[200], char string_inicial[200], int make)
  {
  int j;
  char tempstr[200];

  strcpy(tempstr,string_inicial);
  switch(make)
    {
    case 0 : {
             j = 0;
             while (j!=-1)
               {
               j = strfind(tempstr,',',j);
               if (j!=-1)
                 {
                 strchange(string_final, tempstr,"  ",j);
                 j = j + 2;
                 }
               strcpy(tempstr,string_final);
               }
             j = 0;
             while (j!=-1)
               {
               j = strfind(tempstr,':',j);
               if (j!=-1)
                 {
                 strchange(string_final, tempstr,"  ",j);
                 j = j + 2;
                 }
               strcpy(tempstr,string_final);
               }
             }
    case 1 : {
             j = 0;
             while (j!=-1)
               {
               j = strfind(tempstr,'@',j);
               if (j!=-1)
                 {
                 strchange(string_final, tempstr,"@@",j);
                 j = j + 2;
                 }
               strcpy(tempstr,string_final);
               }
             j = 0;
             while (j!=-1)
               {
               j = strfind(tempstr,'*',j);
               if (j!=-1)
                 {
                 strchange(string_final, tempstr,"o",j);
                 j = j + 2;
                 }
               strcpy(tempstr,string_final);
               }
             j = 0;
             while (j!=-1)
               {
               j = strfind(tempstr,'{',j);
               if (j!=-1)
                 {
                 strchange(string_final, tempstr,"@{",j);
                 j = j + 2;
                 }
               strcpy(tempstr,string_final);
               }
             j = 0;
             while (j!=-1)
               {
               j = strfind(tempstr,'}',j);
               if (j!=-1)
                 {
                 strchange(string_final, tempstr,"@}",j);
                 j = j + 2;
                 }
               strcpy(tempstr,string_final);
               }
             }
    } // switch
  } // find_and_change
