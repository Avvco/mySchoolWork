//  http://134.208.3.66/problem/PR1090704

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* arr, int size) ;

int main(int argc, char const *argv[]) {

  while(1) {
    int person_count;
    int vote_count;
    scanf("%d%d", &person_count, &vote_count);

    if(person_count == 0 && vote_count == 0) {
      return 0;
    }

    int vote[vote_count];
    int person[person_count + 1];
    int personC[person_count + 1];
    for(int i = 0 ; i < person_count + 1 ; i++) {
      person[i] = 0;
      personC[i] = 0;
    }
    for(int i = 0 ; i < vote_count ; i++) {
      scanf("%d", &vote[i]);
    }

    for(int i = 0 ; i < vote_count ; i++) {
      person[vote[i]] = person[vote[i]] + 1;
      personC[vote[i]] = personC[vote[i]] + 1;
    }

    int half;
    if(vote_count % 2 == 0) {
      half = vote_count / 2;
    }else {
      half = (vote_count / 2);
    }

    insertionSort(personC, person_count + 1);


    if(personC[person_count] == personC[person_count-1]) {
      printf("No winner");
      continue;
    }

    int maxPerson = 1;

    for(int index = 1 ; index <= person_count ; index++){
      if(person[maxPerson] < person[index]) {
        maxPerson = index;
      }
    }
    if(person[maxPerson] > half) {
      printf("Majoritarian winner %d", maxPerson);
    }else {
      printf("Plurality winner %d", maxPerson);
    }
  }
}


void insertionSort(int* arr, int size) {
  for(int i = 1 ; i < size ; i++) {
    int key = arr[i];
    int j = i - 1;
    while(key < arr[j] && j >= 0) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}
