/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : CHAPT_03.C                                             -
 - MODULE          : Module containing "Chapter 3" processing               -
 - PROGRAM         : int2txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.1.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01st July, 1998                                        -
 ----------------------------------------------------------------------------

*/
void get_all_topics()
  {
  // Buffers...
  char buf[255];
  char buf2[255];

  int topics_number,line;  // actual line
  int valor_duplo;         // Value returned when we check for duplicate
                           // topics...
  int index;

  line = 0;
  index = 0;
  valor_duplo = 0;
  topics_number = 0;
  while	((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
    // Increment line value
    line++;
    if (is_topic(buf) == 1)
      {
      // Get the next line on the source file to make it menu comment
      fgets(buf2, sizeof(buf2), sourcefile);
      // Increment line value
      line++;
      // Process the line to make it a comment line
      put_comment_temp(buf2,1);
      // Also copy the line to then do a compare
      fprintf(temp14_int_compare,buf2);
      // Update line value
      if (topics_number >= 1) fprintf(temp13_int_lines,"%d\n",line - 3);
      // Write topic
      put_topic_temp(buf,0,'-',1);
      // Update line value
      fprintf(temp13_int_lines,"%d\n",line);
      // Update topics_number value
      topics_number++;
      index++;
      if (index==10)
        {
        cprintf("_");
        index = 0;
        }
      } // if...
    } // while...
   // Update line value
  fprintf(temp13_int_lines,"%d\n",line);
  index = 0;
  // Go back to the beginning of temporary files
  rewind(temp11_int_topics);
  rewind(temp15_int_proc_topics);
  // Start the process to found duplicate topics
  while	((fgets(buf, sizeof(buf), temp11_int_topics)) != NULL)
    {
    // Check if topic already exists...
    valor_duplo = topic_check(buf);
    // Take off format char "\n" at the end of the string
    buf[strlen(buf)-1] = '\0';
    if (valor_duplo > 0)
      {
      fputs(buf, temp15_int_proc_topics);
      fprintf(temp15_int_proc_topics," (%d)\n",valor_duplo);
      fputs(buf, temp10_all_topics);
      fprintf(temp10_all_topics," (%d)\n",valor_duplo);
      } // if...
    else
      {
      fputs(buf, temp15_int_proc_topics);
      fputc('\n',temp15_int_proc_topics);
      fputs(buf, temp10_all_topics);
      fputc('\n',temp10_all_topics);
      } // else...
      index++;
      if (index==10)
        {
        cprintf("_");
        index = 0;
        }
    } // while...
  cprintf("\n\r");
  } // get_all topics

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
  topics_number	= 0;
  // Start finding all topics on source file and copy them to tempfile
  // At the same time, check "line" value and process it...
  while	((fgets(buf, sizeof(buf), temp15_int_proc_topics)) != NULL)
    {
    fgets(buf2, sizeof(buf2), temp12_int_comments);
    fgets(buf3, sizeof(buf3), temp13_int_lines);
    fgets(buf4, sizeof(buf4), temp13_int_lines);
    fgets(buf5, sizeof(buf5), temp14_int_compare);
    if (strncmp(buf5,up_topic,6) == 0)
      {
      fprintf(temp3_file_proc_topics,buf);
      fprintf(temp5_file_comments,buf2);
      fprintf(temp2_file_lines,buf3);
      fprintf(temp2_file_lines,buf4);
      topics_number++;
      }
    } // while
  // Open a new menu...
  fputs("@menu\n",int2txi);
  // Rewind Temporay File to check all topics and write them to the menu...
  rewind(temp3_file_proc_topics);
  rewind(temp5_file_comments);
  i = 0;
  while	(fgets(buf, sizeof(buf), temp3_file_proc_topics) != NULL)
    {
    if (i<topics_number)
      {
      fgets(buf2, sizeof(buf2), temp5_file_comments);
      // Take off format char "\n" at the end of the string
      buf[strlen(buf)-1] = '\0';
      buf2[strlen(buf2)-1] = '\0';
      creat_menu_item(buf,buf2);
      } // if...
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
  for(i=1;i<=topics_number;i++)
    {
    if (i == topics_number)
      {
      if (i==1)
        {
        fgets(buf3, sizeof(buf3), temp3_file_proc_topics);
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
	fgets(buf5, sizeof(buf5), temp3_file_proc_topics);
	buf5[strlen(buf5)-1] = '\0';
        creat_sub_section(buf4,buf5,buf3,up_topic);
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
      fgets(buf, sizeof(buf), temp2_file_lines);
      start_line = atoi(buf);
      fgets(buf, sizeof(buf), temp2_file_lines);
      end_line = atoi(buf);
      fputs("@flushleft\n",int2txi);
      temp_var = transfer_lines(prev_line,start_line, end_line);
      fputs("@end flushleft\n",int2txi);
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
  char tempstr[255];

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
  // Create Temporary Files
  temp1_file_topics = fopen("TEMPFILE.001","wt+");
  temp2_file_lines = fopen("TEMPFILE.002","wt+");
  temp3_file_proc_topics = fopen("TEMPFILE.003","wt+");
  temp5_file_comments = fopen("TEMPFILE.005","wt+");
  temp6_file_main_topics = fopen("TEMPFILE.006","wt+");
  // If file doesn't exist...
  if (check_file("OVERVIEW.LST",0) == 1)
    {
    fprintf(int2txi,"Not processed!!! OVERVIEW.LST wasn't found on the processing");
    }
  else
    {
    // Open source file
    sourcefile = fopen("OVERVIEW.LST","rt");
    // Create Temporary Files
    cprintf("OVERVIEW.LST\n\r");
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
      strcpy(tempstr,buf);
      find_and_change(buf,tempstr,0);
      if(cpy_line > 0) fputs(buf, temp6_file_main_topics);
      }
      rewind(temp6_file_main_topics);
      // Close source file
    fclose(sourcefile);
    // Open a new menu...
    fputs("@menu\n",int2txi);
    // Rewind Temporay File to check all topics and write them to the menu...
    topics_number = 0;
    rewind(temp6_file_main_topics);
    while ((fgets(buf, sizeof(buf), temp6_file_main_topics)) != NULL)
      {
      // Take off format char "\n" at the end of the string
      buf[strlen(buf)-1] = '\0';
      creat_menu_item(buf,"");
      topics_number++;
      } // while...
    // End menu
    fputs("@end menu\n",int2txi);
    rewind(temp6_file_main_topics);
    strcpy(buf,"");
    // If file doesn't exist...
    if (check_file("INTERRUP.LST",0) == 1)
      {
      fprintf(int2txi,"Not processed!!! INTERRUP.LST wasn't found on the processing");
      }
    else
      {
      cprintf("INTERRUP.LST ");
      // Open source file
      sourcefile = fopen("INTERRUP.LST","rt");
      temp11_int_topics = fopen("TEMPFILE.011","wt+");
      temp12_int_comments = fopen("TEMPFILE.012","wt+");
      temp13_int_lines = fopen("TEMPFILE.013","wt+");
      temp14_int_compare = fopen("TEMPFILE.014","wt+");
      temp15_int_proc_topics = fopen("TEMPFILE.015","wt+");
      get_all_topics();
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
          fgets(buf5, sizeof(buf5), temp6_file_main_topics);
          buf5[strlen(buf5)-1] = '\0';
          creat_section(buf4,buf5,buf3,"Interrupts");
          strcpy(buf,buf4);
	  }
        else
	  switch(i)
      	    {
	    case 1 : {
	   	     fgets(buf3, sizeof(buf3), temp6_file_main_topics);
		     fgets(buf4, sizeof(buf4), temp6_file_main_topics);
		     fgets(buf5, sizeof(buf5), temp6_file_main_topics);
		     buf3[strlen(buf3)-1] = '\0';
		     buf4[strlen(buf4)-1] = '\0';
		     buf5[strlen(buf5)-1] = '\0';
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
//        rewind(temp11_int_topics);
          rewind(temp12_int_comments);
          rewind(temp13_int_lines);
          rewind(temp14_int_compare);
          rewind(temp15_int_proc_topics);
          // Create Temporary Files
          temp1_file_topics = fopen("TEMPFILE.001","wt+");
          temp2_file_lines = fopen("TEMPFILE.002","wt+");
          temp3_file_proc_topics = fopen("TEMPFILE.003","wt+");
          temp5_file_comments = fopen("TEMPFILE.005","wt+");
          cprintf(" %d ",i);
          general_int_process(buf);
          // Close temporary files
          fclose(temp1_file_topics);
          fclose(temp2_file_lines);
          fclose(temp3_file_proc_topics);
          fclose(temp5_file_comments);
          // Delete temporary files
          remove("TEMPFILE.001");
          remove("TEMPFILE.002");
          remove("TEMPFILE.003");
          remove("TEMPFILE.005");
          } // if...
        } // for...
      // Close Source File
      fclose(sourcefile);
      // Close temporary files
      // Delete temporary files
      fclose(temp11_int_topics);
      fclose(temp12_int_comments);
      fclose(temp13_int_lines);
      fclose(temp14_int_compare);
      fclose(temp15_int_proc_topics);
      } // else INTERRUP
    } // else OVERVIEW
    // Close Source File
    fclose(sourcefile);
    // Close temporary files
    fclose(temp1_file_topics);
    fclose(temp2_file_lines);
    fclose(temp3_file_proc_topics);
    fclose(temp5_file_comments);
    fclose(temp6_file_main_topics);
    // Delete temporary files
    remove("TEMPFILE.001");
    remove("TEMPFILE.002");
    remove("TEMPFILE.003");
    remove("TEMPFILE.005");
    remove("TEMPFILE.006");
 }  //process_chapter_2_4

