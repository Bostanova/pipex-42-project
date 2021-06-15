
Usage: 
   make
   ./pipex file1 cmd1 cmd2 file2
   
   file1 and file2 are file names, 
   cmd1 and cmd2 are shell commands with their parameters.

The execution of the this program do the same as the next shell command:
  < file1 cmd1 | cmd2 > file2
  
  
For example:
  ./pipex infile "ls -l" "wc -l" outfile 
  is the same as:
  "< infile ls -l | wc -l > outfile"
