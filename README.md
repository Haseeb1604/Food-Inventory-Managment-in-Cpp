# Food Inventory Management System
Managing the storage of food can be tricky, especially in commercial environments. Fridges and freezers will have many items with “use by”, “frozen on”, etc. This project aims to develop a program that would be useful for both commercial and home users, to keep track of a food inventory.

The program allows the ability to store various kinds of items, and warn users of food that needs to be used in the near future or food that is past it’s suitable date and should be thrown out. You could also think of this as something like a commercial warehouse or distributor, where they may have multiple instances of a food item and should prioritize using the older items first, suggesting the shelf and item with the oldest date on a user's request.

## FoodItem Class
The FoodItem class stores the following properties:

- Name: name of the food item
- Category: category of the food item
- Quantity: number of items available
- Barcode: barcode of the item
- Expiry Date: date on which the item will expire
- isExpired(): returns whether the food item has expired or not
- isExpiringSoon(): returns whether the food item will expire soon or not

## Inventory Class
The Inventory class has the following functions:

- addFoodItems(): add a new food item to the inventory
- editFoodItems(): edit the properties of an existing food item
- deleteFoodItem(): delete an existing food item from the inventory
- searchFoodItem(): search for a specific food item in the inventory
- prioritize(): prioritize the items based on their expiry date
- displayWarnings(): display the warnings for food items that are expired or will expire soon
- display(): display the entire inventory

## Technologies Used
This program is written in C++ and uses the following libraries:

- iostream
- string
- ctime
- vector

## How to Use
To use this program, clone this repository and run the main.cpp file using a C++ compiler. The main() function contains sample code to demonstrate the functionality of the program.
