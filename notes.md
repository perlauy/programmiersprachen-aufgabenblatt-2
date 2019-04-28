# Notes
## Aufgabe 2.2
We need the *Include Guards* to prevent defining the same datentypes and objects multiple times (which throws an error when compiling). This may happen as different classes use the same dependencies and if we us them, each of those references would be included.

//TODO: why can't we define the same object more than once?


##Aufgabe 2.7
A struct is the construction used in C++ for Data-Transfer Objects. These are simple data structures, for which all member variables are public and no complex member functions are developed (maybe operators and relevant functions). They can have constructors, but it is not the rule.
