# Free-Space Management
## Homework (Simulation)
The program, malloc.py, lets you explore the behavior of a simple free-space allocator as described in the chapter. See the README for details of its basic operation.

## Questions

1.First run with the flags -n 10 -H 0 -p BEST -s 0 to generate a few random allocations and frees. Can you predict what alloc()/free() will return? Can you guess the state of the free list after each request? What do you notice about the free list over time?
```
ptr[0] = Alloc(3) returned 1000
Free List [Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0]) returned 0
Free List [Size 2 ]: [ addr:1000 sz:3 ] [addr:1003 sz:97 ] 

ptr[1] = Alloc(5)  returned 1003
Free List [Size 2 ]: [ addr:1000 sz:3 ] [ addr:1008 sz:92 ] 

Free(ptr[1]) returned 0
Free List [ Size 3 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:92 ]

ptr[2] = Alloc(8)  returned 1008
Free List [ Size 3 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1016 sz:84 ]

Free(ptr[2]) returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[3] = Alloc(8)  returned 1008
Free List [ Size 3 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1024 sz:76 ]

Free(ptr[3]) returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ] 

ptr[4] = Alloc(2)  returned 1024
Free List [ Size 4 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ] 

ptr[5] = Alloc(7)  returned 1026
Free List [ Size 4 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]
```

2.How are the results different when using a WORST fit policy to search the freelist(-p WORST)? What changes?

The memory is divided into more pieses, for example int question 1, ptr[3] = Alloc(8) will not return 1008 and its free list will still be 4

3.What about when using FIRST fit (-p FIRST)? What speeds up when you use first fit?

search less elements

4.For the above questions, how the list is kept ordered can affect the time it takes to find a free location for some of the policies. Use the different free list orderings(-l ADDRSORT,-l SIZESORT+,-l SIZESORT-) to see how the policies and the list orderings interact.

5.Coalescing of a free list can be quite important. Increase the number of random allocations (say to -n 1000). What happens to larger allocation requests over time? Run with and without coalescing (i.e., without and with the -C flag). What differences in outcome do you see? How big is the free list over time in each case? Does the ordering of the list matter in this case?


without coalescing, larger memory required may return NULL, and the free list is larger than coalescing

6.What happens when you change the percent allocated fraction -P to higher than 50? What happens to allocations as it nears 100? What about as the percent nears 0?

when nears 100, no more spaces to allocate, when near to 0, all pointers are freed

7.What kind of specific requests can you make to generate a highly-fragmented free space? Use the -A flag to create fragmented free lists, and see how different policies and options change the organization of the free list.
