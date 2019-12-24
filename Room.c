

//
//  Room.c
//  Matala 5 (2)
//
//  Created by Maks Moroshek on 12/24/19.
//  Copyright © 2019 Maks Moroshek. All rights reserved.
//

#include "Room.h"

Room* newRoom(bool status, int guests, int bf){
    Room* room = (Room*)malloc(sizeof(Room));
    room->breakfast = bf;
    room->guests = guests;
    room->status = status;
    
    return room;
}
