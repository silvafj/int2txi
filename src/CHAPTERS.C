/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : CHAPTERS.C                                             -
 - MODULE          : Module containing all process to chapters that have    -
 -                   a special processing type                              -
 - PROGRAM         : Int2Txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.2.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01th September, 1998                                   -
 ----------------------------------------------------------------------------

*/

//*************************************************************************//
//////////////////////////  M A I N  C H A P T E R //////////////////////////
//*************************************************************************//
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
  fprintf(int2txi,"@setfilename rbint.inf\n");
  fprintf(int2txi,"@settitle Interrupt List\n");
  fprintf(int2txi,"@c %%**end of header\n");
  fprintf(int2txi,"@setchapternewpage odd\n");
  fprintf(int2txi,"\n");
  fprintf(int2txi,"@ifinfo\n");
  fprintf(int2txi,"@flushleft\n");
  // Read copyright info from source file
  actual_line = find_line(1);
  strcpy(source_release,actual_line->string);
  // Put it in destination file
  fputs(source_release,int2txi);
  // And the same again...
  actual_line = find_line(2);
  strcpy(source_copyright,actual_line->string);
  fputs(source_copyright,int2txi);
  // Continue writing default data...
  fprintf(int2txi,"\n");
  fprintf(int2txi,"This list was converted to TeXinfo format with %s\n",int2txi_version);
  fprintf(int2txi,"Copyright @copyright{} 1998 Fernando J.A. Silva (aka ^Magico^)\n");
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
  fprintf(int2txi,"Copyright @copyright{} 1998 Fernando J.A. Silva  (aka ^Magico^)\n");
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
  fprintf(int2txi,"Copyright @copyright{} 1998 Fernando J.A. Silva (aka ^Magico^)\n");
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
  FILE *sourcefile;

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
    strcpy(makeinfo_release,"GNU MakeInfo\n");
    strcpy(makeinfo_copyright,"Copyright (C) 1996 Free Software Foundation, Inc.\n");
    }
  // Check if the file exists. If not, exit because this is a fatal file
  check_file("INTERRUP.1ST",1);
  // Open a existing file for reading.
  // Force the file to be open in text mode.
  // From this file will be copied some copyright informations
  load_source_file("INTERRUP.1ST");
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
  unload_actual_file();
  } // process_main_chapter()

//*************************************************************************//
//////////////////////////// C H A P T E R   1 //////////////////////////////
//*************************************************************************//
/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : process_chapter_1()                                        |
|  Description : Will process chapter 1                                     *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void process_chapter_1(void)
  {
  first_topic_filetop = 0; // pointer to first entry in file_topics
  last_topic_filetop = 0; // to last entry
  // Load source file to struct
  load_source_file("INTERRUP.1ST");
  // Init pointers to structs
  // Begin a menu...
  fputs("@menu\n",int2txi);
  // Write items
  creat_menu_item("Interrupt List","");
  creat_menu_item(int2txi_version,"");
  // End menu
  fputs("@end menu\n",int2txi);
  // Creation section
  creat_section("Interrupt List",int2txi_version,"Copying","Copying");
  // Process with general processing rotine...
  general_processing_rotine_notables(use_sub_section,"Interrupt List");
  // creates section
  creat_section(int2txi_version,"","Interrupt List","Copying");
  // Start menu
  fputs("@menu\n",int2txi);
  // Write items
  creat_menu_item("Copyright (1)","");
  creat_menu_item("Greets","");
  creat_menu_item("Contact Information","");
  // End menu
  fputs("@end menu\n",int2txi);
  // Writes more data to target file
  creat_sub_section("Copyright (1)","Greets",int2txi_version,int2txi_version);
  fprintf(int2txi,"%s is\n",int2txi_version);
  fputs("Copyright @copyright{} 1998 Fernando J.A. Silva (aka ^Magico^)\n",int2txi);
  fputs("\n",int2txi);
  fputs("This program is free; this means that everyone is free to use it\n",int2txi);
  fputs("and free to redistribute it on a free basis. This program is not in\n",int2txi);
  fputs("the public domain; it is copyrighted and there are restrictions on his\n",int2txi);
  fputs("distribution, but these restrictions are designed to permit everything\n",int2txi);
  fputs("that a good cooperating citizen would want to do.\n",int2txi);
  fputs("What is not allowed is to try to prevent others from further sharing\n",int2txi);
  fputs("any version of this program that they might get from you.\n",int2txi);
  fputs("\n",int2txi);
  fputs("Specifically, I want to make sure that you have the right to give\n",int2txi);
  fputs("away copies of the program, that you receive source code or else can\n",int2txi);
  fputs("get it if you want it, that you can change this program or use pieces of it\n",int2txi);
  fputs("in new free programs, and that you know you can do these things.\n",int2txi);
  fputs("Considering that you should always remember that the original program is copyrighted\n",int2txi);
  fputs("and you should preserve my name and all the names of all contributers.\n",int2txi);
  fputs("\n",int2txi);
  fputs("To make sure that everyone has such rights, I have to forbid you to\n",int2txi);
  fputs("deprive anyone else of these rights.  For example, if you distribute\n",int2txi);
  fputs("copies of this program, you must give the recipients all the rights that you have.\n",int2txi);
  fputs("You must make sure that they, too, receive or can get the source code.\n",int2txi);
  fputs("And you must tell them their rights.\n",int2txi);
  fputs("\n",int2txi);
  fputs("Also, for my own protection, I must make certain that everyone finds\n",int2txi);
  fputs("out that there is no warranty for this program.\n",int2txi);
  fputs("If this program is modified by someone else and passed on, I want\n",int2txi);
  fputs("their recipients to know that what they have is not what I distributed,\n",int2txi);
  fputs("so that any problems introduced by others will not reflect on my reputation.\n",int2txi);
  fputs("\n",int2txi);
  fputs("The precise conditions of the licenses for the program currently\n",int2txi);
  fputs("being distributed are found in the General Public Licenses that accompany it.\n",int2txi);
  fputs("\n",int2txi);
  creat_sub_section("Greets","Contact Information","Copyright (1)",int2txi_version);
  fputs("When we make something we always have someone supporting us, helping us,\n",int2txi);
  fputs("talking with us about what we are making, or about girls, or about\n",int2txi);
  fputs("something relaxing. Or we have just some friends that are always there\n",int2txi);
  fputs("ready to chat with us.\n",int2txi);
  fputs("\n",int2txi);
  fputs("There are so many people I want to say ®Thank You¯. Many of them not for having ",int2txi);
  fputs("something to do with this project, but for being my friends. And that is the most ",int2txi);
  fputs("important thing in life, having good friends. Is not money, is not power, but\n",int2txi);
  fputs("having real good friends!!!\n",int2txi);
  fputs("\n",int2txi);
  fputs("@flushleft\n",int2txi);
  fputs("From PTNet #Coders:\n",int2txi);
  fputs("\n",int2txi);
  fputs("       þ Al-Buba   þ Anjo             þ Azevedo      þ Bond\n",int2txi);
  fputs("       þ CodeWiz   þ CyberLord        þ Deadkill     þ Deep Blue\n",int2txi);
  fputs("       þ Electron  þ Erradicator      þ f7           þ HellMaster\n",int2txi);
  fputs("       þ Karajac   þ Lery             þ MrUnderWorld þ MrWho\n",int2txi);
  fputs("       þ NetCyborg þ Psychic Symphony þ Reboot       þ Shadow\n",int2txi);
  fputs("       þ Shlak     þ Storm_Crow       þ TheFlash     þ Toth\n",int2txi);
  fputs("       þ Violet    þ Bytter           þ Dr_Pro       þ HiTek\n",int2txi);
  fputs("       þ Myke      þ _Catwoman        þ TroyAngel\n",int2txi);
  fputs("\n",int2txi);
  fputs("From BrasIrc #Coders:\n",int2txi);
  fputs("\n",int2txi);
  fputs("       þ xcaRioca\n",int2txi);
  fputs("\n",int2txi);
  fputs("I really hope that I didn't forgot anyone... but just in case\n",int2txi);
  fputs("I'll also want to thanks all other people, on PTNet #Coders,\n",int2txi);
  fputs("BrasIrc #Coders, Undernet #Coders, all other channels\n",int2txi);
  fputs("where I've good friends and ICQ friends.\n",int2txi);
  fputs("\n",int2txi);
  fputs("Also thanks to :\n",int2txi);
  fputs("\n",int2txi);
  fputs("DJ Delorie    --- DJGPP's author\n",int2txi);
  fputs("Robert H”hne  --- RHIDE's author\n",int2txi);
  fputs("Eli Zaretskii --- FAQ's maintainer\n",int2txi);
  fputs("Ralf Brown    --- Interrupt List maintainer\n",int2txi);
  fputs("\n",int2txi);
  fputs("and very specially to\n",int2txi);
  fputs("Salvador Eduardo Tropea (SET)  --- INFO Viewer author\n",int2txi);
  fputs("because he helped me resolving some big troubles.\n",int2txi);
  fputs("\n",int2txi);
  fputs("And to all the people of DJGPP's list.\n",int2txi);
  fputs("\n",int2txi);
  fputs("\n",int2txi);
  fputs("Finally, I want to dedicate this project to my beloved...\n",int2txi);
  fputs("     ...Cristina Marques.\n",int2txi);
  fputs("   17/SEP/98\n",int2txi);
  fputs("@end flushleft\n",int2txi);
  fputs("\n",int2txi);
  creat_sub_section("Contact Information","","Greets",int2txi_version);
  fputs("@flushleft\n",int2txi);
  fputs("Anyone with questions, ideas, problems, critiques...\n",int2txi);
  fputs("> Can send an e-mail to : \n",int2txi);
  fputs("        bfe2333@@mail.telepac.pt\n",int2txi);
  fputs("        magico@@GalaxyCorp.com\n",int2txi);
  fputs("\n",int2txi);
  fputs("> Can find me on ICQ with the UIN : 1197830\n",int2txi);
  fputs("\n",int2txi);
  fputs("> Can find me on PTNet (irc.ualg.pt) with the nickname ^Magico^\n",int2txi);
  fputs("\n",int2txi);
  fputs("> Can write for my mail :\n",int2txi);
  fputs("        Fernando JA Silva\n",int2txi);
  fputs("        Juncal - Assequins\n",int2txi);
  fputs("        3750 µgueda\n",int2txi);
  fputs("        PORTUGAL\n",int2txi);
  fputs("\n",int2txi);
  fputs("> Can check #coders website :\n",int2txi);
  fputs("        http://ptcoders.base.org\n",int2txi);
  fputs("        http://members.xoom.com/ptcoders/\n",int2txi);
  fputs("        http://irc.telepac.pt/canal/coders/\n",int2txi);
  fputs("\n",int2txi);
  fputs("> Or can post a message on pt.comp.geral NewsGroup\n",int2txi);
  fputs("\n",int2txi);
  fputs("GoodBye... and good coding...\n",int2txi);
  fputs("@end flushleft\n",int2txi);
  // Unload struct
  unload_actual_file();
  unload_actual_topics_file();
  } //process_chapter_1

//*************************************************************************//
//////////////////////////// C H A P T E R   2 //////////////////////////////
//*************************************************************************//
/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : process_chapter_2()                                        |
|  Description : Will process chapter 2                                     *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void process_chapter_2(void)
  {
  // Begin menu
  fputs("@menu\n",int2txi);
  creat_menu_item("iAPX 86 Interrupt Primer","");
  creat_menu_item("Public Domain/Freeware/Shareware by Ralf Brown","");
  creat_menu_item("Glossary","");
  creat_menu_item("Bibliography (1)","");
  // End menu
  fputs("@end menu\n",int2txi);
  //------///
  // Start the inicialization to process INTERRUP.PRI
  creat_section("iAPX 86 Interrupt Primer","Public Domain/Freeware/Shareware by Ralf Brown","Overview","Overview");
  // Check if source file is present in the int2txi.exe directory.
  if (check_file("INTERRUP.PRI",0) == 0)
    {
    copy_all_file("INTERRUP.PRI");
    cprintf("INTERRUP.PRI\n\r");
    }
  else fprintf(int2txi,"Not processed!!! INTERRUP.PRI wasn't found on the processing");
  //------///
  // Start the inicialization to process RBROWN.TXT
  creat_section("Public Domain/Freeware/Shareware by Ralf Brown","Glossary","iAPX 86 Interrupt Primer","Overview");
  // Check if source file is present in the int2txi.exe directory.
  if (check_file("RBROWN.TXT",0) == 0)
    {
    copy_all_file("RBROWN.TXT");
    cprintf("RBROWN.TXT\n\r");
    }
  else fprintf(int2txi,"Not processed!!! RBROWN.TXT wasn't found on the processing");
  //------///
  // Start the inicialization to process GLOSSARY.LST
  creat_section("Glossary","Bibliography (1)","Public Domain/Freeware/Shareware by Ralf Brown","Overview");
  // Check if source file is present in the int2txi.exe directory.
  if (check_file("GLOSSARY.LST",0) == 0)
    {
    copy_all_file("GLOSSARY.LST");
    cprintf("GLOSSARY.LST\n\r");
    }
  else fprintf(int2txi,"Not processed!!! GLOSSARY.LST wasn't found on the processing");
  //------///
  // Start the inicialization to process BIBLIO.LST
  creat_section("Bibliography (1)","","Glossary","Overview");
  if (check_file("BIBLIO.LST",0) == 0)
    {
    cprintf("BIBLIO.LST ");
    load_source_file("BIBLIO.LST ");
    general_processing_rotine(1,"Bibliography (1)");
    unload_actual_file();
    unload_actual_topics_file();
    }
  else fprintf(int2txi,"Not processed!!! BIBLIO.LST wasn't found on the processing");
  } //process_chapter_2

//*************************************************************************//
//////////////////////////// C H A P T E R   3 //////////////////////////////
//*************************************************************************//
/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : put_topic_temp_intmain()                                   |
|  Description : Process string by removing some caracters                  *
*  Input       : String -- to process                                       |
|  Input       : Make -- action to do                                       *
*  Input       : Caracter -- remove this caracter                           |
|  Return      : ----                                                       *
*                ----                                                       |
|                                                                           *
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
         ////////////////////////////////////////////////
          ////////////// 255 Main Topics ///////////
         ////////////////////////////////////////////////
void put_topic_temp_intmain(char *string, char caracter)
  {
  // Variables for loop operations
  register int i,j;
  char tempstr[200];
  struct TIntMainTopics *topic;
  struct TIntMainINT *topic_int;
  char *malloc();

  i = 0;
  j = 0;
  // Copy the string to temporary variable
  strcpy(tempstr,string);
  // Find and change some characters
  find_and_change(string,tempstr,0);
  strcpy(tempstr," ");
  // Start processing the string
  for(i=0;i<=strlen(string) - 1;++i)
    {
    if ((string[i] != '!') && (string[i] != caracter))
      {
      tempstr[j] = string[i];
      j++;
      } // if
    } // for...
    // End string with NULL. If this isn't done there are many problems...
    // Do some tests with strings and you will learn many things
    tempstr[j] = NULL;
    // Take off format char "\n" at the end of the string
    tempstr[strlen(tempstr)-1] = '\0';
    // put it on a normal struct
    // alloc some memory
    topic = (struct TIntMainTopics *)malloc(sizeof(int_main_topics));
    strcpy(topic->string,tempstr);
    if (first_topic_intmain != 0)
      { // if is not the first entry
      last_topic_intmain->next_topic = topic;
      topic->previous_topic = last_topic_intmain;
      last_topic_intmain = topic;
      last_topic_intmain->next_topic = 0;
      // update actual_topic for next rotines could use it without
      // problems
      actual_topic_intmain = actual_topic_intmain->next_topic;
      }
    else
      { // if is the first entry
      first_topic_intmain = topic;
      first_topic_intmain->next_topic = 0;
      last_topic_intmain = first_topic_intmain;
      first_topic_intmain->previous_topic = 0;
      // update actual_topic for next rotines could use it without
      // problems
      actual_topic_intmain = first_topic_intmain;
      }
  } // put_topic_temp

void find_nodes_relations_intmain()
  {
  // Rewind struct to start checking next and previous nodes
  actual_topic_intmain = first_topic_intmain;
  while (actual_topic_intmain != 0)
    {
    if (actual_topic_intmain == first_topic_intmain)
      {
      strcpy(actual_topic_intmain->next_node,actual_topic_intmain->next_topic->string);
      strcpy(actual_topic_intmain->previous_node,"");
      }
    else
      if (actual_topic_intmain == last_topic_intmain)
        {
        strcpy(actual_topic_intmain->next_node,"");
        strcpy(actual_topic_intmain->previous_node,actual_topic_intmain->previous_topic->string);
        }
      else
        {
        strcpy(actual_topic_intmain->next_node,actual_topic_intmain->next_topic->string);
        strcpy(actual_topic_intmain->previous_node,actual_topic_intmain->previous_topic->string);
        }
    actual_topic_intmain = actual_topic_intmain->next_topic;
    } // while
  } // find_nodes_relations

void create_all_menu_intmain()
  {
  // Buffers...
  char buf[90];
  char buf2[90];

  // Rewind Temporary file to check all topics and write them to the menu...
  // with the associated comment
  actual_topic_intmain = first_topic_intmain;
  // Open a new menu...
  fputs("@menu\n",int2txi);
  while (actual_topic_intmain != 0)
    {
    // Get topic
    strcpy(buf,actual_topic_intmain->string);
    // Create the topic in the menu
    creat_menu_item(buf,"");
    // update topic pointer
    actual_topic_intmain = actual_topic_intmain->next_topic;
    } // while...
  // End menu
  fputs("@end menu\n",int2txi);
  } // create_all_menu

      ////////////////////////////////////////////////////////////////
         ///////////// Get all interrup.lst topics ////////////////
      ////////////////////////////////////////////////////////////////

void put_topic_temp_intmain2(char *string, char caracter)
  {
  // Variables for loop operations
  register int i,j;
  char tempstr[200];
  struct TIntMain2Topics *topic;
  struct TIntMain2INT *topic_int;
  char *malloc();

  i = 0;
  j = 0;
  // Copy the string to temporary variable
  strcpy(tempstr,string);
  // Find and change some characters
  find_and_change(string,tempstr,0);
  strcpy(tempstr," ");
  // Start processing the string
  for(i=0;i<=strlen(string) - 1;++i)
    {
    if ((string[i] != '!') && (string[i] != caracter))
      {
      tempstr[j] = string[i];
      j++;
      } // if
    } // for...
    // End string with NULL. If this isn't done there are many problems...
    // Do some tests with strings and you will learn many things
    tempstr[j] = NULL;
    // put it on a normal struct
    // alloc some memory
    topic = (struct TIntMain2Topics *)malloc(sizeof(int_main2_topics));
    strcpy(topic->string,tempstr);
    if (first_topic_intmain2 != 0)
      { // if is not the first entry
      last_topic_intmain2->next_topic = topic;
      topic->previous_topic = last_topic_intmain2;
      last_topic_intmain2 = topic;
      last_topic_intmain2->next_topic = 0;
      // update actual_topic for next rotines could use it without
      // problems
      actual_topic_intmain2 = actual_topic_intmain2->next_topic;
      }
    else
      { // if is the first entry
      first_topic_intmain2 = topic;
      first_topic_intmain2->next_topic = 0;
      last_topic_intmain2 = first_topic_intmain2;
      first_topic_intmain2->previous_topic = 0;
      // update actual_topic for next rotines could use it without
      // problems
      actual_topic_intmain2 = first_topic_intmain2;
      }
  } // put_topic_temp

void put_comment_temp_intmain2(char *string)
  {
  // Variables for loop operations
  register int i,j,h;
  char tempstr[200];

  // Copy the string to temporary variable
  strcpy(tempstr,string);
  // Find and change some characters
  find_and_change(string,tempstr,0);
  j = 0;
  if (making_tables == 0)
    j = strfind(string,'-',0);
  // Put a space. When copying the string to the menu we need a blank space
  strcpy(tempstr," ");
  h = 1;
  // Copy the string begining at the specified char position
  for(i=j;i<=strlen(string) - 1;++i)
    {
    tempstr[h] = string[i];
    h++;
    } // for...
  tempstr[h] = NULL;
  strcpy(actual_topic_intmain2->comment,tempstr);
  } // put_comment_temp

void find_all_topics_intmain2()
  {
  // Buffers...
  char buf[90];
  char buf2[90];
  int topics_number;  // File topics_number

  actual_line = first_line;
  while	(actual_line != 0)
    {
    // Get one line
    strcpy(buf,actual_line->string);
    if (is_topic(buf) == 1)
      {
      // Get the next line on the struct to make it menu comment
      strcpy(buf2,actual_line->next_line->string);
      // Write topic
      put_topic_temp_intmain2(buf,'-');
      // Process the line to make it a comment line
      put_comment_temp_intmain2(buf2);
      // Write the main topic, that the sub-topic belongs
      strncpy(actual_topic_intmain2->main_topic,buf2,6);
// actual_topic_intmain2->main_topic[6] = NULL;
      // Update line value
      if (topics_number >= 1) actual_topic_intmain2->previous_topic->end = actual_line->previous_line->number;
      // Update line value
      actual_topic_intmain2->begin = actual_line->next_line->number;
      // Update topics_number value
      topics_number++;
      } // if...
      actual_line = actual_line->next_line;
    } // while...
  // Update line value
  actual_topic_intmain2->end = last_line->number;
  } // find_all_topics

void find_duplicate_topics_intmain2()
  {
  // Buffers...
  char buf[50];
  char temp[50];
  int valor_duplo; // Value returned when we chack for duplicate topics...
  int index;

  index = 0;
  actual_topic_intmain2 = first_topic_intmain2;
  while	(actual_topic_intmain2 != 0)
    {
    // Get one topic
    strcpy(buf,actual_topic_intmain2->string);
    // Bug correction for file CMOS.LST
    if (strcmp(buf,"\n") == 0) strcpy(buf,"Information\n");
    // Check if topic already exists...
    valor_duplo = 0;
    valor_duplo = topic_check(buf);
    // Take off format char "\n" at the end of the string
    buf[strlen(buf)] = NULL;
    buf[strlen(buf)-1] = '\0';
    // If topic already exists
    if (valor_duplo > 0)
      {
      strcpy(temp," ");
      itoa(valor_duplo,temp,10);
      strcat(buf," (");
      strcat(buf,temp);
      strcat(buf,")\n");
      // copy it again deleting old topic, and putting the new one
      strcpy(actual_topic_intmain2->string,buf);
      // copy it to topics main struct
      put_topic_alltopics_struct(buf);
      } // if...
    else
      {
      // if doesn't exist other topic just copy it to temporary file and to
      // topics main list
      strcat(buf,"\n");
      // copy it again deleting old topic, and putting the new one
      strcpy(actual_topic_intmain2->string,buf);
      // copy it to topics main struct
      put_topic_alltopics_struct(buf);
      } // else...
    actual_topic_intmain2 = actual_topic_intmain2->next_topic;
    index++;
    if (index==10)
      {
      cprintf("_");
      index = 0;
      }
    } // while...
  } // find_duplicate_topics

        ////////////////////////////////////////////////////////
        /////////////// Every Main topic process ////////////////
        ////////////////////////////////////////////////////////
void int_process(char *up_topic)
  {
  // Buffers...
  char buf[50];
  char buf2[50];
  char buf3[50];
  int  start_line,end_line; // Self explicit

  // Start finding all topics on source file and copy them to tempfile
  // At the same time, check "line" value and process it...
  actual_topic_intmain2 = first_topic_intmain2;
  while (actual_topic_intmain2 != 0)
    {
    if (strncmp(actual_topic_intmain2->main_topic,up_topic,6) == 0)
      {
      put_topic_temp(actual_topic_intmain2->string,'-');
      strcpy(actual_topic_filetop->comment,actual_topic_intmain2->comment);
      actual_topic_filetop->begin = actual_topic_intmain2->begin;
      actual_topic_filetop->end = actual_topic_intmain2->end;
      }
    actual_topic_intmain2 = actual_topic_intmain2->next_topic;
    } // while
  // Create nodes relations
  find_nodes_relations();
  // Create Menu
  create_all_menu();
  // Rewind Temporary File (again) for starting writing sections, sub-sections
  // and transfering source lines
  actual_topic_filetop = first_topic_filetop;
  while (actual_topic_filetop != 0)
    {
    strcpy(buf,actual_topic_filetop->string);
    strcpy(buf2,actual_topic_filetop->next_node);
    strcpy(buf3,actual_topic_filetop->previous_node);
    buf[strlen(buf)-1] = '\0';
    buf2[strlen(buf2)-1] = '\0';
    buf3[strlen(buf3)-1] = '\0';
    creat_sub_section(buf,buf2,buf3,up_topic);
    start_line = actual_topic_filetop->begin;
    end_line = actual_topic_filetop->end;
    fputs("@flushleft\n",int2txi);
    // transfer lines and check for tables
    transfer_lines(start_line, end_line);
    fputs("@end flushleft\n",int2txi);
    actual_topic_filetop = actual_topic_filetop->next_topic;
    cprintf(".");
    } //while...
  cprintf("\n\r");
  } // int_process

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : process_chapter_3()                                        |
|  Description : Will process chapter 3                                     *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
int process_chapter_3()
  {
  // Buffers...
  char buf[90];
  char buf2[90];
  char buf3[90];
  int topics_number;  // File topics_number
  char temp[90];
  int valor_duplo; // Value returned when we chack for duplicate topics...
  int i = 0;

  if (check_file("OVERVIEW.LST",0) == 0)
    {
    cprintf("OVERVIEW.LST");
    load_source_file("OVERVIEW.LST");
    cprintf("\n\r Lines Loaded : %d\n\r",last_line->number); // to print the number of lines loaded from the file
    }
  else
    {
    fprintf(int2txi,"Not processed!!! OVERVIEW.LST wasn't found on the processing");
    cprintf("INTERRUP.LST will not be processed!!!\n\r");
    return(0);
    }
  // Find all topics
  actual_line = find_line(7);
  while (actual_line != 0)
    {
    strcpy(buf,actual_line->string);
    // Write topic
    put_topic_temp_intmain(buf,'{'); // put topic in the
      // IntMainTopics structure
    actual_line = actual_line->next_line;
    } // while
  // Create nodes relations
  find_nodes_relations_intmain();
  // Creat menu
  create_all_menu_intmain();
  // frees memory occupied by actual file
  unload_actual_file();
  unload_actual_topics_file();
  if (check_file("INTERRUP.LST",0) == 0)
    {
    cprintf("INTERRUP.LST");
    load_source_file("INTERRUP.LST");
    cprintf("\n\r Lines Loaded : %d\n\r",last_line->number); // to print the number of lines loaded from the file
    }
  else
    {
    fprintf(int2txi,"Not processed!!! INTERRUP.LST wasn't found on the processing");
    return(0);
    }
  // Get all topics
  // Start finding all topics on source file and copy them to tempfile
  // At the same time, check "line" value and process it...
  find_all_topics_intmain2(no_string_format);
  // Start the process to found duplicate topics
  find_duplicate_topics_intmain2();
  cprintf("\n\r");
  // Start processing every topic
  actual_topic_intmain = first_topic_intmain;
  while (actual_topic_intmain != 0)
    {
    strcpy(buf,actual_topic_intmain->string);
    strcpy(buf2,actual_topic_intmain->next_node);
    strcpy(buf3,actual_topic_intmain->previous_node);
    creat_section(buf,buf2,buf3,"Interrupts");
    i++;
    cprintf(" %d ",i);
    actual_topic_intmain = actual_topic_intmain->next_topic;
    // Start the processing of the sub_topics...
    int_process(buf);
    unload_actual_topics_file();
    }
  unload_actual_file();
  unload_actual_topics_file();
  } // process_chapter_3

//*************************************************************************//
//////////////////////////// C H A P T E R  12 //////////////////////////////
//*************************************************************************//

void process_chapter_12()
  {
  // Check if source file is present in the int2txi.exe directory.
  // If not, just print some warnings. So, the user SHOULD copy that files
  // to the same directory.
  if (check_file("86BUGS.LST",0) == 0)
    {
    copy_all_file("86BUGS.LST");
    cprintf("86BUGS.LST\n\r");
    }
    else fprintf(int2txi,"Not processed!!! 86BUGS.LST wasn't found on the processing");
  } // process_chapter_12
