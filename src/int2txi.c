/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : INT2TXI.C                                              -
 - MODULE          : Main module                                            -
 - PROGRAM         : Int2Txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.1.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01st July, 1998                                        -
 ----------------------------------------------------------------------------

*/
#ifndef	__Int2Txi_
#define	__Int2Txi_

// Include Standard libraries
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <process.h>

// Define Program information
char int2txi_version[20] = "Int2Txi v1.1.0";

// Include program modules
#include "vars.c"        // Module containing program vars, const and types
#include "display.c"     // Module containing rotines to give info to the user
#include "files.c"	 // Module containing rotines for files operations
#include "strings.c"	 // Module containing specific strings operations
#include "nodes.c"	 // Module containing rotines for nodes operations
#include "process.c"     // Module containing rotines for convertion operations
#include "mainchap.c"	 // Module containing "Main Chapter" processing

#include "chapt_01.c"	 // Module containing "Chapter 1" processing
#include "chapt_02.c"	 // Module containing "Chapter 2" processing
#include "chapt_03.c"	 // Module containing "Chapter 3" processing
#include "chapt_12.c"	 // Module containing "Chapter 12" processing
#include "chapt_13.c"	 // Module containing "Chapter 13" processing

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : main()                                                     |
|  Description : Main Program                                               *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
int main(int argc,char *argv[])
  {
  int i; // This two vars will be used to copy all arguments from de command
  char arguments[80]; // line of arguments

  // Initialize some vars
  use_makeinfo = 0;
  use_gzip = 0;
  // Initialize 'arguments' string
  strcpy(arguments,"");
  // Copy all command line arguments to 'arguments' string
  for(i=0;i<argc;i++)
    {
    strcat(arguments,argv[i]);
    strcat(arguments," ");
    }
  // If the user asks for info about software license
  if (strstr(arguments, "-i") != NULL)
    {
    print_software_license();
    return 0;
    }
  // Check 'arguments' and execute the specified option.
  // If the user put less or more options or if he asks for help.
  if ((argc <= 1) || (strstr(arguments, "-h") != NULL) || (strstr(arguments, "-s") == NULL))
    {
    print_help_options(argv[0]);
    return 0;
    }
  // If the user wants to start the convertion
  if (strstr(arguments, "-s") != NULL)
    {
    // Remove ALL temporary files when exiting int2txi
    atexit(remove_temp_files);
    // Initialy there are no topics processed
    total_topics_number = 0;
    // Clear the screen
    clrscr();
    // Print some information
    fprintf(stdout,"%s converts Ralf Brown Interrupt List to TeXinfo format\n",int2txi_version);
    fprintf(stdout,"(C) 1998 Fernando J.A. Silva <bfe2333@mail.telepac.pt>\n");
    fprintf(stdout,"\n");
    // If the user wants to use makeinfo, we need to check if the program it's
    // present in the system
    if (strstr(arguments, "-m") != NULL) check_makeinfo();
    // If the user wants to use gzip, we need to check if the program it's
    // present in the system
    if (strstr(arguments, "-g") != NULL) check_gzip();
    // Start processing the files...
    fprintf(stdout,"Converting Interrupt List to TeXinfo format...\n");
    fprintf(stdout,"Processing...\n");
    // Create the target file and open it for writing.
    // Force the file to be open in text mode.
    int2txi = fopen("INT2TXI.TXI","wt");
    // Start running the rotine to process the main chapter.
    // Create Temporary File that will have ALL topics created
    temp10_all_topics = fopen("TEMPFILE.004","wt+");
    // Start the processing of main chapter...
    process_main_chapter();
    // Temporary files to keep all found tables
    tempfile7 = fopen("TEMPFILE.007","wt+");
    tempfile8 = fopen("TEMPFILE.008","wt+");
    tempfile9 = fopen("TEMPFILE.009","wt+");
    tempfile10 = fopen("TEMPFILE.010","wt+");
//  fputs("@c *************** CHAPTER 1 ****************\n",int2txi);
    creat_chapter("Copying","Overview","Top","Top");
    // Process chapter 1
    process_chapter_1();
//  fputs("@c *************** CHAPTER 2 ****************\n",int2txi);
    creat_chapter("Overview","Interrupts","Copying","Top");
    // Process chapter 2
    process_chapter_2();
//  fputs("@c *************** CHAPTER 3 ****************\n",int2txi);
    creat_chapter("Interrupts","Memory Map","Overview","Top");
    // If file does not exist run combine.com
    if (!__file_exists("INTERRUP.LST")) system("combine.com .");
    // Process chapter 3
    process_chapter_3();
    fprintf(stdout,"\n\r");
//  fputs("@c *************** CHAPTER 4 ****************\n",int2txi);
    creat_chapter("Memory Map","CMOS-Memory Map","Interrupts","Top");
    // Start the processing
    general_open_rotine("MEMORY.LST","Memory Map",do_tables);
//  fputs("@c *************** CHAPTER 5 ****************\n",int2txi);
    creat_chapter("CMOS-Memory Map","FAR CALL Interface List","Memory Map","Top");
    // Start the processing
    general_open_rotine("CMOS.LST","CMOS-Memory Map",do_tables);
//  fputs("@c *************** CHAPTER 6 ****************\n",int2txi);
    creat_chapter("FAR CALL Interface List","I2C-Bus Devices","CMOS-Memory Map","Top");
    // Start the processing
    general_open_rotine("FARCALL.LST","FAR CALL Interface List",do_tables);
//  fputs("@c *************** CHAPTER 7 ****************\n",int2txi);
    creat_chapter("I2C-Bus Devices","Model-Specific Registers","FAR CALL Interface List","Top");
    // Start the processing
    general_open_rotine("I2C.LST","I2C-Bus Devices",do_tables);
//  fputs("@c *************** CHAPTER 8 ****************\n",int2txi);
    creat_chapter("Model-Specific Registers","System-Management Mode","I2C-Bus Devices","Top");
    // Start the processing
    general_open_rotine("MSR.LST","Model-Specific Registers",do_tables);
//  fputs("@c *************** CHAPTER 9 ****************\n",int2txi);
    creat_chapter("System-Management Mode","List Port","Model-Specific Registers","Top");
    // Start the processing
    general_open_rotine("SMM.LST","System-Management Mode",do_tables);
//  fputs("@c *************** CHAPTER 10 ****************\n",int2txi);
    creat_chapter("List Port","Opcodes List","System-Management Mode","Top");
    // If file does not exist run combine.com
    if (!__file_exists("PORTS.LST")) system("combine.com -p .");
    // Start the processing
    general_open_rotine("PORTS.LST","List Port",do_tables);
//  fputs("@c *************** CHAPTER 11 ****************\n",int2txi);
    creat_chapter("Opcodes List","Hamarsoft's 86BUGS list","List Port","Top");
    // Start the processing
    general_open_rotine("OPCODES.LST","Opcodes List",no_tables);
//  fputs("@c *************** CHAPTER 12 ****************\n",int2txi);
    creat_chapter("Hamarsoft's 86BUGS list","Tables","Opcodes List","Top");
    // Process chapter 12 (86BUGS.LST)
    // This file as special processing...
    process_chapter_12();
//  fputs("@c *************** CHAPTER 13 ****************\n",int2txi);
    creat_chapter("Tables","","Hamarsoft's 86BUGS list","Top");
    fprintf(stdout,"Making Tables\n");
    // Start the processing
    process_chapter_13();
    // GoodBye...
    fputs("@bye\n",int2txi);
    fclose(int2txi);
    // Close temporary files
    fclose(temp1_file_topics);
    fclose(temp2_file_lines);
    fclose(temp3_file_proc_topics);
    fclose(temp10_all_topics);
    fclose(temp5_file_comments);
    fclose(temp6_file_main_topics);
    fclose(tempfile7);
    fclose(tempfile8);
    fclose(tempfile9);
    fclose(tempfile10);
    remove_temp_files();
    fprintf(stdout,"Number of processed topics : %d\n",total_topics_number);
    // Run external programs
    if (use_makeinfo == 1)
      {
      fprintf(stdout,"Running MakeInfo and starting the convertion from Txi format to Info format...\n");
      // Run Makeinfo
      system("makeinfo --o RBINT int2txi.txi");
      }
    if (use_gzip == 1)
      {
      fprintf(stdout,"Running GZip and starting the compression of info files...\n");
      // Run gzip to compress files
      system("gzip.exe RBIN*");
      }
    return 0;
    }
  }
#endif
