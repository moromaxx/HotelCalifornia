//
//  Customer.c
//  Matala 5 (2)
//
//  Created by Maks Moroshek on 12/24/19.
//  Copyright © 2019 Maks Moroshek. All rights reserved.
//

#include "Customer.h"

Customer* newCustomer(char* name, char card[12]){
    static int id = -999;
    Customer* customer = (Customer*)malloc(sizeof(Customer));
    customer->ID = ++id;
    int j=0;
    while (*name != 0)
        customer->name[j++] = *(name++);
    for (int i=0; i<12; i++)
        customer->card[i] = card[i];
    return customer;
}

