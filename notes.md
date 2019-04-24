# Notes
## Aufgabe 2.2
We need the *Include Guards* to prevent defining the same datentypes and objects multiple times (which throws an error when compiling). This may happen as different classes use the same dependencies and if we us them, each of those references would be included.

//TODO: why can't we define the same object more than once?
