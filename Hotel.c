//
//  Hotel.c
//  Matala 5 (2)
//
//  Created by Maks Moroshek on 12/24/19.
//  Copyright © 2019 Maks Moroshek. All rights reserved.
//

#include "Hotel.h"
#include <string.h>

bool compare (const char* a, const char* b){
    while (*a != 0 && *b != 0){
        if (*(a++) != *(b++))
            return false;
    }
    return (*a == *b);
}

Hotel* newHotel (){
    Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
    for (int i=0; i<FLOORS; i++)
        for (int j=0; j<ROOMSPERFLOOR; j++){
            hotel->rooms[i][j] = newRoom(true, 0, 0);
        }
    char def [256] = "";
    for (int i=0; i< MAXSIZE; i++){
        hotel->reservations[i] = newReservation(def, 0, 0, 0, 0);
        hotel->customers[i] = newCustomer(def, def);
    }
    return hotel;
}

void showHotelStatus(Hotel* h){
    for (int i=0; i<FLOORS; i++)
        for (int j=0; j<ROOMSPERFLOOR; j++){
            if (h->rooms[i][j]->status == true){
                printf("The room %d is free.\n", (i+1)*10+j+1);
                continue;
            }
            int guests = 0;
            int bf = 0;
            Customer* customer = 0;
            for (int k=0; k<MAXSIZE; k++){
                if (h->reservations[k]->room == h->rooms[i][j]){
                    customer = h->reservations[k]->customer;
                    guests = h->reservations[k]->guests;
                    bf = h->reservations[k]->breakfast;
                    break;
                }
            }
            printf("The room %d is taken by %s for %d guests and %d will eat breakfast.\n", (i+1)*10+j+1, customer->name, guests, bf);
        }
}

void addCustomer(Hotel* h, char* name, char card [12]){
    for (int i=0; i<MAXSIZE; i++){
        if (h->customers[i]->ID <= 0){
            h->customers[i] = newCustomer(name, card);
            return;
        }
    }
    printf("There is no more space for new customers!\n");
}

void checkIn (Hotel* h){
    printf("Please choose the customer from the following list:\n");
    for (int i=0; i<999; i++)
        if (h->customers[i]->ID > 0){
            printf("%d)%s\n",i+1, h->customers[i]->name);
    }
    char name [256] = {0};
    scanf("%s", name);
    Customer* customer = 0;
    for (int i=0; i<999; i++){
        if (compare(name, h->customers[i]->name)){
            customer = h->customers[i];
            break;
        }
        if (i == 99){
            printf("Try again.\n");
            scanf("%s", &name);
            i=0;
        }
    }
    printf("Insert number of guests:\n");
    int numOfGuests = 0;
    scanf("%d", &numOfGuests);
    while (numOfGuests < 1 || numOfGuests > 4){
        printf("Try again.\n");
        scanf("%d", &numOfGuests);
    }
    printf("Insert number of guests who will eat breakfast:\n");
    int breakfastNum;
    scanf("%d", &breakfastNum);
    while (breakfastNum < 0 || breakfastNum > 4){
        printf("Try again.\n");
        scanf("%d", &breakfastNum);
    }
    char date [8] = {0};
    printf("Insert the date in format dd/mm/yyyy:\n");
    scanf("%s", date);
    Room* room = 0;
    for (int i=0; i < FLOORS; i++)
        if (room != 0)
            break;
        else
        for (int j=0; j < ROOMSPERFLOOR; j++){
            if (h->rooms[i][j]->status){
                room = h->rooms[i][j];
                break;
            }
            if (i == FLOORS-1 && j == ROOMSPERFLOOR-1){
                printf ("All the rooms are unavailable right now!\n");
                return;
            }
        }
    for (int i=0; i < MAXSIZE; i++){
        if (h->reservations[i]->customer == 0){
            *room = *newRoom(false, numOfGuests, breakfastNum);
            h->reservations[i] = newReservation(date, customer, numOfGuests, breakfastNum, room);
            return;
        }
        if (i == 998)
            printf("There are no more space for reservations, sorry.\n");
    }
}

void checkOut (Hotel* h, int roomNum){
    for (int i=0; i < FLOORS; i++)
        for (int j=0; j < ROOMSPERFLOOR; j++){
            if (roomNum == (i+1)*10+(j+1)){
                if (h->rooms[i][j]->status == true){
                    printf("The room is already free!\n");
                    return;
                }
                h->rooms[i][j] = newRoom(true, 0, 0);
                return;
            }
        }
    printf("The number of room is incorrect! The number is an ij where i - number of the floor, j - number of room on the floor.\n");
}
