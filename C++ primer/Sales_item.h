#ifndef SALESITEM_H
#define SALESITEM_H

#include <iostream>
#include <string>

class Sales_item {
    // Non-member Sales_item interface functions
    friend std::istream& operator>>(std::istream&, Sales_item&);
    friend std::ostream& operator<<(std::ostream&, const Sales_item&);
    friend Sales_item operator+(const Sales_item&, const Sales_item&);

public:
    // Constructors
    Sales_item() = default;
    Sales_item(const std::string& book) : isbn(book), units_sold(0), revenue(0.0) { }
    Sales_item(std::istream& is) { is >> *this; }

    // Member functions
    std::string get_isbn() const { return isbn; }
    unsigned get_units_sold() const { return units_sold; }
    double get_revenue() const { return revenue; }
    double avg_price() const;

    Sales_item& operator+=(const Sales_item&);

private:
    std::string isbn;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// Implementation of member functions
inline double Sales_item::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

// Implementation of non-member functions
inline bool compareIsbn(const Sales_item& lhs, const Sales_item& rhs) {
    return lhs.get_isbn() == rhs.get_isbn();
}

std::istream& operator>>(std::istream& in, Sales_item& item) {
    double price;
    in >> item.isbn >> item.units_sold >> price;
    if (in)
        item.revenue = item.units_sold * price;
    else
        item = Sales_item(); // Input failed, reset item to default state
    return in;
}

std::ostream& operator<<(std::ostream& out, const Sales_item& item) {
    out << item.get_isbn() << " " << item.get_units_sold() << " " << item.get_revenue() << " " << item.avg_price();
    return out;
}

Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs) {
    Sales_item sum = lhs;
    sum += rhs;
    return sum;
}

Sales_item& Sales_item::operator+=(const Sales_item& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

#endif
