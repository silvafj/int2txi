/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : CHAPT_03.C                                             -
 - MODULE          : Module containing "Chapter 3" processing               -
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
int general_int_process(char *up_topic)
  {
  // Buffers...
  char buf[255];
  char buf2[255];
  char buf3[255];
  char buf4[255];
  char buf5[255];

  register int i,j;        // Values for loops...
  int topics_number,line;  // File topics_number, and actual line
  int last_line,temp_var,prev_line,start_line,end_line; // Self explicit
  int valor_duplo;         // Value returned when we chack for duplicate
                           // topics...

  // Initialize variables
  strcpy(buf,"");
  strcpy(buf2,"");
  strcpy(buf3,"");
  strcpy(buf4,"");
  strcpy(buf5,"");
  i = 0;
  j = 0;
  line = 0;
  temp_var = 0;
  end_line = 0;
  prev_line = 0;
  last_line = 0;
  start_line = 0;
  valor_duplo = 0;
  topics_number	= 0;
  // Start finding all topics on source file and copy them to tempfile
  // At the same time, check "line" value and process it...
  while	((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
    line++;
    if (is_topic(buf) == 1)
      {
      fgets(buf2, sizeof(buf2), sourcefile);
      if (strncmp(buf2,up_topic,6) == 0)
        {
        put_comment_temp(buf2);
        // Update line value
        if (topics_number >= 1) fprintf(tempfile2,"%d\n",line - 1);
        // Write topic
        put_topic_temp(buf,no_string_format,'-');
        // Update line value
        fprintf(tempfile2,"%d\n",line+1);
        // Update topics_number value
        topics_number++;
        last_line = line;
        }
      else
        {
        if (last_line > 0) break;
        }
        line++;
      } // if...
    } // while...
    fprintf(tempfile2,"%d\n",line - 1);
   // Update line value
  // Go back to the beginning of temporary files
  rewind(tempfile);
  rewind(tempfile3);
  // Start the process to found duplicate topics
  while	((fgets(buf, sizeof(buf), tempfile)) != NULL)
    {
    // Bug correction for file CMOS.LST
    if (strcmp(buf,"\n") == 0) strcpy(buf,"Information\n");
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
    cprintf("_");
    } // while...
  // Open a new menu...
  fputs("@menu\n",Int2TeX);
  // Rewind Temporay File to check all topics and write them to the menu...
  rewind(tempfile3);
  rewind(tempfile5);
  i = 0;
  while	(fgets(buf, sizeof(buf), tempfile3) != NULL)
    {
    if (i<topics_number)
      {
      fgets(buf2, sizeof(buf2), tempfile5);
      // Take off format char "\n" at the end of the string
      buf[strlen(buf)-1] = '\0';
      buf2[strlen(buf2)-1] = '\0';
      creat_menu_item(buf,buf2,automa_item);
      } // if...
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
  for(i=1;i<=topics_number;i++)
    {
    if (i == topics_number)
      {
      if (i==1)
        {
        fgets(buf3, sizeof(buf3), tempfile3);
	buf3[strlen(buf3)-1] = '\0';
        creat_sub_section(buf3,"","",up_topic);
        }
      if (i==2) creat_sub_section(buf4,"",buf3,up_topic);
      if (i>2) creat_sub_section(buf5,"",buf4,up_topic);
      }
    else
      if (i >= 3)
	{
	strcpy(buf3,buf4);
	strcpy(buf4,buf5);
	fgets(buf5, sizeof(buf5), tempfile3);
	buf5[strlen(buf5)-1] = '\0';
        creat_sub_section(buf4,buf5,buf3,up_topic);
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
                   creat_sub_section(buf3,buf4,"",up_topic);
		   break;
		   }
	  case 2 : {
                   creat_sub_section(buf4,buf5,buf3,up_topic);
		   break;
		   }
	  } // Switch (i)
    if (i <=topics_number)
      {
      fgets(buf, sizeof(buf), tempfile2);
      start_line = atoi(buf);
      fgets(buf, sizeof(buf), tempfile2);
      end_line = atoi(buf);
      fputs("@flushleft\n",Int2TeX);
      temp_var = transfer_lines(prev_line,start_line, end_line);
      fputs("@end flushleft\n",Int2TeX);
      cprintf(".");
      prev_line = temp_var;
      } // if...
    } // for...
    cprintf("\n\r");
} // general_int_process



void process_chapter_3(void)
  {
  // Buffers...
  char buf[255];
  char buf2[255];
  char buf3[255];
  char buf4[255];
  char buf5[255];

  register int i,j;        // Values for loops...
  int topics_number,cpy_line,line;  // File topics_number, and actual line
  int start_line,end_line; // Self explicit
  int valor_duplo;         // Value returned when we chack for duplicate
                           // topics...

  // Initialize variables
  i = 0;
  j = 0;
  line = 0;
  cpy_line = 0;
  end_line = 0;
  start_line = 0;
  valor_duplo = 0;
  topics_number	= 0;
  // Open source file
  sourcefile = fopen("OVERVIEW.LST","rt");
  // Create Temporary Files
  printf("OVERVIEW.LST\n");
  // Check if source file is present in the Int2TeX.exe directory.
  // If not, just print some warnings. So, the user SHOULD copy that files
  // to the same directory.
  check_file("OVERVIEW.LST");
  // Start finding all topics on source file and copy them to tempfile
  // At the same time, check "line" value and process it...
  while ((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
    line++;
    if (is_topic(buf) == 1)
      {
      cpy_line = line + 1;
      fgets(buf, sizeof(buf), sourcefile);
      line++;
      } // if...
  j = 0;
  while (j!=-1)
    {
    j = strfind(buf,'@',j+1);
    if (j!=-1) buf[j] = '$';
    }
  j = 0;
  while (j!=-1)
    {
    j = strfind(buf,'{',j+1);
    if (j!=-1) buf[j] = '[';
    }
  j = 0;
  while (j!=-1)
    {
    j = strfind(buf,'}',j+1);
    if (j!=-1) buf[j] = ']';
    }
  j = 0;
  while (j!=-1)
    {
    j = strfind(buf,':',j+1);
    if (j!=-1) buf[j] = ';';
    }
  j = 0;
  while (j!=-1)
    {
    j = strfind(buf,9,j+1);
    if (j!=-1) buf[j] = ' ';
    }
  j = 0;
  while (j!=-1)
    {
    j = strfind(buf,',',j+1);
    if (j!=-1) buf[j] = ';';
    }
    if(cpy_line > 0) fputs(buf, tempfile6);
    }
  rewind(tempfile6);
  // Close source file
  fclose(sourcefile);
  // Open a new menu...
  fputs("@menu\n",Int2TeX);
  // Rewind Temporay File to check all topics and write them to the menu...
  topics_number = 0;
  rewind(tempfile6);
  while ((fgets(buf, sizeof(buf), tempfile6)) != NULL)
    {
    // Take off format char "\n" at the end of the string
    buf[strlen(buf)-1] = '\0';
    creat_menu_item(buf,"",automa_item);
    topics_number++;
    } // while...
  // End menu
  fputs("@end menu\n",Int2TeX);
  rewind(tempfile6);
  strcpy(buf,"");
  cprintf("INTERRUPT.LST ");
  // Check if source file is present in the Int2TeX.exe directory.
  // If not, just print some warnings. So, the user SHOULD copy that files
  // to the same directory.
  check_file("INTERRUP.LST");
  for(i=1;i<=topics_number;i++)
    {
    if (i == topics_number)
      {
      creat_section(buf5,"",buf4,"Interrupts");
      strcpy(buf,buf5);
      }
    else
      if (i >= 3)
	{
	strcpy(buf3,buf4);
	strcpy(buf4,buf5);
	fgets(buf5, sizeof(buf5), tempfile6);
	buf5[strlen(buf5)-1] = '\0';
        creat_section(buf4,buf5,buf3,"Interrupts");
        strcpy(buf,buf4);
	}
      else
	switch(i)
	  {
	  case 1 : {
		   fgets(buf3, sizeof(buf3), tempfile6);
		   fgets(buf4, sizeof(buf4), tempfile6);
		   fgets(buf5, sizeof(buf5), tempfile6);
		   buf3[strlen(buf3)-1]	= '\0';
		   buf4[strlen(buf4)-1]	= '\0';
		   buf5[strlen(buf5)-1]	= '\0';
                   creat_section(buf3,buf4,"","Interrupts");
                   strcpy(buf,buf3);
		   break;
		   }
	  case 2 : {
                   creat_section(buf4,buf5,buf3,"Interrupts");
                   strcpy(buf,buf4);
                   break;
		   }
	  } // Switch (i)
    if (i <=topics_number)
      {
  // Open source file
  sourcefile = fopen("INTERRUP.LST","rt");
  // Create Temporary Files
  tempfile = fopen("TEMPFILE.001","wt+");
  tempfile2 = fopen("TEMPFILE.002","wt+");
  tempfile3 = fopen("TEMPFILE.003","wt+");
  tempfile5 = fopen("TEMPFILE.005","wt+");
  general_int_process(buf);
  cprintf(" %d ",i);
  // Close Source File
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
      } // if...
    } // for...
  // Close temporary files
  // Delete temporary files
  }  //process_chapter_2_4

