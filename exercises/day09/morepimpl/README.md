In here are some more advanced topics about the PIMPL idiom.

We shall see:
- code from item 22 of `Effective Modern C++` by Scott Mayers
- code from Herb Sutter's `Compilation Firewalls, Part 2` (https://herbsutter.com/gotw/_101/) 


For the singleton:
- https://www.modernescpp.com/index.php/creational-patterns-singleton


We can use PIMPL for a simple class or for a singleton.

### Use of PIMPL in a simple class

In modern C++ important authors suggest to use the unique_ptr<> in the PIMPL idiom.

In particular, Scott Meyers in his book `Effective Modern C++` in item 22 suggested something such as in
the exercises.

### Use of PIMPL in a singleton

Mixing up Scott Meyers' C++98 book `More Effective C++` (item 26) and `Effective Modern C++` (item 22) we have a singleton w/ unique pointers, non copiable nor moveable, that can be used in multithread environment. 

See exercises.


