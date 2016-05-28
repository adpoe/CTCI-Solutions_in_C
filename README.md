# Cracking the Coding Interview
## Solutions Written in C

### Why would anyone do this
- Good practice
- Have not yet found a full solution in set in C, so hopefully this helps someone else too

### Notes
- Work in progress, but doing it as time arises
- Currently looking for a reliable set of data structures to use. Was rolling my own for awhile, but that started turning into a separate project. And while very interesting, it was too time consuming for now.
- Ideally would like to build my own library of C structures for the future, but that's a longterm thing, so I'm open to other options until then.
- Decided to try using Zed Shaw's Debug Macros to make debugging simpler (hopefully...)
    * These are online at: http://c.learncodethehardway.org/book/ex20.html
- Also reading through this for tips, and trying out some of the data structures
    * http://www.cs.yale.edu/homes/aspnes/classes/223/notes.pdf

## Implementation Citations
- Using a HashTable written by @tonius on Github
    * found at: https://gist.github.com/tonious/1377667
- Using a LinkedList written by Steven Skiena from the Algorithm Design Manual: http://www.amazon.com/Algorithm-Design-Manual-Steven-Skiena/dp/1848000693/ref=sr_1_1?ie=UTF8&qid=1464411809&sr=8-1&keywords=algorithm+design+manual

## Things I Learned the Hard Way
- You're not too good to use DDD... early and often. (Even though it's not as hardcore as GDB.)
- Printf really is the best debugger in C sometimes. Don't be stubborn.
- Don't try making generalized data structures with void\* data types until you're ready. Ready meaning: You've already got the structure working for a specific type, and you've tested it, and there are no errors. Otherwise you will drive yourself crazy, because you can't even debug the void pointers in DDD. It just says you're referencing a pointer with an unknown type and doesn't give you any info about the value.


