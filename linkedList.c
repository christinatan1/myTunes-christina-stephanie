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

int songcmp (struct song_node *song1, struct song_node *song2) {
  if (song1 != NULL && song2 != NULL) {
    if (strcmp(song1->artist, song2->artist) == 0) {
      return strcmp(song1->name, song2->name);
    }
    return strcmp(song1->artist, song2->artist);
  }
  return 0;
}

struct song_node *insert_order(struct song_node *front, char *myArtist, char *myName){
  struct song_node *newNode = malloc(sizeof(struct song_node));
  strcpy(newNode -> name, myName);
  strcpy(newNode -> artist, myArtist);
  newNode->next = NULL;

  struct song_node *prev;
  struct song_node *current = front;

  for (; current != NULL; prev = current, current = current->next) {
    if (songcmp(current, newNode) > 0) {
      if (current==front) {
        front = newNode;
        newNode->next = current;
        return front;
      }
      else {
        prev->next = newNode;
        newNode->next = current;
        return front;
      }
    }
    if (current->next==NULL) {
      current->next = newNode;
      newNode->next = NULL;
      return front;
    }
  }
  
  return newNode;
}

void print_node(struct song_node *x){
  if (x != NULL)
    printf("%s: %s\n", x->artist, x->name);
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

struct song_node *find_song(struct song_node *front, char *myArtist, char *mySong){
  printf("looking for [%s: %s]\n", myArtist, mySong);
  while (front != NULL){
    if (strcmp(front->artist, myArtist) == 0 && strcmp(front->name, mySong) == 0){
      printf("node found! %s: %s\n", myArtist, mySong);
      return front;
    }
    front = front->next;
  }
  printf("node not found\n");
  return NULL;
}

struct song_node *find_first(struct song_node *front, char *myArtist) {
  printf("by %s ", myArtist);
  while (front != NULL){
    if (strcmp(front->artist, myArtist) == 0){
      printf("song found! %s: %s\n", myArtist, front->name);
      return front;
    }
    front = front->next;
  }
  printf("not found\n");
  return NULL;
}

int length_list(struct song_node *front){
  int output = 1;
  while (front -> next != NULL){
    output++;
    front = front->next;
  }
  return output;
}

void random_element(struct song_node *front){
  int length = length_list(front);
  int random = (rand() % (length + 1));
  int i;
  struct song_node *p = front;
  for (int i = 0; i < random; i++){
    p = p->next;
  }
  printf("%s: %s\n", p->artist, p->name);
}

struct song_node *remove_node(struct song_node *front, char *myArtist, char *myName){
  struct song_node * current = front->next;
  struct song_node * previous = front;

  if (strcmp(front->name, myName) == 0 && strcmp(front->artist, myArtist) == 0) {
    free(front);
    front = NULL;
    return current;
  }

  for (; current != NULL; previous = current, current = current->next ) {
    if (strcmp(current->name, myName) == 0 && strcmp(current->artist, myArtist) == 0) {
      struct song_node * freeNode = current;
      previous->next = current->next;
      free(freeNode);
      freeNode = NULL;
    }
  }
  return front;
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
