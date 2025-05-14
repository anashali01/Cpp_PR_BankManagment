// Bank_Management
#include <iostream>
#include <vector>
using namespace std;

class Bank
{

private:
    string acc_holder_name;
    int acc_no;
    double balance;

protected:
    string acc_type;

public:
    int get_acc_no()
    {
        return acc_no;
    }
    void set_acc_no(int acc_no)
    {
        this->acc_no = acc_no;
    }

    string get_acc_holder_name()
    {
        return acc_holder_name;
    }
    void set_acc_holder_name(string holder_name)
    {
        this->acc_holder_name = holder_name;
    }

    double get_balance()
    {
        return balance;
    }
    void set_balance(double balance)
    {
        this->balance = balance;
    }

    string get_acc_type()
    {
        return acc_type;
    }

    virtual void deposit(double amount) {}
    virtual void withdraw(double amount) {}
    virtual double calculate_interest()
    {
        return 0.0;
    }

    void get_acc_data()
    {
        cout << "Account Number : ";
        cin >> acc_no;
        cout << "Account Holder Name : ";
        cin >> acc_holder_name;
        cout << "Account balance :";
        cin >> balance;
    }
    void show_acc_data()
    {
        cout << "Account Number : " << acc_no << endl;
        cout << "Account Holder Name : " << acc_holder_name << endl;
        cout << "Account balance : " << balance << endl;
        cout << "Account Type : " << acc_type << endl;
    }
    virtual ~Bank() {}
};

class Saving_Account : public Bank
{
private:
    double interest_rate;

public:
    Saving_Account()
    {
        acc_type = "Saving Account";
    }

    double calculate_interest()
    {
        int date;
        cout << "Enter the number of days : ";
        cin >> date;
        interest_rate = (get_balance() * 0.03 * date) / 365;
        set_balance(get_balance() + interest_rate);
        cout << "interest for " << date << " days is : " << interest_rate << endl;
        cout << "Total balance after interest is : " << get_balance() << endl;
        return interest_rate;
    }

    void deposit(double amount)
    {
        set_balance(get_balance() + amount);
        cout << "Total balance after deposit is : " << get_balance() << endl;
    }
    void withdraw(double amount)
    {
        if (get_balance() >= amount)
        {
            set_balance(get_balance() - amount);
            cout << "Total balance after withdraw is : " << get_balance() << endl;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
};

class CheckingAccount : public Bank
{
private:
    double overdraft_limit = 100000;

public:
    CheckingAccount()
    {
        acc_type = "Checking Account";
    }

    void deposit(double amount)
    {
        set_balance(get_balance() + amount);
        cout << "Total balance after deposit is : " << get_balance() << endl;
    }

    void withdraw(double amount)
    {
        if (get_balance() + overdraft_limit >= amount)
        {
            set_balance(get_balance() - amount);
            cout << "Total balance after withdraw is : " << get_balance() << endl;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
};

class FixedDeposit : public Bank
{
private:
    double interest_rate;

public:
    FixedDeposit()
    {
        acc_type = "Fixed Deposit";
    }

    double calculate_interest()
    {
        int date;
        cout << "Enter the number of days : ";
        cin >> date;
        interest_rate = (get_balance() * 0.05 * date) / 365;
        set_balance(get_balance() + interest_rate);
        cout << "interest for " << date << " days is : " << interest_rate << endl;
        cout << "Total balance after interest is : " << get_balance() << endl;
        return interest_rate;
    }

    void deposit(double amount)
    {
        cout << "You cannot deposit in Fixed Deposit account" << endl;
    }

    void withdraw(double amount)
    {
        cout << "You cannot withdraw from Fixed Deposit account" << endl;
    }
};

int main()
{
    
    int choice;
    Saving_Account s_acc;
    CheckingAccount c_acc;
    FixedDeposit f_acc;

    do
    {
        cout << "==========================" << endl;
        cout << "Bank Management System" << endl;
        cout << "==========================" << endl;
        cout << "1. Add New Account" << endl;
        cout << "2. show All Data" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Calculate Interest" << endl;
        cout << "6. Exit" << endl;
        cout << "==========================" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cout << "==========================" << endl;
        switch (choice)
        {
        case 1:
        {
            int acc_type;
            cout << "Select Account Type" << endl;
            cout << "1. Saving Account" << endl;
            cout << "2. Checking Account" << endl;
            cout << "3. Fixed Deposit" << endl;
            cout << "Enter your choice : ";
            cin >> acc_type;

            if (acc_type == 1)
            {
                s_acc.get_acc_data();
                cout<<"Account Created Successfully"<<endl;
            }
            else if (acc_type == 2)
            {
                c_acc.get_acc_data();
            }
            else if (acc_type == 3)
            {
                f_acc.get_acc_data();
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
        }
        break;

        case 2:
            cout << "Choose Account Type" << endl;
            cout << "1. Saving Account" << endl;
            cout << "2. Checking Account" << endl;
            cout << "3. Fixed Deposit" << endl;
            cout << "Enter your choice : ";
            cin >> choice;
            if (choice == 1)
            {
                s_acc.show_acc_data();
            }
            else if (choice == 2)
            {
                c_acc.show_acc_data();
            }
            else if (choice == 3)
            {
                f_acc.show_acc_data();
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
            break;

        case 3:
            int acc_no;
            double amount;
            cout << "Enter Account Number : ";
            cin >> acc_no;
            cout << "Enter Amount : ";
            cin >> amount;
            cout << "Choose Account Type" << endl;
            cout << "1. Saving Account" << endl;
            cout << "2. Checking Account" << endl;
            cout << "3. Fixed Deposit" << endl;
            cout << "Enter your choice : ";
            cin >> choice;
            if (choice == 1)
            {
                s_acc.set_acc_no(acc_no);
                s_acc.deposit(amount);
            }
            else if (choice == 2)
            {
                c_acc.set_acc_no(acc_no);
                c_acc.deposit(amount);
            }
            else if (choice == 3)
            {
                f_acc.set_acc_no(acc_no);
                f_acc.deposit(amount);
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
            break;

        case 4:
            cout << "Enter Account Number : ";
            cin >> acc_no;
            cout << "Enter Amount : ";
            cin >> amount;
            cout << "Choose Account Type" << endl;
            cout << "1. Saving Account" << endl;
            cout << "2. Checking Account" << endl;
            cout << "3. Fixed Deposit" << endl;
            cout << "Enter your choice : ";
            cin >> choice;
            if (choice == 1)
            {
                s_acc.set_acc_no(acc_no);
                s_acc.withdraw(amount);
            }
            else if (choice == 2)
            {
                c_acc.set_acc_no(acc_no);
                c_acc.withdraw(amount);
            }
            else if (choice == 3)
            {
                f_acc.set_acc_no(acc_no);
                f_acc.withdraw(amount);
            }
            else
            {
                cout << "Invalid choice" << endl;
            }

            break;

        case 5:
            cout << "Enter Account Number : ";
            cin >> acc_no;
            cout << "Choose Account Type For Interest" << endl;
            cout << "1. Saving Account" << endl;
            cout << "2. Checking Account" << endl;
            cout << "3. Fixed Deposit" << endl;
            cout << "Enter your choice : ";
            cin >> choice;
            if (choice == 1)
            {
                s_acc.set_acc_no(acc_no);
                s_acc.calculate_interest();
            }
            else if (choice == 2)
            {
                c_acc.set_acc_no(acc_no);
                c_acc.calculate_interest();
            }
            else if (choice == 3)
            {
                f_acc.set_acc_no(acc_no);
                f_acc.calculate_interest();
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 6);
    cout << "Thank you for using Bank Management System" << endl;
    cout << "Have a nice day!" << endl;

    return 0;
}