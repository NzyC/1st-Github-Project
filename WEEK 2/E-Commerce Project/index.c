// Assignment 2 - CS Sushi
//
// This program was written by Nidal Chowdhury (z5421936)
// on (4/08/2022)
//
// This program is a sushi restraunt that allows the user to
// enter commands altering different actions that affect the
// sushi restraunt allowing it to function.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Additional libraries here

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////  CONSTANTS  /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Provided constants
#define TRUE 1
#define FALSE 0

#define MAX_STRING_LENGTH 100
#define EMPTY_CUSTOMER "EMPTY"

#define COMMAND_ADD_TABLE 'a'
#define COMMAND_ADD_CUSTOMER 'c'
// TODO: you may choose to add additional #defines here.

// Provided Enums

// the numerical value is the cost of that plate color
enum plate_colour { RED = 3, GREEN = 4, BLUE = 5, PURPLE = 6, ORANGE = 7 };

enum sushi_type { VEGETARIAN, SEAFOOD, CHICKEN, TEMPURA };

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////  STRUCTS  //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Provided structs
struct table {
    char customer[MAX_STRING_LENGTH];
    struct plate *orders;
    struct table *next;
};

struct plate {
    char roll_name[MAX_STRING_LENGTH];
    enum plate_colour colour;
    enum sushi_type type;
    struct plate *next;
};

struct restaurant {
    struct table *tables;
    struct plate *plates;
};

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  FUNCTION PROTOTYPES  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Helper Functions
void print_restaurant(struct restaurant *restaurant);
int scanf_command(char *command);
void interpret_line(
    char buffer[MAX_STRING_LENGTH], char name[MAX_STRING_LENGTH],
    enum plate_colour *colour, enum sushi_type *type);

void interpret_order(
    char buffer[MAX_STRING_LENGTH], char customer[MAX_STRING_LENGTH],
    char roll[MAX_STRING_LENGTH]);

enum plate_colour string_to_colour(char colour[MAX_STRING_LENGTH]);
enum sushi_type string_to_type(char type[MAX_STRING_LENGTH]);
void remove_newline(char input[MAX_STRING_LENGTH]);
char color_to_char(enum plate_colour colour);
void to_type(char types[MAX_STRING_LENGTH], enum sushi_type type);
void to_colour(char cols[MAX_STRING_LENGTH], enum plate_colour colour);

// TODO: Your function prototypes here
struct table *add_table(char customer[MAX_STRING_LENGTH], struct plate *orders, struct table *next);
struct table *add_table_end(struct restaurant *sushi_restaurant, struct table *head_ptr);
void add_customer(struct restaurant *sushi_restaurant, struct table *head_ptr);
struct plate* add_plate(struct plate *next);
struct plate* add_table_detailed(struct restaurant *sushi_restaurant, struct plate **head);
void print_train(struct plate *head);
struct plate *add_plate_second(char roll_name[MAX_STRING_LENGTH], enum plate_colour colour, enum sushi_type type, struct plate *next);
void order(struct restaurant *sushi_restaurant);
void calculate_bill(struct restaurant *sushi_restaurant);
void closing_restaurant(struct restaurant *sushi_restaurant);

////////////////////////////////////////////////////////////////////////////////
//////////////////////////  FUNCTION IMPLEMENTATIONS  //////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(void) {
    printf("Welcome to CSE Sushi Restaurant!\n");
    
    struct restaurant *sushi_restaurant = malloc(sizeof(struct restaurant));

    sushi_restaurant->tables = NULL;
    sushi_restaurant->plates = NULL;
    
    print_restaurant(sushi_restaurant);
    
    printf("Enter command: ");
    char command;
    while (scanf_command(&command) != EOF) {
        if (command == 'p') {
            print_restaurant(sushi_restaurant);
        } else if (command == 'a') {
            add_table_end(sushi_restaurant, sushi_restaurant->tables);
        } else if (command == 'c') {
            add_customer(sushi_restaurant, sushi_restaurant->tables);
        } else if (command == 'r') {
            add_table_detailed(sushi_restaurant, &sushi_restaurant->plates);
        } else if (command == 't') {
            print_train(sushi_restaurant->plates);
        } else if (command == 'o') { 
            order(sushi_restaurant);
        } else if (command == 'b') {   
            calculate_bill(sushi_restaurant);
        } else if (command == 'q') {
            closing_restaurant(sushi_restaurant);
            printf("Thank you for dining with CSE Sushi Restaurant!\n");
            return 0;
        }
        
        printf("Enter command: ");
        
    }
    
    closing_restaurant(sushi_restaurant);
    
    printf("Thank you for dining with CSE Sushi Restaurant!\n");
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////////// ADDITIONAL FUNCTIONS /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: you may need to add additional functions here

struct table* add_table(char customer[MAX_STRING_LENGTH], struct plate *orders, struct table *next) {
    struct table *new_table = malloc(sizeof(struct table));
    new_table->orders = orders;
    new_table->next = next;
    strcpy(new_table->customer, customer);

    return new_table;
}

struct table *add_table_end(struct restaurant *sushi_restaurant, struct table *head_ptr) {
    struct table *current = head_ptr;
    
    if (current == NULL) {
        struct table *new_table = add_table(EMPTY_CUSTOMER, NULL, NULL);
        sushi_restaurant->tables = new_table;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        struct table *new_table = add_table(EMPTY_CUSTOMER, NULL, NULL);
        current->next = new_table;    
    }
    return head_ptr;
}

void add_customer(struct restaurant *sushi_restaurant, struct table *head_ptr) {
    struct table *current = head_ptr;
    printf("Enter customer name: ");
    char new_customer[MAX_STRING_LENGTH];      
    fgets(new_customer, MAX_STRING_LENGTH, stdin);
    remove_newline(new_customer);
    if (current == NULL) {
        printf("No empty tables!\n");
    } else {
        while (strcmp(current->customer, EMPTY_CUSTOMER) == 1 && current->next != NULL) {
            current = current->next;
        }
        if (strcmp(current->customer, EMPTY_CUSTOMER) == 0) {   
            strcpy(current->customer, new_customer);
        } else {
            printf("No empty tables!\n");
        }
    }
}

struct plate* add_plate(struct plate *next) {
    struct plate *new_plate = malloc(sizeof(struct plate));
    char input[MAX_STRING_LENGTH];
    fgets(input, MAX_STRING_LENGTH, stdin);
    char dish_name[MAX_STRING_LENGTH];
    enum sushi_type type;
    enum plate_colour colour;
    interpret_line(input, dish_name, &colour, &type);
    strcpy(new_plate->roll_name, dish_name);
    new_plate->colour = colour; 
    new_plate->next = next; 
    new_plate->type = type; 
    
    return new_plate;
}

struct plate* add_table_detailed(struct restaurant *sushi_restaurant, struct plate **head) {
    struct plate *current = *head;
    struct plate *previous = NULL;
    struct plate *new_plate = add_plate(NULL);
    while (current->type <= new_plate->type && current != NULL) {
        previous = current;
        current = current->next;
    }
    new_plate->next = current;
    if (previous == NULL) {
        *head = new_plate;
    } else {
        previous->next = new_plate;
    }
    return *head;
}

void print_train(struct plate *head) {
    struct plate *current = head;
    if (current == NULL) {
        printf("    empty :(\n");
    } else {
        while (current != NULL) {
            printf("    %s-", current->roll_name);
            if (current->type == 0) {
                printf("vegetarian-");
            } else if (current->type == 1) {
                printf("seafood-");
            } else if (current->type == 2) {
                printf("chicken-");
            } else if (current->type == 3) {
                printf("tempura-");
            } else if (current->colour == 3) {
                printf("red\n");
            } else if (current->colour == 4) {
                printf("green\n");
            } else if (current->colour == 5) {
                printf("blue\n");
            } else if (current->colour == 6) {
                printf("purple\n");
            } else if (current->colour == 7) {
                printf("orange\n");
            }
            printf("      |\n");
            printf("      v\n");
            current = current->next;
        }
    }
}

struct plate *add_plate_second(char roll_name[MAX_STRING_LENGTH], enum plate_colour colour, enum sushi_type type, struct plate *next) {
    struct plate *new_plate = malloc(sizeof(struct table)); 
    strcpy(new_plate -> roll_name, roll_name); 
    new_plate->colour = colour; 
    new_plate->next = next; 
    new_plate->type = type;
    return new_plate; 
}

void order(struct restaurant *sushi_restaurant) {
    struct table *current_table = sushi_restaurant->tables;
    struct plate *current_plate = sushi_restaurant->plates;
    struct plate *previous_plate = NULL;
    char order_code[MAX_STRING_LENGTH];
    remove_newline(order_code);
    fgets(order_code, MAX_STRING_LENGTH, stdin);
    char customer[MAX_STRING_LENGTH];
    char dish_name[MAX_STRING_LENGTH];
    interpret_order(order_code, customer, dish_name);
    while (strcmp(current_table->customer, customer) != 0 && current_table != NULL) {
        current_table = current_table->next;
    }
    if (current_table == NULL) {
        printf("There is no customer with that name!\n");
        return;
    }
    while (strcmp(current_plate->roll_name, dish_name) != 0 && current_plate != NULL) {
        previous_plate = current_plate;
        current_plate = current_plate->next;
    }
    struct plate *table_plate = current_table->orders;
    if (current_plate == NULL) {
        printf("Enter dish details: ");
        char food_input[MAX_STRING_LENGTH];
        fgets(food_input, MAX_STRING_LENGTH, stdin);
        char roll_name[MAX_STRING_LENGTH];
        enum plate_colour colour;
        enum sushi_type type;
        interpret_line(food_input, roll_name, &colour, &type);
        struct plate *new_plate = add_plate_second(dish_name, colour, type, NULL);
        if (table_plate == NULL) {
            current_table->orders = new_plate;
        } else {
            while (table_plate->next != NULL) {
                table_plate = table_plate->next;
            }
            table_plate->next = new_plate;
        }        
    } else {
        if (table_plate == NULL) {
            if (previous_plate == NULL) {
                current_table->orders = current_plate;
                sushi_restaurant->plates = current_plate->next;
                current_plate->next = NULL;
            } else {
                current_table->orders = current_plate;
                previous_plate->next = current_plate->next;
                current_plate->next = NULL;
            }
        } else {
            while (table_plate->next != NULL) {
                table_plate = table_plate->next;
            }
            table_plate->next = current_plate;
            previous_plate->next = current_plate->next;
            current_plate->next = NULL;
        }
    }
}

void calculate_bill(struct restaurant *sushi_restaurant) {
    struct table *current_table = sushi_restaurant->tables;
    printf("Enter customer name: ");
    char customer_last[MAX_STRING_LENGTH];
    fgets(customer_last, MAX_STRING_LENGTH, stdin);
    remove_newline(customer_last);
    while (current_table != NULL) {
        if (strcmp(current_table->customer, customer_last) == 0) {
            struct plate *current_plate = current_table->orders;
            int bill = 0;
            while (current_plate != NULL) {
                bill = bill + current_plate->colour;
                current_plate = current_plate->next;
            }
            printf("Thank you for dining with CSE Sushi! Your total is: $%d\n", bill);
            strcpy(current_table -> customer, EMPTY_CUSTOMER);
            struct plate *table_plate = current_table->orders;
            struct plate *prev_table_plate = current_table->orders;
            while (table_plate != NULL) {
                prev_table_plate = table_plate;
                table_plate = table_plate->next;
                free(prev_table_plate);
            }    
            current_table->orders = NULL;       
            return;
        } else {
            printf("There is no customer with that name!");
        }
        current_table = current_table->next;      
    }
}

void closing_restaurant(struct restaurant *sushi_restaurant) {
    struct table *current_table = NULL; 
    struct table *previous_table = NULL; 
    struct plate *current_plate = NULL; 
    struct plate *previous_plate = NULL; 
    if (sushi_restaurant -> tables != NULL) {
        current_table = sushi_restaurant -> tables;
        previous_table = current_table;
        sushi_restaurant -> tables = NULL;
    }
    while (current_table != NULL) {
        if (current_table->orders != NULL) {
            current_plate = current_table -> orders;
            current_table->orders = NULL; 
        }
        while (current_plate != NULL) {
            previous_plate = current_plate;
            current_plate = current_plate->next; 
            previous_plate->next = NULL;
            free(previous_plate);
        } 
        previous_table = current_table; 
        current_table = current_table->next; 
        previous_table->next = NULL;
        free(previous_table); 
    }
    current_plate = NULL;
    previous_plate = NULL; 
    if (sushi_restaurant->plates!= NULL) {
        current_plate = sushi_restaurant->plates; 
        previous_plate = current_plate;
        sushi_restaurant->plates = NULL; 
    }
    while (current_plate != NULL) {
        previous_plate = current_plate; 
        current_plate = current_plate -> next;
        previous_plate->next = NULL;
        free(previous_plate);
    }
    free(sushi_restaurant);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// PROVIDED FUNCTIONS //////////////////////////////
/////////////////////////// (DO NOT EDIT BELOW HERE) ///////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Provided Function - DO NOT EDIT
void print_restaurant(struct restaurant *restaurant) {
    int i;
    if (restaurant == NULL) {
        printf("ERROR: No restaurant!\n");
        return;
    };

    printf("CSE Sushi Restaurant\n");
    struct table *table = restaurant->tables;
    int table_num = 0;
    while (table != NULL) {
        int table_length = 5;
        if (strcmp(table->customer, EMPTY_CUSTOMER) != 0) {
            table_length = strlen(table->customer) + 4;
        }
        // calculate number of plates
        int number_of_plates = 0;
        struct plate *curr = table->orders;
        while (curr != NULL) {
            number_of_plates++;
            curr = curr->next;
        }

        printf(" ");
        for (i = 0; i < table_length; i++) {
            printf("_");
        }
        printf(" ");

        // print out the top row
        for (i = 0; i < number_of_plates; i++) {
            printf("    _____ ");
        }

        printf("\n");

        // print out the data
        int occupied = FALSE;
        if (strcmp(table->customer, "EMPTY") != 0) {
            occupied = TRUE;
        }
        if (occupied) {
            printf("|  %s  |-->", table->customer);
        } else {
            printf("|  %d  |-->", table_num);
        }

        // print out the plates
        struct plate *order = table->orders;
        while (order != NULL) {
            printf("|  %c  |-->", color_to_char(order->colour));

            order = order->next;
        }

        printf("\n");
        printf(".");
        for (i = 0; i < table_length; i++) {
            printf("-");
        }
        printf(".");
        // print out the top row
        for (i = 0; i < number_of_plates; i++) {
            printf("   |-----|");
        }

        printf("\n");
        table = table->next;
        table_num++;
    }
}

// Helper Function
// scans a single character from the user and returns the value of scanf;
//
// Parameters:
//  - command: a pointer to a character to store the command
//
// Returns:
//  - the value that scanf returns (this will be 1 if it was successfully read);
//
// Usage:
//  ```
//  char command;
//  while (scanf_command(&command) == 1) {
//  ```
// this function does some wizadry that you **do not need to understand**
// for you to ensure that subsequent
// calls to fgets works correctlly.
int scanf_command(char *command) {
    // read in character + newline + null-terminator
    char buffer[3];
    char *result = fgets(buffer, 3, stdin);
    if (result == NULL) {
        return EOF;
    }

    // a non a-z character probably means not a char
    if (buffer[0] < 'a' || buffer[0] > 'z') {
        return EOF;
    }

    // set the character
    *command = buffer[0];
    return 1;
}

// Helper Function
// You DO NOT NEED TO UNDERSTAND THIS FUNCTION, and will not need to change it.
//
// Given a raw string in the format: [string] [enum1] [enum2]
// This function will extract the relevant values into the given variables.
// The function will also remove any newline characters.
//
// For example, if given: "salmon red seafood"
// The function will copy the string:
//     "salmon" into the 'name' array
// And will copy the enums:
//     red      into the colour pointer
//     seafood  into the type pointer
//
// If you are interested, `strtok` is a function which takes a string,
// and splits it up into before and after a "token" (the second argument)
//
// Parameters:
//     buffer  = A null terminated string in the following format
//               [string] [enum1] [enum2]
//     name    = An array for the [string] to be copied into
//     colour  = A pointer to where [enum1] should be stored
//     type    = A pointer to where [enum2] should be stored
// Returns:
//     None
void interpret_line(
    char buffer[MAX_STRING_LENGTH], char name[MAX_STRING_LENGTH],
    enum plate_colour *colour, enum sushi_type *type) {
    // Remove extra newline
    remove_newline(buffer);

    // Extract value 1 as string (sushi roll name)
    char *name_str = strtok(buffer, " ");
    if (name_str != NULL) {
        // Extract word
        strcpy(name, name_str);
    }

    // Extract value 2 as str, then enum
    char *colour_str = strtok(NULL, " ");
    if (colour_str != NULL) {
        *colour = string_to_colour(colour_str);
    }

    // Extract value 2 as str, then enum
    char *type_str = strtok(NULL, " ");
    if (type_str != NULL) {
        *type = string_to_type(type_str);
    }

    if (name_str == NULL || colour_str == NULL || type_str == NULL) {
        // If any of these are null, there were not enough words.
        printf("Could not properly interpret line: %s.\n", buffer);
    }
}

// Helper Function
// You DO NOT NEED TO UNDERSTAND THIS FUNCTION, and will not need to change it.
//
// Given a raw string in the following foramt: [string1] [string2]
// This function will extract the relevant values into the given variables.
// The function will also remove any newline characters.
//
// For example, if given: "Gab salmon"
// The function will put:
//     "Gab" into the 'customer' array
//     "salmon" into the 'roll' array
//
// Parameters:
//     buffer   = A null terminated string in the following format
//                [string1] [string2]
//     customer = An array for the [string1] to be copied into
//     roll     = An array for the [string2] to be copied into
// Returns:
//     None
void interpret_order(
    char buffer[MAX_STRING_LENGTH], char customer[MAX_STRING_LENGTH],
    char roll[MAX_STRING_LENGTH]) {
    // Remove extra newline
    remove_newline(buffer);

    // Extract value 1 as string
    char *customer_str = strtok(buffer, " ");
    if (customer_str != NULL) {
        strcpy(customer, customer_str);
    }

    // Extract value 2 as string
    char *roll_str = strtok(NULL, " ");
    if (roll_str != NULL) {
        strcpy(roll, roll_str);
    }

    if (customer_str == NULL || roll_str == NULL) {
        // If any of these are null, there were not enough words.
        printf("Could not properly interpret line: %s.\n", buffer);
    }
}

// Helper Function
// You likely do not need to change this function.
//
// Given a raw string will remove and first newline it sees.
// The newline character wil be replaced with a null terminator ('\0')
void remove_newline(char input[MAX_STRING_LENGTH]) {
    // Find the newline or end of string
    int index = 0;
    while (input[index] != '\n' && input[index] != '\0') {
        index++;
    }
    // Goto the last position in the array and replace with '\0'
    // Note: will have no effect if already at null terminator
    input[index] = '\0';
}

// Helper Function
// You likely do not need to change this function.
//
// Given an enum plate_colour will return the first letter of enum, or ? if the
// value is not one of the plate_colour values.
// Parameters:
//     colour  = enum plate_colour for a plate
// Returns:
//     char    = character represtning the first letter of the plate colour
char color_to_char(enum plate_colour colour) {
    if (colour == RED) {
        return 'r';
    } else if (colour == GREEN) {
        return 'g';
    } else if (colour == BLUE) {
        return 'b';
    } else if (colour == PURPLE) {
        return 'p';
    } else if (colour == ORANGE) {
        return 'o';
    } else {
        return '?';
    }
}

// Helper Function
// You likely do not need to change this function.
//
// Given a raw string will return the corresponding enum plate_colour, or FALSE
// if the string doesn't correspond with the enums.
// Parameters:
//     colour  = string representing the corresponding enum plate_colour value
// Returns:
//     enum plate_colour
enum plate_colour string_to_colour(char colour[MAX_STRING_LENGTH]) {
    if (strcmp(colour, "red") == 0) {
        return RED;
    } else if (strcmp(colour, "green") == 0) {
        return GREEN;
    } else if (strcmp(colour, "blue") == 0) {
        return BLUE;
    } else if (strcmp(colour, "purple") == 0) {
        return PURPLE;
    } else if (strcmp(colour, "orange") == 0) {
        return ORANGE;
    }
    return FALSE;
}

// Helper Function
// You likely do not need to change this function.
//
// Given a raw string will return the corresponding enum sushi_type, or FALSE
// if the string doesn't correspond with the enums.
// Parameters:
//     type  = string representing the corresponding enum sushi_type value
// Returns:
//     enum sushi_type
enum sushi_type string_to_type(char type[MAX_STRING_LENGTH]) {
    if (strcmp(type, "vegetarian") == 0) {
        return VEGETARIAN;
    } else if (strcmp(type, "seafood") == 0) {
        return SEAFOOD;
    } else if (strcmp(type, "chicken") == 0) {
        return CHICKEN;
    } else if (strcmp(type, "tempura") == 0) {
        return TEMPURA;
    }
    return FALSE;
}

// Helper Function
// You likely do not need to change this function.
//
// Given an enum sushi_type will return the enum name as a string, or "ERROR" if
// the value was not one of the given enums.
// Parameters:
//     types  = string to store the name of the enum in
//     type   = sushi_type enum to have the name stored in types.
// Returns:
//     None
void to_type(char types[MAX_STRING_LENGTH], enum sushi_type type) {
    if (type == VEGETARIAN) {
        strcpy(types, "vegetarian");
    } else if (type == SEAFOOD) {
        strcpy(types, "seafood");
    } else if (type == CHICKEN) {
        strcpy(types, "chicken");
    } else if (type == TEMPURA) {
        strcpy(types, "tempura");
    } else {
        strcpy(types, "ERROR");
    }
}

// Helper Function
// You likely do not need to change this function.
//
// Given an enum plate_colour will return the enum name as a string, or "ERROR"
// if the value was not one of the given enums.
// Parameters:
//     cols   = string to store the name of the enum in
//     colour = plate_colour enum to have the name stored in cols
// Returns:
//     None
void to_colour(char cols[MAX_STRING_LENGTH], enum plate_colour colour) {
    if (colour == RED) {
        strcpy(cols, "red");
    } else if (colour == BLUE) {
        strcpy(cols, "blue");
    } else if (colour == GREEN) {
        strcpy(cols, "green");
    } else if (colour == PURPLE) {
        strcpy(cols, "purple");
    } else if (colour == ORANGE) {
        strcpy(cols, "orange");
    } else {
        strcpy(cols, "ERROR");
    }
}