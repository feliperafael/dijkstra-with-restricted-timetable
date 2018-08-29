# dijkstra-with-restricted-timetable

This repository aims to present the modified Dijkstra algorithm to find the smallest path between two nodes of a graph, respecting the constraint of timetable

The Dijkstra algorithm, designed to solve the problem of the shortest path in a directed or non-directed graph with non-negative weight edges, at computational time *O ([m + n] log n)* where m is the number of edges n is the number of vertices

# Input file
the input file must be placed inside input folder. The input file must be mounted as follows:

- in the first line the number of nodes must be reported;
- in the second row the number of edges;
- the third line should inform the source node;
- the fourth line must inform the destination node;
- in the fifth line, the departure time must be informed;
- from the sixth line, the time window constraints of each node must be reported. If no there are restrictions, put *0000 0000*;
- Finally, we must inform the vertices and their weights in the form: source node, a space, node of destination, a space, and weight.

Here is an example of an input file, which can be found in *input/example_input_file.dat*

    
	6
    8
    1
    6
    0730
    1 0800 1230
    2 0700 1400
    3 1400 2100
    4 0800 1000
    5 0000 0000
    6 0700 1900
    1 2 5
    1 3 15
    2 4 5
    2 5 5
    3 4 5
    3 5 5
    4 6 15
    5 6 5
