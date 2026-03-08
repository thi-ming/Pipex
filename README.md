_This project has been created as part of the 42 curriculum by thi-ming_

# Description :
	* Pipex is a 42 project that recreates the behavior of the shell pipeline:
	* < infile cmd1 | cmd2 > outfile
	* The program reproduces this behavior using only low‑level UNIX system calls.
	* The project shows how file descriptors work, how processes communicate through pipes, and how shells implement redirections internally.

# Instructions :
	* make builds the pipex executable.
	* The program must be executed as follows:
	./pipex infile "cmd1" "cmd2" outfile
	* This should behave exactly like the shell:
	< infile cmd1 | cmd2 > outfile

# Resources :
	* https://dev.to/herbievine/42-a-comprehensive-guide-to-pipex-5165?utm_source=copilot.com
	* https://en.wikipedia.org/wiki/Pipeline_(Unix)
	* AI helps explain a lot of details and missing pieces of the parent - children processes.

		
