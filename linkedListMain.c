#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedListHeader.h"


int main(){

  printf("******************* LINKED LIST TESTS *******************\n");

  struct song_node *linkedList;
  linkedList = NULL;

  //testing print_list
  printf("Testing print_list: \n");
  print_list(linkedList);

  //testing insert_front
  printf("\nInserting nodes:\n");
  linkedList = insert_front(linkedList, "feelings", "lauv");
  linkedList = insert_front(linkedList, "boy with luv", "bts");
  linkedList = insert_front(linkedList, "lose you to love me", "selena gomez");
  linkedList = insert_front(linkedList, "feel special", "twice");
  linkedList = insert_front(linkedList, "liar", "camila cabello");
  print_list(linkedList);

  //testing find_song
  printf("\nFinding node:\n");
  findSong(linkedList, "bts", "boy with luv");
  findSong(linkedList, "dna", "dna");

  //testing random song
  printf("\nTesting random:\n");
  srand(time(0));
  randomElement(linkedList);
  randomElement(linkedList);
  randomElement(linkedList);

  //testing free_list
  linkedList = free_list(linkedList);
  printf("\nFreeing list...\n");
  print_list(linkedList);
}
