# get_next_line - @42Wolfsburg
## description
get_next_line is a project about creating a function that reads a line ending with a newline character ('\n') from a file descriptor, without knowing its size beforehand.

main concepts in this project are:

  → static variables, and complexity of using of one or many of them;
  
  → allocations, in stack memory or in the heap memory;
  
  → manipulation and the life cycle of a buffer.

here are some **sources** that helped me:

• [get_next_line explained : develop a function that reads a file line by line](https://www.youtube.com/watch?v=8E9siq7apUU&ab_channel=Oceano)

• [master file I/O operations with 42’s get_next_line project](https://medium.com/@ayogun/master-file-i-o-operations-with-42s-get-next-line-project-5fb001d1fff5)

• [42 get next line guide (string approach)](https://medium.com/@lannur-s/gnl-c3cff1ee552b)
  

## how does it work
this project uses special variables called **static variables**, they remember their value even after the function is called again.

my code reads lines from a file one by one, as required.

it first reads characters from the file until it encounters a newline character or reaches the end of the file.

then, it extracts the line it has read and returns it. the function keeps track of the remaining part of the line for future reads.

if there are no more lines to read, it returns NULL.

## my final grade
![get_next_line grade](https://github.com/idleira/get_next_line/assets/127216218/3197b842-aa2b-4d7b-a57f-31fc3e3156c0)
