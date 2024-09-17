/*
 pointers.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";
char list1[80];
char list2[80];
int counter = 0;

void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void work(){
  const char *ptr_text;
  char *ptr_list;
  int *ptr_counter = counter;

  ptr_text = text1;
  ptr_list = list1;

  copycodes(ptr_text, ptr_list,ptr_counter);

  ptr_text = text2;
  ptr_list = list2;
  copycodes(ptr_text,ptr_list,ptr_counter);
}

void copycodes(char *pointer_txt, char *pointer_list, int *pointer_count){
  while (pointer_txt != 0){
    pointer_txt = (int*) pointer_list;

    pointer_txt++;
    pointer_list + 4;

    pointer_count++;

  }
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n", 
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));
  
}

int main(void){
 
    work();
    printf("\nlist1: ");
    printlist(list1);
    printf("\nlist2: ");
    printlist(list2);
    printf("\nCount = %d\n", counter);

    endian_proof((char*) &counter);
}
