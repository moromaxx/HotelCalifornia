//
//  Reservation.h
//  Matala 5 (2)
//
//  Created by Maks Moroshek on 12/24/19.
//  Copyright © 2019 Maks Moroshek. All rights reserved.
//

#ifndef Reservation_h
#define Reservation_h

#include <stdio.h>
#include "Customer.h"
#include "Room.h"

typedef struct Reservation {
    char date [8];
    Customer* customer;
    int guests;
    int breakfast;
    Room* room;
} Reservation;

Reservation* newReservation(char d[8], Customer* c, int guests, int bf, Room* r);

#endif /* Reservation_h */
