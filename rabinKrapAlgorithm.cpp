#include<iostream>
#include<vector>
using namespace std;

#define d 256 

void search(char pat[], char txt[], int q) {

}
int main(){
     char txt[] = "GEEKS FOR GEEKS"; 
    char pat[] = "GEEK";
        
      //we mod to avoid overflowing of value but we should take as big q as possible to avoid the collison
    int q =INT_MAX; 
      
      // Function Call
      search(pat, txt, q); 
    return 0; 
}