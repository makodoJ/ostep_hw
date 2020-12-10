# Homework (Simulation)
This simulator, paging-policy.py, allows you to play around with different page-replacement policies. See the README for details.

## Questions
1.Generate random addresses with the following arguments: -s 0 -n 10, -s 1 -n 10, and -s 2 -n 10. Change the policy from FIFO, to LRU, to OPT. Compute whether each access in said address traces are hits or misses.

`./paging-policy.py -s 0 -n 10` hit rate: 
                                          FIFO: 0.1   LRU: 0.2    OPT: 0.4
`./paging-policy.py -s 1 -n 10` hit rate:
                                          FIFO: 0.2   LRU: 0.2    OPT: 0.3
`./paging-policy.py -s 2 -n 10` hit rate:
                                          FIFO: 0.4   LRU: 0.4    OPT: 0.4 


2.For a cache of size 5, generate worst-case address reference streams for each of the following policies: FIFO, LRU, and MRU (worst-case reference streams cause the most misses possible). For the worst case reference streams, how much bigger of a cache is needed to improve performance dramatically and approach OPT?



3.Generate a random trace (use python or perl). How would you expect the different policies to perform on such a trace?




4.Generate a random trace (use python or perl). How would you expect the different policies to perform on such a trace?



5.Use a program like valgrind to instrument a real application and generate a virtual page reference stream. For example, running valgrind --tool=lackey --trace-mem=yes ls will output a nearly-complete reference trace of every instruction and data reference made by the program ls. To make this useful for the simulator above, you’ll have to first transform each virtual memory reference into a virtual page-number reference (done by masking off the offset and shifting the resulting bits downward). How big of a cache is needed for your application trace in order to satisfy a large fraction of requests? Plot a graph of its working set as the size of the cache increases.



