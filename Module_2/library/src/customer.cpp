#include "customer.hpp"
#include <iostream>
#include "book.hpp"
/* Customer:
    * the constructor of the Customer class, takes the following parameters:
    * - the customer's name (reference to const string), 
    * - the customer number (reference to const string).
    */
Customer::Customer(const string &customer_name, const string &customer_number)
{
    name_ = customer_name;
    id_ = customer_number;
}

/* GetName:
    * returns the Customer's name as a string, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
string Customer::GetName() const
{
    return name_;
}

/* GetID:
    * returns the Customer's customer number as a string, takes no parameters. 
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
string Customer::GetID() const
{
    return id_;
}

/* GetLoanAmount:
    * returns the Customer's number of loans as an int, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
int Customer::GetLoanAmount() const
{
    return loaned_book.size();
}

/* GetLoans:
    * returns the Customer's loans as a vector<Book>, takes no parameters.
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
std::vector<Book> Customer::GetLoans() const
{
    return loaned_book;
}

/* LoanBook:
    * loans a book for the customer
    * takes a reference to a book as a parameter and returns the result of loaning (from Book loan-function).
    */
bool Customer::LoanBook(Book &book)
{
    bool loan = book.Loan();
    if (loan)
        loaned_book.push_back(book);
    return loan;
}

/* ReturnBook:
    * returns a book from the customer
    * takes a reference to a book as a parameter and returns nothing.
    */
void Customer::ReturnBook(Book &book)
{

    for (vector<Book>::size_type it = 0; it < loaned_book.size(); it++)
    {
        if (loaned_book[it].GetISBN() == book.GetISBN())
        {
            loaned_book.erase(loaned_book.begin() + it);
            break;
        }
    }
    book.Restore();
}

/* Print:
    * prints the customer's information to the standard output stream.
    * The function takes no parameters and returns nothing. 
    * The output format should be like the following (for 2 loans):
Customer: <name>, <customer_id>, has <number_of_loans> books on loan:\n
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
void Customer::Print() const
{
    cout << "Customer: " << GetName() << ", "
         << GetID() << ", "
         << "has " << GetLoans().size() << " books on loan:" << endl;

    for (vector<Book>::size_type it = 0; it < loaned_book.size(); it++)
    {
        cout << "- Book: " << loaned_book[it].GetName() << ", "
             << "author: " << loaned_book[it].GetAuthor() << ", "
             << "ISBN: " << loaned_book[it].GetISBN() << ", "
             << "loaned " << (loaned_book[it].GetStatus() ? "true" : "false") << ", "
             << "due date: " << loaned_book[it].GetDueDate().day << "." << loaned_book[it].GetDueDate().month << "." << loaned_book[it].GetDueDate().year << endl;
    }
}
