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
  linkedList = insert_front(linkedList, "feel special", "twice");
  linkedList = insert_front(linkedList, "lose you to love me", "selena gomez");
  linkedList = insert_front(linkedList, "feelings", "lauv");
  linkedList = insert_front(linkedList, "liar", "camila cabello");
  linkedList = insert_front(linkedList, "boy with luv", "bts");
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
  struct song_node *song1 = find_song(linkedList, "lauv", "feelings");
  struct song_node *song2 = find_song(linkedList, "bts", "boy with luv");
  struct song_node *song3 = find_song(linkedList, "bryson tiller", "don't");
  struct song_node *song4 = find_song(linkedList, "bryson tiller", "exchange");

  find_song(linkedList, "bts", "dna");

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
  find_first(linkedList, "bryson tiller");
  find_first(linkedList, "post malone");

  //testing random song
  printf("\nTesting random:\n");
  srand(time(0));
  random_element(linkedList);
  random_element(linkedList);
  random_element(linkedList);

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



  printf("\n\n\n******************* SONG LIBRARY TESTS *******************\n");

  struct song_node *table[27] = {};
      
  //testing add_song
  printf("\nAdding song:\n");
  add_song(table, "blackbear", "do re mi");
  add_song(table, "sia", "chandelier");
  add_song(table, "sia", "elastic heart");
  add_song(table, "kiiara", "gold");
  add_song(table, "rihanna", "needed me");

  //testing print_letter
  printf("\nSearching under letters:\n");
  print_letter(table, 's');

  //testing search_song
  printf("\nSearching for songs:\n");
  search_song(table, "sia", "big girls cry");
  search_song(table, "sia", "elastic heart");
  
  //testing print_library
  printf("\nPrinting full library:\n");
  print_library(table);

  //testing delete_song
  printf("\nTesting remove song:\n");
  delete_song(table, "sia", "chandelier");
  print_library(table);
  delete_song(table, "kiiara", "gold");
  print_library(table);

  //testing clear_library
  printf("\nClearing library:\n");
  table = clear_library(table);
  print_library(table);

}
