/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : FILES.C                                                -
 - MODULE          : Files module containing rotines for files operations   -
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
*  Rotine      : remove_temp_files()                                        |
|  Description : This rotine removes ALL temporary files                    *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void remove_temp_files()
  {
  remove("TEMPFILE.001");
  remove("TEMPFILE.002");
  remove("TEMPFILE.003");
  remove("TEMPFILE.004");
  remove("TEMPFILE.005");
  remove("TEMPFILE.006");
  remove("TEMPFILE.007");
  remove("TEMPFILE.008");
  remove("TEMPFILE.009");
  remove("TEMPFILE.010");
  remove("TEMPFILE.011");
  remove("TEMPFILE.012");
  remove("TEMPFILE.013");
  remove("TEMPFILE.014");
  remove("TEMPFILE.015");
  } // remove_temp_files
