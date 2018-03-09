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

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\  
&nbsp;&nbsp;&nbsp;&nbsp;b&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;g  
&nbsp;&nbsp;&nbsp;/&nbsp;\\&nbsp;&nbsp;&nbsp;/&nbsp;\\  
&nbsp;&nbsp;c&nbsp;&nbsp;&nbsp;d&nbsp;h&nbsp;&nbsp;&nbsp;i  
&nbsp;&nbsp;&nbsp;\\&nbsp;/&nbsp;&nbsp;&nbsp;\\&nbsp;/  
&nbsp;&nbsp;&nbsp;&nbsp;e&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\&nbsp;&nbsp;&nbsp;/  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\&nbsp;/  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;f  

**Input file**

10  
1  
2 3  
4  
4  
5  
  
7 8  
9  
9  
5  

**Output file**

0: 0 6  
1: 1 7 8  
2: 2 3 9  
3: 4  
4: 5  
