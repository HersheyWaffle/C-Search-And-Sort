<h1>Description</h1>
This was a simple exercise using C for my Principles of Programming Languages class (COMP 348), in which I was to build an application which reads and processes a text file into an array of strings, then searches for particular words according to the paramters, sorts the result and displays the output in the command prompt.

<h1>How to use</h1>
I did not include the output files, so the project needs to be compiled on the user's end before being used. After doing so, assuming the app compiled is named <i>ssort.exe</i> the basic command line structure is as follows:
<br><br>
<i>ssort.exe inputfile n wtype sorttype skipword skipword skipword ...</i>
<br><br>
<i>inputfile</i>: REQUIRED. The text file which contains the words to read
<br>
<i>n</i>: REQUIRED. The number of words to read.
<br>
<i>wtype</i>: REQUIRED. The type of words to look for. Accepts 3 types: ALPHA for strictly letter-based words, ALPHANUM for words with letters and numbers and ALL for all characters except commas and whitespaces
<br>
<i>sorttype</i>: OPTIONAL. How the words are sorted. ASC for ascending order and DESC for descending order. If omitted, the default is ascending order.
<br>
<i>skipword</i>: OPTIONAL. Every parameter after sorttype is a blacklisted word that will be ignored.
<br><br>
For example ssort.exe input.txt 15 ALPHA wordA wordB wordC wordD wordE will read input.txt and print the first 15 words with only letters in them in ascending order while ignoring wordA, wordB, wordC, wordD and wordE.
