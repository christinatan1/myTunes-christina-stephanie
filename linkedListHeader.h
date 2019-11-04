#include <stdio.h>
#include <stdlib.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node *insert_front(struct song_node *front, char *myName, char *myArtist);

int songcmp (struct song_node *song1, struct song_node *song2);

struct song_node *insert_order(struct song_node *front, char *myName, char *myArtist);

void print_node(struct song_node *x);

void print_list(struct song_node *x);

struct song_node *find_song(struct song_node *front, char *myArtist, char *mySong);

struct song_node *find_first(struct song_node *front, char *myArtist);

int length_list(struct song_node *front);

void random_element(struct song_node *front);

struct song_node *remove_node(struct song_node *front, char *myArtist, char *myName);

struct song_node *free_list(struct song_node *front);
