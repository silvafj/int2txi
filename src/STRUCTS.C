/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : STRUCTS.C                                              -
 - MODULE          : Module containing rotines for structs operations       -
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
*  Rotine      : load_source_file                                           |
|  Description : Loads a specified file to a struct for later processing    *
*  Input       : filename                                                   |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void load_source_file(char *_filename)
  {
  FILE *sourcefile; // source file
  char buf[90];
  struct TLine *getting_line; // temp sctruct
  char *xmalloc();
  int file_actual_line;
  
  strcpy(buf,""); // initialize empty vars
  file_actual_line = 0;
  sourcefile = fopen(_filename,"rt");
  // load first line to the struct to initialize it.
  fgets(buf, sizeof(buf), sourcefile); // get first line
  file_actual_line++;
  getting_line = (struct TLine *)xmalloc(sizeof(line)); // alloc memory for
  getting_line->number = file_actual_line; // fill the blocks with the data
  strcpy(getting_line->string,buf);
  first_line = getting_line; // initialize first entry with the specific
  first_line->next_line = 0; // and correct pointers
  last_line = first_line;
  first_line->previous_line = 0;
  // start loading all the rest of the file lines
  while ((fgets(buf, sizeof(buf), sourcefile)) != NULL)
    {
    file_actual_line++;
    getting_line = (struct TLine *)xmalloc(sizeof(line)); // alloc memory
    getting_line->number = file_actual_line; // fill the blocks with data
    strcpy(getting_line->string,buf);
    last_line->next_line = getting_line; // update pointers
    getting_line->previous_line = last_line;
    last_line = getting_line;
    last_line->next_line = 0;
    } // until the end of the file
  } // load_source_file

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : unload_actual_file                                         |
|  Description : Frees all memory used by an actual file loaded in memory   *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void unload_actual_file()
  {
  struct TLine *deleting_line;

  while (first_line != last_line)
    {
    deleting_line = last_line;
    last_line = deleting_line->previous_line;
    last_line->next_line = 0;
    last_line->previous_line = deleting_line->previous_line->previous_line;
    xfree(deleting_line);
    }
  first_line = 0;
  last_line = 0;
  } // unload_actual_file

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : find_line                                                  |
|  Description : Finds the number of a specified line                       *
*  Input       : line_to_find                                               |
|  Return      : a pointer to the entry containing the specified line number*
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
struct TLine *find_line(int line_to_find)
  {
  struct TLine *searching_line;

  searching_line = first_line;
  while (searching_line)
    {
    if (line_to_find == searching_line->number) return searching_line;
    searching_line = searching_line->next_line; // seacrh next line entry
    }
  return(0);
  } // find_line

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : init_all_topics_struct                                     |
|  Description : Inits the struct that will contain all topics found        *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void init_all_topics_struct()
  {
  struct TAllTopics *topic;
  char *xmalloc();

  topic = (struct TAllTopics *)xmalloc(sizeof(all_topics)); // alloc some memory
  strcpy(topic->string,"STRUCT 'ALL TOPICS' INITIATED"); // copy just a "fun" data
  first_topic_alltop = topic;
  first_topic_alltop->next_topic = 0;
  last_topic_alltop = first_topic_alltop;
  first_topic_alltop->previous_topic = 0;
  } //  init_all_topics_struct

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : put_topic_alltopics_struct                                 |
|  Description : Put's a specified topic in the main struct ALL topics      *
*  Input       : string --> the topic to put in the struct                  |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void put_topic_alltopics_struct(char *string)
  {
  struct TAllTopics *topic;
  char *xmalloc();

  topic = (struct TAllTopics *)xmalloc(sizeof(all_topics)); // alloc some mem
  strcpy(topic->string,string); // copy data
  last_topic_alltop->next_topic = topic;
  topic->previous_topic = last_topic_alltop;
  last_topic_alltop = topic;
  last_topic_alltop->next_topic = 0;
  } // put_topic_alltopics_struct

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : unload_actual_topics_file                                  |
|  Description : Frees all memory used by an actual topics file             *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void unload_actual_topics_file()
  {
  struct TFileTopics *deleting_topic;

  while (first_topic_filetop != last_topic_filetop)
    {
    deleting_topic = last_topic_filetop;
    last_topic_filetop = deleting_topic->previous_topic;
    last_topic_filetop->next_topic = 0;
    last_topic_filetop->previous_topic = deleting_topic->previous_topic->previous_topic;
    xfree(deleting_topic);
    }
  first_topic_filetop = 0;
  last_topic_filetop = 0;
  } // unload_actual_topics_file

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : unload_all_topics_struct                                   |
|  Description : Frees all memory used by all topics struct                 *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void unload_all_topics_struct()
  {
  struct TAllTopics *deleting_topic;

  while (first_topic_alltop != last_topic_alltop)
    {
    deleting_topic = last_topic_alltop;
    last_topic_alltop = deleting_topic->previous_topic;
    last_topic_alltop->next_topic = 0;
    last_topic_alltop->previous_topic = deleting_topic->previous_topic->previous_topic;
    xfree(deleting_topic);
    }
  first_topic_alltop = 0;
  last_topic_alltop = 0;
  } // unload_actual_topics_file

