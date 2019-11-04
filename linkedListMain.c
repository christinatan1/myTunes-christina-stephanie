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

  //testing insert_order
  printf("\nInserting nodes in order:\n");
  linkedList = insert_order(linkedList, "exchange", "bryson tiller");
  linkedList = insert_order(linkedList, "don't", "bryson tiller");
  linkedList = insert_order(linkedList, "on the road", "post malone");
  linkedList = insert_order(linkedList, "enemies", "post malone");
  linkedList = insert_order(linkedList, "allergic", "post malone");
  print_list(linkedList);

  //testing find_song
  printf("\nFinding node:\n");
  struct song_node *song1 = findSong(linkedList, "lauv", "feelings");
  struct song_node *song2 = findSong(linkedList, "bts", "boy in luv");
  struct song_node *song3 = findSong(linkedList, "bryson tiller", "exchange");
  struct song_node *song4 = findSong(linkedList, "bryson tiller", "don't");

  findSong(linkedList, "bts", "dna");

  //testing songcmp
  printf("\nComparing songs:\n");
  print_node(song1);
  print_node(song1);
  printf("%d\n", songcmp(song1, song1));
  print_node(song1);
  print_node(song2);
  printf("%d\n", songcmp(song1, song2));
  print_node(song3);
  print_node(song4);
  printf("%d\n", songcmp(song3, song4));

  //testing find_first
  printf("\nFinding first songs by artist:\n");
  findFirst(linkedList, "bryson tiller");
  findFirst(linkedList, "post malone");

  //testing random song
  printf("\nTesting random:\n");
  srand(time(0));
  randomElement(linkedList);
  randomElement(linkedList);
  randomElement(linkedList);

  //testing remove_node
  printf("\nRemoving songs:\n");
  printf("remove post malone: allergic\n");
  remove_node(linkedList, "post malone", "allergic");
  printf("remove lauv: feelings\n");
  remove_node(linkedList, "lauv", "feelings");
  print_list(linkedList);

  //testing free_list
  linkedList = free_list(linkedList);
  printf("\nFreeing list...\n");
  print_list(linkedList);
}
