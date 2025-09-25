#include <iostream> 
#include <string> 
using namespace std; 
class Stock { 
private: 
 string symbol;  
 double price;  
 int quantity;  
public: 
  
 Stock(string s, double p, int q) : symbol(s), price(p), quantity(q) {} 
  
 Stock& operator++() { 
 ++quantity; 
 return *this; 
 } 
  
 Stock& operator--() { 
 if (quantity > 0) { 
 --quantity; 
 } else { 
 cout << "Cannot reduce further, no stocks left.\n";  } 
 return *this; 
 } 
  
 Stock operator-() { 
 return Stock(symbol, -price, quantity); 
 } 
  
 void display() const { 
 cout << "Stock: " << symbol 
 << " | Price: $" << price 
 << " | Quantity: " << quantity << endl; 
 }
}; 
int main() { 
  
 Stock s1("AAPL", 150.50, 10); 
 cout << "Initial Stock Details:\n"; 
 s1.display(); 
  
 ++s1; 
 cout << "\nAfter buying 1 stock (++):\n";  s1.display(); 
  
 --s1; 
 cout << "\nAfter selling 1 stock (--):\n";  s1.display(); 
  
 Stock s2 = -s1; 
 cout << "\nAfter applying unary - (negating price):\n";  s2.display(); 
 return 0; 
}
