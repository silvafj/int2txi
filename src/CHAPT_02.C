/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : CHAPT_02.C                                             -
 - MODULE          : Module containing "Chapter 2" processing               -
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
/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : process_chapter_2_1()                                      |
|  Description : Will process chapter 2, Section 1                          *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void process_chapter_2_1(void)
  {
  // Buffers...
  char buf[255];
  char buf2[255];
  char buf3[255];
  char buf4[255];
  char buf5[255];

  register int i,j;        // Values for loops...
  int topics_number,line;  // File topics_number, and actual line
  int start_line,end_line; // Self explicit
  int valor_duplo;         // Value returned when we chack for duplicate
                           // topics...

  // Initialize variables
  i = 0;
  j = 0;
  line = 0;
  end_line = 0;
  start_line = 0;
  valor_duplo = 0;
  topics_number	= 0;
  // Start finding all topics on source file and copy them to tempfile
  // At the same time, check "line" value and process it...
  while ((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
    line++;
    if (is_topic(buf) == 1)
      {
      // Update line value
      if (topics_number >= 1) fprintf(tempfile2,"%d\n",line - 2);
      // Write topic
      put_topic_temp(buf2,no_string_format,'!');
      // Update line value
      fprintf(tempfile2,"%d\n",line+1);
      // Update topics_number value
      topics_number++;
      } // if...
    // The real topic is the previous line...
    strcpy(buf2,buf);
    } // while...
   // Update line value
  fprintf(tempfile2,"%d\n",line);
  // Go back to the beginning of temporary files
  rewind(tempfile);
  rewind(tempfile3);
  // Start the process to found duplicate topics
  while	((fgets(buf, sizeof(buf), tempfile)) != NULL)
    {
    // Check if topic already exists...
    valor_duplo = topic_check(buf);
    // Take off format char "\n" at the end of the string
    buf[strlen(buf)-1] = '\0';
    if (valor_duplo > 0)
      {
      fputs(buf, tempfile3);
      fprintf(tempfile3," (%d)\n",valor_duplo);
      fputs(buf, tempfile4);
      fprintf(tempfile4," (%d)\n",valor_duplo);
      } // if...
    else
      {
      fputs(buf, tempfile3);
      fputc('\n',tempfile3);
      fputs(buf, tempfile4);
      fputc('\n',tempfile4);
      } // else...
    } // while...
  // Open a new menu...
  fputs("@menu\n",Int2TeX);
  // Rewind Temporay File to check all topics and write them to the menu...
  rewind(tempfile);
  i = 0;
  while ((fgets(buf, sizeof(buf), tempfile)) != NULL)
    {
    if (i<topics_number - 1)
      {
      // Take off format char "\n" at the end of the string
      buf[strlen(buf)-1] = '\0';
      creat_menu_item(buf,"",automa_item);
      } //if...
      i++;
    } // while...
  // End menu
  fputs("@end menu\n",Int2TeX);
  // Rewind Temporary File (again) for starting writing sections, sub-sections
  // and transfering source lines
  rewind(tempfile3);
  rewind(tempfile2);
  // Rewind Source File to start transfering source lines.
  rewind(sourcefile);
  for(i=1;i<topics_number;i++)
    {
    if (i == topics_number - 1)
      {
      creat_sub_section(buf5,"",buf4,"iAPX 86 Interrupt Primer");
      }
    else
      if (i >= 3)
        {
        strcpy(buf3,buf4);
        strcpy(buf4,buf5);
        fgets(buf5, sizeof(buf5), tempfile3);
        buf5[strlen(buf5)-1] = '\0';
        creat_sub_section(buf4,buf5,buf3,"iAPX 86 Interrupt Primer");
        }
      else
        switch(i)
          {
          case 1 : {
                   fgets(buf3, sizeof(buf3), tempfile3);
                   fgets(buf4, sizeof(buf4), tempfile3);
                   fgets(buf5, sizeof(buf5), tempfile3);
                   buf3[strlen(buf3)-1] = '\0';
                   buf4[strlen(buf4)-1] = '\0';
                   buf5[strlen(buf5)-1] = '\0';
                   creat_sub_section(buf3,buf4,"","iAPX 86 Interrupt Primer");
                   break;
                   }
          case 2 : {
                   creat_sub_section(buf4,buf5,buf3,"iAPX 86 Interrupt Primer");
                   break;
                   }
          } // Switch (i)
    if (i < topics_number)
      {
      fgets(buf, sizeof(buf), tempfile2);
      start_line = atoi(buf);
      fgets(buf, sizeof(buf), tempfile2);
      end_line = atoi(buf);
      transfer_lines(0,start_line, end_line);
      } //if...
    } // for...
  }  //process_chapter_2_1

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : process_chapter_2_2()                                      |
|  Description : Will process chapter 2, Section 2                          *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void process_chapter_2_2(void)
  {
  // Buffers...
  char buf[255];
  char buf2[255];
  char buf3[255];
  char buf4[255];
  char buf5[255];

  register int i,j;        // Values for loops...
  int topics_number,line;  // File topics_number, and actual line
  int start_line,end_line; // Self explicit
  int valor_duplo;         // Value returned when we chack for duplicate
                           // topics...

  // Initialize variables
  i = 0;
  j = 0;
  line = 0;
  end_line = 0;
  start_line = 0;
  valor_duplo = 0;
  topics_number	= 0;
  fprintf(tempfile2,"%d\n",4);
  // Start finding all topics on source file and copy them to tempfile
  // At the same time, check "line" value and process it...
  while ((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
    line++;
    if (is_topic(buf) == 1)
      {
      topics_number++;
      }
    if ((is_topic(buf) == 1) && (topics_number <= 4) && (topics_number%2==0))
      {
      fprintf(tempfile2,"%d\n",line - 3);
      put_topic_temp(buf2,no_string_format,':');
      fprintf(tempfile2,"%d\n",line+1);
      }
    strcpy(buf2,buf);
    }
  fprintf(tempfile2,"%d\n",line);
  // Open a new menu...
  rewind(tempfile2);
  fgets(buf, sizeof(buf), tempfile2);
  start_line = atoi(buf);
  fgets(buf, sizeof(buf), tempfile2);
  end_line = atoi(buf);
  fputs("@flushleft\n",Int2TeX);
  transfer_lines(0,start_line, end_line);
  fputs("@end flushleft\n",Int2TeX);
  // Go back to the beginning of temporary files
  rewind(tempfile);
  rewind(tempfile3);
  // Start the process to found duplicate topics
  while	((fgets(buf, sizeof(buf), tempfile)) != NULL)
    {
    // Check if topic already exists...
    valor_duplo = topic_check(buf);
    // Take off format char "\n" at the end of the string
    buf[strlen(buf)-1] = '\0';
    if (valor_duplo > 0)
      {
      fputs(buf, tempfile3);
      fprintf(tempfile3," (%d)\n",valor_duplo);
      fputs(buf, tempfile4);
      fprintf(tempfile4," (%d)\n",valor_duplo);
      } // if...
    else
      {
      fputs(buf, tempfile3);
      fputc('\n',tempfile3);
      fputs(buf, tempfile4);
      fputc('\n',tempfile4);
      } // else...
    } // while...
  fputs("@menu\n",Int2TeX);
  // Rewind Temporay File to check all topics and write them to the menu...
  rewind(tempfile3);
  i = 0;
  while ((fgets(buf, sizeof(buf), tempfile3)) != NULL)
    {
    if (i<topics_number)
      {
      buf[strlen(buf)-1] = '\0';
      creat_menu_item(buf,"",automa_item);
      }
      i++;
    }
  fputs("@end menu\n",Int2TeX);
  // Rewind Temporay File to check all topics and write them to the menu...
  rewind(tempfile3);
  fgets(buf2, sizeof(buf2), tempfile3);
  fgets(buf3, sizeof(buf3), tempfile3);
  buf2[strlen(buf2)-1] = '\0';
  buf3[strlen(buf3)-1] = '\0';
  creat_sub_section(buf2,buf3,"Public Domain/Freeware/Shareware by Ralf Brown","Public Domain/Freeware/Shareware by Ralf Brown");
  fgets(buf, sizeof(buf), tempfile2);
  start_line = atoi(buf);
  fgets(buf, sizeof(buf), tempfile2);
  end_line = atoi(buf);
  fputs("@flushleft\n",Int2TeX);
  transfer_lines(0,start_line, end_line);
  fputs("@end flushleft\n",Int2TeX);
  creat_sub_section(buf3,"",buf2,"Public Domain/Freeware/Shareware by Ralf Brown");
  fgets(buf, sizeof(buf), tempfile2);
  start_line = atoi(buf);
  fgets(buf, sizeof(buf), tempfile2);
  end_line = atoi(buf);
  fputs("@flushleft\n",Int2TeX);
  transfer_lines(0,start_line, end_line);
  fputs("@end flushleft\n",Int2TeX);
 } // process_chapter_2_2

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : process_chapter_2_3()                                      |
|  Description : Will process chapter 2, Section 3                          *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void process_chapter_2_3(void)
  {
  // Buffers...
  char buf[255];
  char buf2[255];
  char buf3[255];
  char buf4[255];
  char buf5[255];

  register int i,j;        // Values for loops...
  int topics_number,line;  // File topics_number, and actual line
  int start_line,end_line; // Self explicit
  int valor_duplo;         // Value returned when we chack for duplicate
                           // topics...

  // Initialize variables
  i = 0;
  j = 0;
  line = 0;
  end_line = 0;
  start_line = 0;
  valor_duplo = 0;
  topics_number	= 0;
  strcpy(buf3,"");
  while	((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
    line++;
    if (strlen(buf) == 1)
      {
      fgets(buf2, sizeof(buf2),	sourcefile);
      line++;
      if (strcmp(buf2,"\n") != 0)
	{
	put_topic_temp(buf2,no_string_format,'!');
	if (topics_number >= 1)	fprintf(tempfile2,"%d\n",line -	1);
	fprintf(tempfile2,"%d\n",line+1);
	topics_number++;
	}
      }
    }
  fprintf(tempfile2,"%d\n",line);
  // Go back to the beginning of temporary files
  rewind(tempfile);
  rewind(tempfile3);
  // Start the process to found duplicate topics
  while	((fgets(buf, sizeof(buf), tempfile)) != NULL)
    {
    // Check if topic already exists...
    valor_duplo = topic_check(buf);
    // Take off format char "\n" at the end of the string
    buf[strlen(buf)-1] = '\0';
    if (valor_duplo > 0)
      {
      fputs(buf, tempfile3);
      fprintf(tempfile3," (%d)\n",valor_duplo);
      fputs(buf, tempfile4);
      fprintf(tempfile4," (%d)\n",valor_duplo);
      } // if...
    else
      {
      fputs(buf, tempfile3);
      fputc('\n',tempfile3);
      fputs(buf, tempfile4);
      fputc('\n',tempfile4);
      } // else...
    } // while...
  // Open a new menu...
  fputs("@menu\n",Int2TeX);
  // Rewind Temporay File to check all topics and write them to the menu...
  rewind(tempfile3);
  i = 0;
  while	((fgets(buf, sizeof(buf), tempfile3)) !=NULL)
    {
    if (i<topics_number)
      {
      buf[strlen(buf)-1] = '\0';
      creat_menu_item(buf,"",automa_item);
      }
      i++;
    }
  fputs("@end menu\n",Int2TeX);
  // Rewind Temporary File (again) to check topics...
  rewind(tempfile3);
  rewind(tempfile2);
  // Rewind Source File To start making sections...
  rewind(sourcefile);
  for(i=1;i<=topics_number;i++)
    {
      if (i == topics_number)
	{
	creat_sub_section(buf5,"",buf4,"Glossary");
	}
      else
      if (i >= 3)
	{
	strcpy(buf3,buf4);
	strcpy(buf4,buf5);
	fgets(buf5, sizeof(buf5), tempfile3);
	buf5[strlen(buf5)-1] = '\0';
	creat_sub_section(buf4,buf5,buf3,"Glossary");
	}
      else
	switch(i)
	  {
	  case 1 : {
		   fgets(buf3, sizeof(buf3), tempfile3);
		   fgets(buf4, sizeof(buf4), tempfile3);
		   fgets(buf5, sizeof(buf5), tempfile3);
		   buf3[strlen(buf3)-1]	= '\0';
		   buf4[strlen(buf4)-1]	= '\0';
		   buf5[strlen(buf5)-1]	= '\0';
		   creat_sub_section(buf3,buf4,"","Glossary");
		   break;
		   }
	  case 2 : {
		   creat_sub_section(buf4,buf5,buf3,"Glossary");
		   break;
		   }
	} // Switch (i)
	if (i <	topics_number)
	 {
	   fgets(buf, sizeof(buf), tempfile2);
	   start_line =	atoi(buf);
	   fgets(buf, sizeof(buf), tempfile2);
	   end_line = atoi(buf);
	   transfer_lines(0,start_line, end_line);
	 }
      }	// for
  cprintf("\n\r");
  }  //process_chapter_2_3

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : process_chapter_2_4()                                      |
|  Description : Will process chapter 2, Section 4                          *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void process_chapter_2_4(void)
  {
  general_processing_rotine(1,"Bibliography",string_format);
  }  //process_chapter_2_4

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
  fputs("@menu\n",Int2TeX);
  creat_menu_item("iAPX 86 Interrupt Primer","",manual_item);
  creat_menu_item("Public Domain/Freeware/Shareware by Ralf Brown","",manual_item);
  creat_menu_item("Glossary","",manual_item);
  creat_menu_item("Bibliography","",manual_item);
  // End menu
  fputs("@end menu\n",Int2TeX);
  // Start the inicialization to process INTERRUP.PRI
  creat_section("iAPX 86 Interrupt Primer","Public Domain/Freeware/Shareware by Ralf Brown","Overview","Overview");
  // Open source file
  sourcefile = fopen("INTERRUP.PRI","rt");
  printf("INTERRUP.PRI\n");
  // Check if source file is present in the Int2TeX.exe directory.
  // If not, just print some warnings. So, the user SHOULD copy that files
  // to the same directory.
  check_file("INTERRUP.PRI");
  // Create Temporary Files
  tempfile = fopen("TEMPFILE.001","wt+");
  tempfile2 = fopen("TEMPFILE.002","wt+");
  tempfile3 = fopen("TEMPFILE.003","wt+");
  // process INTERRUP.PRI
  // This file has a special processing...
  process_chapter_2_1();
  // Close Source File
  fclose(sourcefile);
  // Close temporary files
  fclose(tempfile);
  fclose(tempfile2);
  fclose(tempfile3);
  // Delete temporary files
  unlink("TEMPFILE.001");
  unlink("TEMPFILE.002");
  unlink("TEMPFILE.003");
  creat_section("Public Domain/Freeware/Shareware by Ralf Brown","Glossary","iAPX 86 Interrupt Primer","Overview");
  // Open source file
  sourcefile = fopen("RBROWN.TXT","rt");
  // Create Temporary Files
  tempfile = fopen("TEMPFILE.001","wt+");
  tempfile2 = fopen("TEMPFILE.002","wt+");
  tempfile3 = fopen("TEMPFILE.003","wt+");
  printf("RBROWN.TXT\n");
  // Check if source file is present in the Int2TeX.exe directory.
  // If not, just print some warnings. So, the user SHOULD copy that files
  // to the same directory.
  check_file("RBROWN.TXT");
  // process RBROWN.TXT
  // This file has a special processing...
  process_chapter_2_2();
  // Close Source File
  fclose(sourcefile);
  // Close temporary files
  fclose(tempfile);
  fclose(tempfile2);
  fclose(tempfile3);
  // Delete temporary files
  unlink("TEMPFILE.001");
  unlink("TEMPFILE.002");
  unlink("TEMPFILE.003");
  creat_section("Glossary","Bibliography","Public Domain/Freeware/Shareware by Ralf Brown","Overview");
  // Open source file
  sourcefile = fopen("GLOSSARY.LST","rt");
  // Create Temporary Files
  tempfile = fopen("TEMPFILE.001","wt+");
  tempfile2 = fopen("TEMPFILE.002","wt+");
  tempfile3 = fopen("TEMPFILE.003","wt+");
  cprintf("GLOSSARY.LST ");
  // Check if source file is present in the Int2TeX.exe directory.
  // If not, just print some warnings. So, the user SHOULD copy that files
  // to the same directory.
  check_file("GLOSSARY.LST");
  // process GLOSSARY.LST
  // This file has a special processing...
  process_chapter_2_3();
  // Close Source File
  fclose(sourcefile);
  // Close temporary files
  fclose(tempfile);
  fclose(tempfile2);
  fclose(tempfile3);
  // Delete temporary files
  unlink("TEMPFILE.001");
  unlink("TEMPFILE.002");
  unlink("TEMPFILE.003");
  creat_section("Bibliography","","Glossary","Overview");
  // Open source file
  sourcefile = fopen("BIBLIO.LST","rt");
  // Create Temporary Files
  tempfile = fopen("TEMPFILE.001","wt+");
  tempfile2 = fopen("TEMPFILE.002","wt+");
  tempfile3 = fopen("TEMPFILE.003","wt+");
  cprintf("BIBLIO.LST ");
  // Check if source file is present in the Int2TeX.exe directory.
  // If not, just print some warnings. So, the user SHOULD copy that files
  // to the same directory.
  check_file("BIBLIO.LST");
  // process BIBLIO.LST
  // This file as a normal (general) processing...
  process_chapter_2_4();
  // Close Source File
  fclose(sourcefile);
  // Close temporary files
  fclose(tempfile);
  fclose(tempfile2);
  fclose(tempfile3);
  // Delete temporary files
  unlink("TEMPFILE.001");
  unlink("TEMPFILE.002");
  unlink("TEMPFILE.003");
  } //process_chapter_2
