#include <iostream> 
#include <string> 
using namespace std; 
class Stock { 
private: 
 string symbol;  
 double price;  
 int quantity;  
public: 
  
 Stock(string s = "", double p = 0.0, int q = 0) 
 : symbol(s), price(p), quantity(q) {} 
  
 Stock operator+(const Stock& other) { 
 if (symbol == other.symbol && price == other.price) {  return Stock(symbol, price, quantity + other.quantity);  } else { 
 cout << "? Cannot add different stock types or mismatched prices!\n"; 
 return *this; 
 } 
 } 
  
 Stock operator-(const Stock& other) { 
 if (symbol == other.symbol && price == other.price) {  int newQty = quantity - other.quantity; 
 if (newQty < 0) newQty = 0; 
 return Stock(symbol, price, newQty); 
 } else { 
 cout << "? Cannot subtract different stock types or mismatched prices!\n"; 
 return *this; 
 } 
 } 
  
 bool operator==(const Stock& other) {
 return (symbol == other.symbol && price == other.price && quantity == other.quantity); 
 } 
  
 void display() const { 
 cout << "Stock: " << symbol 
 << " | Price: $" << price 
 << " | Quantity: " << quantity << endl; 
 } 
}; 
int main() { 
 Stock s1("AAPL", 150.50, 10); 
 Stock s2("AAPL", 150.50, 5); 
 Stock s3("TSLA", 250.75, 8); 
 cout << "Initial Stock Holdings:\n"; 
 s1.display(); 
 s2.display(); 
 s3.display(); 
  
 cout << "\nAfter Adding AAPL stocks:\n"; 
 Stock s4 = s1 + s2; 
 s4.display(); 
  
 cout << "\nAfter Selling Some AAPL stocks:\n"; 
 Stock s5 = s1 - s2; 
 s5.display(); 
  
 cout << "\nComparison Check:\n"; 
 if (s1 == s2) 
 cout << " s1 and s2 are identical holdings.\n"; 
 else 
 cout << " s1 and s2 are NOT identical holdings.\n";  
 cout << "\nTrying to add AAPL and TSLA:\n";  Stock invalid = s1 + s3; 
 return 0; 
}
