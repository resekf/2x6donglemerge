# Namco System 2x6 dongle merger

##### Note: This program isn't written very well since I'm still a beginner in C++ and programming. But I had fun doing it.
This program takes 512 bytes from the dongle file, then adds 16 bytes from the ECC data file, does that 16384 times and adds that merged data to a new file.

## What?
MAME System 2x6 dongle files are most often distributed as 2 files, for example:
* tk71.ic002
* tk71_spr.ic002
#### .ic002 File Format
The .ic002 files are just PS2 Memory Card images with a different file extension. PS2 Memory Card images always include the ECC data inside of the file, meanwhile System 2x6 dongle images which you can find online usually have the ECC data in a separate file (_spr.ic002). This makes it harder to extract the files from the dongles using mymc because the dongle file is an incorrect size.
The "_spr.ic002" files contain the ECC data which is just a bunch of 16 byte `20-bit Hamming` codes.
## Why?
I know this program most likely won't be used by anyone since the merged dongle files are available online, but I wanted to make this program anyways because I've always wanted to learn C++ and this was a fun project to begin with. (also I found out about the merged files online after I made the program... oh well)
