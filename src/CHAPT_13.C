/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : CHAPT_12.C                                             -
 - MODULE          : Module containing "Chapter 13" processing              -
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
*  Rotine      : process_chapter_13()                                       |
|  Description : Will process chapter 13                                    *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void process_chapter_13(void)
  {
  // Define buffers...
  char buf[255];
  char buf2[255];
  char buf3[255];
  char buf4[255];
  char buf5[255];

  register int i,j;        // Values for loops...
  int topics_number,line;  // File topics_number, and actual line
  int start_line,end_line; // Self explicit
  int prev_line,temp_var;

  // Initialize all variables to 0
  i = 0;
  j = 0;
  line = 0;
  end_line = 0;
  start_line = 0;
  topics_number	= 0;
  temp_var = 0;
  prev_line = 0;
  rewind(tempfile7);
  rewind(tempfile8);
  rewind(tempfile9);
  rewind(tempfile10);
  // Start finding all topics on source file and copy them to tempfile
  // At the same time, check "line" value and process it...
  i = 0;
  while	((fgets(buf, sizeof(buf), tempfile9)) != NULL)
    {
    line++;
    if (buf[0] == '#')
      {
      // Update line value
      if (i >= 1) fprintf(tempfile10,"%d\n",line - 1);
      // Update line value
      fprintf(tempfile10,"%d\n",line+1);
      i++;
      } // if...
    } // while...
  topics_number = i;
   // Update line value
  fprintf(tempfile10,"%d\n",line);
  rewind(tempfile7);
  rewind(tempfile8);
  rewind(tempfile9);
  rewind(tempfile10);
  fputs("@menu\n",int2txi);
  // Rewind Temporay File to check all topics and write them to the menu...
  while	(fgets(buf, sizeof(buf), tempfile7) != NULL)
    {
    fgets(buf2, sizeof(buf2), tempfile8);
    // Take off format char "\n" at the end of the string
    buf[strlen(buf)-1] = '\0';
    buf2[strlen(buf2)-1] = '\0';
    creat_menu_item(buf,buf2);
    cprintf("_");
     } // while...
  // End menu
  fputs("@end menu\n",int2txi);
  // Rewind Temporary File (again) for starting writing sections, sub-sections
  // and transfering source lines
  rewind(tempfile7);
  rewind(tempfile8);
  rewind(tempfile9);
  rewind(tempfile10);
  i = 0;
  for(i=1;i<=topics_number;i++)
    {
    if (i == topics_number)
      {
      creat_section(buf5,"",buf4,"Tables");
      }
    else
      if (i >= 3)
	{
	strcpy(buf3,buf4);
	strcpy(buf4,buf5);
	fgets(buf5, sizeof(buf5), tempfile7);
	buf5[strlen(buf5)-1] = '\0';
        creat_section(buf4,buf5,buf3,"Tables");
	}
      else
	switch(i)
	  {
	  case 1 : {
		   fgets(buf3, sizeof(buf3), tempfile7);
		   fgets(buf4, sizeof(buf4), tempfile7);
		   fgets(buf5, sizeof(buf5), tempfile7);
		   buf3[strlen(buf3)-1]	= '\0';
		   buf4[strlen(buf4)-1]	= '\0';
		   buf5[strlen(buf5)-1]	= '\0';
                   creat_section(buf3,buf4,"","Tables");
		   break;
		   }
	  case 2 : {
                   creat_section(buf4,buf5,buf3,"Tables");
		   break;
		   }
	  } // Switch (i)
    if (i <=topics_number)
      {
      fgets(buf, sizeof(buf), tempfile10);
      start_line = atoi(buf);
      fgets(buf, sizeof(buf), tempfile10);
      end_line = atoi(buf);
      fputs("@flushleft\n",int2txi);
      temp_var = transfer_lines_2(prev_line,start_line, end_line);
      fputs("@end flushleft\n",int2txi);
      cprintf(".");
      prev_line = temp_var;
      } // if...
    } // for...
    cprintf("\n\r");

  } // process_chapter_13
