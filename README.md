
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
  
 BONUS part:
 -  Handle multiple pipes:
       ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
        equivalent to:
       < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
 - Support « and » when the first parameter is "here_doc"
       ./pipex here_doc LIMITER cmd cmd1 file
        equivalent to:
       cmd << LIMITER | cmd1 >> file
