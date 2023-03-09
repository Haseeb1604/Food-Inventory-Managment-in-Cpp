// Inventory Managing the storage of food can be tricky, especially in commercial environments.
// Fridges and freezers will have many items with “use by”, “frozen on”, etc. 
// 
// The aim of this project is to develop a program that would be useful for both commercial and home
// users, to keep track of a food inventory. 
// 
// Allow the ability to store various kinds of items, and warn users of food that needs to be used in the near future or food that is past it’s
// suitable date and should be thrown out. 
// 
// You could also think of this as something like a commercial warehouse or distributor, where they may have multiple instances of a food
// item and should prioritise using the older items first, suggesting the shelf and item with the oldest date on a users’ request.
// 
 
// FoodItem
//  - Name
//  - Category
//  - Quantity
//  - Expiry Date
//  - isExpired()
//  - isExpiringSoon()

# include <iostream>
# include <string>
# include <ctime>
# include <vector>

using namespace std;

class FoodItem{
	public:
		string name;
		string category;
		int quantity;
		string barcode;
		time_t expiryDate;
		
		FoodItem(string name, string category, int quantity, string barcode ,time_t expiryDate){
			this->name = name;
			this->category = category;
			this->quantity = quantity;
			this->barcode = barcode;
			this->expiryDate = expiryDate;
		}
		
		// This will check expiry date and will tell us whether our food item is expired or not
		bool isExpired(){
			time_t now = time(NULL); // Time() will return our Current Time
			return expiryDate < now; // if the item is expired it will return True and if it is not expired it will return False	
		}
		
		// isExpiring Function will tell us whether our Food Item will expire in our defined time or not
		// date parameter is our limit in which we want to check our food to be expiring or not
		bool isExpiring(int date=1){
			time_t now = time(NULL); // Time() will return our Current Time 
			time_t threshold = now + date * 24 * 60 * 60;// Add up our current time with the limit we want to check for expiring
			return expiryDate < threshold;
			// Threshold = 08/03/2023 + 1 Day
			// Our Threshold is 09/03/2023
			// 09/03/2023 < 09/03/2023  
		}
};

// Add Food Item | Done
// Edit Food Item | Done
// Delete Food Item 
// Search Food Item 
// Prioritise 
// DisplayWarnings  
// Display Inventory | Done

class Inventory{
	private:
		vector<FoodItem> items;
	public:
		void addFoodItems(string name, string category, int quantity, string barcode, time_t expiryDate){
			items.emplace_back(name, category, quantity, barcode, expiryDate);
		}
		
		void editFoodItems(int index, string name, string category, int quantity, string barcode, time_t expiryDate){
			if(index < items.size()){
				items[index].name = name;
				items[index].category = category;
				items[index].quantity = quantity;
				items[index].barcode = barcode;
				items[index].expiryDate = expiryDate;
				cout<<"Successfully Edited the Values at defined index\n";
			}else{
				cout<<"Index is out of Range\n";
			}
		}
		
		void Display(){
			cout<<"Our Inventory\n";
			cout<<"Name-Category-Quantity-Barcode-Expiry Date \n";
			for(auto item:items){
				cout<<item.name<<" - "<<item.category<<" - "<<item.quantity<<" - "<< item.barcode<< " - " <<asctime(localtime(&item.expiryDate))<<endl;
			}
		}
};

int main(){
	Inventory inventory;	
	inventory.addFoodItems("Mangoo", "Fruit", 3, "#b1234" ,time(NULL) + 5*24*60*60);
	inventory.addFoodItems("Milk", "Diary", 2, "#b1234" , time(NULL) + 2*24*60*60);
	inventory.addFoodItems("Banana", "Fruit", 5, "#b1234" , time(NULL) + 7*24*60*60);
	inventory.Display();
	cout<<endl;
	inventory.editFoodItems(7, "Apple", "Fruit", 5, "#b3245", time(NULL) + 6*24*60*60);
	inventory.Display();
}
