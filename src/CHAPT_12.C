/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : CHAPT_12.C                                             -
 - MODULE          : Module containing "Chapter 12" processing              -
 - PROGRAM         : Int2TeX                                                -
 - DESCRIPTION     : This program converts Interrupt List to TeXInfo format -
 - VERSION         : 1.0                                                    -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01st June, 1998                                        -
 ----------------------------------------------------------------------------
 - HISTORIAL                                                                -    
 - ~~~~~~~~~                                                                -
 - April 06 1998   v.0.1  + First Version                                   -
 - June  01 1998   v.1.0  + First Release                                   -
 -                                                                          -
 ----------------------------------------------------------------------------

*/
void process_chapter_12()
{
  char buf[255];
  int j;

  rewind(sourcefile);
  fputs("@flushleft\n",Int2TeX);
  while ((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
      j = 0;
      while (j!=-1)
        {
        j = strfind(buf,'@',j);
        if (j!=-1)
          {
          buf[j] = '$';
          // if (j!=-1) strinst(buf,"$",j);
          j++;
          }
        }
      j = 0;
      while (j!=-1)
        {
        j = strfind(buf,'{',j);
        if (j!=-1)
          {
          buf[j] = '[';
          // if (j!=-1) strinst(buf,"$",j);
          j++;
          }
        }
      j = 0;
      while (j!=-1)
        {
        j = strfind(buf,'}',j);
        if (j!=-1)
          {
          buf[j] = ']';
          // if (j!=-1) strinst(buf,"$",j);
          j++;
          }
        }
      j = 0;
      while (j!=-1)
        {
        j = strfind(buf,'*',j);
        if (j!=-1)
          {
          buf[j] = 'o';
          // if (j!=-1) strinst(buf,"$",j);
          j++;
          }
        }
      fputs(buf, Int2TeX);
      }
  fputs("@end flushleft\n",Int2TeX);
}
