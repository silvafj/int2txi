/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : NODES.C                                                -
 - MODULE          : Nodes module containing rotines for nodes operations   -
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
*  Rotine      : create_node()                                              |
|  Description : Creates a node directly on the output file                 *
*  Input       : Node Name, Next Node, Previous Node, Up Node               |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void creat_node(char *node_name, char *next_node, char *prev_node, char *up_node)
  {
  fputs("\n",int2txi);
  fprintf(int2txi,"@node    %s,%s,%s,%s\n",node_name,next_node,prev_node,up_node);
//  fputs("@comment node-name, next, previous, up\n",int2txi);
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
  fputs("\n",int2txi);
  fprintf(int2txi,"@node    %s,%s,%s,%s\n",chapter_name,next_node,prev_node,up_node);
//  fputs("@comment node-name, next, previous, up\n",int2txi);
  fprintf(int2txi,"@chapter %s\n\n",chapter_name);
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
  fputs("\n",int2txi);
  fprintf(int2txi,"@node    %s,%s,%s,%s\n",section_name,next_node,prev_node,up_node);
//  fputs("@comment node-name, next, previous, up\n",int2txi);
  fprintf(int2txi,"@section %s\n\n",section_name);
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
  fputs("\n",int2txi);
  fprintf(int2txi,"@node    %s,%s,%s,%s\n",sub_section_name,next_node,prev_node,up_node);
//  fputs("@comment node-name, next, previous, up\n",int2txi);
  fprintf(int2txi,"@subsection %s\n\n",sub_section_name);
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
  fputs("\n",int2txi);
  fprintf(int2txi,"@node    %s,%s,%s,%s\n",sub_sub_section_name,next_node,prev_node,up_node);
//  fputs("@comment node-name, next, previous, up\n",int2txi);
  fprintf(int2txi,"@subsubsection %s\n\n",sub_sub_section_name);
  } // creat_sub_section

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : create_menu_item()                                         |
|  Description : Creates a menu item directly on the output file            *
*  Input       : Item Name, Comment                                         |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void creat_menu_item(char *topic_name,char *comment)
  {
  fprintf(int2txi,"* %s:: %s\n",topic_name,comment);
  total_topics_number++;
  } // creat_menu_item
