/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : NODES.C                                                -
 - MODULE          : Module containing rotines for convertion operations    -
 - PROGRAM         : Int2Txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.1.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01st July, 1998                                        -
 ----------------------------------------------------------------------------

*/
/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : is_topic()                                                 |
|  Description : Checks a string and determines if is a topic string        *
*  Input       : String                                                     |
|  Return      : 1 if is topic                                              *
*                0 if is not                                                |
|                                                                           *
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
int is_topic(char *string)
  {
  if (strncmp(string, "--------", 8) == 0)
    return(1);
  else
    return(0);
  }

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : put_topic_temp()                                           |
|  Description : Process string by removing some caracters                  *
*  Input       : String -- to process                                       |
|  Input       : Make -- action to do                                       *
*  Input       : Caracter -- remove this caracter                           |
|  Return      : ----                                                       *
*                ----                                                       |
|                                                                           *
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void put_topic_temp(char *string,int make, char caracter, int filetype)
  {
  // Variables for loop operations
  register int i,j;
  char tempstr[200];

  // Copy the string to temporary variable
  strcpy(tempstr,string);
  // Find and change some characters
  find_and_change(string,tempstr,0);
  // Start copying the string
  for(i=0;i<=strlen(string) - 1;++i)
    {
    if ((string[i] != '!') && (string[i] != caracter))
      {
      switch(make)
        {
        // copy string as original
        case 0 : break;
        // copy string but process the next chars to lower chars
        case 1 : {
                 string[i+1] = tolower(string[i+1]);
                 break;
                 }
        } // switch
      switch(filetype)
        {
        case 0 : {
                 fputc(string[i],temp1_file_topics);
                 break;
                 }
        case 1 : {
                 fputc(string[i],temp11_int_topics);
                 break;
                 }
        } // switch
      } // if...
    } // for...
  } // put_topic_temp

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : put_comment_temp()                                         |
|  Description : Process string by removing some caracters                  *
*  Input       : String -- to process                                       |
|                Make -- action to do                                       *
*                Caracter -- remove this caracter                           |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void put_comment_temp(char *string, int filetype)
  {
  // Variables for loop operations
  register int i,j;
  char tempstr[200];

  // Copy the string to temporary variable
  strcpy(tempstr,string);
  // Find and change some characters
  find_and_change(string,tempstr,0);
  // Find a specified char '-'
  j = 0;
  j = strfind(string,'-',j);
  // If the char wasn't found assume as the begin of the string
  if (j==-1) j=strlen(string) - 1;
  // Put a space. When copying the string to the menu we need a blank space
  switch(filetype)
    {
    case 0 : {
             fputc(' ',temp5_file_comments);
             // Copy the string begining at the specified char position
             for(i=j;i<=strlen(string) - 1;++i)
               {
               fputc(string[i],temp5_file_comments);
               } // for...
             break;
             }
    case 1 : {
             fputc(' ',temp12_int_comments);
             // Copy the string begining at the specified char position
             for(i=j;i<=strlen(string) - 1;++i)
               {
               fputc(string[i],temp12_int_comments);
               } // for...
             break;
             }
    } // switch
  } // put_comment_temp

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : transfer_lines()                                           |
|  Description : tranfers a specified number of line                        *
*  Input       : actual_position --> self explained                         |
|                start_line --> self explained                              *
*                end_line --> self explained                                |
|  Return      : the last line that was transfered                          *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
int transfer_lines(int actual_position, int start_line, int end_line)
  {
  int i,j;
  char buf[255];
  char buf2[255];
  char buf3[255];
  int do_tabela;
  static int valor_duplo;
  char tempstr[200];

  do_tabela = 0;
  j = 0;
  strcpy(buf,"");
  strcpy(buf2,"");
  strcpy(buf3,"");
  if (actual_position == 0)
    {
    rewind(sourcefile);
    i = 0;
    }
  else i = actual_position;
  while ((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
    i++;
    if ((i>=start_line) && (i <= end_line))
      {
      strcpy(tempstr,buf);
      find_and_change(buf,tempstr,1);
      if (strstr(buf,"(Table") != NULL)
        {
        j = 0;
        while (j!=-1)
          {
          j = strfind(buf,':',j);
          if (j!=-1)
            {
            buf[j] = ' ';
            // if (j!=-1) strinst(buf,"$",j);
            j++;
            }
          }
        do_tabela = 1;
        j = 0;
        j = strfind(buf,'(',j);
        if (j!=-1)
          {
          j = strfind(buf,'T',j);
          if (j!= -1) j = j + 6;
          }
        buf3[0] = buf[j];
        buf3[1] = buf[j+1];
        buf3[2] = buf[j+2];
        buf3[3] = buf[j+3];
        buf3[4] = '\0';
        // due to a bug on the file I2C.LST
        if (valor_duplo == 1)
          {
          buf3[4] = ' ';
          buf3[5] = '(';
          buf3[6] = '1';
          buf3[7] = ')';
          buf3[8] = '\0';
          valor_duplo = 0;
          }
        if (strncmp(buf3,"I001",4) == 0) valor_duplo = 1;
        else valor_duplo = 0;
        if (strlen(buf2) >= 2)
          {
          fprintf(int2txi,"@xref{#%s} - %s\n",buf3,buf2);
          fprintf(tempfile7,"#%s\n",buf3);
          fprintf(tempfile8," %s",buf2);
          fprintf(tempfile9,"#%s\n",buf3);
          fprintf(temp10_all_topics,"#%s\n",buf3);
          fputs(buf2,tempfile9);
          }
        else
          {
          fprintf(tempfile9,"#%s\n",buf3);
          fprintf(temp10_all_topics,"#%s\n",buf3);
          fputs(buf,tempfile9);
          strcpy(buf2,buf);
          fgets(buf, sizeof(buf), sourcefile);
          j = 0;
          while (j!=-1)
            {
            j = strfind(buf,':',j);
            if (j!=-1)
              {
              buf[j] = ';';
              j++;
              }
            }
          i++;
          fprintf(int2txi,"@xref{#%s} - %s",buf3,buf);
          fprintf(tempfile7,"#%s\n",buf3);
          fprintf(tempfile8," %s",buf);
          }
        }
      if ((strstr(buf,"Bitfields") == NULL) &&
          (strstr(buf,"Values") == NULL) && (strstr(buf,"Format") == NULL))
        if (do_tabela == 1) fputs(buf, tempfile9);
        else fputs(buf, int2txi);
      } //if...
    strcpy(buf2,buf);
    if (i>end_line) return(i);
    } // while...
  do_tabela = 0;
  return 0;
  } // transfer_lines

int transfer_lines_2(int actual_position, int start_line, int end_line)
  {
  int i,j;
  char buf[255];
  char tempstr[200];


  j = 0;
  if (actual_position == 0)
    {
    rewind(tempfile9);
    i = 0;
    }
  else i = actual_position;
  while ((fgets(buf, sizeof(buf), tempfile9)) != NULL)
    {
    i++;
    if ((i>=start_line) && (i <= end_line))
      {
      strcpy(tempstr,buf);
      find_and_change(buf,tempstr,1);
      fputs(buf, int2txi);
      } // if...
    if (i>end_line) return(i);
    } // while...
  return 0;
  } // transfer_lines

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : topic_check()                                              |
|  Description : Check if a topic already exists                            *
*  Input       : String -- to process                                       |
|  Return      : The value of existent equal strings                        *
*                ----                                                       |
|                                                                           *
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
int topic_check(char *string)
  {
  // Buffer...
  char buf[255];
  // Variable for loop operation
  register int i;

  i = 0; // Initialize value
  // Go to the beginning of "temp10_all_topics"
  rewind(temp10_all_topics);
  while((fgets(buf, sizeof(buf), temp10_all_topics)) != NULL)
    {
    if (strncmp(buf,string,strlen(string) - 1) == 0) i++;
    } // while...
  return(i);
  } // topic_check

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : general_processing_rotine()                                |
|  Description : This is a rotine to convert general topics                 *
*  Input       : section_type --> section, sub_section or sub_sub_section   |
|                up_topic --> up topic                                      *
*                format_type --> 1 format the topic, 0 maintain the topic   |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void general_processing_rotine(int section_type,char *up_topic,int format_type, int make)
  {
  // Buffers...
  char buf[255];
  char buf2[255];
  char buf3[255];
  char buf4[255];
  char buf5[255];

  register int i,j;        // Values for loops...
  int topics_number,line;  // File topics_number, and actual line
  int temp_var,prev_line,start_line,end_line; // Self explicit
  int valor_duplo;         // Value returned when we chack for duplicate
                           // topics...

  // Initialize variables
  i = 0;
  j = 0;
  line = 0;
  temp_var = 0;
  end_line = 0;
  prev_line = 0;
  start_line = 0;
  valor_duplo = 0;
  topics_number	= 0;
  // Start finding all topics on source file and copy them to tempfile
  // At the same time, check "line" value and process it...
  while	((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
    // Increment line value
    line++;
    if (is_topic(buf) == 1)
      {
      // Get the next line on the source file to make it menu comment
      fgets(buf2, sizeof(buf2), sourcefile);
      // Process the line to make it a comment line
      put_comment_temp(buf2,0);
      // Update line value
      if (topics_number >= 1) fprintf(temp2_file_lines,"%d\n",line - 1);
      // Write topic
      put_topic_temp(buf,format_type,'-',0);
      // Update line value
      fprintf(temp2_file_lines,"%d\n",line+1);
      // Update topics_number value
      topics_number++;
      // Update line value
      line++;
      } // if...
    } // while...
   // Update line value
  fprintf(temp2_file_lines,"%d\n",line);
  // Go back to the beginning of temporary files
  rewind(temp1_file_topics);
  // Start the process to found duplicate topics
  while	((fgets(buf, sizeof(buf), temp1_file_topics)) != NULL)
    {
    // Bug correction for file CMOS.LST
    if (strcmp(buf,"\n") == 0) strcpy(buf,"Information\n");
    // Check if topic already exists...
    valor_duplo = topic_check(buf);
    // Take off format char "\n" at the end of the string
    buf[strlen(buf)-1] = '\0';
    // If topic already exists
    if (valor_duplo > 0)
      {
      // copy it to 'temp3_file_proc_topics'
      fputs(buf, temp3_file_proc_topics);
      // concate the next value, to make topic diferent
      fprintf(temp3_file_proc_topics," (%d)\n",valor_duplo);
      // copy it to topics main list
      fputs(buf, temp10_all_topics);
      // concate the next value, to make topic diferent
      fprintf(temp10_all_topics," (%d)\n",valor_duplo);
      } // if...
    else
      {
      // if doesn't exist other topic just copy it to temporary file and to
      // topics main list
      fputs(buf, temp3_file_proc_topics);
      fputc('\n',temp3_file_proc_topics);
      fputs(buf, temp10_all_topics);
      fputc('\n',temp10_all_topics);
      } // else...
    cprintf("_");
    } // while...
  // Open a new menu...
  fputs("@menu\n",int2txi);
  // Rewind Temporary file to check all topics and write them to the menu...
  // with the associated comment
  rewind(temp3_file_proc_topics);
  rewind(temp5_file_comments);
  i = 0;
  // Get the topic...
  while	(fgets(buf, sizeof(buf), temp3_file_proc_topics) != NULL)
    {
    if (i<topics_number)
      {
      // Get the comment...
      fgets(buf2, sizeof(buf2), temp5_file_comments);
      // Take off format char "\n" at the end of the string
      buf[strlen(buf)-1] = '\0';
      buf2[strlen(buf2)-1] = '\0';
      // Create the topic in the menu
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
      switch(section_type)
        {
        case 0 : {
                 creat_section(buf5,"",buf4,up_topic);
                 break;
                 }
        case 1 : {
                 creat_sub_section(buf5,"",buf4,up_topic);
                 break;
                 }
        case 2 : {
                 creat_sub_sub_section(buf5,"",buf4,up_topic);
                 break;
                 }
        } // switch...
      } // if...
    else
      if (i >= 3)
	{
	strcpy(buf3,buf4);
	strcpy(buf4,buf5);
	fgets(buf5, sizeof(buf5), temp3_file_proc_topics);
	buf5[strlen(buf5)-1] = '\0';
        switch(section_type)
          {
          case 0 : {
                   creat_section(buf4,buf5,buf3,up_topic);
                   break;
                   }
          case 1 : {
                   creat_sub_section(buf4,buf5,buf3,up_topic);
                   break;
                   }
          case 2 : {
                   creat_sub_sub_section(buf4,buf5,buf3,up_topic);
                   break;
                   }
          } // switch...
	} // if...
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
                   switch(section_type)
                     {
                     case 0 : {
                              creat_section(buf3,buf4,"",up_topic);
                              break;
                              }
                     case 1 : {
                              creat_sub_section(buf3,buf4,"",up_topic);
                              break;
                              }
                     case 2 : {
                              creat_sub_sub_section(buf3,buf4,"",up_topic);
                              break;
                              }
                     } // switch...
		   break;
		   } // case 1
 	  case 2 : {
                   switch(section_type)
                     {
                     case 0 : {
                              creat_section(buf4,buf5,buf3,up_topic);
                              break;
                              }
                     case 1 : {
                              creat_sub_section(buf4,buf5,buf3,up_topic);
                              break;
                              }
                     case 2 : {
                              creat_sub_sub_section(buf4,buf5,buf3,up_topic);
                              break;
                              }
                     } // switch...
		   break;
		   } // case 2
	  } // Switch (i)
    if (i <=topics_number)
      {
      fgets(buf, sizeof(buf), temp2_file_lines);
      start_line = atoi(buf);
      fgets(buf, sizeof(buf), temp2_file_lines);
      end_line = atoi(buf);
      fputs("@flushleft\n",int2txi);
      switch(make)
        {
        // no_tables
        case 0 : {
                 temp_var = transfer_lines_2(prev_line,start_line, end_line);
                 break;
                 }
        // do_tables
        case 1 : {
                 temp_var = transfer_lines(prev_line,start_line, end_line);
                 break;
                 }
        }
      fputs("@end flushleft\n",int2txi);
      cprintf(".");
      prev_line = temp_var;
      } // if...
    } // for...
    cprintf("\n\r");
  } // general_processing_rotine

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : general_open_rotine()                                      |
|  Description : This is a rotine that opens a general file                 *
*  Input       : file_name --> the file to open                             |
|                up_topic --> up topic                                      *
*  Return      : ----                                                       |
|                                                                           *
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void general_open_rotine(char *file_name,char *up_topic, int make)
  {
  // Check if source file is present in the int2txi.exe directory.
  // If not, just print some warnings. So, the user SHOULD copy that files
  // to the same directory.
  if (check_file(file_name,0) == 0)
    {
    // Open source file
    sourcefile = fopen(file_name,"rt");
    cprintf("%s ",file_name);
    // Create Temporary Files
    temp1_file_topics = fopen("TEMPFILE.001","wt+");
    temp2_file_lines = fopen("TEMPFILE.002","wt+");
    temp3_file_proc_topics = fopen("TEMPFILE.003","wt+");
    temp5_file_comments = fopen("TEMPFILE.005","wt+");
    // This file as a normal (general) processing...
    general_processing_rotine(0,up_topic,no_string_format,make);
    // Close Source File
    fclose(sourcefile);
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
    remove("TEMPFILE.003");
    }
  else fprintf(int2txi,"Not processed!!! %s wasn't found on the processing",file_name);
  } // general_open_rotine
