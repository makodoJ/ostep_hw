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

FIFO: `./paging-policy.py --addresses=0,1,2,3,4,5,0,1,2,3,4,5 -c`

LRU: `./paging-policy.py --addresses=0,1,2,3,4,5,0,1,2,3,4,5 -p LRU -c`

MRU: `./paging-policy.py --addresses=0,1,2,3,4,5,4,5,4,5,4,5 -p MRU -c`

add one

3.Generate a random trace (use python or perl). How would you expect the different policies to perform on such a trace?

```
./paging-policy.py -s 0 -n 10 -c
FINALSTATS hits 1   misses 9   hitrate 10.00

./paging-policy.py -s 0 -n 10 -c -p LRU
FINALSTATS hits 2   misses 8   hitrate 20.00

./paging-policy.py -s 0 -n 10 -c -p OPT
FINALSTATS hits 4   misses 6   hitrate 40.00

./paging-policy.py -s 0 -n 10 -c -p UNOPT
FINALSTATS hits 0   misses 10   hitrate 0.00

./paging-policy.py -s 0 -n 10 -c -p RAND
FINALSTATS hits 0   misses 10   hitrate 0.00

./paging-policy.py -s 0 -n 10 -c -p CLOCK
FINALSTATS hits 1   misses 9   hitrate 10.00
```


4.Now generate a trace with some locality. How can you generate such a trace? How does LRU perform on it? How much better than RAND is LRU? How does CLOCK do? How about CLOCK with different numbers of clock bits?

```
./paging-policy.py --addresses=4,8,1,1,1,1,1,1,2,3,1,1 -c

FINALSTATS hits 7   misses 5   hitrate 58.33


./paging-policy.py --addresses=4,8,1,1,1,1,1,1,2,3,1,1 -p LRU -c

FINALSTATS hits 7   misses 5   hitrate 58.33


./paging-policy.py --addresses=4,8,1,1,1,1,1,1,2,3,1,1 -p CLOCK -c -b 0

FINALSTATS hits 6   misses 6   hitrate 50.00


./paging-policy.py --addresses=4,8,1,1,1,1,1,1,2,3,1,1 -p CLOCK -c -b 1

FINALSTATS hits 6   misses 6   hitrate 50.00


./paging-policy.py --addresses=4,8,1,1,1,1,1,1,2,3,1,1 -p CLOCK -c -b 2

FINALSTATS hits 6   misses 6   hitrate 50.00
```

5.Use a program like valgrind to instrument a real application and generate a virtual page reference stream. For example, running valgrind --tool=lackey --trace-mem=yes ls will output a nearly-complete reference trace of every instruction and data reference made by the program ls. To make this useful for the simulator above, you’ll have to first transform each virtual memory reference into a virtual page-number reference (done by masking off the offset and shifting the resulting bits downward). How big of a cache is needed for your application trace in order to satisfy a large fraction of requests? Plot a graph of its working set as the size of the cache increases.



