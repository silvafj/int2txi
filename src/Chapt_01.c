/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : CHAPT_01.C                                             -
 - MODULE          : Module containing "Chapter 1" processing               -
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
  // Begin a menu...
  fputs("@menu\n",Int2TeX);
  // Write items
  creat_menu_item("Interrupt List","",manual_item);
  creat_menu_item("Int2TeX v1.0","",manual_item);
  // End menu
  fputs("@end menu\n",Int2TeX);
  // Creation section
  creat_section("Interrupt List","Int2TeX v1.0","Copying","Copying");
  // Process...
  general_processing_rotine(1,"Interrupt List",string_format);
  // creates section
  creat_section("Int2TeX v1.0","","Interrupt List","Copying");
  // Start menu
  fputs("@menu\n",Int2TeX);
  // Write items
  creat_menu_item("Copyright (1)","",manual_item);
  creat_menu_item("Greets","",manual_item);
  creat_menu_item("Contact Information","",manual_item);
  // End menu
  fputs("@end menu\n",Int2TeX);
  // Writes more data to target file
  creat_sub_section("Copyright (1)","Greets","Int2TeX v1.0","Int2TeX v1.0");
  fputs("Int2TeX v1.0 is\n",Int2TeX);
  fputs("Copyright @copyright{} 1998 Fernando J.A. Silva\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("This program is free; this means that everyone is free to use it\n",Int2TeX);
  fputs("and free to redistribute it on a free basis. This program is not in\n",Int2TeX);
  fputs("the public domain; it is copyrighted and there are restrictions on his\n",Int2TeX);
  fputs("distribution, but these restrictions are designed to permit everything\n",Int2TeX);
  fputs("that a good cooperating citizen would want to do.\n",Int2TeX);
  fputs("What is not allowed is to try to prevent others from further sharing\n",Int2TeX);
  fputs("any version of this program that they might get from you.\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("Specifically, I want to make sure that you have the right to give\n",Int2TeX);
  fputs("away copies of the program, that you receive source code or else can\n",Int2TeX);
  fputs("get it if you want it, that you can change this program or use pieces of it\n",Int2TeX);
  fputs("in new free programs, and that you know you can do these things.\n",Int2TeX);
  fputs("Considering that you should always remember that the original program is copyrighted\n",Int2TeX);
  fputs("and you should preserve my name and all the names of all contributers.\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("To make sure that everyone has such rights, I have to forbid you to\n",Int2TeX);
  fputs("deprive anyone else of these rights.  For example, if you distribute\n",Int2TeX);
  fputs("copies of this program, you must give the recipients all the rights that you have.\n",Int2TeX);
  fputs("You must make sure that they, too, receive or can get the source code.\n",Int2TeX);
  fputs("And you must tell them their rights.\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("Also, for my own protection, I must make certain that everyone finds\n",Int2TeX);
  fputs("out that there is no warranty for this program.\n",Int2TeX);
  fputs("If this program is modified by someone else and passed on, I want\n",Int2TeX);
  fputs("their recipients to know that what they have is not what I distributed,\n",Int2TeX);
  fputs("so that any problems introduced by others will not reflect on my reputation.\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("The precise conditions of the licenses for the program currently\n",Int2TeX);
  fputs("being distributed are found in the General Public Licenses that accompany it.\n",Int2TeX);
  fputs("\n",Int2TeX);
  creat_sub_section("Greets","Contact Information","Copyright (1)","Int2TeX v1.0");
  fputs("When we make something we always have someone supporting us, helping us,\n",Int2TeX);
  fputs("talking with us about what we are making, or about girls, or about\n",Int2TeX);
  fputs("something relaxing. Or we have just some friends that are always there\n",Int2TeX);
  fputs("ready to chat with us.\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("Internet modifies a person life. For example I'm a boy not so communicative,\n",Int2TeX);
  fputs("yes I no, I'm shy. Nevertheless on the Internet, specially on the IRC I'm an active \n",Int2TeX);
  fputs("person, we make projects on the IRC, we discuss ideas, we try to do things better.\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("And is to that persons (probably my real friends) that I want to say: \n",Int2TeX);
  fputs("®Thanks guys!!! You are really the best!!!!¯\n",Int2TeX);
  fputs("So, here is the list of the guys on the PTNet #Coders (irc.telepac.pt) \n",Int2TeX);
  fputs("always trying to make something, specially trying to give love advices...\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("@flushleft\n",Int2TeX);
  fputs("þ Anjo ----------- What happened to you? Are you giving advices about girls to\n",Int2TeX);
  fputs("                  someone else?\n",Int2TeX);
  fputs("þ Azevedo -------- Thanks for the CD. I was really needing that.\n",Int2TeX);
  fputs("þ Bond ----------- Is name is Bond, James Bond. So, what are you doing right now ?\n",Int2TeX);
  fputs("                  Say nothing. I will guess...hmmmm...you are using Delphi again...\n",Int2TeX);
  fputs("þ Bytter --------- Yo man. How is going your HP? Cool GFX... And your tutorials?\n",Int2TeX);
  fputs("þ CodeWiz -------- What can I say about him? His PTNet #Coders founder. And he gave\n",Int2TeX);
  fputs("                  me registered OP on the channel, after I boring him about one\n",Int2TeX);
  fputs("                  month. Thanks Code, but for your advices.\n",Int2TeX);
  fputs("                  By the way, why don't you still like my FTP?\n",Int2TeX);
  fputs("þ CyberLord ------ HeHe The most famous guy in Torres Vedras. You are going well...\n",Int2TeX);
  fputs("þ Deadkill ------- You were admired for found your MOD Player on my FTP? You should\n",Int2TeX);
  fputs("                  know that only the best stay there!!!\n",Int2TeX);
  fputs("þ Deep Blue ------ What can we say more about him... His Deep... His Blue...\n",Int2TeX);
  fputs("                  His an IBM... LOL\n",Int2TeX);
  fputs("þ Electron ------- The most electric guy on the channel.\n",Int2TeX);
  fputs("þ Erradicator ---- Hei man, should I still be waiting for your data base made\n",Int2TeX);
  fputs("                  with ASM on the next century?\n",Int2TeX);
  fputs("þ HELLMaster ----- Yo always liked my FTP, no?\n",Int2TeX);
  fputs("þ HiTek ---------- High Tecnology for sure!!!\n",Int2TeX);
  fputs("þ Lery ----------- Lery... Lery... Lery... Lery...\n",Int2TeX);
  fputs("þ MrUnderWorld --- Always downloading from my FTP. You are my best ®costumer¯!!!\n",Int2TeX);
  fputs("þ MrWho ---------- I love some of your modules, Relax8r, Boosted, Arabian Woman...\n",Int2TeX);
  fputs("                  Go on the good job... You are a good Tracker\n",Int2TeX);
  fputs("þ Myke ----------- When do you intend to make just one copy of ®Gamble¯ just for me?\n",Int2TeX);
  fputs("                  By the way did you already made your N§1000 kick\n",Int2TeX);
  fputs("                  You are really the best ""kicker"" on PTNet\n",Int2TeX);
  fputs("þ NetCyborg ------ My first coder friend on IRC, do you learned something of the\n",Int2TeX);
  fputs("                  things I teached you? I know I'm not a good teacher, but I\n",Int2TeX);
  fputs("                  always try to do my best!!!\n",Int2TeX);
  fputs("þ Reboot --------- A guy that makes less reboots than I, only because his using a\n",Int2TeX);
  fputs("                  true and good OS of course that is Linux.\n",Int2TeX);
  fputs("þ Shadow --------- Hmmm... where are you? I'm just seeing your shadow...\n",Int2TeX);
  fputs("þ Shlak ---------- Of course, I didn't forgot you, how could I forget the guy that\n",Int2TeX);
  fputs("                  gave me some ideas for the new PTNet #Coders HomePage?\n",Int2TeX);
  fputs("þ Storm_Crow ----- Oh well... another one...\n",Int2TeX);
  fputs("þ TheFlash ------- My theacher, I'll not forget you, you teached me great lessons...\n",Int2TeX);
  fputs("þ Toth ----------- Thanks for some sources you gave me. I couldn't learn somethings\n",Int2TeX);
  fputs("                  from elsewhere than your sources. By the way how is going your\n",Int2TeX);
  fputs("                  FTP Client?\n",Int2TeX);
  fputs("þ TroyAngel ------ The last ones are always the first ones...\n",Int2TeX);
  fputs("                  Can I sign your Script GuestBook?\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("I really hope that I didn't forgot anyone... but just in case\n",Int2TeX);
  fputs("I'll also want to thanks all other people,\n",Int2TeX);
  fputs("on the others PTNet channels, Undernet #Coders and ICQ friends.\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("But I can't leave without specially thanks to :\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("DJ Delorie    --- DJGPP's author\n",Int2TeX);
  fputs("Robert H”hne  --- RHIDE's author\n",Int2TeX);
  fputs("Eli Zaretskii --- FAQ's maintainer\n",Int2TeX);
  fputs("Ralf Brown    --- Interrupt List maintainer\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("and very specially to\n",Int2TeX);
  fputs("Salvador Eduardo Tropea (SET)  --- INFO Viewer author\n",Int2TeX);
  fputs("because he helped me resolving some big troubles.\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("And to all the people of DJGPP's list.\n",Int2TeX);
  fputs("@end flushleft\n",Int2TeX);
  fputs("\n",Int2TeX);
  creat_sub_section("Contact Information","","Greets","Int2TeX v1.0");
  fputs("@flushleft\n",Int2TeX);
  fputs("Anyone with questions, ideas, problems, critiques...\n",Int2TeX);
  fputs("> Can send an e-mail to : \n",Int2TeX);
  fputs("        bfe2333@@mail.telepac.pt\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("> Can find me on ICQ with the UIN : 1197830\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("> Can find me on PTNet (irc.telepac.pt) with the nickname ^Magico^\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("> Can write for my mail :\n",Int2TeX);
  fputs("        Fernando JA Silva\n",Int2TeX);
  fputs("        Juncal - Assequins\n",Int2TeX);
  fputs("        3750 µgueda\n",Int2TeX);
  fputs("        PORTUGAL\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("> Or can post a message on pt.comp.geral NewsGroup\n",Int2TeX);
  fputs("\n",Int2TeX);
  fputs("GoodBye... and good coding...\n",Int2TeX);
  fputs("@end flushleft\n",Int2TeX);
  } //process_chapter_1
