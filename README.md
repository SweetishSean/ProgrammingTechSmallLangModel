# ProgrammingTechSmallLangModel
This program is for SU's Programming Techniques course.
This has been written by Sean Weinstein.

This program wll use a small language model with some input text to generate text.
The code is all in the ./src folder. The text must be in the same folder as the Makefile.
The program assumes that every character can fit into 1 byte.
The text I downloaded off canvas "a_modest_proposal.txt" and "moby_dick.txt" do not have this quality. For some reason every return is actually two characters (I believe its a windows problem). There are some other exceptions too but this is the main one. I created versions that stripped all those out and just left with the one char. These I titled "a_modest_proposal_ascii.txt" and "moby_dick_ascii.txt". The program works much better with these versions.

To use this program do the following steps:
$ make
$ ./slm k file.txt length
or
$ ./slm -a alpha k file.txt length

the program wants k and length to be an positive non-zero integer. Alpha to be a an positive non-zero number. If you want something close to english then low alpha is better. file.txt is just a file for the data to read in from.
The program will handel errors.
