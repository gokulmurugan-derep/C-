#include <iostream>
#include <string>
using namespace std;
class TradingWebsite {
private:
string traderName;
string stockSymbol;
double stockPrice;
static int totalTrades; // Static variable to keep track of total trades

static string platformName; // Static variable for the platform name
public:
// Constructor to initialize trader details
TradingWebsite(string name, string symbol, double price) {
traderName = name;
stockSymbol = symbol;
stockPrice = price;
totalTrades++; // Increment total trades each time a new object is created

}
// Static function to get the total number of trades
static int getTotalTrades() {
return totalTrades;
}
// Static function to display the total number of trades
static void showTotalTrades() {
cout << "Total Trades on " << platformName << ": " << totalTrades
<< endl;
}
// Static function to set the platform name
static void setPlatformName(string name) {
platformName = name;
}
// Function to display trade details (non-static)
void displayTradeDetails() const {
cout << "Trader: " << traderName << endl;
cout << "Stock Symbol: " << stockSymbol << endl;
cout << "Stock Price: $" << stockPrice << endl;
}

// Destructor
~TradingWebsite() {
// Destructor does not affect static members
}
};
// Initialize static members outside the class
int TradingWebsite::totalTrades = 0;
string TradingWebsite::platformName = "Unknown Platform";
int main() {
// Setting platform name using static function
TradingWebsite::setPlatformName("TradeX");
// Creating objects of TradingWebsite (each represents a trade)
TradingWebsite trade1("John Doe", "AAPL", 145.30);
trade1.displayTradeDetails();
TradingWebsite trade2("Jane Smith", "TSLA", 730.10);
trade2.displayTradeDetails();
TradingWebsite trade3("Michael Lee", "GOOG", 2805.60);
trade3.displayTradeDetails();
cout << endl;
// Display the total number of trades using static function
TradingWebsite::showTotalTrades();
return 0;
}