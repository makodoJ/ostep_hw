Interlude: Memory API
========
Homework (Code)
---------
In this homework, you will gain some familiarity with memory allocation. First, you’ll write some buggy programs (fun!). Then, you’ll use some tools to help you find the bugs you inserted. Then, you will realize how awesome these tools are and use them in the future, thus making yourself more happy and productive. The tools are the debugger (e.g., gdb), and a memory-bug detector called valgrind[SN05].

Questions
----------
1.First, write a simple program called null.c that creates a pointer to an integer, sets it to NULL, and then tries to dereference it. Compile this into an executable called null. What happens when you run this program?\
`segmentation fault  ./null`

2.Next,compile this program with symbol information included(with the -g flag). Doing so let’s put more information into the executable, enabling the debugger to access more useful information about variable names and the like. Run the program under the debugger by typing gdb null and then, once gdb is running, typing run. What does gdb show you?\
  ` stop reason = EXC_BAD_ACCESS (code=1, address=0x0)`\
    `frame #0: 0x0000000100000f45 null`\
    `main(argc=1, argv=0x00007ffeefbff9c0) at null.c:11:20`\
    `-> 11  	    printf("%d\n", *p_int);`\
3.Finally, use the valgrind tool on this program. We’ll use the memcheck tool that is a part of valgrind to analyze what happens. Run this by typing in the following: valgrind --leak-check=yes null. What happens when you run this? Can you interpret the output from the tool?
    ==28464== Invalid read of size 4
    ==28464==    at 0x100000F45: main (null.c:11)
    ==28464==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
