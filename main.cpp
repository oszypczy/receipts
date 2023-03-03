#include "product.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <map>

const int receiptLength = 40;

int getProductPrice(std::string name, int amount) {
    std::map<std::string, int> productsDatabase;
    productsDatabase["Bananas"] = 499;
    productsDatabase["Oranges"] = 800;
    productsDatabase["Milk"] = 315;
    if (productsDatabase.count(name)>=1) {
        return amount * productsDatabase[name];
    }
    return 0;
}

std::vector<int> getSplitPrice(int price){
    int priceZl = price / 100;
    int priceGr = price % 100;
    std::vector<int> splitPrice = {priceZl, priceGr};
    return splitPrice;
}

std::string formatPrice(std::vector<int>& price){
    std::stringstream ss;
    ss << std::to_string(price[0]) + "." << std::setw(2) << std::setfill('0') << std::to_string(price[1]) << " zł";
    return ss.str();
}

int printRow(std::string name, int amount, int index){
    int price = getProductPrice(name, amount);
    std::vector<int> splittedPrice = getSplitPrice(price);
    std::cout << std::setw(4) << index << ". " << std::setw(receiptLength) << std::left << name << std::right << formatPrice(splittedPrice) << std::endl;
    return price;
}

std::_Put_time<char> getDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_time);
    return std::put_time(now_tm, "%d.%m.%Y, %H:%M");
}

void printReceipt(std::vector<Product>& receipt){
    if (receipt.size() == 0) {
        std::cout << "The receipt is empty.";
    } else {
        std::cout << "Date: " << getDate() << std::endl;
        int index = 1;
        int totalPrice = 0;
        for (auto& product : receipt) {
            totalPrice += printRow(product.getProductName(), product.getProductQuantity(), index);
            ++index;
        }
        std::cout << std::string(receiptLength+10, '-') << std::endl;
        std::vector<int> splitPrice = getSplitPrice(totalPrice);
        std::cout << std::setw(receiptLength) << std::left << "Total:" << std::right << formatPrice(splitPrice);
    }
}

int main(){
    std::vector<Product> myReceipt = {
        Product("Bananas", 3),
        Product("Milk", 2),
        Product("Oranges", 3)
    };
    printReceipt(myReceipt);
    return 0;
}
