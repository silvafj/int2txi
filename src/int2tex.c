/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : INT2TEX.C                                              -
 - MODULE          : Main module                                            -
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
#ifndef	__Int2TeX_
#define	__Int2TeX_

// Include Standard libraries
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <process.h>

// Define FILE variables.
FILE *Int2TeX;	   // Target file
FILE *sourcefile;  // Source file
FILE *tempfile;	   // In this file will be written all topics found on source file
FILE *tempfile2;   // And in this the lines corresponding to each topic
FILE *tempfile3;   // in this will be written the topics, but already processed
		   // and checked if exists any duplicate topic
FILE *tempfile4;   // In this will be written *ALL* topics found
FILE *tempfile5;   // In this will be written comments to the topics...
FILE *tempfile6;   // In this will be written more topics...
FILE *tempfile7;   // In this will be written *ALL* topics found
FILE *tempfile8;   // In this will be written comments to the topics...
FILE *tempfile9;   // In this will be written more topics...
FILE *tempfile10;   // In this will be written more topics...



// The total number of topics that were processed
int total_topics_number;
// This constants will be used by "creat_menu_item"...
int automa_item	= 0; // This means that the rotine will imediatily write the
		     // topic to the target file
int manual_item	= 1; // This means that the rotine will check "tempfile4"
		     // were are ALL topics to check if already exists one
		     // and will process it.
// This constants will be used by "put_topic_temp"...
int no_string_format = 0; // This means that the specified string will be
			  // copied exactly how was found
int string_format = 1;	  // This means that the string will be processed
			  // puting first string char to Upper and the others
			  // to Lower case
char *makeinfo;  // This will be used to keep makeinfo path

char *args[] = {  // Arguments to use when running makeinfo
               "--verbose",
               "--no-split",
               "int2tex.tex",
               0
               };
int delete_all; // delete all redundant files.

int i; // This two vars will be used to copy all arguments from de command
char arguments[200]; // line

// Include program modules
#include "strings.c"	 // Module containing specific strings operations
#include "nodes.c"	 // Module containing rotines for nodes operations
#include "default.c"	 // Module containing "Default Info" processing
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
  strcpy(arguments,"");
  for(i=0;i<argc;i++)
    {
    strcat(arguments,argv[i]);
    strcat(arguments," ");
    }
  if ((argc <= 1) || (argc >= 4) || (strstr(arguments, "-h") != NULL) || ((strstr(arguments, "-d") != NULL) && (strstr(arguments, "-s") == NULL)))
    {
    printf("\n");
    printf("Int2TeX v1.0 converts Ralf Brown Interrupt List to TeXInfo format\n");
    printf("(C) 1998 Fernando J.A. Silva <bfe2333@mail.telepac.pt>\n");
    printf("\n");
    printf("usage: %s [options]\n",argv[0]);
    printf("\n");
    printf("options :\n");
    printf("  -s start convertion\n");
    printf("  -d delete ALL redundant files created in this session\n");
    printf("  -i display software license\n");
    printf("  -h this help\n");
    printf("\n");
    return 0;
    }
  if (strstr(arguments, "-i") != NULL)
    {
    clrscr();
    printf("\n");
    printf("Int2TeX v1.0 converts Ralf Brown Interrupt List to TeXInfo format\n");
    printf("(C) 1998 Fernando J.A. Silva <bfe2333@mail.telepac.pt>\n");
    printf("\n");
    printf("    Int2TeX is free software; you can redistribute it and/or\n");
    printf("    modify them under the terms of the GNU General Public License as\n");
    printf("    published by the Free Software Foundation; either version 2 of\n");
    printf("    the License, or (at your option) any later version.\n");
    printf("\n");
    printf("    This program is distributed in the hope that it will be useful,\n");
    printf("    but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
    printf("    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
    printf("    GNU General Public License for more details.\n");
    printf("\n");
    printf("    You should have received a copy of the GNU General Public License\n");
    printf("    along with this program; see the file COPYING.\n");
    printf("    If not, write to the Free Software Foundation, Inc.,\n");
    printf("    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.\n");
    printf("\n");
    return 0;
    }
  if (strstr(arguments, "-s") != NULL)
    {
    if (strstr(arguments, "-d") != NULL)
      {
      delete_all = 1;
      }
    else
      {
      delete_all = 0;
      }
    atexit(remove_temp_files);
    // Initialy there are no topics processed
    total_topics_number =	0;
    // Clear the screen
    clrscr();
    // Print some information
    printf("Int2TeX v1.0 converts Ralf Brown Interrupt List to TeXInfo format\n");
    printf("(C) 1998 Fernando J.A. Silva <bfe2333@mail.telepac.pt>\n");
    printf("\n");
    printf("Converting Interrupt List to TexInfo format...\n");
    // Check if source file is present in the Int2TeX.exe directory.
    // If not, just print some warnings. So, the user SHOULD copy that files
    // to the same directory.
    check_file("INTERRUP.1ST");
    // Start processing the files...
    printf("Processing...\n");
    // Create a new file and open it for writing.
    // Force the file to be open in text mode.
    Int2TeX = fopen("Int2TeX.TEX","wt");
    // Open a existing file for reading.
    // Force the file to be open in text mode.
    // From this file will be copied some copyright informations
    sourcefile = fopen("INTERRUP.1ST","rt");
    cprintf("INTERRUP.1ST ");
    // Create Temporary File that will have ALL topics created
    tempfile4 = fopen("TEMPFILE.004","wt+");
    tempfile7 = fopen("TEMPFILE.007","wt+");
    tempfile8 = fopen("TEMPFILE.008","wt+");
    tempfile9 = fopen("TEMPFILE.009","wt+");
    tempfile10 = fopen("TEMPFILE.010","wt+");
    // Write default information
    write_default_data();
    // Begins main menu
    fputs("@menu\n",Int2TeX);
    // Write topics
    creat_menu_item("Copying","",manual_item);
    creat_menu_item("Overview","",manual_item);
    creat_menu_item("Interrupts","",manual_item);
    creat_menu_item("Memory Map","",manual_item);
    creat_menu_item("CMOS-Memory Map","",manual_item);
    creat_menu_item("FAR CALL Interface List","",manual_item);
    creat_menu_item("I2C-Bus Devices","",manual_item);
    creat_menu_item("Model-Specific Registers","",manual_item);
    creat_menu_item("System-Management Mode","",manual_item);
    creat_menu_item("List Port","",manual_item);
    creat_menu_item("Opcodes List","",manual_item);
    creat_menu_item("Hamarsoft's 86BUGS list","",manual_item);
    creat_menu_item("Tables","",manual_item);
    // End main menu
    fputs("@end menu\n",Int2TeX);
    fputs("\n",Int2TeX);
    // close source file
    fclose(sourcefile);
    fputs("@c *************** CHAPTER 1 ****************\n",Int2TeX);
    creat_chapter("Copying","Overview","Top","Top");
    // Open source file
    sourcefile = fopen("INTERRUP.1ST","rt");
    // Create Temporary Files
    tempfile = fopen("TEMPFILE.001","wt+");
    tempfile2 = fopen("TEMPFILE.002","wt+");
    tempfile3 = fopen("TEMPFILE.003","wt+");
    tempfile5 = fopen("TEMPFILE.005","wt+");
    // Process chapter 1 (INTERRUP.PRI)
    // This file as a normal (general) processing...
    process_chapter_1();
    // Close source file
    fclose(sourcefile);
    // Close temporary files
    fclose(tempfile);
    fclose(tempfile2);
    fclose(tempfile3);
    fclose(tempfile5);
    // Delete temporary files
    unlink("TEMPFILE.001");
    unlink("TEMPFILE.002");
    unlink("TEMPFILE.003");
    unlink("TEMPFILE.005");
    fputs("@c *************** CHAPTER 2 ****************\n",Int2TeX);
    creat_chapter("Overview","Interrupts","Copying","Top");
    // Process chapter 2
    process_chapter_2();
    fputs("@c *************** CHAPTER 3 ****************\n",Int2TeX);
    creat_chapter("Interrupts","Memory Map","Overview","Top");
    if (!__file_exists("INTERRUP.LST"))
      {
      if (delete_all == 1)
        {
        system("combine.com -d .");
        }
      else
        {
        system("combine.com .");
        }
      }
    // Create Temporary Files
    tempfile = fopen("TEMPFILE.001","wt+");
    tempfile2 = fopen("TEMPFILE.002","wt+");
    tempfile3 = fopen("TEMPFILE.003","wt+");
    tempfile5 = fopen("TEMPFILE.005","wt+");
    tempfile6 = fopen("TEMPFILE.006","wt+");
    // Process chapter 3
    process_chapter_3();
    // Close Source File
    fclose(sourcefile);
    // Close temporary files
    fclose(tempfile);
    fclose(tempfile2);
    fclose(tempfile3);
    fclose(tempfile5);
    fclose(tempfile6);
    // Delete temporary files
    unlink("TEMPFILE.001");
    unlink("TEMPFILE.002");
    unlink("TEMPFILE.003");
    unlink("TEMPFILE.005");
    unlink("TEMPFILE.006");
    cprintf("\n\r");
    fputs("@c *************** CHAPTER 4 ****************\n",Int2TeX);
    creat_chapter("Memory Map","CMOS-Memory Map","Interrupts","Top");
    // Start the processing
    general_open_rotine("MEMORY.LST","Memory Map");
    fputs("@c *************** CHAPTER 5 ****************\n",Int2TeX);
    creat_chapter("CMOS-Memory Map","FAR CALL Interface List","Memory Map","Top");
    // Start the processing
    general_open_rotine("CMOS.LST","CMOS-Memory Map");
    fputs("@c *************** CHAPTER 6 ****************\n",Int2TeX);
    creat_chapter("FAR CALL Interface List","I2C-Bus Devices","CMOS-Memory Map","Top");
    // Start the processing
    general_open_rotine("FARCALL.LST","FAR CALL Interface List");
    fputs("@c *************** CHAPTER 7 ****************\n",Int2TeX);
    creat_chapter("I2C-Bus Devices","Model-Specific Registers","FAR CALL Interface List","Top");
    // Start the processing
    general_open_rotine("I2C.LST","I2C-Bus Devices");
    fputs("@c *************** CHAPTER 8 ****************\n",Int2TeX);
    creat_chapter("Model-Specific Registers","System-Management Mode","I2C-Bus Devices","Top");
    // Start the processing
    general_open_rotine("MSR.LST","Model-Specific Registers");
    fputs("@c *************** CHAPTER 9 ****************\n",Int2TeX);
    creat_chapter("System-Management Mode","List Port","Model-Specific Registers","Top");
    // Start the processing
    general_open_rotine("SMM.LST","System-Management Mode");
    fputs("@c *************** CHAPTER 10 ****************\n",Int2TeX);
    creat_chapter("List Port","Opcodes List","System-Management Mode","Top");
    // Start the processing
    if (!__file_exists("PORTS.LST"))
      {
      if (delete_all == 1)
        {
        system("combine.com -d -p .");
        }
      else
        {
        system("combine.com -p .");
        }
      }
    general_open_rotine("PORTS.LST","List Port");
    fputs("@c *************** CHAPTER 11 ****************\n",Int2TeX);
    creat_chapter("Opcodes List","Hamarsoft's 86BUGS list","List Port","Top");
    // Start the processing
    general_open_rotine("OPCODES.LST","Opcodes List");
    fputs("@c *************** CHAPTER 12 ****************\n",Int2TeX);
    creat_chapter("Hamarsoft's 86BUGS list","Tables","Opcodes List","Top");
    // Open source file
    sourcefile = fopen("86BUGS.LST","rt");
    // Create Temporary Files
    printf("86BUGS.LST\n");
    // Check if source file is present in the Int2TeX.exe directory.
    // If not, just print some warnings. So, the user SHOULD copy that files
    // to the same directory.
    check_file("86BUGS.LST");
    // Process chapter 12 (86BUGS.LST)
    // This file as special processing...
    process_chapter_12();
    // Close source file
    fclose(sourcefile);
    // Close temporary files
    // Delete temporary files
    fputs("@c *************** CHAPTER 13 ****************\n",Int2TeX);
    creat_chapter("Tables","","Hamarsoft's 86BUGS list","Top");
    printf("Making Tables\n");
    // Start the processing
    process_chapter_13();
    // GoodBye...
    fputs("@bye\n",Int2TeX);
    fclose(Int2TeX);
    // Close temporary file
    // Close temporary files
    fclose(tempfile);
    fclose(tempfile2);
    fclose(tempfile3);
    fclose(tempfile4);
    fclose(tempfile5);
    fclose(tempfile6);
    fclose(tempfile7);
    fclose(tempfile8);
    fclose(tempfile9);
    fclose(tempfile10);
    remove_temp_files();
    printf("Number of processed topics : %d\n",total_topics_number);
    makeinfo = (char *)(searchpath("makeinfo.exe"));
    if (makeinfo != NULL)
      {
      printf("MakeInfo found as %s\n",makeinfo);
      printf("Running MakeInfo and starting the convertion from TeX format to Info format...\n");
      spawnvp(P_WAIT,makeinfo,args);
      if (delete_all == 1)
        {
        printf("Delecting redundant files...\n");
        remove_temp_files();
        remove("INT2TEX.TEX");
        }
      }
    else
      {
      printf("MakeInfo not found.\n");
      printf("Can't start the convertion from TeX format to Info format.\n");
      }
    return 0;
    }
  }
#endif
