Data Structures CIA – II

Data Structures –
1. Van Emde Boas Tree
2. Treap

Roles – 
Project manager:
Madhu Shraya

Business Analyst:
Bharat Kameswaran

Developers:
Ashwin V
Madhu Shraya
Gaurav Mahesh
Manasvi
Niharika

Tester:
Mohammed Farhan K
 
Project Overview –

Introduction:
The project focuses on the implementation and analysis of two advanced data structures: the Van Emde Boas Tree and the Treap.
Both data structures are essential tools in computer science for efficient storage, retrieval, and manipulation of data.
Objective:
The primary objective of the project is to understand the principles, implementation, and performance characteristics of the Van Emde Boas Tree and Treap data structures.
Key goals include implementing the data structures, analyzing their time complexities, and evaluating their suitability for various applications.
Implementation:
The project includes complete implementations of both the Van Emde Boas Tree and Treap data structures, including all necessary functions and operations.
Each data structure is implemented in a C++.
Function Analysis:
Comprehensive analyses of the functions and operations within each data structure are conducted to determine their time complexities.
The time complexities of essential operations such as insertion, deletion, search, and traversal are thoroughly examined and documented. 
GitHub Repository:
A dedicated GitHub repository is created to host the project code, documentation, and related resources.
The repository contains organized directories for each data structure, including source code files, README.md files, and any additional documentation.  
Van Emde Boas Tree

Introduction –
“A van Emde Boas tree, also known as a vEB tree or van Emde Boas priority queue, is a tree data structure which implements an associative array with m-bit integer keys.” – Wikipedia
It is also called as “Van Emde Boas Priority Queue”, as it provides efficient implementations for many priority queue operations, such as finding the minimum or maximum element, inserting elements, and deleting elements. It's particularly useful when the universe of possible key values is known in advance and limited.
“It was formulated by Peter Van Emde Boas in 1975.” - www.sanfoundry.com

Supported functions –
1. Insert – Insert a value with an m-bit value
2. Delete – Remove the value with a given value
3. Search – Find the value associated with a given value
4. Successor – Find the value with the smallest value which is greater than a given value
5. Predecessor – Find the value with the smallest value which is smaller than a given value
6. Minimum – Return the smallest element stored in the tree
7. Maximum – Return the largest element stored in the tree

 
Algorithms –

Algorithm 1: Inserting a value.

Input: 
v1 – the van Emde Boas tree to insert to
value – the value to insert

	Output: 
The value successfully inserted to the vEB tree.

	Algorithm:
	1. if v1 is empty:
      		Create a new v1 with appropriate parameters.
2. if value already exists in v1:
      		Update the value associated with the value.
      		Exit the algorithm.
3. if v1 is a base case:
      		Update the value associated with the value.
      		Exit the algorithm.
4. cluster, offset = SplitValue(value)
5. if cluster not in v1.cluster_summary:
      		Insert(cluster, value) into v1.cluster_summary recursively.
6. Insert(offset, value) into v1.cluster[cluster] recursively.
7. if v1.min_value is None or value < v1.min_value:
      		Update v1.min_value to value.
8. if v1.max_value is None or value > v1.max_value:
      		Update v1.max_value to value.

	Time Complexity: O(log log N)

Algorithm 2: Deleting a value 

	Input:
	v1 – the van Emde Boas tree to insert to
	value – the value to delete

	Output:
	The value completely removed from the vEB tree

	Algorithm:
	1. if v1 is empty:
      		Exit the algorithm.
2. if value does not exist in v1:
      		Exit the algorithm.
3. if v1 is a base case:
      		Remove the value and its associated value from the base case.
     		 Exit the algorithm.
4. cluster, offset = SplitValue(value)
5. if cluster is not in v1.cluster_summary:
     		Exit the algorithm (value not found).
6. Delete(offset, v1.cluster[cluster]) recursively.
7. if v1.cluster[cluster] is empty:
      		Delete(cluster, v1.cluster_summary) recursively.
8. if value is equal to v1.min_value:
      		Find the successor of value in v1.
      		Update v1.min_value to the successor.
9. if value is equal to v1.max_value:
      		Find the predecessor of value in v1.
      		Update v1.max_value to the predecessor

	Time Complexity: O(log log N)

Algorithm 3: Finding the value associated with the given value

	Input:
v1 – the van Emde Boas tree to insert to
	value – the value to look for

	Output:
	return true, if the value was found
	return false, if the value was not found

	

Algorithm:
1. if v1 is empty:
     		 Return false.
2. if value is equal to v1.min_value or value is equal to v1.max_value:
      		Return true.
3. if v1 is a base case:
     		 If value exists in the base case, return true, otherwise return false.
4. cluster, offset = SplitValue(value)
5. if cluster is not in v1.cluster_summary:
      		Return false.
6. Lookup offset in v1.cluster[cluster] recursively.
7. Return the result of the lookup operation.

Time complexity: O(log log N)

Algorithm 4: Finding the next value.

	Input: 
v1 - the van Emde Boas tree to search
       	value - the value for which to find the next value

	Output:
return true, if the next value was found
	return false, if the next value was not found

	Algorithm:
1. if v1 is empty:
 	Return false.
2. if value is equal to v1.max_value:
Return false.
3. if v1 is a base case:
 	If the base case contains a value larger than 'value', return true, otherwise return false.
4. cluster, offset = SplitValue(value)
5. if cluster is not in v1.cluster_summary or offset < v1.cluster[cluster].max_value:
Find the successor of value in v1.cluster[cluster].
Return true.
6. Find the successor of cluster in v1.cluster_summary.
7. If no successor exists, return false.
8. Let next_cluster be the successor.
9. Let min_value_in_next_cluster be the minimum value in v1.cluster[next_cluster].
10. Return true.

Time Complexity: O(log log N)

 
Algorithm 5: Finding the previous value.

Input: 
v1 - the van Emde Boas tree to search
       	value - the value for which to find the next value

	Output:
return true, if the previous value was found
	return false, if the previous value was not found

	Algorithm:
1. if v1 is empty:
 	Return false.
2. if value is equal to v1.min_value:
Return false.
3. if v1 is a base case:
 	If the base case contains a value smaller than 'value', return true, otherwise return false.
4. cluster, offset = SplitValue(value)
5. if cluster is not in v1.cluster_summary or offset > v1.cluster[cluster].max_value:
Find the predecessor of value in v1.cluster[cluster].
Return true.
6. Find the predecessor of cluster in v1.cluster_summary.
7. If no predecessor exists, return false.
8. Let prev_cluster be the predecessor.
9. Let max_value_in_prev_cluster be the maximum value in v1.cluster[prev_cluster].
10. Return true.

Time Complexity: O(log log N)

Algorithm 6: Returning the smallest element stored in the tree

	Input:
	v1 - the van Emde Boas tree to search

	Output:
	return 0 if minimum element was not found
	return the minimum element itself if found

	Algorithm:
	1. if v1 is empty:
      		Return 0
2. if v1 is a base case:
      		Return the minimum value in the base case.
3. Let min_cluster be the minimum value in v1.cluster_summary.
4. Let min_offset_in_min_cluster be the minimum value in v1.cluster[min_cluster].
5. Return CombineValues(min_cluster, min_offset_in_min_cluster).

Time Complexity: O(1)
Algorithm 7: Returning the largest element stored in the tree

	Input:
	v1 - the van Emde Boas tree to search

	Output:
	return 0 if maximum element was not found
	return the maximum element itself if found

	Algorithm:
	1. if v1 is empty:
      		Return 0
2. if v1 is a base case:
      		Return the maximum value in the base case.
3. Let max_cluster be the maximum value in v1.cluster_summary.
4. Let max_offset_in_max_cluster be the maximum value in v1.cluster[max_cluster].
5. Return CombineValues(max_cluster, max_offset_in_max_cluster).

Time Complexity: O(1)
 
Advantages of Van Emde Boas Tree –
Some of the advantages of Van Emde Boas Tree are:

1. Its highly efficient operations: - 
vEB trees excel in performing crucial operations like finding minimum, maximum, predecessor, successor, inserting, and deleting elements.  They achieve a time complexity of O(log log N) for these operations, which is significantly faster than standard binary search trees (O(log N)).

2. Ordered Retrieval: -
vEB trees maintain order within the stored elements. This allows for efficient retrieval of elements based on their position.

3. Constant Time Minimum and Maximum Operations:
vEB trees explicitly store the minimum and maximum values within the data structure. This enables finding the minimum and maximum elements in constant time (O(1)), regardless of the tree size.

Limitations –
While offering high speeds, there are some limitations involved, viz.

1. Space Usage: -
Space usage of a vEB tree is given as follows:
S(2) = Θ(1)
 S(U) = (U1/2 + 1)S(U1/2) + Θ(U1/2)
The space complexity of the van Emde Boas (vEB) tree is Θ(U), where U represents the universe of possible values. 
Additional: In order to reduce the space complexity to Θ(N), one can use cuckoo hashing on every operation besides insert. However, this is an expensive solution and requires a bunch of hash tables.

2. Limited Data Type: -
vEB trees are designed specifically for storing and manipulating integers. They cannot handle other data types like strings or custom objects unless you implement additional conversion mechanisms.

Applications of Van Emde Boas Tree –
Some of the applications include,
1. Priority Queues – provides efficient implementations for many priority queue operations.
2. Cache-oblivious data structures - vEB layout optimizes cache utilization and improves performance for cache-oblivious data structures.
3. Computational geometry – vEB trees can help find objects within a specific rectangular query region due to its high-speed algorithms.
 
Treap

Introduction –
“A treap is a search tree data structure based on binary search trees (BST) and heaps.” – hawaii.edu
In a treap, each node has a key (which follows the binary search tree property) and a priority (which follows the heap property). The binary search tree property ensures that the keys are stored in a sorted order, while the heap property ensures that the priorities maintain a certain order, typically following a heap structure such as a max-heap or a min-heap.

Supported functions –
1.	Insert – Insert a node into the treap data structure
2.	Delete – Delete a node from the treap data structure
3.	Inorder – Traverse through the treap by in order traversal
4.	Preorder – Traverse through the treap by pre order traversal
5.	Postorder – Traverse through the treap by post order traversal
6.	Split – Splits the treap into two separate treaps: one containing all nodes with keys less than or equal to the given key, and the other containing all nodes with keys greater than the given key. 
7.	Merge –  Merges the current treap with another treap (treap2).
8.	RotationLeft – Rearrange the tree by moving the target node downwards and making the left child node the parent.
9.	RotationRight – Rearrange the tree by moving the target node downwards and making the right child node the parent.
 
Algorithms –

Algorithm 1: Inserting an element into the treap

	Input: Key and priority of the node to be inserted.

	Output: The updated treap after insertion

	Algorithm:
1.	Create a new node with the given key and priority.
2.	If the treap is empty, set the new node as the root of the treap and return.
3.	Let (x, y) be a pointer to the root of the treap, and let p be a pointer to the parent of x (initialize p as null).
4.	While x is not null, do the following:
Set p to x.
If the key to be inserted is less than x.key, set x to x.left.
If the key to be inserted is greater than x.key, set x to x.right.
If the key to be inserted is equal to x.key, handle as needed (e.g., update priority) and return.
5.	Set the new node's parent pointer to p.
6.	If the key to be inserted is less than p.key, set p.left to the new node; otherwise, set p.right to the new node.
7.	While the priority of the new node is greater than the priority of its parent (p):
If the new node is the root of the treap, set the new node as the new root and return.
If the new node is a left child of its parent (p):
Perform a right rotation on p.
If the new node is a right child of its parent (p):
Perform a left rotation on p.
8.	End
 
Time Complexity: O(log N)

Algorithm 2: Deleting an element from the treap

	Input: Key of the node to be deleted

	Output: The updated treap after deletion

	Algorithm:
1.	Let (x, y) be a pointer to the root of the treap, p be a pointer to the parent of x, and found be a boolean flag indicating if the node to be deleted is found (initialize p as null and found as false).
2.	While x is not null:
Set p to x.
If the key to be deleted is less than x.key, set x to x.left.
If the key to be deleted is greater than x.key, set x to x.right.
If the key to be deleted is equal to x.key, set found to true and break.
3.	If the node to be deleted is not found, return the treap unchanged.
4.	While x is not a leaf node:
If x has both a left and right child:
If the priority of x.left is greater than the priority of x.right, perform a right rotation on x.
Otherwise, perform a left rotation on x.
Otherwise, if x has only a left child, perform a right rotation on x.
Otherwise, if x has only a right child, perform a left rotation on x.
5.	Remove the leaf node x from the treap.
6.	If x is the root of the treap, set the root to null and return.
7.	Otherwise, if x is the left child of p, set p.left to null; otherwise, set p.right to null.
8.	End.
 
Time Complexity – O(log N)

Algorithm 3: Traversing the treap by in order

	Input: root of the treap.
	
	Output: A list of keys obtained from the inorder traversal.

	Algorithm:
1.	Initialize an empty list to store the keys obtained from the inorder traversal.
2.	Define a function InorderTraversal(node): 
If node is null, return. 
Recursively call InorderTraversal(node.left) to traverse the left subtree. 
Append the key of node to the list. 
Recursively call InorderTraversal(node.right) to traverse the right subtree.
3.	Call InorderTraversal(root) with the root of the treap.
4.	Return the list obtained from the inorder traversal.

Time Complexity: O(N)

Algorithm 4: Traversing the treap by preorder

	Input: root of the treap

	Output: A list of keys obtained from the preorder traversal

	Algorithm:
1.	Initialize an empty list to store the keys obtained from the preorder traversal.
2.	Define a function PreorderTraversal(node): 
If node is null, return. 
Append the key of node to the list. 
Recursively call PreorderTraversal(node.left) to traverse the left subtree. 
Recursively call PreorderTraversal(node.right) to traverse the right subtree.
3.	Call PreorderTraversal(root) with the root of the treap.
4.	Return the list obtained from the preorder traversal.

Time Complexity: O(N)

Algorithm 5: Traversing the treap by postorder

	Input: root of the treap

	Output: A list of keys obtained from the postorder traversal

	Algorithm:
1.	Initialize an empty list to store the keys obtained from the postorder traversal.
2.	Define a function PostorderTraversal(node):
If node is null, return.
Recursively call PostorderTraversal(node.left) to traverse the left subtree.
Recursively call PostorderTraversal(node.right) to traverse the right subtree.
Append the key of node to the list.
3.	Call PostorderTraversal(root) with the root of the treap.
4.	Return the list obtained from the postorder traversal.

Time Complexity: O(N)

Algorithm 6: Splitting the treap into two treaps

	Input: root of the original treap and a key for splitting.

Output: roots of two separate treaps: one containing all nodes with keys less than or equal to the given key, and the other containing all nodes with keys greater than the given key.

Algorithm:
1.	If root is null, return two null pointers (no nodes to split). 
2.	If the key of root is less than or equal to the given key:
Recursively call SplitTreap(root.right, key) to split the right subtree of root.
Set root.right to the second output of the recursive call.
Return root and the first output of the recursive call. c. If the key of root is greater than the given key:
Recursively call SplitTreap(root.left, key) to split the left subtree of root.
Set root.left to the first output of the recursive call.
Return the second output of the recursive call and root.
 
	Time Complexity: O(log N)

Algorithm 7: Merging two treaps with one another

	Input: roots of two separate treaps.

	Output: root of the merged treap.

	Algorithm:
1.	If either root1 or root2 is null, return the other root (no merging needed).
2.	If the priority of root1 is greater than the priority of root2:
Set root1.right to the result of MergeTreaps(root1.right, root2).
Return root1.
3.	Otherwise (the priority of root2 is greater than or equal to the priority of root1):
Set root2.left to the result of MergeTreaps(root1, root2.left).
Return root2.

	Time Complexity: O(log N)

Algorithm 8: Rotating the treap to the left

	Input: node to be rotated.

	Output: new root of the subtree after rotation.

	
Algorithm:
1.	If node is null or node.right is null (no right child), return node.
2.	Let newRoot be node.right.
3.	Set node.right to newRoot.left.
4.	Set newRoot.left to node.
5.	Return newRoot.

Time Complexity: O(1)

Algorithm 9: Rotating the treap to the right

	Input: Node to be rotated

	Output: new root of the subtree after rotation

	Algorithm:
1.	If node is null or node.left is null (no left child), return node.
2.	Let newRoot be node.left.
3.	Set node.left to newRoot.right.
4.	Set newRoot.right to node.
5.	Return newRoot.

Time Complexity: O(1)
 
Advantages of Treap –
1.	Provides a hierarchical way of storing data
2.	Reflects structural relationship in a data set
3.	Allows insertion, deletion and searching operations that yield results faster than an array or linked list
4.	Provides a flexible way to hold and move data
5.	Allows storage of many nodes

Limitations of Treap –
1.	All these operations take worst case time O(H), where H is the height of the treap.
2.	However, treaps (like BST’s) can become very unbalanced, so that H = O(N), and that’s bad.

Applications of Treap –
Some of the applications include,
1.	Databases and Indexing:
Treaps can be used in databases and indexing systems to efficiently store and retrieve data based on keys or priorities.
2.  Wireless Communication Networks: 
Treaps can be applied in wireless communication networks for scheduling and prioritizing data transmission. Nodes in the network can be represented as treap nodes, where the priorities represent the importance or urgency of transmitting data packets.
3. Operating Systems: 
Treaps can be utilized in operating systems for various purposes, such as process scheduling and memory management. In process scheduling, treaps can help prioritize processes based on their importance or resource requirements.
 
4. Online Gaming: 
Treaps can be applied in online gaming systems for managing player rankings and leaderboards. Each player's ranking can be represented as a node in a treap, where the priorities represent the player's score or ranking.


Conclusion:
The exploration of the Treap and Van Emde Boas tree data structures has provided valuable insights into advanced techniques for efficient data organization and manipulation.
The Treap, with its ingenious combination of binary search tree properties and heap priorities, offers a versatile solution for priority-based operations and balanced storage. Its randomized structure ensures optimal performance in various applications, including priority queues, databases, and optimization algorithms.
The Van Emde Boas tree, with its hierarchical structure and specialized operations, provides an elegant solution for managing large dynamic sets with integer keys. Its efficient support for predecessor and successor queries, along with its space-efficient representation, makes it suitable for applications requiring fast search and retrieval operations.
 
Bibliography –

Van Emde Boas Tree:

Sites referred –
TISparta, José Leonidas García Gonzales. “Van-Emde-Boas-Tree/Src/Vebtree.Cpp at Master · Tisparta/Van-Emde-Boas-Tree.” GitHub, 2019, github.com/TISparta/Van-Emde-Boas-tree/blob/master/src/vEBTree.cpp. 
Panchal, Aakash. “Van Emde Boas Tree: Set 1: Basics and Construction.” GeeksforGeeks, GeeksforGeeks, 4 Dec. 2023, www.geeksforgeeks.org/van-emde-boas-tree-set-1-basics-and-construction/. 
Tal, Mika. “Van Emde Boas Trees.” Medium, Medium, 5 Sept. 2022, medium.com/@mikatal/van-emde-boas-trees-3e3c228cebc7. 
“Van Emde Boas Tree.” Wikipedia, Wikimedia Foundation, 24 Feb. 2024, en.wikipedia.org/wiki/Van_Emde_Boas_tree. 
Van Emde Boas Trees, web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/14/Slides14.pdf. Accessed 28 Apr. 2024. 
“Van Emde Boas Tree Questions and Answers.” Sanfoundry, 1 Feb. 2022, www.sanfoundry.com/van-emde-boas-tree-multiple-choice-questions-answers-mcqs/#:~:text=d)%20Non%20–%20Binary-,Explanation%3A%20The%20Van%20Emde%20Boas%20Tree%20data%20structure%20is%20also,non%20–%20binary%20type%20of%20tree. 

Blogs referred –
Templatetypedef. “Applications of van Emde Boas Trees?” Stackoverflow, 4 Feb. 2012, https://stackoverflow.com/questions/8545851/applications-of-van-emde-boas-trees. Accessed 28 Apr. 2024. 
Ménétrier, Jérémy. “How Is a van Emde Boas Tree Used in Practice?” Quora, 2011, https://www.quora.com/How-is-a-van-Emde-Boas-tree-used-in-practice. Accessed 28 Apr. 2024.  
Video referred –
MIT OpenCourseWare. “4. Divide & Conquer: Van Emde Boas Trees.” YouTube, YouTube, 4 Mar. 2016, www.youtube.com/watch?v=hmReJCupbNU&t=1s. 

AI prompts used –
“What is the van emde boas tree?” prompt. ChatGPT 3.5, OpenAI, 28 April 2024, https://chat.openai.com/chat

“Name me a few advantages of van emde boas tree” prompt. Gemini, Google, 28 April 2024,
https://gemini.google.com/app/chat

“Give me some real time applications of vEB tree” prompt. Gemini, Google, 28 April 2024,
https://gemini.google.com/app/chat

Treap:

Sites referred –
“Lecture 7: Randomized Search Trees 1 Treaps.” Hawaii.Edu, www2.hawaii.edu/~nodari/teaching/f19/scribes/notes07.pdf. Accessed 28 Apr. 2024. 
Singh, Ramandeep. “Treap.” Scaler Topics, Scaler Topics, 13 Apr. 2022, www.scaler.com/topics/data-structures/treap/. 
“Treap (a Randomized Binary Search Tree).” GeeksforGeeks, GeeksforGeeks, 15 Dec. 2022, www.geeksforgeeks.org/treap-a-randomized-binary-search-tree/. 
Indeed Editorial Team. “What Is the Tree Data Structure? (With Advantages and Types) | Indeed.Com India.” Indeed, 3 Feb. 2023, in.indeed.com/career-advice/finding-a-job/what-is-tree-data-structure. 
Disadvantages of Treaps, seweb.ucsd.edu/~kube/cls/100/Lectures/lec5/lec5-20.html. Accessed 28 Apr. 2024. 
 
Video referred – 
Professor Painter. “Binary Search Trees 9 - Left and Right Rotations.” YouTube, YouTube, 4 Feb. 2021, www.youtube.com/watch?v=dCF_d-zc_bQ&t=253s. 

AI prompts used –
“What is a treap” prompt. ChatGPT 3.5, OpenAI, 28 April 2024,
https://chat.openai.com/chat

“Give me some real life applications of treaps” prompt. ChatGPT 3.5, OpenAI, 28 April 2024,
https://chat.openai.com/chat



