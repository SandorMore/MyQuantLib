#include "OrderBook/OrderBook.h"
#include <iostream>

Order::Order(int _qty, double _price)        
{
    this->qty = _qty;
    this->price = _price;
}

bool Order::operator<(const Order& other) const
{
    return (this->price < other.get_price());
}

bool Order::operator==(const Order& other) const
{
    return other.get_price() == this->price;
}

bool Order::operator>(const Order& other) const
{
    return (this->price > other.get_price());
}

int Order::get_qty() const
{
    return qty;
}

double Order::get_price() const
{
    return price;
}

void OrderBook::print_bid() const
{
    for(const auto& [timestamp, order] : bid)
    {
        auto seconds = chrono::duration_cast<chrono::duration<double>>(timestamp.time_since_epoch()).count();

        std::cout << seconds << "\t\t" << order.get_qty() << "\t" << order.get_price() << "\n";
    }
}

void OrderBook::print_ask() const
{
    for(const auto& [timestamp, order] : ask)
    {
        auto seconds = chrono::duration_cast<chrono::duration<double>>(timestamp.time_since_epoch()).count();

        std::cout << seconds << "\t\t" << order.get_qty() << "\t" << order.get_price() << "\n";
    }
}

std::vector<Order> OrderBook::order_by_price() const
{
    std::vector<Order> orders;

    for(const auto& [timestamp, order] : bid)
    {
        orders.push_back(order);
    }

    std::sort(orders.begin(), orders.end(), [](const Order& order1, const Order& order2){return order1.get_price() < order2.get_price();});

    return orders;
}