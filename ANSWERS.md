**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Created: The process has been initially created
Ready: The process has been fully set up (initially or from a waiting state), and is ready to run.
Running: The process is executing its code
Waiting: The process has stopped running, and has been put on standby while something else runs.
Terminated: The process has exited, and is waiting for cleanup from its parent process.



**2. What is a zombie process?**
A zombie process is a process in the point in time after it exits, but before its parent has cleaned it up.


**3. How does a zombie process get created? How does one get destroyed?**
A zombie process comes into (un)being when a child process terminates, and remains that way until its parent process cleans it up (destroys it).


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled languages often confer large speed benefits due to them natively being closer to machine code than an interpreted language like javascript, which is interpreted and run at runtime. Compiled languages also generally offer more access to system level functionality as well, such as direct allocation of memory (malloc) and accessing the file system.
