/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : CHAPT_12.C                                             -
 - MODULE          : Module containing "Chapter 12" processing              -
 - PROGRAM         : int2txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.1.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01st July, 1998                                        -
 ----------------------------------------------------------------------------

*/
void process_chapter_12()
{
  char buf[255];
  char tempstr[200];
  int j;

  // Check if source file is present in the int2txi.exe directory.
  // If not, just print some warnings. So, the user SHOULD copy that files
  // to the same directory.
  if (check_file("86BUGS.LST",0) == 0)
    {
    // Open source file
    sourcefile = fopen("86BUGS.LST","rt");
    // Create Temporary Files
    fprintf(stdout,"86BUGS.LST\n");
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
    }
    else fprintf(int2txi,"Not processed!!! 86BUGS.LST wasn't found on the processing");
    
}
