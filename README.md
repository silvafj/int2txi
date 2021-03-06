
                                                  Int2Txi
                                                  ~~~~~~~

                                        Ralph Brown's interrupt list

                                        converter for TeXinfo format

                                               version 1.2.0
  
                                             Copyright (C) 1998

                                            Fernando J.A. Silva


# What is It?

Int2Txi is a converter that converts, the famous, Ralph Brown's Interrupt List to Texinfo format, that then is converted to Info format with makeinfo.

The final info files can be viewed with RHIDE InfoViewer, DJGPP Info or with SET's Editor.

# How to Install?

This distribution includes the binary file and the source files.

So, you have just to do:

     unzip i2txi120.zip     or   pkunzip -d i2txi120.zip

in your DJGPP directory.

# How to Use?

Create a directory where you should put *ALL* Interrupt List files, including a file called "COMBINE.COM".

You should have be installed "Makeinfo" too. This file will convert from Texinfo to Info format.

If you have also "GZip" installed it will be used to compress the final info files.

Simply type:

           Int2Txi [options]

Use the -h option for command line help.
Use the -i option for software license.
Use the -s option to start the convertion.
Use the -m option to use makeinfo (if present in the system)
Use the -g option to use gzip (if present in the system)

The convertion takes about 20 minutes (10 minutes Int2Txi and 10 minutes Makeinfo).

The final files will be : "INT2TXI.TXI" is the file created by Int2Txi, and if you choose "-m" option, the program will also run makeinfo to create the final info files, they are about 180 files RBINxxx. You need to put all this info files on you DJGPP\Info directory.

The use of this files requires that you already know how to access Info files.

The symbols that appear when Int2Txi is converting a file are :
* the name of the file being processed
* the numbers are the corrent interrupt being processed
* '_' means that the program is checking all topics and it's creting
a menu
* '.' means that data it's being transfered

# Legal Issues

Int2Txi is covered by the GNU General Public Licence (GLP).
Please see LICENSE file for more information.

# Warranty

 #include "as_usual_no_warranty.h"
 Please see COPYING file for more information.

# Thanks

DJ Delorie for DJGPP.
Salvador Eduardo Tropea for some helpfull ideas.
Eli Zaretskii and all the others that gave me bug reports and
also very good ideas.

# Contact

 Fernando J.A. Silva
 email : bfe2333@mail.telepac.pt
 UIN   : 1197830
 #Coders irc.telepac.pt

# History
v1.0.0  1998. 06. 01
====================
- Original release.

v1.1.0  1998. 07. 01
====================
- The name changed from Int2TeX to Int2Txi because it's the right one.
- The convertion algorithm was corrected. Now it converts all topics.
- The speed was also incresed. Now it's about 25% faster.
- Some annoying situations, as some fatal errors, when some files were missing, were corrected.

# Things to do

+ Use memory access for faster convertion, and do more work with less time.
+ Make more cross references. Actually I only have cross references to tables.
- Actually I'm using disk access for temporary files.

Symbols
+ Things to do
- Things to delete

# Known bugs or problems

Problem  : When viewing the info file with RHIDE, there are some nodes where RHIDE freezes.
Solution : That happens if you are using RHIDE version 1.4, with the new version 1.4.5 that doesn't happen anymore

Problem  : When the program run "makeinfo" and starts the convertion from TeXinfo to Info format, it aborts and says that there is no memory available.
Solution : Yes, it's true. To resolve this you can do two things, or you buy more RAM, or you run "Int2Txi" in DOS (not DOS prompt) and not inside Windows.

Problem  : When converting the list there are various files that are missing.
Solution : Int2Txi was made based on RBList 56, so if you don't have release 56 or later, you should get one. You should also check if you copied ALL RBList files to one directory.

# Referenced in

https://www.google.com/#safe=strict&q=%22int2tex+v1%22+OR+%22int2txi+v1%22 
