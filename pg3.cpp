#include <iostream>
using namespace std;
class Stock {
private:
string symbols[3];
float prices[3];
float balance;
public:
Stock() {
symbols[0] = "AAPL";
prices[0] = 150.0;
symbols[1] = "GOOGL";
prices[1] = 2800.0;
symbols[2] = "TSLA";
prices[2] = 700.0;
balance = 5000.0;
}
void displayStocks() {
cout << "Available Stocks:\n";
for (int i = 0; i < 3; i++) {
cout << i + 1 << ". " << symbols[i] << " - $" << prices[i] << endl;
}
}
void showBalance() {
cout << "Current Balance: $" << balance << endl;
}
friend void buyStock(Stock& s, int index, int quantity);
};
void buyStock(Stock& s, int index, int quantity) {
if (index < 0 || index >= 3) {
cout << "Invalid stock index.\n";
return;
}
float total = s.prices[index] * quantity;

if (s.balance >= total) {
s.balance -= total;
cout << "Bought " << quantity << " shares of " << s.symbols[index]
<< " for $" << total << endl;
} else {
cout << "Insufficient balance to buy " << quantity << " shares.\n";
}
}
int main() {
Stock s;
s.displayStocks();
s.showBalance();
int choice, qty;
cout << "\nEnter stock number to buy (1-3): ";
cin >> choice;
cout << "Enter quantity: ";
cin >> qty;
buyStock(s, choice - 1, qty);
s.showBalance();
return 0;
}