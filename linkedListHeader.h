#include <stdio.h>
#include <stdlib.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node *insert_front(struct song_node *front, char *myName, char *myArtist);

void print_list(struct song_node *x);

void findSong(struct song_node *front, char *myArtist, char *mySong);

void randomElement(struct song_node *front);
int lengthList(struct song_node *front);

struct song_node *free_list(struct song_node *front);
