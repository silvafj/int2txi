/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : VARS.C                                                 -
 - MODULE          : Module containing program types, vars and const values -
 - PROGRAM         : Int2Txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.2.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01st September, 1998                                   -
 ----------------------------------------------------------------------------

*/
// Define FILE variables.
FILE *int2txi; // Target file
FILE *tablesfile; // A file that will keep all tables found

// Define Structs that will be used to work all data
struct TLine // this struct will keep the source file for processing
  {
  int number; // the number of the line
  char string[100]; // the line itself
  struct TLine *next_line; // pointer to next line
  struct TLine *previous_line; // pointer to previous line
  } line;

struct TLine *first_line; // pointer to keep first line,
struct TLine *last_line; // last line,
struct TLine *actual_line; // and the line currently being used

struct TFileTopics // this struct will keep the topics referencing to the
  {                // actual file being processed
  char string[100]; // the topic, this will be very usefull, because will keep
                   // the topic when found, but will keep to the topic when
                   // processed and checked
  int begin; // the line where the topic begins
  int end; // the line where the topic ends
  char comment[100]; // the topics have comments, and this will keep them
  char next_node[100]; // the name of the next node in this sequence
  char previous_node[100]; // and obvious the previous
  struct TFileTopics *next_topic; // pointer to next topic
  struct TFileTopics *previous_topic; // pointer to previous topic
  } file_topics;
  
struct TFileTopics *first_topic_filetop; // pointers to the first,
struct TFileTopics *last_topic_filetop; // last and
struct TFileTopics *actual_topic_filetop; // actual topic from the file

struct TAllTopics  // this struct will keep all topics found, it will be very
  {               // usefull and much faster than using temp disk files
  char string[100]; // the topic
  struct TAllTopics *next_topic; // pointer to next topic
  struct TAllTopics *previous_topic; // pointer to previous topic
  } all_topics;

struct TAllTopics *first_topic_alltop; // pointers to the first,
struct TAllTopics *last_topic_alltop; // last and
struct TAllTopics *actual_topic_alltop; // actual topic from ALL topics found

struct TIntMainTopics  // this struct will keep the interrupt main topics
  {
  char string[100]; // the topic
  char next_node[100];
  char previous_node[100];
  struct TIntMainTopics *next_topic; // pointer to next topic
  struct TIntMainTopics *previous_topic; // pointer to previous topic
  } int_main_topics;

struct TIntMainTopics *first_topic_intmain; // pointers to the first,
struct TIntMainTopics *last_topic_intmain; // last and
struct TIntMainTopics *actual_topic_intmain; // actual topic from ALL topics found

struct TIntMain2Topics  // this struct will keep the interrupt main topics
  {
  char string[100]; // the topic, this will be very usefull, because will keep
                   // the topic when found, but will keep to the topic when
                   // processed and checked
  int begin; // the line where the topic begins
  int end; // the line where the topic ends
  char comment[100]; // the topics have comments, and this will keep them
  char main_topic[7]; // the main topic that the sub-topic belongs
  struct TIntMain2Topics *next_topic; // pointer to next topic
  struct TIntMain2Topics *previous_topic; // pointer to previous topic
  } int_main2_topics;

struct TIntMain2Topics *first_topic_intmain2; // pointers to the first,
struct TIntMain2Topics *last_topic_intmain2; // last and
struct TIntMain2Topics *actual_topic_intmain2; // actual topic from ALL topics found

// The total number of topics that were processed
int total_topics_number;
// This constants will be used by "creat_menu_item"...
int automa_item	= 0; // This means that the rotine will imediatily write the
		     // topic to the target file
int manual_item	= 1; // This means that the rotine will check ALLTopics struct
		     // were are ALL topics to check if already exists one
		     // and will process it.
// This constants will be used by "put_topic_temp"...
int no_string_format = 0; // This means that the specified string will be
			  // copied exactly how was found
int string_format = 1;	  // This means that the string will be processed
			  // puting first string char to Upper and the others
			  // to Lower case
int use_sub_section = 1;
int no_tables = 0;
int do_tables = 1;
int making_tables = 0;

char *makeinfo;  // This will be used to keep makeinfo path
char *gzip;  // This will be used to keep makeinfo path

int use_makeinfo; // Use makeinfo to convert txi to info format
int use_gzip; // Use gzip to compress the final files

char source_release[81];
char source_copyright[81];
char makeinfo_release[81];
char makeinfo_copyright[81];

