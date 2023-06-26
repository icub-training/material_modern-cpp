# Move semantics exercise

In the provided code `exerciseMoveSem.cpp` you can find the definition of a copiable class.

1. Make BigObject a movable class also
2. Overload ContainerOfObject::addObject function for temporaries.
3. compile and run the code. ` g++ -std=c++11 exerciseMoveSem.cpp -o exeMoveSem` `./exeMoveSem`
4. check if RVO has been applied. What is RVO??
5. the program should crash! Why? fix it please!
6. create obj3 and obj4 from a temporary BigObject. Here are possible 2 solutions? Can you find both?? see `#warning question 6:`
7. add 10 BigObject to the container in order to avoid copies. `#warning question 7:`