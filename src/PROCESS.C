/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : PROCESS.C                                              -
 - MODULE          : Module containing rotines for convertion operations    -
 - PROGRAM         : Int2Txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.2.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01st September, 1998                                   -
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
void put_topic_temp(char *string, char caracter)
  {
  // Variables for loop operations
  register int i,j;
  char tempstr[255];
  struct TFileTopics *topic;
  struct TFileTopicsINT *topic_int;
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
    topic = (struct TFileTopics *)malloc(sizeof(file_topics));
    strcpy(topic->string,tempstr);
    if (first_topic_filetop != 0)
      { // if is not the first entry
      last_topic_filetop->next_topic = topic;
      topic->previous_topic = last_topic_filetop;
      last_topic_filetop = topic;
      last_topic_filetop->next_topic = 0;
      // update actual_topic for next rotines could use it without
      // problems
      actual_topic_filetop = actual_topic_filetop->next_topic;
      }
    else
      { // if is the first entry
      first_topic_filetop = topic;
      first_topic_filetop->next_topic = 0;
      last_topic_filetop = first_topic_filetop;
      first_topic_filetop->previous_topic = 0;
      // update actual_topic for next rotines could use it without
      // problems
      actual_topic_filetop = first_topic_filetop;
      }
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
void put_comment_temp(char *string)
  {
  // Variables for loop operations
  register int i,j,h;
  char tempstr[255];

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
  strcpy(actual_topic_filetop->comment,tempstr);
  } // put_comment_temp

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : transfer_lines()                                           |
|  Description : tranfers a specified number of line                        *
*  Input       : start_line --> self explained                              |
|                end_line --> self explained                                *
*  Return      : -----                                                      |
|                                                                           *
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void transfer_lines(int start_line, int end_line)
  {
  int i,j;
  char buf[255];
  char buf2[255];
  char buf3[255];
  int do_tabela;
  static int valor_duplo;
  char tempstr[255];

  do_tabela = 0;
  j = 0;
  strcpy(buf,"");
  strcpy(buf2,"");
  strcpy(buf3,"");
  actual_line = find_line(start_line);
  while (actual_line->number <= end_line)
    {
    strcpy(buf,actual_line->string);
    strcpy(tempstr,buf);
    find_and_change(buf,tempstr,1);
    // Start checking if it's a table
    if (strstr(buf,"(Table") != NULL)
      {
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
      buf3[4] = buf[j+4];
      buf3[5] = '\0';
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
      if (strlen(buf2) >= 2)
        {
        fprintf(int2txi,"@xref{#%s} - %s",buf3,buf2);
        fprintf(tablesfile,"--------------------#%s-------\n",buf3);
        fputs(buf2,tablesfile);
        }
      else
        {
        fprintf(tablesfile,"--------------#%s\n",buf3);
        fputs(buf,tablesfile);
        strcpy(buf2,buf);

        actual_line = actual_line->next_line;
        strcpy(buf,actual_line->string);
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
        }
      } // if table
    if ((strstr(buf,"Bitfields") == NULL) &&
        (strstr(buf,"Values") == NULL) && (strstr(buf,"Format") == NULL))
      if (do_tabela == 1) fputs(buf, tablesfile);
      else fputs(buf, int2txi);
  strcpy(buf2,buf);
  actual_line = actual_line->next_line;
  } // while...
  do_tabela = 0;
  } // transfer_lines

void transfer_lines_notables(int start_line, int end_line)
  {
  char buf[255];
  char buf3[255];
  char tempstr[255];
  int i,j;

  actual_line = find_line(start_line);
  while (actual_line->number <= end_line)
    {
    strcpy(buf,actual_line->string);
    strcpy(tempstr,buf);
    find_and_change(buf,tempstr,1);
    if (strstr(buf,"(see #") != NULL)
      {
      j = 0;
      j = strfind(buf,'#',j);
      if ((buf[j-4] == 's') && (buf[j-3] == 'e') && (buf[j-2] == 'e'))
        {
        strcpy(buf3,"@xref{");
        buf3[6] = buf[j];
        buf3[7] = buf[j+1];
        buf3[8] = buf[j+2];
        buf3[9] = buf[j+3];
        buf3[10] = buf[j+4];
        buf3[11] = buf[j+5];
        buf3[12] = '}';
        buf3[13] = ')';
        buf3[14] = '\n';
        strcpy(tempstr,buf);
        strchange(buf,tempstr,buf3,j);
        }
      }
    fputs(buf, int2txi);
    actual_line = actual_line->next_line;
    }
  } // transfer_lines_notables

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
  char buf[100];
  char buf2[100];
  // Variable for loop operation
  register int i;

  i = 0; // Initialize value
  // Go to the beginning of the struct "All Topics"
  actual_topic_alltop = first_topic_alltop;
  strcpy(buf2,string);
  strlwr(buf2);
  while (actual_topic_alltop != 0)
    {
    strcpy(buf,actual_topic_alltop->string);
    strlwr(buf);
    if (strncmp(buf,buf2,strlen(buf2) - 1) == 0) i++;
    actual_topic_alltop = actual_topic_alltop->next_topic;
    } // while...
  return(i);
  } // topic_check

void find_all_topics()
  {
  // Buffers...
  char buf[100];
  char buf2[100];
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
      put_topic_temp(buf,'-');
      // Process the line to make it a comment line
      put_comment_temp(buf2);
      // Update line value
      if (topics_number >= 1) actual_topic_filetop->previous_topic->end = actual_line->previous_line->number;
      // Update line value
      actual_topic_filetop->begin = actual_line->next_line->number;
      // Update topics_number value
      topics_number++;
      } // if...
      actual_line = actual_line->next_line;
    } // while...
  // Update line value
  actual_topic_filetop->end = last_line->number;
  } // find_all_topics

void find_duplicate_topics()
  {
  // Buffers...
  char buf[100];
  char temp[100];
  int valor_duplo; // Value returned when we chack for duplicate topics...

  actual_topic_filetop = first_topic_filetop;
  while	(actual_topic_filetop != 0)
    {
    // Get one topic
    strcpy(buf,actual_topic_filetop->string);
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
      strcpy(actual_topic_filetop->string,buf);
      // copy it to topics main struct
      put_topic_alltopics_struct(buf);
      } // if...
    else
      {
      // if doesn't exist other topic just copy it to temporary file and to
      // topics main list
      strcat(buf,"\n");
      // copy it again deleting old topic, and putting the new one
      strcpy(actual_topic_filetop->string,buf);
      // copy it to topics main struct
      put_topic_alltopics_struct(buf);
      } // else...
    actual_topic_filetop = actual_topic_filetop->next_topic;
    cprintf("_");
    } // while...
  } // find_duplicate_topics
  
void create_all_menu()
  {
  // Buffers...
  char buf[100];
  char buf2[100];

  // Rewind Temporary file to check all topics and write them to the menu...
  // with the associated comment
  actual_topic_filetop = first_topic_filetop;
  // Open a new menu...
  fputs("@menu\n",int2txi);
  while (actual_topic_filetop != 0)
    {
    // Get topic
    strcpy(buf,actual_topic_filetop->string);
    // Get the comment...
    strcpy(buf2,actual_topic_filetop->comment);
    // Take off format char "\n" at the end of the string
    buf[strlen(buf)-1] = '\0';
    buf2[strlen(buf2)-1] = '\0';
    // Create the topic in the menu
    creat_menu_item(buf,buf2);
    // update topic pointer
    actual_topic_filetop = actual_topic_filetop->next_topic;
    } // while...
  // End menu
  fputs("@end menu\n",int2txi);
  } // create_all_menu

void find_nodes_relations()
  {
  // Rewind struct to start checking next and previous nodes
  actual_topic_filetop = first_topic_filetop;
  while (actual_topic_filetop != 0)
    {
    // this just check if in the menu there are only one node
    if ((actual_topic_filetop == first_topic_filetop) && (actual_topic_filetop == last_topic_filetop))
      {
      strcpy(actual_topic_filetop->next_node,"");
      strcpy(actual_topic_filetop->previous_node,"");
      }
    else
    // it is the first topic
      if (actual_topic_filetop == first_topic_filetop)
        {
        strcpy(actual_topic_filetop->next_node,actual_topic_filetop->next_topic->string);
        strcpy(actual_topic_filetop->previous_node,"");
        }
      else
        // it is the last topic
        if (actual_topic_filetop == last_topic_filetop)
          {
          strcpy(actual_topic_filetop->next_node,"");
          strcpy(actual_topic_filetop->previous_node,actual_topic_filetop->previous_topic->string);
          }
        // it is other topic
        else
          {
          strcpy(actual_topic_filetop->next_node,actual_topic_filetop->next_topic->string);
          strcpy(actual_topic_filetop->previous_node,actual_topic_filetop->previous_topic->string);
          }
    actual_topic_filetop = actual_topic_filetop->next_topic;
    } // while
  } // find_nodes_relations
  
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
void general_processing_rotine(int section_type,char *up_topic)
  {
  // Buffers...
  char buf3[100];
  char buf4[100];
  char buf5[100];
  int  start_line,end_line; // Self explicit

  // Start finding all topics on source file and copy them to tempfile
  // At the same time, check "line" value and process it...
  find_all_topics();
  // Start the process to found duplicate topics
  find_duplicate_topics();
  // Create nodes relations
  find_nodes_relations();
  // Create Menu
  create_all_menu();
  // Rewind Temporary File (again) for starting writing sections, sub-sections
  // and transfering source lines
  actual_topic_filetop = first_topic_filetop;
  while (actual_topic_filetop != 0)
    {
    strcpy(buf3,actual_topic_filetop->string);
    strcpy(buf4,actual_topic_filetop->next_node);
    strcpy(buf5,actual_topic_filetop->previous_node);
    buf3[strlen(buf3)-1] = '\0';
    buf4[strlen(buf4)-1] = '\0';
    buf5[strlen(buf5)-1] = '\0';
    switch(section_type)
      {
      case 0 : {
               creat_section(buf3,buf4,buf5,up_topic);
               break;
               }
      case 1 : {
               creat_sub_section(buf3,buf4,buf5,up_topic);
               break;
               }
      case 2 : {
               creat_sub_sub_section(buf3,buf4,buf5,up_topic);
               break;
               }
      } // switch...
    start_line = actual_topic_filetop->begin;
    end_line = actual_topic_filetop->end;
    fputs("@flushleft\n",int2txi);
    // transfer lines and check for tables
    transfer_lines(start_line, end_line);
    fputs("@end flushleft\n",int2txi);
    actual_topic_filetop = actual_topic_filetop->next_topic;
    cprintf(".");
    }
    cprintf("\n\r");
  } // general_processing_rotine

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : general_processing_rotine_notables()                       |
|  Description : This is a rotine to convert general topics                 *
*  Input       : section_type --> section, sub_section or sub_sub_section   |
|                up_topic --> up topic                                      *
*                format_type --> 1 format the topic, 0 maintain the topic   |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void general_processing_rotine_notables(int section_type,char *up_topic)
  {
  // Buffers...
  char buf3[100];
  char buf4[100];
  char buf5[100];
  int  start_line,end_line; // Self explicit

  // Start finding all topics on source file and copy them to tempfile
  // At the same time, check "line" value and process it...
  find_all_topics();
  // Start the process to found duplicate topics
  find_duplicate_topics();
  // Create nodes relations
  find_nodes_relations();
  // Create Menu
  create_all_menu();
  // Rewind Temporary File (again) for starting writing sections, sub-sections
  // and transfering source lines
  actual_topic_filetop = first_topic_filetop;
  while (actual_topic_filetop != 0)
    {
    strcpy(buf3,actual_topic_filetop->string);
    strcpy(buf4,actual_topic_filetop->next_node);
    strcpy(buf5,actual_topic_filetop->previous_node);
    buf3[strlen(buf3)-1] = '\0';
    buf4[strlen(buf4)-1] = '\0';
    buf5[strlen(buf5)-1] = '\0';
    switch(section_type)
      {
      case 0 : {
               creat_section(buf3,buf4,buf5,up_topic);
               break;
               }
      case 1 : {
               creat_sub_section(buf3,buf4,buf5,up_topic);
               break;
               }
      case 2 : {
               creat_sub_sub_section(buf3,buf4,buf5,up_topic);
               break;
               }
      } // switch...
    start_line = actual_topic_filetop->begin;
    end_line = actual_topic_filetop->end;
    fputs("@flushleft\n",int2txi);
    // transfer lines and check for tables
    transfer_lines_notables(start_line, end_line);
    fputs("@end flushleft\n",int2txi);
    actual_topic_filetop = actual_topic_filetop->next_topic;
    cprintf(".");
    }
    cprintf("\n\r");
  } // general_processing_rotine_notables

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
  FILE *sourcefile;

  // Check if source file is present in the int2txi.exe directory.
  // If not, just print some warnings. So, the user SHOULD copy that files
  // to the same directory.
  if (check_file(file_name,0) == 0)
    {
    // Open source file
    sourcefile = fopen(file_name,"rt");
    cprintf("%s ",file_name);
    // Create Temporary Files
    load_source_file(file_name);
    cprintf("\n\r Lines Loaded : %d\n\r",last_line->number); // to print the number of lines loaded from the file
    switch(make)
      {
      case 0 : { // This file as a normal (general) processing... but don't
               // check for tables
               general_processing_rotine_notables(0,up_topic);
               break;
               }
      case 1 : { // This file as a normal (general) processing...
               general_processing_rotine(0,up_topic);
               break;
               }
      }
    // Close Source File
    fclose(sourcefile);
    // Close temporary files
    unload_actual_file();
    unload_actual_topics_file();
    }
  else fprintf(int2txi,"Not processed!!! %s wasn't found on the processing",file_name);
  } // general_open_rotine
