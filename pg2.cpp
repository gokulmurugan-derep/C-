#include <iostream>
#include <string>
using namespace std;


void buyDomain(string domainName, double price = 10.0, string extension = ".com") {
    cout << "Buying domain: " << domainName << extension << endl;
    cout << "Price: $" << price << endl;
    cout << "Purchase successful!" << endl << endl;
}


void sellDomain(string domainName, double price = 15.0, string extension = ".com") {
    cout << "Selling domain: " << domainName << extension << endl;
    cout << "Listing price: $" << price << endl;
    cout << "Domain listed for sale." << endl << endl;
}


int main() {
    cout << "=== Domain Trading System ===" << endl << endl;


   
    buyDomain("mywebsite");                       
    buyDomain("techworld", 12.5);                    
    buyDomain("shoponline", 8.99, ".net");      


   
    sellDomain("coolsite");                         
    sellDomain("programmershub", 20.0);             
    sellDomain("bestdesigns", 18.0, ".org");       


    return 0;
}



