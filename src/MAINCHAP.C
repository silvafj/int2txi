/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : MAINCHAP.C                                             -
 - MODULE          : Module containing "Main Chapter" processing            -
 - PROGRAM         : Int2Txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.1.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01th July, 1998                                        -
 ----------------------------------------------------------------------------

*/
/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : write_default_data()                                       |
|  Description : Will write default data to target file                     *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void write_default_data(void)
  {

  // Start writing data in INT2TXI.TXI file
  fprintf(int2txi,"\\input texinfo   @c -*-texinfo-*-\n");
  fprintf(int2txi,"@c %%**start of header\n");
  fprintf(int2txi,"@setfilename intinfo.inf\n");
  fprintf(int2txi,"@settitle Interrupt List\n");
  fprintf(int2txi,"@c %%**end of header\n");
  fprintf(int2txi,"@setchapternewpage odd\n");
  fprintf(int2txi,"\n");
  fprintf(int2txi,"@ifinfo\n");
  fprintf(int2txi,"@flushleft\n");
  // Read copyright info from source file
  fgets(source_release, 81, sourcefile);
  // Put it in destination file
  fputs(source_release,int2txi);
  // And the same again...
  fgets(source_copyright, 81, sourcefile);
  fputs(source_copyright,int2txi);
  // Continue writing default data...
  fprintf(int2txi,"\n");
  fprintf(int2txi,"This list was converted to TeXinfo format with %s\n",int2txi_version);
  fprintf(int2txi,"Copyright @copyright{} 1998 Fernando J.A. Silva\n");
  fprintf(int2txi,"\n");
  fprintf(int2txi,"And was compiled to Info format with %s",makeinfo_release);
  fprintf(int2txi,"%s",makeinfo_copyright);
  fprintf(int2txi,"@end flushleft\n");
  fprintf(int2txi,"@end ifinfo\n");
  fprintf(int2txi,"\n");
  fprintf(int2txi,"@titlepage\n");
  fprintf(int2txi,"@sp 10\n");
  fprintf(int2txi,"@comment The title is printed in a large font.\n");
  fprintf(int2txi,"@center @titlefont{Interrupt List}\n");
  fprintf(int2txi,"@c The following two commands start the copyright page.\n");
  fprintf(int2txi,"@page\n");
  fprintf(int2txi,"@vskip 0pt plus 1filll\n");
  fputs(source_release,int2txi);
  fputs(source_copyright,int2txi);
  fprintf(int2txi,"This list was converted to TeXinfo format with %s\n",int2txi_version);
  fprintf(int2txi,"Copyright @copyright{} 1998 Fernando J.A. Silva\n");
  fprintf(int2txi,"@end titlepage\n");
  creat_node("Top","Copying","(dir)","(dir)");
  fprintf(int2txi,"@flushleft\n");
  fprintf(int2txi,"Interrupt List\n");
  fprintf(int2txi,"**************\n");
  fprintf(int2txi,"@end flushleft\n");
  fprintf(int2txi,"\n");
  fprintf(int2txi,"This is a comprehensive listing of more than 8500 functions available through\n");
  fprintf(int2txi,"interrupt calls on IBM PC's and compatibles. Includes both documented and\n");
  fprintf(int2txi,"undocumented functions, plus lists of I/O port, CMOS, and memory locations,\n");
  fprintf(int2txi,"far-call entry points, and model-specific registers.\n");
  fprintf(int2txi,"\n");
  fprintf(int2txi,"@flushleft\n");
  fputs(source_release,int2txi);
  fputs(source_copyright,int2txi);
  fprintf(int2txi,"\n");
  fprintf(int2txi,"This list was converted to TeXinfo format with %s\n",int2txi_version);
  fprintf(int2txi,"Copyright @copyright{} 1998 Fernando J.A. Silva\n");
  fprintf(int2txi,"\n");
  fprintf(int2txi,"And was compiled to Info format with %s",makeinfo_release);
  fprintf(int2txi,"%s",makeinfo_copyright);
  fprintf(int2txi,"@end flushleft\n");
  fprintf(int2txi,"\n");
  } // write_default_data()

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : process_main_chapter                                       |
|  Description : Will process main chapter                                  *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void process_main_chapter()
  {
  if (use_makeinfo == 1)
    {
    system("makeinfo --version > MAKEVER.TXT");
    // Open a existing file for reading.
    // Force the file to be open in text mode.
    // From this file will be copied some copyright informations
    sourcefile = fopen("MAKEVER.TXT","rt");
    // Read makeinfo copyright info
    fgets(makeinfo_release, 81, sourcefile);
    fgets(makeinfo_copyright, 81, sourcefile);
    // Close temp source file
    fclose(sourcefile);
    // Remove temp source file
    remove("MAKEVER.TXT");
    }
  else
    {
    strcpy(makeinfo_release,"GNU MakeInfo");
    strcpy(makeinfo_copyright,"Copyright (C) 1996 Free Software Foundation, Inc.");
    }
  // Check if the file exists. If not, exit because this is a fatal file
  check_file("INTERRUP.1ST",1);
  // Open a existing file for reading.
  // Force the file to be open in text mode.
  // From this file will be copied some copyright informations
  sourcefile = fopen("INTERRUP.1ST","rt");
  cprintf("INTERRUP.1ST ");
  // Write default information
  write_default_data();
  // Begins main menu
  fprintf(int2txi,"@menu\n");
  // Write topics
  creat_menu_item("Copying","");
  creat_menu_item("Overview","");
  creat_menu_item("Interrupts","");
  creat_menu_item("Memory Map","");
  creat_menu_item("CMOS-Memory Map","");
  creat_menu_item("FAR CALL Interface List","");
  creat_menu_item("I2C-Bus Devices","");
  creat_menu_item("Model-Specific Registers","");
  creat_menu_item("System-Management Mode","");
  creat_menu_item("List Port","");
  creat_menu_item("Opcodes List","");
  creat_menu_item("Hamarsoft's 86BUGS list","");
  creat_menu_item("Tables","");
  // End main menu
  fprintf(int2txi,"@end menu\n");
  fprintf(int2txi,"\n");
  // close source file
  fclose(sourcefile);
  } // process_main_chapter()

