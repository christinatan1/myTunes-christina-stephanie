#include <stdio.h>
#include <stdlib.h>

struct song_node *table[27];

void add_song(struct song_node **library, char *myArtist, char *myName);

struct song_node *search_song(struct song_node **library, char *myArtist, char *myName);

struct song_node *search_artist(struct song_node **library, char *myArtist);

void print_letter(struct song_node **library, char letter);
