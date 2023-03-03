#include "product.h"
#include "receipt.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

const int receiptLength = 40;

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

int printRow(Product product, int index){
    int price = product.getProductPrice();
    std::vector<int> splittedPrice = getSplitPrice(price);
    std::cout << std::setw(4) << index << ". " << std::setw(receiptLength) << std::left << product.getProductName() << std::right << formatPrice(splittedPrice) << std::endl;
    return price;
}


void printReceipt(Receipt& receipt){
    if (receipt.getProductList().size() == 0) {
        std::cout << "The receipt is empty.";
    } else {
        std::cout << "Date: " << receipt.getDate() << std::endl;
        int index = 1;
        int totalPrice = 0;
        for (auto& product : receipt.getProductList()) {
            totalPrice += printRow(product, index);
            ++index;
        }
        std::cout << std::string(receiptLength+10, '-') << std::endl;
        std::vector<int> splitPrice = getSplitPrice(totalPrice);
        std::cout << std::setw(receiptLength) << std::left << "Total:" << std::right << formatPrice(splitPrice);
    }
}

int main(){
    std::vector<Product> products = {
        Product("Bananas", 3),
        Product("Milk", 2),
        Product("Oranges", 3),
        Product("Apples", 10)
    };
    Receipt myReceipt(products);
    printReceipt(myReceipt);
    return 0;
}
