/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : DEFAULT.C                                              -
 - MODULE          : Module containing "Default Info" processing            -
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
void write_default_data(void)
  {
  char source_release[81];
  char source_copyright[81];

  // Start writing data in Int2TeX.TEX file
  fputs("\\input texinfo   @c -*-texinfo-*-\n",Int2TeX);
  fputs("@c %**start of header\n",Int2TeX);
  fputs("@setfilename intinfo.info\n",Int2TeX);
  fputs("@settitle Interrupt List\n",Int2TeX);
  fputs("@c %**end of header\n",Int2TeX);
  fputs("@setchapternewpage odd\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("@ifinfo\n",Int2TeX);
  fputs("@flushleft\n",Int2TeX);
  // Read copyright info from source file
  fgets(source_release, 81, sourcefile);
  // Put it in destination file
  fputs(source_release,Int2TeX);
  // And the same again...
  fgets(source_copyright, 81, sourcefile);
  fputs(source_copyright,Int2TeX);
  // Continue writing default data...
  fputs("\n",Int2TeX);
  fputs("This list was converted to TexInfo format with Int2TeX v1.0\n",Int2TeX);
  fputs("Copyright @copyright{} 1998 Fernando J.A. Silva\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("And was compiled to Info format with GNU MakeInfo (TexInfo 3.9) v1.67\n",Int2TeX);
  fputs("Copyright @copyright{} 1996 Free Software Foundation, Inc.\n",Int2TeX);
  fputs("@end flushleft\n",Int2TeX);
  fputs("@end ifinfo\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("@titlepage\n",Int2TeX);
  fputs("@sp 10\n",Int2TeX);
  fputs("@comment The title is printed in a large font.\n",Int2TeX);
  fputs("@center @titlefont{Interrupt List}\n",Int2TeX);
  fputs("@c The following two commands start the copyright page.\n",Int2TeX);
  fputs("@page\n",Int2TeX);
  fputs("@vskip 0pt plus 1filll\n",Int2TeX);
  fputs(source_release,Int2TeX);
  fputs(source_copyright,Int2TeX);
  fputs("This Info file was compiled with Int2TeX v1.0\n",Int2TeX);
  fputs("Copyright @copyright{} 1998 Fernando J.A. Silva\n",Int2TeX);
  fputs("@end titlepage\n",Int2TeX);
  creat_node("Top","Copying","(dir)","(dir)");
  fputs("@flushleft\n",Int2TeX);
  fputs("Interrupt List\n",Int2TeX);
  fputs("**************\n",Int2TeX);
  fputs("@end flushleft\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("This is a comprehensive listing of more than 8500 functions available through\n",Int2TeX);
  fputs("interrupt calls on IBM PC's and compatibles. Includes both documented and\n",Int2TeX);
  fputs("undocumented functions, plus lists of I/O port, CMOS, and memory locations,\n",Int2TeX);
  fputs("far-call entry points, and model-specific registers.\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("@flushleft\n",Int2TeX);
  fputs(source_release,Int2TeX);
  fputs(source_copyright,Int2TeX);
  fputs("\n",Int2TeX);
  fputs("This list was converted to TexInfo format with Int2TeX v1.0\n",Int2TeX);
  fputs("Copyright @copyright{} 1998 Fernando J.A. Silva\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("And was compiled to Info format with GNU MakeInfo (TexInfo 3.9) v1.67\n",Int2TeX);
  fputs("Copyright @copyright{} 1996 Free Software Foundation, Inc.\n",Int2TeX);
  fputs("@end flushleft\n",Int2TeX);
  fputs("\n",Int2TeX);
  }
