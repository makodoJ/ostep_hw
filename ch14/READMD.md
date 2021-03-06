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
    `==28464== Invalid read of size 4`\
    `==28464==    at 0x100000F45: main (null.c:11)`\
    `==28464==  Address 0x0 is not stack'd, malloc'd or (recently) free'd`\
    
    ==28464== Process terminating with default action of signal 11 (SIGSEGV)
    ==28464==  Access not within mapped region at address 0x0
    ==28464==    at 0x100000F45: main (null.c:11)
    
    ==28464== HEAP SUMMARY:
    ==28464==     in use at exit: 13,753 bytes in 160 blocks
    ==28464==   total heap usage: 174 allocs, 14 frees, 18,497 bytes allocated

4.Write a simple program that allocates memory using malloc() but forgets to free it before exiting. What happens when this program runs? Can you use gdb to find any problems with it? How about valgrind (again with the --leak-check=yes flag)?\
  it runs fine\
  No\
  `==28489== Invalid write of size 4
==28489==    at 0x100000F38: main (in ./data)
==28489==  Address 0x10080e5e0 is 0 bytes after a block of size 400 alloc'd
==28489==    at 0x100110635: malloc (in /usr/local/Cellar/valgrind/HEAD-adaae87/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==28489==    by 0x100000F2F: main (in ./data)
==28489== 
==28489== Invalid read of size 4
==28489==    at 0x100000F46: main (in ./data)
==28489==  Address 0x10080e5e0 is 0 bytes after a block of size 400 alloc'd
==28489==    at 0x100110635: malloc (in /usr/local/Cellar/valgrind/HEAD-adaae87/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==28489==    by 0x100000F2F: main (in ./data)
==28489== 
0
==28489== 
==28489== HEAP SUMMARY:
==28489==     in use at exit: 17,845 bytes in 160 blocks
==28489==   total heap usage: 175 allocs, 15 frees, 22,989 bytes allocated
==28489== 
==28489== LEAK SUMMARY:
==28489==    definitely lost: 0 bytes in 0 blocks
==28489==    indirectly lost: 0 bytes in 0 blocks
==28489==      possibly lost: 0 bytes in 0 blocks
==28489==    still reachable: 0 bytes in 0 blocks
==28489==         suppressed: 17,845 bytes in 160 blocks`\
6.Create a program that allocates an array of integers (as above), frees them, and then tries to print the value of one of the elements of the array. Does the program run? What happens when you use valgrind on it?\

it runs well

`==28589== Invalid read of size 4`\
`==28589==    at 0x100000F46: main (in ./free_print)`\
`==28589==  Address 0x10080e450 is 0 bytes inside a block of size 40 free'd`\

7.Now pass a funny value to free (e.g., a pointer in the middle of the array you allocated above). What happens? Do you need tools to find this type of problem?

`funny_free_print.c:13:10: warning: incompatible integer to pointer conversion`\
      `passing 'int' to parameter of type 'void *' [-Wint-conversion]`\
    `free(array[5]);`\
    
    ==28615== Invalid free() / delete / delete[] / realloc()
    ==28615==    at 0x100110A0D: free (in /usr/local/Cellar/valgrind/HEAD-adaae87/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
    ==28615==    by 0x100000F2D: main (in ./funny_free_print)
    ==28615==  Address 0x5 is not stack'd, malloc'd or (recently) free'd
    
8.Try out some of the other interfaces to memory allocation. For example, create a simple vector-like data structure and related routines that use realloc() to manage the vector. Use an array to store the vectors elements; when a user adds an entry to the vector, use realloc() to allocate more space for it. How well does such a vector perform? How does it compare to a linked list? Use valgrind to help you find bugs.


