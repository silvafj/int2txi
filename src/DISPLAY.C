/*
                              FILE INFORMATION
 ----------------------------------------------------------------------------
 - FILE            : DISPLAY.C                                              -
 - MODULE          : Module containing rotines to give info to the user     -
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
*  Rotine      : print_help_options()                                       |
|  Description : Prints the basic commands to the screen                    *
*  Input       : location --> where is the current program                  |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void print_help_options(char *location)
  {
  fprintf(stdout,"\n");
  fprintf(stdout,"%s converts Ralf Brown Interrupt List to TeXinfo format\n",int2txi_version);
  fprintf(stdout,"(C) 1998 Fernando J.A. Silva <bfe2333@mail.telepac.pt>\n");
  fprintf(stdout,"\n");
  fprintf(stdout,"usage: %s [options]\n",location);
  fprintf(stdout,"\n");
  fprintf(stdout,"options :\n");
  fprintf(stdout,"  -s start convertion\n");
  fprintf(stdout,"  -m use makeinfo to convert to info format\n");
  fprintf(stdout,"     (you need to have makeinfo installed in your system)\n");
  fprintf(stdout,"  -g use gzip to compress the final files (you need to have gzip)\n");
  fprintf(stdout,"     (you need to have gzip installed in your system)\n");
  fprintf(stdout,"  -i display software license\n");
  fprintf(stdout,"  -h this help\n");
  fprintf(stdout,"\n");
  } // print_help_options()

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : print_software_license()                                   |
|  Description : self explained                                             *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void print_software_license()
  {
  clrscr();
  fprintf(stdout,"\n");
  fprintf(stdout,"%s converts Ralf Brown Interrupt List to TeXinfo format\n",int2txi_version);
  fprintf(stdout,"(C) 1998 Fernando J.A. Silva <bfe2333@mail.telepac.pt>\n");
  fprintf(stdout,"\n");
  fprintf(stdout,"    Int2Txi is free software; you can redistribute it and/or\n");
  fprintf(stdout,"    modify them under the terms of the GNU General Public License as\n");
  fprintf(stdout,"    published by the Free Software Foundation; either version 2 of\n");
  fprintf(stdout,"    the License, or (at your option) any later version.\n");
  fprintf(stdout,"\n");
  fprintf(stdout,"    This program is distributed in the hope that it will be useful,\n");
  fprintf(stdout,"    but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
  fprintf(stdout,"    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
  fprintf(stdout,"    GNU General Public License for more details.\n");
  fprintf(stdout,"\n");
  fprintf(stdout,"    You should have received a copy of the GNU General Public License\n");
  fprintf(stdout,"    along with this program; see the file COPYING.\n");
  fprintf(stdout,"    If not, write to the Free Software Foundation, Inc.,\n");
  fprintf(stdout,"    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.\n");
  fprintf(stdout,"\n");
  fprintf(stdout,"    For more information visit:\n");
  fprintf(stdout,"    http://members.xoom.com/Coders/projectos/int2txi.htm\n");
  fprintf(stdout,"\n");
  } // print_software_license()

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : check_makeinfo()                                           |
|  Description : Checks for the presence of makeinfo                        *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void check_makeinfo()
  {
  makeinfo = (char *)(searchpath("makeinfo.exe"));
  if (makeinfo != NULL)
    {
    fprintf(stdout,"MakeInfo found as %s\n",makeinfo);
    fprintf(stdout,"Makeinfo will be used to convert TeXinfo to info format\n");
    fprintf(stdout,"\n");
    use_makeinfo = 1;
    }
  else
    {
    fprintf(stdout,"Makeinfo not found\n");
    fprintf(stdout,"Makeinfo will not be used to convert TeXinfo to info format\n");
    fprintf(stdout,"\n");
    use_makeinfo = 0;
    }
  } // check_makeinfo

/*
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
|                                                                           *
*  Rotine      : check_gzip()                                               |
|  Description : Checks for the presence od gzip                            *
*  Input       : ----                                                       |
|  Return      : ----                                                       *
*                                                                           |
*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
*/
void check_gzip()
  {
  gzip = (char *)(searchpath("gzip.exe"));
  if (gzip != NULL)
    {
    fprintf(stdout,"Gzip found as %s\n",gzip);
    fprintf(stdout,"Gzip will be used to compress the final info files\n");
    fprintf(stdout,"\n");
    use_gzip = 1;
    }
  else
    {
    fprintf(stdout,"Gzip not found\n");
    fprintf(stdout,"Gzip will not be used to compress the final info files\n");
    fprintf(stdout,"\n");
    use_gzip = 0;
    }
  } // check_gzip
  
  
