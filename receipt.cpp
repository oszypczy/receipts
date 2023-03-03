#include "receipt.h"
#include <chrono>
#include <iomanip>
#include <string>
#include <sstream>


Receipt::Receipt(std::vector<Product> newProductList){
    productList = newProductList;
}

std::vector<Product> Receipt::getProductList() {
    return productList;
}

std::string Receipt::getDate(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_time);
    std::stringstream stream;
    stream << std::put_time(now_tm, "%d.%m.%Y, %H:%M");
    return stream.str();
}