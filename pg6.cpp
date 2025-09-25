#include <iostream> 
#include <vector> 
using namespace std; 
class DomainTrading { 
private: 
 vector<string> domains; // store registered domains 
public: 
 // Register with default 1-year plan 
 void registerDomain(string name) { 
 domains.push_back(name); 
 cout << "[Registered] " << name 
 << " for 1 year at $10.\n"; 
 } 
 // Register with given duration 
 void registerDomain(string name, int years) {  domains.push_back(name); 
 cout << "[Registered] " << name 
 << " for " << years 
 << " years at $" << years * 10 << ".\n";  } 
 // Register with duration and custom price 
 void registerDomain(string name, int years, double price) {  domains.push_back(name); 
 cout << "[Registered] " << name 
 << " for " << years 
 << " years at custom price $" << price << ".\n";  } 
 // Show all registered domains 
 void showDomains() { 
 cout << "\n--- Domain Portfolio ---\n"; 
 for (auto &d : domains) { 
 cout << "world " << d << endl; 
 } 
 } 
};
int main() { 
 DomainTrading trader; 
 trader.registerDomain("techverse.com");  trader.registerDomain("cloudhub.net", 3);  trader.registerDomain("premiumai.io", 5, 250.0); 
 trader.showDomains(); 
 return 0; 
}
