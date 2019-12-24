//
//  Reservation.c
//  Matala 5 (2)
//
//  Created by Maks Moroshek on 12/24/19.
//  Copyright © 2019 Maks Moroshek. All rights reserved.
//

#include "Reservation.h"

Reservation* newReservation(char d[8], Customer* c, int guests, int bf, Room* r){
    Reservation* reservation = (Reservation*)malloc(sizeof(Reservation));
    for (int i=0; i<8; i++)
        reservation->date[i] = d[i];
    reservation->customer = c;
    reservation->guests = guests;
    reservation->breakfast = bf;
    reservation->room = r;
    return reservation;
}
