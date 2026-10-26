#include <iostream>
using namespace std;

// Parent class
class Payment
{
public:
    virtual void makePayment()
    {
        cout << "Processing a general payment."
             << endl;
    }

    virtual ~Payment() = default;
};

// First derived class
class CashPayment : public Payment
{
public:
    void makePayment() override
    {
        cout << "Payment made using cash."
             << endl;
    }
};

// Second derived class
class MobileMoneyPayment : public Payment
{
public:
    void makePayment() override
    {
        cout << "Payment made using mobile money."
             << endl;
    }
};

int main()
{
    // Create derived-class objects
    CashPayment cash;
    MobileMoneyPayment mobileMoney;

    // Create a base-class pointer
    Payment *payment;

    // Point to the CashPayment object
    payment = &cash;

    cout << "CASH PAYMENT:" << endl;
    payment->makePayment();

    // Point to the MobileMoneyPayment object
    payment = &mobileMoney;

    cout << "\nMOBILE MONEY PAYMENT:" << endl;
    payment->makePayment();

    return 0;
}