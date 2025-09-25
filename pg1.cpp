#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Stock {
private:
    string stockName;
    string stockSymbol;
    double currentPrice;
    int volume;


public:
   
    Stock(string name, string symbol, double price, int vol) {
        stockName = name;
        stockSymbol = symbol;
        currentPrice = price;
        volume = vol;
    }


    void displayStockInfo() const {
       
        cout << "Stock Name   : " << stockName << endl;
        cout << "Stock Symbol : " << stockSymbol << endl;
        cout << "Price (INR)  : " << currentPrice << endl;
        cout << "Volume       : " << volume << endl;
        
    }


   
    string getSymbol() const {
        return stockSymbol;
    }


   
    void updatePrice(double newPrice) {
        currentPrice = newPrice;
    }


  
    void updateVolume(int newVolume) {
        volume = newVolume;
    }
};


int findStockIndexBySymbol(const vector<Stock>& stocks, const string& symbol) {
    for (size_t i = 0; i < stocks.size(); ++i) {
        if (stocks[i].getSymbol() == symbol)
            return i;
    }
    return -1;
}


int main() {
    vector<Stock> stocks;
    int choice;


    do {
        cout << "\n NSE Stock Management Menu \n";
        cout << "1. Add New Stock\n";
        cout << "2. Display All Stocks\n";
        cout << "3. Update Stock Price\n";
        cout << "4. Update Stock Volume\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;


        switch (choice) {
            case 1: {
                string name, symbol;
                double price;
                int vol;
                cout << "\nEnter Stock Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Stock Symbol: ";
                getline(cin, symbol);
                cout << "Enter Current Price: ";
                cin >> price;
                cout << "Enter Volume: ";
                cin >> vol;
                stocks.push_back(Stock(name, symbol, price, vol));
                cout << "Stock added successfully.\n";
                break;
            }


            case 2: {
                if (stocks.empty()) {
                    cout << "No stocks available.\n";
                } else {
                    cout << "\n--- All Stocks ---\n";
                    for (const auto& stock : stocks) {
                        stock.displayStockInfo();
                    }
                }
                break;
            }


            case 3: {
                string symbol;
                double newPrice;
                cout << "\nEnter Stock Symbol to Update Price: ";
                cin.ignore();
                getline(cin, symbol);
                int index = findStockIndexBySymbol(stocks, symbol);
                if (index != -1) {
                    cout << "Enter New Price: ";
                    cin >> newPrice;
                    stocks[index].updatePrice(newPrice);
                    cout << "Price updated successfully.\n";
                } else {
                    cout << "Stock symbol not found.\n";
                }
                break;
            }


            case 4: {
                string symbol;
                int newVolume;
                cout << "\nEnter Stock Symbol to Update Volume: ";
                cin.ignore();
                getline(cin, symbol);
                int index = findStockIndexBySymbol(stocks, symbol);
                if (index != -1) {
                    cout << "Enter New Volume: ";
                    cin >> newVolume;
                    stocks[index].updateVolume(newVolume);
                    cout << "Volume updated successfully.\n";
                } else {
                    cout << "Stock symbol not found.\n";
                }
                break;
            }


            case 5: {
                cout << "Exiting program. Thank you!\n";
                break;
            }


            default:
                cout << "Invalid choice. Please try again.\n";
        }


    } while (choice != 5);


    return 0;
}
