#include <iostream> 
#include <string> 
using namespace std; 
class TradingDomain { 
private: 
 string stockSymbol; 
 string market; 
 double price; 
public: 
  
 TradingDomain() { 
 stockSymbol = "UNKNOWN"; 
 market = "UNKNOWN"; 
 price = 0.0; 
 cout << "Default constructor called!" << endl;  } 
  
 TradingDomain(string symbol, string mkt, double stockPrice) {  stockSymbol = symbol; 
 market = mkt; 
 price = stockPrice; 
 cout << "Parameterized constructor called!" << endl;  } 
  
 TradingDomain(const TradingDomain &other) { 
 stockSymbol = other.stockSymbol; 
 market = other.market; 
 price = other.price; 
 cout << "Copy constructor called!" << endl;  } 
  
 void display() const { 
 cout << "Stock Symbol: " << stockSymbol << endl;  cout << "Market: " << market << endl; 
 cout << "Price: $" << price << endl;
 } 
  
 ~TradingDomain() { 
 cout << "Destructor called for trading domain: " << stockSymbol << endl; 
 } 
}; 
int main() { 
  
 TradingDomain trading1; 
 trading1.display(); 
 cout << endl; 
  
 TradingDomain trading2("AAPL", "NASDAQ", 145.30); 
 trading2.display(); 
 cout << endl; 
  
 TradingDomain trading3 = trading2; 
 trading3.display(); 
 return 0; 
}
