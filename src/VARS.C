/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : VARS.C                                                 -
 - MODULE          : Module containing program types, vars and const values -
 - PROGRAM         : Int2Txi                                                -
 - DESCRIPTION     : This program converts Interrupt List to Texinfo format -
 - VERSION         : 1.1.0                                                  -
 - AUTHOR          : Fernando J.A. Silva (aka ^Magico^)                     -
 - DATE            : 01st July, 1998                                        -
 ----------------------------------------------------------------------------

*/
// Define FILE variables.
FILE *int2txi;	   // Target file
FILE *sourcefile;  // Source file
FILE *tempfile7;
FILE *tempfile8;
FILE *tempfile9;
FILE *tempfile10;

FILE *temp1_file_topics; // In this file will be written all topics found
                         // on source file
FILE *temp2_file_lines;  // The lines where the topic begins and ends
FILE *temp3_file_proc_topics; // in this will be written the topics, but
                              // already processed and checked if exists
                              // any duplicate topic
FILE *temp5_file_comments; // In this will be written comments to the topics
                           // found on the source file
FILE *temp6_file_main_topics;  // In this will be written more topics...

FILE *temp10_all_topics; // In this will be written *ALL* topics found
FILE *temp11_int_topics;   // In this will be written topics found on INT
FILE *temp12_int_comments; // In this will be written comments "   "   "
FILE *temp13_int_lines;    // In this will be written lines    "   "   "
FILE *temp14_int_compare;  // In this will be written comments, but without format
FILE *temp15_int_proc_topics;  // In this will be written processed topics


// The total number of topics that were processed
int total_topics_number;
// This constants will be used by "creat_menu_item"...
int automa_item	= 0; // This means that the rotine will imediatily write the
		     // topic to the target file
int manual_item	= 1; // This means that the rotine will check "tempfile4"
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

char *makeinfo;  // This will be used to keep makeinfo path
char *gzip;  // This will be used to keep makeinfo path

int use_makeinfo; // Use makeinfo to convert txi to info format
int use_gzip; // Use gzip to compress the final files

char source_release[81];
char source_copyright[81];
char makeinfo_release[81];
char makeinfo_copyright[81];

