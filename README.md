Comgraph
========

Computes the independent nodes of an acyclic directed graph by depth.

Usage
--------

_compgraph.exe \<INPUTFILE\> \<OUTPUTFILE\>_

Input format
-------------

First line is the number of nodes in the graph. Next give the adjacency lists of the nodes line by line with node IDs starting from 0. If a node doesn'h have any adjacent nodes enter an empty line.

Output format
---------------

The independent nodes by depth.

Example
---------

**Graph**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\  
&nbsp;&nbsp;&nbsp;&nbsp;1&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6  
&nbsp;&nbsp;&nbsp;/&nbsp;\\&nbsp;&nbsp;&nbsp;/&nbsp;\\  
&nbsp;&nbsp;2&nbsp;&nbsp;&nbsp;3&nbsp;7&nbsp;&nbsp;&nbsp;8  
&nbsp;&nbsp;&nbsp;\\&nbsp;/&nbsp;&nbsp;&nbsp;\\&nbsp;/  
&nbsp;&nbsp;&nbsp;&nbsp;4&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;9  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\&nbsp;&nbsp;&nbsp;/  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\&nbsp;/  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;5  

**Input file**

10  
6  
2 3  
4  
4  
5  
  
7 8  
9  
9  
5  

**Output file**

0: 0 1  
1: 6 2 3  
2: 7 8 4  
3: 9  
4: 5  
