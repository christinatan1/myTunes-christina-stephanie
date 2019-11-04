#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedListHeader.h"
#include "arrayLibraryHeader.h"

struct song_node *add_song(struct song_node **library, char *myArtist, char *myName) {
  printf("adding [%s: %s]\n", myArtist, myName);
  
  int num = myArtist[0] - 'a';

  struct song_node * song = insert_order(library[num], myArtist, myName);
  return song;
}

struct song_node *search_song(struct song_node **library, char *myArtist, char *myName) {
  int num = myArtist[0] - 'a';
  return find_song(library[num], myArtist, myName);
}
  
struct song_node *search_artist(struct song_node **library, char *myArtist) {
  printf("searching for %s", myArtist);

  int num = myArtist[0] - 'a';
  
  return find_first(library[num], myArtist);
}

void print_letter(struct song_node **library, char letter) {
  printf("entries under %c\n", letter);

  int num = letter - 'a';

  print_list(library[num]);
  
}
