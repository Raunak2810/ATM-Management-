#include <iostream>
using namespace std;
class AtmManagement {
    private:
      int balance;
      int pin;
    public:
       AtmManagement(){
            pin = 1234;
           balance = 100000;
    } 
    bool verifyPin(int enteredPin) {
    return enteredPin == pin;
    }
    void checkBalance() {
    cout << "your Current Balance: Rs" << balance << endl;
   }
   void depositemoney(int amount) {
      if (amount > 0) {
        balance += amount;
        cout << "Successfully deposited / rashi jama ho gai" << amount << endl;
    }
    else {
        cout << "Invalid deposit amount/ paryapt rashi nhi hai " << endl;
      }
   }
   void withdrawmoney(int amount) {
       if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Successfully withdrow/ rashi nikal li gai" << amount << endl;
       } 
       else {
        cout << "Invalid withdrawal amount or insufficient balance/paryapt rashi nahi hai" << endl;
       }
    }
    void changepin(int newpin) {
       if (newpin >= 1000 && newpin <= 9999) {
        pin = newpin;
        cout << "PIN successfully changed/pin badal gaya" << endl;
       }
       else {
        cout << "Invalid PIN format. PIN should be a 4-digit number./sahi pin nahi hai. pin 4 digit hona chahiye" << endl;
    }
    }
};
int main() {
AtmManagement atm;
int enteredPin;
cout << "Enter your PIN:/ apna pin daalo: ";
cin >> enteredPin;
if (!atm.verifyPin(enteredPin)) {
    cout << "Incorrect PIN. Access denied./ apka pin galat hai" << endl;
    return 0;
}
int choice;
do {
    cout << "\nATM Menu:\n";
    cout << "1. Check Balance/kripya apna balance dekhein\n";
    cout << "2. Deposit Money/ rashi jama karein\n";       
    cout << "3. Withdraw Money/ rashi nikalein\n";
    cout << "4. Change PIN/ pin badalein\n";
    cout << "5. Exit/ dhanyawad\n";
    cout << "Enter your choice: / apna pasand daalo: ";
    cin >> choice;
    switch (choice) {
        case 1:
            atm.checkBalance();
            break;
        case 2: {
            int amount;
            cout << "Enter amount to deposit: / rashi daalo: ";
            cin >> amount;
            atm.depositemoney(amount);
            break;
        }
        case 3: {
            int amount;
            cout << "Enter amount to withdraw: / rashi nikalo: ";
            cin >> amount;
            atm.withdrawmoney(amount);
            break;
        }
        case 4: {
            int newpin;
            cout << "Enter new 4-digit PIN: / naya 4 digit pin daalo: ";
            cin >> newpin;
            atm.changepin(newpin);      
            break;
        }
        case 5:
            cout << "Exiting. Thank you for using the ATM. / dhanyawad - apka din subh rhe " << endl;    
            break;
        default:
            cout << "Invalid choice. Please try again./ galat pasand hai. kripya dubara try karein" << endl;
    }
} while (choice != 5);
return 0;
}
