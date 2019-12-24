//
//  Customer.h
//  Matala 5 (2)
//
//  Created by Maks Moroshek on 12/24/19.
//  Copyright © 2019 Maks Moroshek. All rights reserved.
//

#ifndef Customer_h
#define Customer_h

#include <stdio.h>

typedef struct Customer {
    int ID;
    char name [256];
    char card [12];
} Customer;

Customer* newCustomer(char* name, char card[12]);

#endif /* Customer_h */
