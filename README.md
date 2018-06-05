<h1>Homework order</h1>
Bob has many projects to do as a part of his studies so he has to prepare a schedule. Since there is a possibility that he may be unable to complete all the projects by their respective deadlines, he has to make sure that the most important ones are completed. The priority of projects may be subject to change over time.</br> 
Projects may be divided in the groups. Bob may be interested in finding the project with a highest priority from a given group. The groups may be merged. Help Bob schedule his homework - implement the following operations:</br>
<ul><li>a group value - Add element with value to the group</li>
<li>e group - Extract element with maximum value from the group and print it's value</li>
<li>p group - Print values of all elements in the group according to their decreasing</li>
<li>m group1 group2 - Merge groups 1 and 2. Group 1 should contain all elements. Group two should become empty</li>
<li>i group oldValue newValue - increase value of element in group from oldValue to newValue</li></ul>
If operation is illegal (extraction from empty group, increasing priority of element thay does not belong to the specified group), the output should be "na" 
<h3>Input</h3>
Input will have the following form: n</br>
operation</br>
operation...,</br>
</br>
where n is the number of operations. There are at most 1000 groups. There are at most 200000 elements in a group
<h3>Output</h3>
<h4>Example</h4>
<h5>Input</h5>
10</br>
a 1 2</br>
a 1 3</br>
e 1</br>
a 2 4</br>
m 1 2</br>
e 2</br>
e 1</br>
i 1 2 5</br>
e 1</br>
e 1</br>
<h5>Output</h5>
3</br>
na</br>
4</br>
5</br>
na</br>
