/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : CHAPT_02.C                                             -
 - MODULE          : Module containing "Chapter 2" processing               -
 - PROGRAM         : int2txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.1.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01st July, 1998                                        -
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
      if (topics_number >= 1) fprintf(temp2_file_lines,"%d\n",line - 2);
      // Write topic
      put_topic_temp(buf2,no_string_format,'!',0);
      // Update line value
      fprintf(temp2_file_lines,"%d\n",line+1);
      // Update topics_number value
      topics_number++;
      } // if...
    // The real topic is the previous line...
    strcpy(buf2,buf);
    } // while...
   // Update line value
  fprintf(temp2_file_lines,"%d\n",line);
  // Go back to the beginning of temporary files
  rewind(temp1_file_topics);
  // Start the process to found duplicate topics
  while	((fgets(buf, sizeof(buf), temp1_file_topics)) != NULL)
    {
    // Check if topic already exists...
    valor_duplo = topic_check(buf);
    // Take off format char "\n" at the end of the string
    buf[strlen(buf)-1] = '\0';
    if (valor_duplo > 0)
      {
      fputs(buf, temp3_file_proc_topics);
      fprintf(temp3_file_proc_topics," (%d)\n",valor_duplo);
      fputs(buf, temp10_all_topics);
      fprintf(temp10_all_topics," (%d)\n",valor_duplo);
      } // if...
    else
      {
      fputs(buf, temp3_file_proc_topics);
      fputc('\n',temp3_file_proc_topics);
      fputs(buf, temp10_all_topics);
      fputc('\n',temp10_all_topics);
      } // else...
    } // while...
  // Open a new menu...
  fputs("@menu\n",int2txi);
  // Rewind Temporay File to check all topics and write them to the menu...
  rewind(temp1_file_topics);
  i = 0;
  while ((fgets(buf, sizeof(buf), temp1_file_topics)) != NULL)
    {
    if (i<topics_number - 1)
      {
      // Take off format char "\n" at the end of the string
      buf[strlen(buf)-1] = '\0';
      creat_menu_item(buf,"");
      } //if...
      i++;
    } // while...
  // End menu
  fputs("@end menu\n",int2txi);
  // Rewind Temporary File (again) for starting writing sections, sub-sections
  // and transfering source lines
  rewind(temp3_file_proc_topics);
  rewind(temp2_file_lines);
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
        fgets(buf5, sizeof(buf5), temp3_file_proc_topics);
        buf5[strlen(buf5)-1] = '\0';
        creat_sub_section(buf4,buf5,buf3,"iAPX 86 Interrupt Primer");
        }
      else
        switch(i)
          {
          case 1 : {
                   fgets(buf3, sizeof(buf3), temp3_file_proc_topics);
                   fgets(buf4, sizeof(buf4), temp3_file_proc_topics);
                   fgets(buf5, sizeof(buf5), temp3_file_proc_topics);
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
      fgets(buf, sizeof(buf), temp2_file_lines);
      start_line = atoi(buf);
      fgets(buf, sizeof(buf), temp2_file_lines);
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
  char buf[255];
  char tempstr[200];

  fputs("@flushleft\n",int2txi);
  while ((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
    strcpy(tempstr,buf);
    find_and_change(buf,tempstr,1);
    fputs(buf, int2txi);
    }
  fputs("@end flushleft\n",int2txi);
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
	put_topic_temp(buf2,no_string_format,'!',0);
	if (topics_number >= 1)	fprintf(temp2_file_lines,"%d\n",line -	1);
	fprintf(temp2_file_lines,"%d\n",line+1);
	topics_number++;
	}
      }
    }
  fprintf(temp2_file_lines,"%d\n",line);
  // Go back to the beginning of temporary files
  rewind(temp1_file_topics);
  rewind(temp3_file_proc_topics);
  // Start the process to found duplicate topics
  while	((fgets(buf, sizeof(buf), temp1_file_topics)) != NULL)
    {
    // Check if topic already exists...
    valor_duplo = topic_check(buf);
    // Take off format char "\n" at the end of the string
    buf[strlen(buf)-1] = '\0';
    if (valor_duplo > 0)
      {
      fputs(buf, temp3_file_proc_topics);
      fprintf(temp3_file_proc_topics," (%d)\n",valor_duplo);
      fputs(buf, temp10_all_topics);
      fprintf(temp10_all_topics," (%d)\n",valor_duplo);
      } // if...
    else
      {
      fputs(buf, temp3_file_proc_topics);
      fputc('\n',temp3_file_proc_topics);
      fputs(buf, temp10_all_topics);
      fputc('\n',temp10_all_topics);
      } // else...
    } // while...
  // Open a new menu...
  fputs("@menu\n",int2txi);
  // Rewind Temporay File to check all topics and write them to the menu...
  rewind(temp3_file_proc_topics);
  i = 0;
  while	((fgets(buf, sizeof(buf), temp3_file_proc_topics)) !=NULL)
    {
    if (i<topics_number)
      {
      buf[strlen(buf)-1] = '\0';
      creat_menu_item(buf,"");
      }
      i++;
    }
  fputs("@end menu\n",int2txi);
  // Rewind Temporary File (again) to check topics...
  rewind(temp3_file_proc_topics);
  rewind(temp2_file_lines);
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
	fgets(buf5, sizeof(buf5), temp3_file_proc_topics);
	buf5[strlen(buf5)-1] = '\0';
	creat_sub_section(buf4,buf5,buf3,"Glossary");
	}
      else
	switch(i)
	  {
	  case 1 : {
		   fgets(buf3, sizeof(buf3), temp3_file_proc_topics);
		   fgets(buf4, sizeof(buf4), temp3_file_proc_topics);
		   fgets(buf5, sizeof(buf5), temp3_file_proc_topics);
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
	   fgets(buf, sizeof(buf), temp2_file_lines);
	   start_line =	atoi(buf);
	   fgets(buf, sizeof(buf), temp2_file_lines);
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
  general_processing_rotine(1,"Bibliography (1)",string_format,1);
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
  fputs("@menu\n",int2txi);
  creat_menu_item("iAPX 86 Interrupt Primer","");
  creat_menu_item("Public Domain/Freeware/Shareware by Ralf Brown","");
  creat_menu_item("Glossary","");
  creat_menu_item("Bibliography (1)","");
  // End menu
  fputs("@end menu\n",int2txi);
  // Start the inicialization to process INTERRUP.PRI
  creat_section("iAPX 86 Interrupt Primer","Public Domain/Freeware/Shareware by Ralf Brown","Overview","Overview");
  // Check if source file is present in the int2txi.exe directory.
  if (check_file("INTERRUP.PRI",0) == 0)
    {
    // Open source file
    sourcefile = fopen("INTERRUP.PRI","rt");
    cprintf("INTERRUP.PRI\n\r");
    // Create Temporary Files
    temp1_file_topics = fopen("TEMPFILE.001","wt+");
    temp2_file_lines = fopen("TEMPFILE.002","wt+");
    temp3_file_proc_topics = fopen("TEMPFILE.003","wt+");
    // process INTERRUP.PRI
    // This file has a special processing...
    process_chapter_2_1();
    // Close Source File
    fclose(sourcefile);
    // Close temporary files
    fclose(temp1_file_topics);
    fclose(temp2_file_lines);
    fclose(temp3_file_proc_topics);
    // Delete temporary files
    remove("TEMPFILE.001");
    remove("TEMPFILE.002");
    remove("TEMPFILE.003");
    }
  else fprintf(int2txi,"Not processed!!! INTERRUP.PRI wasn't found on the processing");
  creat_section("Public Domain/Freeware/Shareware by Ralf Brown","Glossary","iAPX 86 Interrupt Primer","Overview");
  // Check if source file is present in the int2txi.exe directory.
  if (check_file("RBROWN.TXT",0) == 0)
    {
    // Open source file
    sourcefile = fopen("RBROWN.TXT","rt");
    // Create Temporary Files
    temp1_file_topics = fopen("TEMPFILE.001","wt+");
    temp2_file_lines = fopen("TEMPFILE.002","wt+");
    temp3_file_proc_topics = fopen("TEMPFILE.003","wt+");
    cprintf("RBROWN.TXT\n\r");
    // process RBROWN.TXT
    // This file has a special processing...
    process_chapter_2_2();
    // Close Source File
    fclose(sourcefile);
    // Close temporary files
    fclose(temp1_file_topics);
    fclose(temp2_file_lines);
    fclose(temp3_file_proc_topics);
    // Delete temporary files
    remove("TEMPFILE.001");
    remove("TEMPFILE.002");
    remove("TEMPFILE.003");
    }
  else fprintf(int2txi,"Not processed!!! RBROWN.TXT wasn't found on the processing");
  creat_section("Glossary","Bibliography (1)","Public Domain/Freeware/Shareware by Ralf Brown","Overview");
  if (check_file("GLOSSARY.LST",0) == 0)
    {
    // Open source file
    sourcefile = fopen("GLOSSARY.LST","rt");
    // Create Temporary Files
    temp1_file_topics = fopen("TEMPFILE.001","wt+");
    temp2_file_lines = fopen("TEMPFILE.002","wt+");
    temp3_file_proc_topics = fopen("TEMPFILE.003","wt+");
    cprintf("GLOSSARY.LST");
    // process GLOSSARY.LST
    // This file has a special processing...
    process_chapter_2_3();
    // Close Source File
    fclose(sourcefile);
    // Close temporary files
    fclose(temp1_file_topics);
    fclose(temp2_file_lines);
    fclose(temp3_file_proc_topics);
    // Delete temporary files
    remove("TEMPFILE.001");
    remove("TEMPFILE.002");
    remove("TEMPFILE.003");
    }
  else fprintf(int2txi,"Not processed!!! GLOSSARY.LST wasn't found on the processing");
  creat_section("Bibliography (1)","","Glossary","Overview");
  if (check_file("BIBLIO.LST",0) == 0)
    {
    // Open source file
    sourcefile = fopen("BIBLIO.LST","rt");
    // Create Temporary Files
    temp1_file_topics = fopen("TEMPFILE.001","wt+");
    temp2_file_lines = fopen("TEMPFILE.002","wt+");
    temp3_file_proc_topics = fopen("TEMPFILE.003","wt+");
    cprintf("BIBLIO.LST ");
    // process BIBLIO.LST
    // This file as a normal (general) processing...
    process_chapter_2_4();
    // Close Source File
    fclose(sourcefile);
    // Close temporary files
    fclose(temp1_file_topics);
    fclose(temp2_file_lines);
    fclose(temp3_file_proc_topics);
    // Delete temporary files
    remove("TEMPFILE.001");
    remove("TEMPFILE.002");
    remove("TEMPFILE.003");
    }
  else fprintf(int2txi,"Not processed!!! BIBLIO.LST wasn't found on the processing");
  } //process_chapter_2
