//
//  main.c
//  Matala 5 (2)
//
//  Created by Maks Moroshek on 12/24/19.
//  Copyright © 2019 Maks Moroshek. All rights reserved.
//

#include <stdio.h>
#include "Hotel.h"

int main() {
    
    Hotel california = *newHotel();
    
    printf("Welcome to the hotel \"California!\"");
    int choose = 1;
    while(choose != 0){
        printf("\n\tTo show hotel status press 1\n\tTo add customer press 2\n\tTo check in press 3\n\tTo check out press 4\n\tTo exit the program press 0\n");
        scanf("%d", &choose);

        if (choose < 0 || choose > 4){
            printf("Incorrect choose!\n");
            choose = -1;
        }
        switch (choose){
            case 1:
                showHotelStatus(&california);
                continue;
            case 2:
                printf("Insert name of the customer:\n");
                char* name = (char*)malloc(sizeof(char));
                scanf("%s", name);
                printf("Insert 12 digits of the card:\n");
                char card [12] = {0};
                scanf("%s", card);
                addCustomer(&california, name, card);
                continue;
            case 3:
                checkIn(&california);
                continue;
            case 4:
                printf("Insert the number of room:\n");
                int roomNum = 0;
                scanf("%d", &roomNum);
                checkOut(&california, roomNum);
                continue;
            case -1:
                continue;
        }
    }
    
    printf("See you later. Thank you for choosing hotel \"California\"!\n");
    
    return 0;
}
