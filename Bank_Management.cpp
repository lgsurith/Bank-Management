#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <sstream> 

using namespace std;

class Bank {
private:
    string date;
    string dob;
    string email;
    vector<string> transactionHistory;
public:
	double balance;
	int age;
	string first_name;
    string last_name;
	long long acc_no;
    void CreateBankAccount();
    void UpdateBankAccount();
    void DeleteBankAccount();
    void SearchBankAccount();
    //void ListAccounts();
    void Transact();
    void BankStatement();
};

void Bank::CreateBankAccount() {
    balance = 0.0;
    cout << "--------------------------------------------------------" << endl;
    cout << "             ENTER THE GIVEN DETAILS               " << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your First Name                : ";
    cin >> first_name;
    cout << "Enter your Last Name                 : ";
    cin.ignore();
    getline(cin, last_name);
    cout << "Enter your D.O.B (in DD/MM/YYYY)     : ";
    cin >> dob;
    cout << "Enter your age                       : ";
    cin >> age;
    cout << "Enter your Email ID                  : ";
    cin >> email;
    srand((unsigned)time(NULL));
    acc_no = rand();
    cout << "--------------------------------------------------------" << endl;
    cout << "         THE ACCOUNT NUMBER          : " << acc_no << endl;
    cout << endl;
    cout << "Account " << acc_no << " has been successfully created." << endl;
    cout << endl;
    cout << "Press Enter to go to the Home Page ";
    cin.ignore();
    cin.get();
}

void Bank::UpdateBankAccount() {
    int c1;
    cout << "----------------------------------------------------" << endl;
    cout << "                 UPDATION COUNTER                   " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << " YOUR ACCOUNT NUMBER                    : " << acc_no << endl;
    cout << endl;
    cout << "What Updation do you need in " << acc_no << " ? \n";
    cout << endl;
    cout << "1) First Name                             " << endl;
    cout << "2) Last  Name                             " << endl;
    cout << "3) D.O.B                                  " << endl;
    cout << "4) Age                                    " << endl;
    cout << "5) Email ID                               " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Enter the Choice                               : ";
    cin >> c1;
    switch (c1) {
    case 1: {
        string fs;
        string copyfs = first_name;
        cout << "Enter the Updated First Name                   : ";
        cin >> fs;
        first_name = fs;
        cout << "----------------------------------------------------" << endl;
        cout << "   The Updation is successful from   " << copyfs << " ---> " << first_name << endl;
        break;
    }
    case 2: {
        string ls;
        string copyls = last_name;
        cout << "Enter the Updated Last Name                    : ";
        cin >> ls;
        last_name = ls;
        cout << "----------------------------------------------------" << endl;
        cout << "   The Updation is successful from   " << copyls << " ---> " << last_name << endl;
        break;
    }
    case 3: {
        string dob1;
        string copydob1 = dob;
        cout << "Enter the Updated D.O.B                        : ";
        cin >> dob1;
        dob = dob1;
        cout << "----------------------------------------------------" << endl;
        cout << "   The Updation is successful from   " << copydob1 << " ---> " << dob << endl;
        break;
    }
    case 4: {
        int age1;
        int copyage = age;
        cout << "Enter the Updated Age                          : ";
        cin >> age1;
        age = age1;
        cout << "----------------------------------------------------" << endl;
        cout << "   The Updation is successful from   " << copyage << " ---> " << age << endl;
        break;
    }
    case 5: {
        string email_1;
        string copyem = email;
        cout << "Enter the Updated Email                        : ";
        cin >> email_1;
        email = email_1;
        cout << "----------------------------------------------------" << endl;
        cout << "   The Updation is successful from   " << copyem << " ---> " << email << endl;
        break;
    }
    default:
        cout << "Enter Valid Options" << endl;
    }
    cout << endl;
    cout << endl;
    cout << "Press Enter to go to the Home Page ";
    cin.ignore();
    cin.get();
}
/*
void Bank::ListAccounts() {
    cout << "---------------------------------------------------------------" << endl;
    cout << "                        BANK ACCOUNTS                          " << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "   Account Number  |        Name         |  Age  |   Balance   " << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << acc_no << "    | " << (first_name + " " + last_name) << "| " << age << "  | Rs. " << fixed << setprecision(2) << balance << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Press Enter to go to the Home Page ";
    cin.ignore();
    cin.get();
}*/

void Bank::Transact() {
    string choice;
    double amt;
    cout << "---------------------------------------------------------------" << endl;
    cout << "                        BANK NAME                              " << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "ACC NO : " << acc_no << endl;
    cout << endl;
    cout << "             ------------------------------                     " << endl;
    cout << "            |                              |                    " << endl;
    cout << "            |           DEPOSIT            |                    " << endl;
    cout << "            |                              |                    " << endl;
    cout << "             ------------------------------                     " << endl;
    cout << "             ------------------------------                     " << endl;
    cout << "            |                              |                    " << endl;
    cout << "            |           WITHDRAW           |                    " << endl;
    cout << "            |                              |                    " << endl;
    cout << "             ------------------------------                     " << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Enter the action                 : ";
    cin >> choice;
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    if (choice == "deposit") {
        cout << "Enter the amount to be deposited : Rs.";
        cin >> amt;
        balance += amt;

        ostringstream oss;
        oss << fixed << setprecision(2) << amt;
        string transaction = "Credited Rs. " + oss.str();

        transactionHistory.push_back(transaction);

        cout << endl;
        cout << "Amount Rs." << amt << " has been credited to your acc  " << acc_no << "." << endl;
        cout << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "                Current Balance : Rs." << balance << endl;
    } else if (choice == "withdraw") {
        cout << "Enter the amount to be withdrawn : Rs.";
        cin >> amt;
        if (amt > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            balance -= amt;

            ostringstream oss;
            oss << fixed << setprecision(2) << amt;
            string transaction = "Debited  Rs. " + oss.str();

            transactionHistory.push_back(transaction);

            cout << endl;
            cout << "Amount Rs." << amt << " has been debited from your acc  " << acc_no << "." << endl;
            cout << endl;
            cout << "---------------------------------------------------------------" << endl;
            cout << "                Current Balance : Rs." << balance << endl;
        }
    } else {
        cout << "Please check the spelling or enter the required field alone." << endl;
    }

    cout << endl;
    cout << endl;
    cout << "Press Enter to go to the Home Page ";
    cin.ignore();
    cin.get();
}

void Bank::BankStatement() {
    cout << "---------------------------------------------------------------" << endl;
    cout << "                       BANK STATEMENT                          " << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "   Date & Time                |        Transaction Description        " << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (size_t i = 0; i < transactionHistory.size(); ++i) {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        char dt[20];
        strftime(dt, sizeof(dt), "%Y-%m-%d %H:%M:%S", ltm);

        cout << setw(27) << dt << "   | " << transactionHistory[i] << endl;
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Press Enter to go to the Home Page ";
    cin.ignore();
    cin.get();
}


void Bank::DeleteBankAccount() {
    string yn;
    cout << "---------------------------------------------------------------" << endl;
    cout << "                        BANK NAME                              " << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
    cout << " Are you sure that you want to delete your Bank Account Details" << endl;
    cout << "                        (YES/NO)                               " << endl;
    cout << endl;
    cout << "                   Enter your choice : ";
    cin >> yn;
    transform(yn.begin(), yn.end(), yn.begin(), ::tolower);
    cout << endl;
    if (yn == "y" || yn == "yes") {
        cout << "             Account " << acc_no << " has been deleted." << endl;
        first_name = "";
        last_name = "";
        dob = "";
        age = 0;
        email = "";
        balance = 0.0;
        acc_no = 0;
        transactionHistory.clear();
    } else {
        cout << "           Account Deletion Cancelled.                     " << endl;
    }
    cout << endl;
    cout << endl;
    cout << "Press Enter to go to the Home Page ";
    cin.ignore();
    cin.get();
}

int main() {
    int c;
    vector<Bank> accounts; // Store multiple user accounts
    while (1) {
        cout << "----------------------------------------" << endl;
        cout << "              BANK NAME                 " << endl;
        cout << "----------------------------------------" << endl;
        cout << endl;
        cout << "1) Create Account\n";
        cout << "2) Update Account\n";
        cout << "3) Delete Account\n";
        cout << "4) List Accounts\n";
        cout << "5) Transact (Withdraw/Deposit) \n";
        cout << "6) Bank Statement\n";
        cout << "7) Exit\n";
        cout << "----------------------------------------" << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> c;
        switch (c) {
        case 1: {
            system("cls");
            Bank newAccount;
            newAccount.CreateBankAccount();
            accounts.push_back(newAccount);
            system("cls");
            break;
        }
        case 2: {
            system("cls");
            cout << "----------------------------------------------------" << endl;
            for(int i=0;i<accounts.size();i++){
            	cout << "Account Number : " << accounts[i].acc_no << endl;
            	cout << "Account Holder : " << accounts[i].first_name << " " << accounts[i].last_name << endl;
            	cout << "----------------------------------------------------" << endl;
			}
			cout << endl;
            int accNo;
            cout << "Enter the Account Number to Update: ";
            cin >> accNo;
            bool found = false;
            for (int i = 0; i < accounts.size(); ++i) {
                if (accounts[i].acc_no == accNo) {
                    accounts[i].UpdateBankAccount();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found." << endl;
            }
            system("cls");
            break;
        }
        case 3: {
            system("cls");
            cout << "---------------------------------------------------------------" << endl;
            for(int i=0;i<accounts.size();i++){
            	cout << "Account Number : " << accounts[i].acc_no << endl;
            	cout << "Account Holder : " << accounts[i].first_name << " " << accounts[i].last_name << endl;
            	cout << "---------------------------------------------------------------" << endl;
			}
			cout << endl;
            int accNo;
            cout << "Enter the Account Number to Delete: ";
            cin >> accNo;
            for (int i = 0; i < accounts.size(); ++i) {
    			if (accounts[i].acc_no == accNo) {
        				accounts[i].DeleteBankAccount();
        				accounts.erase(accounts.begin() + i);
        				break;
    				}
				}
            system("cls");
            break;
        }
        case 4: {
    		system("cls");
    		if (accounts.empty()) {
        	cout << "No accounts found." << endl;
    		} 
			else {
        		cout << "---------------------------------------------------------------" << endl;
        		cout << "                         ACCOUNTS                              " << endl;
        		cout << "---------------------------------------------------------------" << endl;
        		for (int i = 0; i < accounts.size(); ++i) {
            			cout << "Account " << i + 1 << endl;
            			cout << "   Account Number : " << accounts[i].acc_no << endl;
            			cout << "   Name           : " << accounts[i].first_name << " " << accounts[i].last_name << endl;
            			cout << "   Age            : " << accounts[i].age << endl;
            			cout << "   Balance        : Rs. " << fixed << setprecision(2) << accounts[i].balance << endl;
            			cout << "---------------------------------------------------------------" << endl;
        		}
        	cout << endl;
        	cout << "Press Enter to return to the Home Page ";
        	cin.ignore();
        	cin.get();
    	}
    	system("cls");
    	break;
		}
		case 5: {
            system("cls");
            cout << "---------------------------------------------------------------" << endl;
            for(int i=0;i<accounts.size();i++){
            	cout << "Account Number : " << accounts[i].acc_no << endl;
            	cout << "Account Holder : " << accounts[i].first_name << " " << accounts[i].last_name << endl;
            	cout << "---------------------------------------------------------------" << endl;
			}
			cout << endl;
            int accNo;
            cout << "Enter the Account Number to Transact: ";
            cin >> accNo;
            bool found = false;
            for (int i = 0; i < accounts.size(); ++i) {
                if (accounts[i].acc_no == accNo) {
                    accounts[i].Transact();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found." << endl;
            }
            system("cls");
            break;
        }
        case 6: {
            system("cls");
            cout << "---------------------------------------------------------------" << endl;
            for(int i=0;i<accounts.size();i++){
            	cout << "Account Number : " << accounts[i].acc_no << endl;
            	cout << "Account Holder : " << accounts[i].first_name << " " << accounts[i].last_name << endl;
            	cout << "---------------------------------------------------------------" << endl;
			}
			cout << endl;
            int accNo;
            cout << "Enter the Account Number for Bank Statement: ";
            cin >> accNo;
            bool found = false;
            for (int i = 0; i < accounts.size(); ++i) {
                if (accounts[i].acc_no == accNo) {
                    accounts[i].BankStatement();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found." << endl;
            }
            system("cls");
            break;
        }
        case 7: {
            cout << "Exiting the program..." << endl;
            return 0;
        }
        default:
            cout << "Invalid choice." << endl;
            cout << endl;
        }
    }
    return 0;
}


