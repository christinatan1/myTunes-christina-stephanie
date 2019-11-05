#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "linkedListHeader.h"
#include "arrayLibraryHeader.h"

void add_song(struct song_node **library, char *myArtist, char *myName) {
  printf("adding [%s: %s]\n", myArtist, myName);
  int num = myArtist[0] - 'a';
  library[num] = insert_order(library[num], myArtist, myName);
}


struct song_node *search_song(struct song_node **library, char *myArtist, char *myName) {
  int num = myArtist[0] - 'a';
  return find_song(library[num], myArtist, myName);
}


struct song_node *search_artist(struct song_node **library, char *myArtist) {
  int num = myArtist[0] - 'a';
  return find_first(library[num], myArtist);
}


void print_letter(struct song_node **library, char letter) {
  printf("entries under %c\n", letter);
  int num = letter - 'a';
  print_list(library[num]);

}


void print_library(struct song_node **library){
  int i;
  for (int i = 0; i <27; i++){
    if (library[i] != NULL){
      print_letter(library, i + 'a');
    }
  }
}


void shuffle(struct song_node **library, int length){
  while (length > 0) {
    int rand_row = rand()%26;
    if (library[rand_row] != NULL) {
      random_element(library[rand_row]);
      length--;
    }
    else
      rand_row = rand()%26;
  }
}


void delete_song(struct song_node **library, char *myArtist, char *myName){
  printf("deleting [%s: %s]\n", myArtist, myName);
  int num = myArtist[0] - 'a';
  library[num] = remove_node(library[num], myArtist, myName);
}


struct song_node **clear_library(struct song_node **library){
  int i;
  for (int i = 0; i < 27; i++){
    if (library[i] != NULL){
      free_list(library[i]);
      library[i] = NULL;
    }
  }
  return library;
}
