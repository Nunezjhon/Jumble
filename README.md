<h4>Created by: Jhon Nunez </h4>
<h3>University of Illinois at Chicago </h3>

<h3>To run this program:</h3>

 1. make jumble.cpp dictionary-small 
 2. run ./jumble
 3. you can also make jumble.cpp using dictionary-big

<h3>SUMMARY </h3>

In this project you will use a clever application of hash tables to 
solve "word jumble" puzzles.  You have probably seen these puzzles 
in the newspaper.  
  

After the program sets up its internal data structures, it enters an simple interactive loop which behaves as follows:

I.	The user does one of the following:
	A.	enter a string of characters (presumably a jumbled version of one or more English words).
	B.	or types ctrl-d to terminate the interactive loop.

II.	If the user enters a string (1a above), a list of all English words in the given dictionary that are rearrangements 
	(anagrams) of the user input.  The list can appear in any order.  If there are no such English words, 
	the program reports “no matches.”  The user is then prompted for another input.

III.	When the user terminates the interactive loop (1b above), the program produces a report with 
	the following information and then the program terminates:
	
	The number of words read from the input file.
	
	The number of "equivalence-classes":  every word in the input file belongs to exactly 
	one subset of the dictionary where all words in the subset are rearrangements of each other.  
	For instance, "stake", "skate", "steak", "takes" all belong to the same equivalence class.  
	This part of the report gives the number equivalence classes formed by the words in the dictionary.

	The size of the largest equivalence class.
	The "key" associated with the largest equivalence class (see the Algorithm section).
	Finally, the members of the largest equivalence class.  The ordering of the members can be arbitrary as long as all members are listed.
