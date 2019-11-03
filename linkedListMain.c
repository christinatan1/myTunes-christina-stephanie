#include <stdio.h>
#include <stdlib.h>
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
  linkedList = insert_front(linkedList, "boy in luv", "bts");
  print_list(linkedList);

  //testing find_song
  printf("\nFinding node:\n");
  findSong(linkedList, "bts", "boy in luv");
  findSong(linkedList, "bts", "dna");

  //testing random song
  randomElement(linkedList);
  randomElement(linkedList);
  randomElement(linkedList);

  //testing free_list
  linkedList = free_list(linkedList);
  printf("\nFreeing list...\n");
  print_list(linkedList);
}
