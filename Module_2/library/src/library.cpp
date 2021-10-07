#include <iostream>
#include "book.hpp"
#include "customer.hpp"
#include "library.hpp"

/* Library:
    * the constructor of the Library class, takes following parameters:
    *  - the library's name (const reference to string)
    */
Library::Library(const string &name)
{
    name_ = name;
}

/* GetName:
    * returns the library's name as a string, takes no parameters.
    * This function should not alter the Library object's state, in other words the function should be const.
    */
string Library::GetName() const
{
    return name_;
}
/* GetBooks:
    * returns the Library's books as a reference to a vector<Book>, takes no parameters.
    */
vector<Book> &Library::GetBooks()
{
    return books_;
}

/* GetCustomers:
    * returns the Library's customers as a reference to a vector<Customer>, takes no parameters.
    */
vector<Customer> &Library::GetCustomers()
{
    return customers_;
}

/* FindBookByName:
    * returns a Book, takes a const reference to a string as a parameter,
    * if a Book is not found, a new book with an empty strings as parameters 
    * for the name, author and isbn is returned.
    */
Book Library::FindBookByName(const string &name)
{

    for (vector<Book>::size_type it = 0; it < books_.size(); it++)
    {
        if (books_[it].GetName() == name)
        {
            return books_[it];
        }
    }

    return Book("", "", "");
}

/* FindBooksByAuthor:
    * returns a vector of Books, takes a const reference to a string as a parameter,
    * if no books are found, an empty vector is returned.
    */
vector<Book> Library::FindBooksByAuthor(const string &name)
{
    vector<Book> emptybook;
    for (vector<Book>::size_type it = 0; it < books_.size(); it++)
    {
        if (books_[it].GetAuthor() == name)
        {
            emptybook.push_back(books_[it]);
        }
    }
    return emptybook;
}

/* FindAllLoanedBooks():
    * returns a vector of Books, takes no parameters,
    * if no books are found, an empty vector is returned.
    */
vector<Book> Library::FindAllLoanedBooks()
{
    vector<Book> emptybook;
    for (vector<Book>::size_type it = 0; it < books_.size(); it++)
    {
        if (books_[it].GetStatus())
            emptybook.push_back(books_[it]);
    }
    return emptybook;
}

/* FindCustomer:
    * returns a Customer, takes a const reference to a string representing the Customer's id as a parameter,
    * if a Customer is not found, a new Customer with empty strings are parameters 
    * for name and id is returned.
    */
Customer Library::FindCustomer(const string &customerID)
{
    // vector<Customer> emptyCustomer;
    for (vector<Customer>::size_type it = 0; it < customers_.size(); it++)
    {
        if (customers_[it].GetID() == customerID)
        {
            return customers_[it];
        }
    }
    return Customer("", "");
}
