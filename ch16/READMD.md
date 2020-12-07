# Segmentation
## Homework (Simulation)
This program allows you to see how address translations are performed in a system with segmentation. See the README for details.
## Questions
1.First let’s use a tiny address space to translate some addresses. Here’s a simple set of parameters with a few different random seeds; can you translate the addresses?
```
segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 0
segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 1
segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 2
```
which tells the program to generate virtual addresses for a 128-byte address space placed somewhere in a 512-byte physical memory. both segmentation-0 and segmentation-1's limits are 20. with segmentation-0's base 0, segmentation-1's base 128.  


2.Now, let’s see if we understand this tiny address space we’ve constructed (using the parameters from the question above). What is the highest legal virtual address in segment 0? What about the lowest legal virtual address in segment 1? What are the lowest and highest illegal addresses in this entire address space? Finally, how would you run segmentation.py with the -A flag to test if you are right?  


the highest legal virtual address in segment-0 : 19

the lowest legal virtual address in segment-1 is :128 - 20 = 108

segmentation-0's physical address:0 - 19

segmentation-1's physical address:492 - 511

the lowest illegal physical address:20

the highest illegal phycical address:512

```
Virtual Address Trace
  VA  0: 0x00000013 (decimal:   19) --> VALID in SEG0: 0x00000013 (decimal:   19)
  VA  1: 0x0000006c (decimal:  108) --> VALID in SEG1: 0x000001ec (decimal:  492)
  VA  2: 0x00000014 (decimal:   20) --> SEGMENTATION VIOLATION (SEG0)
  VA  3: 0x0000006b (decimal:  107) --> SEGMENTATION VIOLATION (SEG1)
  ```

3.
