/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : FILES.C                                                -
 - MODULE          : Files module containing rotines for files operations   -
 - PROGRAM         : Int2Txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.2.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01st September, 1998                                   -
 ----------------------------------------------------------------------------

*/
/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : check_file()                                               |
|  Description : This rotine says that a specified file doesn't exist       *
*  Input       : _fn --> The file we are checking for.                      |
|                stop --> if 1 exits, if 0 continue                         *
*  Return      : 0 -- if file exists                                        |
|                1 -- if file doesn't exist                                 *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
int check_file(char *_fn,int stop)
  {
  if (!__file_exists(_fn))
    {
    if (stop == 1)
      {
      printf("Warning : %s not found!!! CAN'T continue the processing...\n",_fn);
      exit(1);
      }
    printf("Warning : %s not found!!!\n",_fn);
    return(1);
    }
  return(0);
  } // check_file

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : copy_all_file()                                            |
|  Description : This rotine copies the source file exactly to target file  *
*  Input       : _fn --> The file we are checking for.                      |
|  Return      : ------                                                     *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void copy_all_file(char *_fn)
  {
  FILE *sourcefile;
  char buf[255];
  char tempstr[255];

  // Open source file
  sourcefile = fopen(_fn,"rt");
  rewind(sourcefile);
  fputs("@flushleft\n",int2txi);
  while ((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
    strcpy(tempstr,buf);
    find_and_change(buf,tempstr,1);
    fputs(buf, int2txi);
    }
  fputs("@end flushleft\n",int2txi);
  // Close source file
  fclose(sourcefile);
  } // copy_all_file
