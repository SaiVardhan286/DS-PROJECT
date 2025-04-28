Densest Subgraph Discovery Project
==================================

Group Members:
- E THIRUMALA SAI VARDHAN
- B ROHITH SRINIVAS
- K HARI HARA PRASAD GOUD

---------------------------------------------------------------------
1. Project Overview
---------------------------------------------------------------------
This project implements two algorithms for the Densest Subgraph
Discovery (DSD) problem on undirected graphs:

 • Algorithm-1 (Exact): a binary-search + maximum-flow method  
   (Edmonds-Karp) to find the true densest subgraph by edge-density.
 • Algorithm-4 (CoreExact): an optimized exact method that prunes
   the search space via k-core decomposition, then applies max flow.

All code is written in standard C++11, uses STL containers, and
compiles under `g++` on Linux/Windows.

---------------------------------------------------------------------
2. Datasets Used
---------------------------------------------------------------------
We evaluated our algorithms on two canonical small social networks
from the **Network Repository**:

1. **Zachary’s Karate Club**  
   – URL: https://networkrepository.com/karate.php  
   – 34 nodes, 78 edges.


 Dataset is publicly available and widely used for graph-mining experiments.

---------------------------------------------------------------------
3. Sample Input File
---------------------------------------------------------------------
We have provided a sample `input.txt` representing the Zachary Karate
Club graph, hosted here:

  

Format of `input.txt`:

First line: `n m` (number of vertices and edges).  
Each subsequent line: one undirected edge `u v` (0-indexed).

---------------------------------------------------------------------
4. Compilation & Running
---------------------------------------------------------------------
From the project root directory, run:

```bash
make
This produces an executable named main.

To run with the sample input:

./main < input.txt


