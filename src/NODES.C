/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : NODES.C                                                -
 - MODULE          : Nodes module containing rotines for nodes operations   -
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
*  Rotine      : check_file()                                               |
|  Description : This rotine says that a specified file doesn't exist       *
*  Input       : The file we are checking for.                              |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void check_file(char *_fn)
  {
  if (!__file_exists(_fn))
    {
    printf("Warning : %s not found!!! CAN'T continue the processing...\n",_fn);
    exit(1);
    }
  } // check_file

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : remove_temp_files()                                        |
|  Description : This rotine removes ALL temporary files                    *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void remove_temp_files()
  {
  remove("TEMPFILE.001");
  remove("TEMPFILE.002");
  remove("TEMPFILE.003");
  remove("TEMPFILE.004");
  remove("TEMPFILE.005");
  remove("TEMPFILE.006");
  remove("TEMPFILE.007");
  remove("TEMPFILE.008");
  remove("TEMPFILE.009");
  remove("TEMPFILE.010");
  } // remove_temp_files

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : create_node()                                              |
|  Description : Creates a node directly on the output file                 *
*  Input       : Node Name, Next Node, Previous Node, Up Node               |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void creat_node(char *node_name, char *next_node, char *prev_node, char *up_node)
  {
  fputs("\n",Int2TeX);
  fputs("@node    ",Int2TeX);
  fputs(node_name,Int2TeX);
  fputs(",",Int2TeX);
  fputs(next_node,Int2TeX);
  fputs(",",Int2TeX);
  fputs(prev_node,Int2TeX);
  fputs(",",Int2TeX);
  fputs(up_node,Int2TeX);
  fputs("\n",Int2TeX);
  fputs("@comment node-name, next, previous, up\n",Int2TeX);
  fputs("\n",Int2TeX);
  } // creat_node

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : create_chapter()                                           |
|  Description : Creates a chapter directly on the output file              *
*  Input       : Chapter Name, Next Node, Previous Node, Up Node            |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void creat_chapter(char *chapter_name, char *next_node, char *prev_node, char *up_node)
  {
  fputs("\n",Int2TeX);
  fputs("@node    ",Int2TeX);
  fputs(chapter_name,Int2TeX);
  fputs(",",Int2TeX);
  fputs(next_node,Int2TeX);
  fputs(",",Int2TeX);
  fputs(prev_node,Int2TeX);
  fputs(",",Int2TeX);
  fputs(up_node,Int2TeX);
  fputs("\n",Int2TeX);
  fputs("@comment node-name, next, previous, up\n",Int2TeX);
  fputs("@chapter ",Int2TeX);
  fputs(chapter_name,Int2TeX);
  fputs("\n\n",Int2TeX);
  } // creat_chapter

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : create_section()                                           |
|  Description : Creates a section directly on the output file              *
*  Input       : Section Name, Next Node, Previous Node, Up Node            |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void creat_section(char *section_name, char *next_node, char *prev_node, char *up_node)
  {
  fputs("\n",Int2TeX);
  fputs("@node    ",Int2TeX);
  fputs(section_name,Int2TeX);
  fputs(",",Int2TeX);
  fputs(next_node,Int2TeX);
  fputs(",",Int2TeX);
  fputs(prev_node,Int2TeX);
  fputs(",",Int2TeX);
  fputs(up_node,Int2TeX);
  fputs("\n",Int2TeX);
  fputs("@comment node-name, next, previous, up\n",Int2TeX);
  fputs("@section ",Int2TeX);
  fputs(section_name,Int2TeX);
  fputs("\n\n",Int2TeX);
  } // creat_section

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : create_sub_section()                                       |
|  Description : Creates a sub section directly on the output file          *
*  Input       : Sub Section Name, Next Node, Previous Node, Up Node        |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void creat_sub_section(char *sub_section_name, char *next_node, char *prev_node, char *up_node)
  {
  fputs("\n",Int2TeX);
  fputs("@node    ",Int2TeX);
  fputs(sub_section_name,Int2TeX);
  fputs(",",Int2TeX);
  fputs(next_node,Int2TeX);
  fputs(",",Int2TeX);
  fputs(prev_node,Int2TeX);
  fputs(",",Int2TeX);
  fputs(up_node,Int2TeX);
  fputs("\n",Int2TeX);
  fputs("@comment node-name, next, previous, up\n",Int2TeX);
  fputs("@subsection ",Int2TeX);
  fputs(sub_section_name,Int2TeX);
  fputs("\n\n",Int2TeX);
  } // creat_sub_section

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : create_sub_sub_section()                                   |
|  Description : Creates a sub sub section directly on the output file      *
*  Input       : Sub sub Section Name, Next Node, Previous Node, Up Node    |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void creat_sub_sub_section(char *sub_sub_section_name, char *next_node, char *prev_node, char *up_node)
  {
  fputs("\n",Int2TeX);
  fputs("@node    ",Int2TeX);
  fputs(sub_sub_section_name,Int2TeX);
  fputs(",",Int2TeX);
  fputs(next_node,Int2TeX);
  fputs(",",Int2TeX);
  fputs(prev_node,Int2TeX);
  fputs(",",Int2TeX);
  fputs(up_node,Int2TeX);
  fputs("\n",Int2TeX);
  fputs("@comment node-name, next, previous, up\n",Int2TeX);
  fputs("@subsubsection ",Int2TeX);
  fputs(sub_sub_section_name,Int2TeX);
  fputs("\n\n",Int2TeX);
  } // creat_sub_section

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : create_menu_item()                                         |
|  Description : Creates a menu item directly on the output file            *
*  Input       : Item Name                                                  |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void creat_menu_item(char *topic_name,char *comment,int make)
  {
  int valor_duplo;

  switch(make)
    {
    case 0 : {
             fputs("* ",Int2TeX);
             fputs(topic_name,Int2TeX);
             fputs("::",Int2TeX);
             fputs(comment,Int2TeX);
             fputs("\n",Int2TeX);
             break;
             }
    case 1 : {
             valor_duplo = 0;
             valor_duplo = topic_check(topic_name);
             if (valor_duplo > 0)
               {
               fprintf(Int2TeX,"* %s (%d):: %s\n",topic_name,valor_duplo,comment);
               fprintf(tempfile4,"%s (%d)\n",topic_name,valor_duplo);
               }
             else
               {
               fprintf(Int2TeX,"* %s:: %s\n",topic_name,comment);
               fprintf(tempfile4,"%s\n",topic_name);
               }
             }
  }
  total_topics_number++;
  } // creat_menu_item

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
void put_topic_temp(char *string,int make, char caracter)
  {
  // Variables for loop operations
  register int i,j;
  char tempstr[200];

  strcpy(tempstr,string);
  find_and_change(string,tempstr,0);
  for(i=0;i<=strlen(string) - 1;++i)
    {
    if ((string[i] != '!') && (string[i] != caracter))
      {
      switch(make)
        {
        case 0 : break;
        case 1 : {
                 string[i+1] = tolower(string[i+1]);
                 break;
                 }
        } // switch
      fputc(string[i],tempfile);
      } // if...
    } // for...
  } // put_topic_temp

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : put_comment_temp()                                         |
|  Description : Process string by removing some caracters                  *
*  Input       : String -- to process                                       |
|  Input       : Make -- action to do                                       *
*  Input       : Caracter -- remove this caracter                           |
|  Return      : ----                                                       *
*                ----                                                       |
|                                                                           *
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void put_comment_temp(char *string)
  {
  // Variables for loop operations
  register int i,j;
  char tempstr[200];

  strcpy(tempstr,string);
  find_and_change(string,tempstr,0);
  j = 0;
  j = strfind(string,'-',j);
  if (j==-1) j=strlen(string) - 1;
  fputc(' ',tempfile5);
  for(i=j;i<=strlen(string) - 1;++i)
    {
    fputc(string[i],tempfile5);
    } // for...
  } // put_comment_temp

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
      find_and_change(buf,tempstr,2);
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
          fprintf(Int2TeX,"@xref{#%s} - %s\n",buf3,buf2);
          fprintf(tempfile7,"#%s\n",buf3);
          fprintf(tempfile8," %s",buf2);
          fprintf(tempfile9,"#%s\n",buf3);
          fprintf(tempfile4,"#%s\n",buf3);
          fputs(buf2,tempfile9);
          }
        else
          {
          fprintf(tempfile9,"#%s\n",buf3);
          fprintf(tempfile4,"#%s\n",buf3);
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
          fprintf(Int2TeX,"@xref{#%s} - %s",buf3,buf);
          fprintf(tempfile7,"#%s\n",buf3);
          fprintf(tempfile8," %s",buf);
          }
        }
      if ((strstr(buf,"Bitfields") == NULL) &&
          (strstr(buf,"Values") == NULL) && (strstr(buf,"Format") == NULL))
        if (do_tabela == 1) fputs(buf, tempfile9);
        else fputs(buf, Int2TeX);
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
      fputs(buf, Int2TeX);
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
  // Go to the beginning of "tempfile4"
  rewind(tempfile4);
  while((fgets(buf, sizeof(buf), tempfile4)) != NULL)
    {
    if (strncmp(buf,string,strlen(string) - 1) == 0) i++;
    } // while...
  return(i);
  } // topic_check

void general_processing_rotine(int section_type,char *up_topic,int format_type)
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
    line++;
    if (is_topic(buf) == 1)
      {
      fgets(buf2, sizeof(buf2), sourcefile);
      put_comment_temp(buf2);
      // Update line value
      if (topics_number >= 1) fprintf(tempfile2,"%d\n",line - 1);
      // Write topic
      put_topic_temp(buf,format_type,'-');
      // Update line value
      fprintf(tempfile2,"%d\n",line+1);
      // Update topics_number value
      topics_number++;
      line++;
      } // if...
    } // while...
   // Update line value
  fprintf(tempfile2,"%d\n",line);
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
        }
      }
    else
      if (i >= 3)
	{
	strcpy(buf3,buf4);
	strcpy(buf4,buf5);
	fgets(buf5, sizeof(buf5), tempfile3);
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
        }
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
        }
		   break;
		   }
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
        }
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
} // general_processing_rotine

void general_open_rotine(char *file_name,char *up_topic)
  {
  // Open source file
  sourcefile = fopen(file_name,"rt");
  cprintf("%s ",file_name);
  // Check if source file is present in the Int2TeX.exe directory.
  // If not, just print some warnings. So, the user SHOULD copy that files
  // to the same directory.
  check_file(file_name);
  // Create Temporary Files
  tempfile = fopen("TEMPFILE.001","wt+");
  tempfile2 = fopen("TEMPFILE.002","wt+");
  tempfile3 = fopen("TEMPFILE.003","wt+");
  tempfile5 = fopen("TEMPFILE.005","wt+");
  // This file as a normal (general) processing...
  general_processing_rotine(0,up_topic,no_string_format);
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
}
