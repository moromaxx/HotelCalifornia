//
//  Hotel.h
//  Matala 5 (2)
//
//  Created by Maks Moroshek on 12/24/19.
//  Copyright © 2019 Maks Moroshek. All rights reserved.
//

#ifndef Hotel_h
#define Hotel_h

#define FLOORS 4
#define ROOMSPERFLOOR 4
#define MAXSIZE 999

#include <stdio.h>
#include "Room.h"
#include "Customer.h"
#include "Reservation.h"

typedef struct Hotel {
    Room* rooms [FLOORS][ROOMSPERFLOOR];
    Reservation* reservations[MAXSIZE];
    Customer* customers[MAXSIZE];
} Hotel;

Hotel* newHotel ();

void showHotelStatus(Hotel*);

void addCustomer(Hotel*, char*, char*);

void checkIn (Hotel*);

void checkOut (Hotel*, int);

#endif /* Hotel_h */
