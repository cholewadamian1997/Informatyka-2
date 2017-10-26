#include "Date.hpp"


int main(){

   Date date1(25,3,2012);
   cout << "date1: " << date1 << endl;

   Date date2 = date1 + 367;
   cout << "date2: " << date2 << endl;


   int difference = date2 - date1;
   cout << "date2 - date1: " << difference << endl;

   if(date1 == date2) {cout << "date1 = date2" << endl;}
   else cout << "date1 != date2" << endl;

   int days = 4382;
   date1 -= days;
   cout << "date " << days <<" before date1: " << date1 << endl;


return 0;
}
