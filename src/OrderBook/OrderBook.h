#include <unordered_map>
#include <map>
#include <vector>
#include <cstdint>
#include <chrono>
#include <algorithm>

namespace chrono = std::chrono;

class Order final 
{
public:
    Order(int, double);

    bool operator<(const Order&) const;
    bool operator==(const Order&) const;
    bool operator>(const Order&) const;

    inline int get_qty() const;
    inline double get_price() const;
private:
    int qty;
    double price;
};

class OrderBook final 
{
public:
    OrderBook() = default;

    void print_bid() const;
    void print_ask() const;

    std::vector<Order> order_by_price() const;
private:
    std::map<chrono::time_point<chrono::system_clock>, Order> bid;
    std::map<chrono::time_point<chrono::system_clock>, Order> ask;
};