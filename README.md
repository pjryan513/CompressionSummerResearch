# Byte-Aligned Bitmap Code (BBC) Compression Algorithm

This BBC compression Algorithm was written by Patrick Ryan and Ian white during
the summer of 2017, under the supervision of Professor David Chiu, University of Puget Sound.
The algorithm is a continuation of the compression research being carried out by Professor Chiu.
Patrick Ryan and Ian White are the authors of the BBC portion of the project.
They make no claim to the other portions of the project, such as the VAL or WAL compression algorithms.

#Bitmap-Engine

The Bitmap-Engine folder contains the test environment for the overall compression research.  
This includes all current compression algorithms include up to the point where Patrick and Ian added their BBC code.
This is only a test version of the compression research for the creation and testing of new compression algorithms, specifically BBC.
The full and up to date version of the compression research can be found at Professor Chiu's github repository.  

#Documentation

The documentation folder contains the progress reports and weekly updates submitted by Patrick and Ian.
As well as other documenting materials such as finite state machines for mapping the BBC algorithm.
The weekly updates are written as html and css webpages and should at some point be hosted online soon, with up to date mapping of the project (coming soon...hopefully...also please ignore memes).

#Our_Code

The Our_Code folder contains the BBC portion of the Bitmap-Engine written by Patrick and Ian.
The folder is just to contain and present the files written by both students and can not be run due to lacking addition c and h files needed to compile and run.
The BBC algorithm can be run from the Bitmap-Engine folder.

#Running BBC

As of written now the main compression research algorithm can not be run from the central main function (Bitmap-Engine/BitmapEngine/src/main.c).
Instead the bbc_test_main should be used (Bitmap-Engine/BitmapEngine/src/bbc_test_main.c).
