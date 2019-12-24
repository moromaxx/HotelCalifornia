//
//  Room.h
//  Matala 5 (2)
//
//  Created by Maks Moroshek on 12/24/19.
//  Copyright © 2019 Maks Moroshek. All rights reserved.
//

#ifndef Room_h
#define Room_h

#include <stdio.h>
#include <stdbool.h>

typedef struct Room {
    bool status;
    int guests;
    int breakfast;
} Room;

Room* newRoom(bool status, int guests, int bf);

#endif /* Room_h */
