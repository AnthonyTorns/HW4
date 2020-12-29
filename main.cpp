#include<iostream>
#include "recursive.h"
#include "hw4.h"


bool ListEqual (list_t l1, list_t l2) {
    // EFFECTS: returns true of l1 and l2 are equal, false otherwise
    // If either are empty, both must be empty for equality
    if (list_isEmpty(l1) || list_isEmpty(l2)) {
	return (list_isEmpty(l1) && list_isEmpty(l2));
    }

    if (list_first(l1) != list_first(l2)) {
	return false;
    } else {
	return ListEqual(list_rest(l1), list_rest(l2));
    }
}

bool notByFour(int i) {
    return (i%4);
}
int add(int x, int y ) {
    x =2; 
    x =4;
    return x + y;
}

int main() {
    list_t original = list_make();
    list_t rotated = list_make();
    list_t testlist;

    const int largest = 7;
    const int steps = 4+largest;

    bool answer = true;

    for (int i = largest-1; i>=0; i--) {
      original = list_make(i, original);
      rotated = list_make((i+steps)%largest, rotated);
    }
    std::cout << "Sum: "<<sum(original) << std::endl;
    std::cout << "Product: "<<product(original) << std::endl;
    std::cout<<"Reverse: ";
    list_print(reverse(original));
    std::cout<<std::endl;
    std::cout<<"Even Filter: ";
    list_print(filter_even(original));
    std::cout<<std::endl;
    std::cout<<"Odd Filter: ";
    list_print(filter_odd(original));
    std::cout<<std::endl<<"Chop: ";
    list_print(chop(original, 1));
    std::cout<<std::endl<<"Insert List: ";
    list_print(insert_list(original, rotated, 2));
    std::cout<<std::endl<<"Rotated: ";
    list_print(rotate(original, 3));
    std::cout<<std::endl<<"Append: ";
    list_print(append(original, rotated));
    std::cout<<std::endl<<"Filter: ";
    list_print(filter(original, *notByFour));
    std::cout<<std::endl<<"Accumulate: ";
    std::cout<<accumulate(original, add, 0)<<std::endl;
    std::cout<<"Fibonacci: "<<fib(7)<<std::endl;
    std::cout<<"Fibonacci Tail: "<<fib_tail(6)<<std::endl;
    
    testlist = rotate(original, steps);
    bool results  = ListEqual(testlist, rotated);

  list_print(rotated);
  list_print(testlist);



}