# ACA-OOPS-2022
## 1)To change directory in CMD
### a)CD\
#### Goes to the root of the drive
### b)CD path
#### To navigate a specific folder in CMD
### c)CD..
#### To change the parent directory in CMD
## 2)To change the drive in CMD
#### a)If you want to change the drive from C: to D: ,you should type d:,Command prompt is not case sensitive
#### b)If you want to change the drive and the directory at the same time,use the cd command,followed by the /d switch.
#### By typing only the drive letter you automatically move to yur most recent location on that drive.
## 3)To view the contents of a directory in Command Prompt 
### DIR in CMD
#### To navigate to the folder,we have to use the command cd/dD:\folder name.To view the contents od the folder,typr DIR
## 4)To create a new directory with command prompt
#### To make anew folder,syntax is MKDIR Folder or MD Folder
## 5)To rename files and folders
#### If you want to rename a Folder with New folder name, we use the syntax: ren Folder New folder name
## 6)To copy files in CMD
#### COPY command allows you to copy files from one location to another.
####syntax:copy location\filename.extension
####       newlocation\newname.extension
## 7)TO copy folders in CMD including their contents
#### TO copy a folder and its content from one location to other
#### syntax:xcopy/s/i d:\location1c:\location2
## 8)To delete files
#### To delete all the files from a folder
#### syntax:del folder
### a)DEL*DOCX
#### deletes all files in the current folder that have the DOCX extension 
### b)DEL Test*.*
#### deletes all the files in the working folder whose names begin with Test
### c)DEL*.*
#### deletes all the files in the current folder
## 9)To delete a folder from CMD
#### DEL command cannot be used to delete folders.To remove any empty folder we use RD
#### syntax:RD[Folder]
####To delete the directory too we use RD folder name
##10)To launch an app from CMD
####If you want to launch control panel using command prompt go to C:\Windows\System32,whee its executable is:control.exe
##11)To get help in the command prompt
####help displays a list of all the available commands.If a particular command interests you,type help followed by name of that command.Another way to do same thing is to type the command's name followed by /?parameter.
