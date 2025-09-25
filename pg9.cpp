#include <iostream> 
#include <string> 
using namespace std; 
class User { 
protected: 
 string username; 
public: 
 void setUser(string name) { 
 username = name; 
 } 
 void displayUser() { 
 cout << "User: " << username << endl; 
 } 
}; 
class Product { 
protected: 
 string productName; 
 double price; 
public: 
 void setProduct(string pname, double p) { 
 productName = pname; 
 price = p; 
 } 
 void displayProduct() { 
 cout << "Product: " << productName << " | Price: $" << price << endl; 
 } 
}; 
class Trading : public User, public Product { 
public: 
 void makeTransaction() { 
 cout << "Transaction Successful!" << endl; 
 cout << username << " bought " << productName << " for $" << price << endl; 
 } 
};
int main() { 
 Trading t; 
 t.setUser("Alice"); 
 t.setProduct("Laptop", 1200.50);  t.displayUser(); 
 t.displayProduct(); 
 t.makeTransaction(); 
 return 0; 
}

