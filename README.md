# Cracking the Coding Interview
## Solutions Written in C

### Why would anyone do this
- Good practice
- Have not yet found a full solution in set in C, so hopefully this helps someone else too

### Notes
- Work in progress
- Currently looking for a reliable set of data structures to use. Was rolling my own for awhile, but that started turning into a separate project. And while very interesting, I don't have time available time for it presently.
- Right now considering Collections C, from **srdja**: https://github.com/srdja/Collections-C/tree/master/src
    * These have what look like a solid API documentation at: http://blog.srdja.me/Collections-C/#introduction
- Open to suggestions if anyone has any
- Also decided to try using Zed Shaw's Debug Macros to make debugging simpler (hopefully...)
    * These are online at: http://c.learncodethehardway.org/book/ex20.html

## Thoughts, Questions, and Stuff I've Learned
- GDB isn't a bad debugger (when I was first forced to use it for class, I really disliked it). What makes it bearable: using the -tui option will give you a really simple GUI.
    * Why doesn't anybody tell you this up front?
- DDD is awesome for visualizing data structures, but wish there was an easier way to work on the code directly, and compile, even within the DDD window, like a true IDE. People complain about the 90s-looking interface, but I kind of like. Maybe just nostalgia.
    * Problem:  DDD doesn't seem applicable for all systems, while GDB does.
- CLion is a great C IDE. But using it feels a bit like cheating, mostly because it doesn't seem practical for a real world environment.
- Is Emacs really that much better than vim for C programming?
- I'm considering using the LLVM system, but one step at a time.
- Using void * pointers to allow for generic types is a great idea in theory, but a serious pain in practice. Though, I probably just need more practice.
- Complex data structures that have arrays should be defined as "type_name\*\*;"  in the header file. Not "type_name \*var_name[SIZE]", because these statically sized arrays can't be malloc'd later
- DON'T try to build your own data structures in C, unless it's absolutely necessary. Or that data structure library is the main project. That way lies madness, as the project will grow uncontrollably...
    * I guess what I'm saying is always focus on the task at hand, and solve the problem you're given, not 10 other problems that are tangentially related because they seem cool. This is always hard to re-learn, even though I know it intuitively.
- Writing C is painful. Or maybe Python has just made me soft.

