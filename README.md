# bitRank
optional usage of storage ( for AVR's or Arduino )

Almost all Arduino boards like UNO, micro, nano etc, provided not enough RAM therefore you cannot write big project. This lib is written to a litle bit change this situation, and it at least give opportunity for writing regarding big cellular automata or just reduce memory using due storing 8 bool in one byte. 

Here is simple instance of usage:

```c++
bitrank test(133); //creating bitrank object with 133 bites 
test.setBitOn(9, true); //changing bit at 9 index to true value
cout << test[9] << endl; //chek it

```

