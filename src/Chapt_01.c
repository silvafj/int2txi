/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : CHAPT_01.C                                             -
 - MODULE          : Module containing "Chapter 1" processing               -
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
*  Rotine      : process_chapter_1()                                        |
|  Description : Will process chapter 1                                     *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void process_chapter_1(void)
  {
  // Define buffers...
  char buf[255];
  char buf3[255];
  char buf4[255];
  char buf5[255];

  register int i,j;        // Values for loops...
  int topics_number,line;  // File topics_number, and actual line
  int start_line,end_line; // Self explicit
  int valor_duplo;         // Value returned when we chack for duplicate
                           // topics...


  // Initialize all variables to 0
  i = 0;
  j = 0;
  line = 0;
  end_line = 0;
  start_line = 0;
  valor_duplo = 0;
  topics_number	= 0;
  // Open source file
  sourcefile = fopen("INTERRUP.1ST","rt");
  // Create Temporary Files
  temp1_file_topics = fopen("TEMPFILE.001","wt+");
  temp2_file_lines = fopen("TEMPFILE.002","wt+");
  temp3_file_proc_topics = fopen("TEMPFILE.003","wt+");
  temp5_file_comments = fopen("TEMPFILE.005","wt+");
  // Begin a menu...
  fputs("@menu\n",int2txi);
  // Write items
  creat_menu_item("Interrupt List","");
  creat_menu_item(int2txi_version,"");
  // End menu
  fputs("@end menu\n",int2txi);
  // Creation section
  creat_section("Interrupt List",int2txi_version,"Copying","Copying");
  // Process with general processing rotine...
  general_processing_rotine(use_sub_section,"Interrupt List",string_format,1);
  // creates section
  creat_section(int2txi_version,"","Interrupt List","Copying");
  // Start menu
  fputs("@menu\n",int2txi);
  // Write items
  creat_menu_item("Copyright (1)","");
  creat_menu_item("Greets","");
  creat_menu_item("Contact Information","");
  // End menu
  fputs("@end menu\n",int2txi);
  // Writes more data to target file
  creat_sub_section("Copyright (1)","Greets",int2txi_version,int2txi_version);
  fprintf(int2txi,"%s is\n",int2txi_version);
  fputs("Copyright @copyright{} 1998 Fernando J.A. Silva\n",int2txi);
  fputs("\n",int2txi);
  fputs("This program is free; this means that everyone is free to use it\n",int2txi);
  fputs("and free to redistribute it on a free basis. This program is not in\n",int2txi);
  fputs("the public domain; it is copyrighted and there are restrictions on his\n",int2txi);
  fputs("distribution, but these restrictions are designed to permit everything\n",int2txi);
  fputs("that a good cooperating citizen would want to do.\n",int2txi);
  fputs("What is not allowed is to try to prevent others from further sharing\n",int2txi);
  fputs("any version of this program that they might get from you.\n",int2txi);
  fputs("\n",int2txi);
  fputs("Specifically, I want to make sure that you have the right to give\n",int2txi);
  fputs("away copies of the program, that you receive source code or else can\n",int2txi);
  fputs("get it if you want it, that you can change this program or use pieces of it\n",int2txi);
  fputs("in new free programs, and that you know you can do these things.\n",int2txi);
  fputs("Considering that you should always remember that the original program is copyrighted\n",int2txi);
  fputs("and you should preserve my name and all the names of all contributers.\n",int2txi);
  fputs("\n",int2txi);
  fputs("To make sure that everyone has such rights, I have to forbid you to\n",int2txi);
  fputs("deprive anyone else of these rights.  For example, if you distribute\n",int2txi);
  fputs("copies of this program, you must give the recipients all the rights that you have.\n",int2txi);
  fputs("You must make sure that they, too, receive or can get the source code.\n",int2txi);
  fputs("And you must tell them their rights.\n",int2txi);
  fputs("\n",int2txi);
  fputs("Also, for my own protection, I must make certain that everyone finds\n",int2txi);
  fputs("out that there is no warranty for this program.\n",int2txi);
  fputs("If this program is modified by someone else and passed on, I want\n",int2txi);
  fputs("their recipients to know that what they have is not what I distributed,\n",int2txi);
  fputs("so that any problems introduced by others will not reflect on my reputation.\n",int2txi);
  fputs("\n",int2txi);
  fputs("The precise conditions of the licenses for the program currently\n",int2txi);
  fputs("being distributed are found in the General Public Licenses that accompany it.\n",int2txi);
  fputs("\n",int2txi);
  creat_sub_section("Greets","Contact Information","Copyright (1)",int2txi_version);
  fputs("When we make something we always have someone supporting us, helping us,\n",int2txi);
  fputs("talking with us about what we are making, or about girls, or about\n",int2txi);
  fputs("something relaxing. Or we have just some friends that are always there\n",int2txi);
  fputs("ready to chat with us.\n",int2txi);
  fputs("\n",int2txi);
  fputs("Internet modifies a person life. For example I'm a boy not so communicative,\n",int2txi);
  fputs("yes I no, I'm shy. Nevertheless on the Internet, specially on the IRC I'm an active \n",int2txi);
  fputs("person, we make projects on the IRC, we discuss ideas, we try to do things better.\n",int2txi);
  fputs("\n",int2txi);
  fputs("And is to that persons (probably my real friends) that I want to say: \n",int2txi);
  fputs("®Thanks guys!!! You are really the best!!!!¯\n",int2txi);
  fputs("So, here is the list of the guys on the PTNet #Coders (irc.telepac.pt) \n",int2txi);
  fputs("always trying to make something, specially trying to give love advices...\n",int2txi);
  fputs("\n",int2txi);
  fputs("@flushleft\n",int2txi);
  fputs("þ Anjo ----------- What happened to you? Are you giving advices about girls to\n",int2txi);
  fputs("                  someone else?\n",int2txi);
  fputs("þ Azevedo -------- Thanks for the CD. I was really needing that.\n",int2txi);
  fputs("þ Bond ----------- Is name is Bond, James Bond. So, what are you doing right now ?\n",int2txi);
  fputs("                  Say nothing. I will guess...hmmmm...you are using Delphi again...\n",int2txi);
  fputs("þ Bytter --------- Yo man. How is going your HP? Cool GFX... And your tutorials?\n",int2txi);
  fputs("þ CodeWiz -------- What can I say about him? His PTNet #Coders founder. And he gave\n",int2txi);
  fputs("                  me registered OP on the channel, after I boring him about one\n",int2txi);
  fputs("                  month. Thanks Code, but for your advices.\n",int2txi);
  fputs("                  By the way, why don't you still like my FTP?\n",int2txi);
  fputs("þ CyberLord ------ HeHe The most famous guy in Torres Vedras. You are going well...\n",int2txi);
  fputs("þ Deadkill ------- You were admired for found your MOD Player on my FTP? You should\n",int2txi);
  fputs("                  know that only the best stay there!!!\n",int2txi);
  fputs("þ Deep Blue ------ What can we say more about him... His Deep... His Blue...\n",int2txi);
  fputs("                  His an IBM... LOL\n",int2txi);
  fputs("þ Electron ------- The most electric guy on the channel.\n",int2txi);
  fputs("þ Erradicator ---- Hei man, should I still be waiting for your data base made\n",int2txi);
  fputs("                  with ASM on the next century?\n",int2txi);
  fputs("þ HELLMaster ----- Yo always liked my FTP, no?\n",int2txi);
  fputs("þ HiTek ---------- High Tecnology for sure!!!\n",int2txi);
  fputs("þ Lery ----------- Lery... Lery... Lery... Lery...\n",int2txi);
  fputs("þ MrUnderWorld --- Always downloading from my FTP. You are my best ®costumer¯!!!\n",int2txi);
  fputs("þ MrWho ---------- I love some of your modules, Relax8r, Boosted, Arabian Woman...\n",int2txi);
  fputs("                  Go on the good job... You are a good Tracker\n",int2txi);
  fputs("þ Myke ----------- When do you intend to make just one copy of ®Gamble¯ just for me?\n",int2txi);
  fputs("                  By the way did you already made your N§1000 kick\n",int2txi);
  fputs("                  You are really the best ""kicker"" on PTNet\n",int2txi);
  fputs("þ NetCyborg ------ My first coder friend on IRC, do you learned something of the\n",int2txi);
  fputs("                  things I teached you? I know I'm not a good teacher, but I\n",int2txi);
  fputs("                  always try to do my best!!!\n",int2txi);
  fputs("þ Reboot --------- A guy that makes less reboots than I, only because his using a\n",int2txi);
  fputs("                  true and good OS of course that is Linux.\n",int2txi);
  fputs("þ Shadow --------- Hmmm... where are you? I'm just seeing your shadow...\n",int2txi);
  fputs("þ Shlak ---------- Of course, I didn't forgot you, how could I forget the guy that\n",int2txi);
  fputs("                  gave me some ideas for the new PTNet #Coders HomePage?\n",int2txi);
  fputs("þ Storm_Crow ----- Oh well... another one...\n",int2txi);
  fputs("þ TheFlash ------- My theacher, I'll not forget you, you teached me great lessons...\n",int2txi);
  fputs("þ Toth ----------- Thanks for some sources you gave me. I couldn't learn somethings\n",int2txi);
  fputs("                  from elsewhere than your sources. By the way how is going your\n",int2txi);
  fputs("                  FTP Client?\n",int2txi);
  fputs("þ TroyAngel ------ The last ones are always the first ones...\n",int2txi);
  fputs("                  Can I sign your Script GuestBook?\n",int2txi);
  fputs("\n",int2txi);
  fputs("I really hope that I didn't forgot anyone... but just in case\n",int2txi);
  fputs("I'll also want to thanks all other people,\n",int2txi);
  fputs("on the others PTNet channels, Undernet #Coders and ICQ friends.\n",int2txi);
  fputs("\n",int2txi);
  fputs("But I can't leave without specially thanks to :\n",int2txi);
  fputs("\n",int2txi);
  fputs("DJ Delorie    --- DJGPP's author\n",int2txi);
  fputs("Robert H”hne  --- RHIDE's author\n",int2txi);
  fputs("Eli Zaretskii --- FAQ's maintainer\n",int2txi);
  fputs("Ralf Brown    --- Interrupt List maintainer\n",int2txi);
  fputs("\n",int2txi);
  fputs("and very specially to\n",int2txi);
  fputs("Salvador Eduardo Tropea (SET)  --- INFO Viewer author\n",int2txi);
  fputs("because he helped me resolving some big troubles.\n",int2txi);
  fputs("\n",int2txi);
  fputs("And to all the people of DJGPP's list.\n",int2txi);
  fputs("@end flushleft\n",int2txi);
  fputs("\n",int2txi);
  creat_sub_section("Contact Information","","Greets",int2txi_version);
  fputs("@flushleft\n",int2txi);
  fputs("Anyone with questions, ideas, problems, critiques...\n",int2txi);
  fputs("> Can send an e-mail to : \n",int2txi);
  fputs("        bfe2333@@mail.telepac.pt\n",int2txi);
  fputs("\n",int2txi);
  fputs("> Can find me on ICQ with the UIN : 1197830\n",int2txi);
  fputs("\n",int2txi);
  fputs("> Can find me on PTNet (irc.telepac.pt) with the nickname ^Magico^\n",int2txi);
  fputs("\n",int2txi);
  fputs("> Can write for my mail :\n",int2txi);
  fputs("        Fernando JA Silva\n",int2txi);
  fputs("        Juncal - Assequins\n",int2txi);
  fputs("        3750 µgueda\n",int2txi);
  fputs("        PORTUGAL\n",int2txi);
  fputs("\n",int2txi);
  fputs("> Can check #coders website :\n",int2txi);
  fputs("        ptcoders.home.ml.org\n",int2txi);
  fputs("        OR\n",int2txi);
  fputs("        members.xoom.com/Coders/\n",int2txi);
  fputs("\n",int2txi);
  fputs("> Or can post a message on pt.comp.geral NewsGroup\n",int2txi);
  fputs("\n",int2txi);
  fputs("GoodBye... and good coding...\n",int2txi);
  fputs("@end flushleft\n",int2txi);
  // Close source file
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
  } //process_chapter_1
