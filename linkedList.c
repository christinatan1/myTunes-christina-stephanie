#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "linkedListHeader.h"

// struct song_node{
//   char name[100];
//   char artist[100];
//   struct song_node *next;
// };


struct song_node *insert_front(struct song_node *front, char *myName, char *myArtist){
  struct song_node *newNode = malloc(sizeof(struct song_node));
  strcpy(newNode->name, myName);
  strcpy(newNode->artist, myArtist);
  newNode->next = front;
  return newNode;
}


void print_list(struct song_node *x){
  if (x == 0){
    printf("Printing empty list: [ ]\n");
  }
  else {
    printf("Printing list: \n");
    while (x != 0){
      printf("%s: %s | ", x->artist, x->name);
      x = x->next;
    }
    printf(" \n");
  }
}


void findSong(struct song_node *front, char *myArtist, char *mySong){
  printf("looking for [%s: %s]\n", myArtist, mySong);
  while (front -> next != NULL){
    if (strcmp(front->artist, myArtist) == 0 && strcmp(front->name, mySong) == 0){
      printf("node found! %s: %s\n", myArtist, mySong);
      return;
    }
    front = front->next;
  }
  if (strcmp(front->artist, myArtist) == 0 || strcmp(front->name, mySong) == 0){
    printf("node found! %s: %s\n", myArtist, mySong);
    return;
  }
  printf("node not found\n");
}


int lengthList(struct song_node *front){
  int output = 1;
  while (front -> next != NULL){
    output++;
    front = front->next;
  }
  return output;
}

void randomElement(struct song_node *front){
  int length = lengthList(front);
  int random = (rand() % (length + 1));
  int i;
  struct song_node *p = front;
  for (int i = 0; i < random; i++){
    p = p->next;
  }
  printf("%s: %s\n", p->artist, p->name);
}


struct song_node *free_list(struct song_node *front){
  struct song_node *p;
  while (front -> next != NULL){
    p = front->next;
    free(front);
    front = NULL;
    front = p;
  }
  free(front);
  front = NULL;
  return front;
}
