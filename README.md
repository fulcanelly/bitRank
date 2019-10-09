# bitRank

Almost all Arduino boards like UNO, micro, nano etc, provide not enough RAM, therefore you cannot write big project. This lib is written to a little bit change this situation, and at least give opportunity for writing relatively big cellular automata or just reduce memory using due to storing 8 bool in one byte. Also, it might be used to storing monochrome images.

Here is simple instance of usage:

```c++
bitrank test(133); //creating bitrank object with 133 bites 
test.setBitOn(9, true); //changing bit at 9 index to true value
cout << test[9] << endl; //chek it

```

In the future I want to extending this project and add new futures. If you intersting you can support me and join our [chat]( https://t.me/fulcanellydev) in telegram.

PS: sorry for mistakes.
