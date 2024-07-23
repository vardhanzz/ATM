#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class atm{
    private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;
    public:
    void setData(long int account_No_a,string name_a,int PIN_a,double balance_a,string mobile_No_a)
    {
        account_No=account_No_a;
        PIN=PIN_a;
        balance=balance_a;
        mobile_No=mobile_No_a;
        name=name_a;
    }
    long int getAccountNo(){
        return account_No;
    }
    string getName(){
        return name;

    }
    int getPIN(){
        return PIN;
    }
    double getBalance(){
        return balance;

    }
    string getMobileNo(){
        return mobile_No;
    }
    void setMobile(string mob_prev,string mob_new){
        if(mob_prev==mobile_No)
        {
            mobile_No=mob_new;
            cout<<endl<<"successfully updated mobile no.";
            _getch();
        
        }
        else{
            cout<<endl<<"incorrect old mobile no";
        }
    }
    void cashWithDraw(int amount_a){
        if(amount_a>0 && amount_a<balance){
            balance=balance-amount_a;
            cout<<endl<<"please collect your cash";
            cout<<endl<<"Available balance :"<<balance;
            _getch();

        }
        else {
            cout<<endl<<"INVALID input or insufficient balance";
            _getch();
        }
    }
};

int main(){
    int choice=0;
    int enterPIN;
    long int enterAccountNo;
    system("cls");
    atm user1;
    user1.setData(1234567,"Tim",1111,45000.90,"6387470090");
    do{
        system("cls");
        cout<<endl<<"***WELCOME TO ATM***"<<endl;
        cout<<"Enter your Account No";
        cin>>enterAccountNo;
        cout<<endl<<"Enter PIN ";
        cin>>enterPIN;
        if((enterAccountNo==user1.getAccountNo()) && (enterPIN==user1.getPIN()))
        {
            do{
                int amount =0;
                string oldMobileNo,newMobileNo;
                system("cls");
                cout<<endl<<"***Welcome to Atm***"<<endl;
                cout<<endl<<"Select options ";
                cout<<endl<<"1. check balance";
                cout<<endl<<"2. cash withdrawl";
                cout<<endl<<"3. show user details";
                cout<<endl<<"4. update mobile no.";
                cout<<endl<<"5. exit"<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                    cout<<endl<<"your bank balance is :"<<user1.getBalance();
                    _getch();
                    break;
                    case 2:
                    cout<<endl<<"enter the amount :";
                    cin>>amount;
                    user1.cashWithDraw(amount);
                    break;
                    case 3:
                    cout<<endl<<"***User details are -";
                    cout<<endl<<"> Account No"<<user1.getAccountNo();
                      cout<<endl<<"> Name"<<user1.getName();
                  cout<<endl<<"> Balance"<<user1.getBalance();
                  cout<<endl<<"> Mobile No"<<user1.getMobileNo();
                  _getch();
                  break;
                  case 4:
                  cout<<endl<<"Enter old mobile no. ";
                  cin>>oldMobileNo;
                  cout<<endl<<"Enter new mobile no. ";
                  cin>>newMobileNo;
                  user1.setMobile(oldMobileNo,newMobileNo);
                  break;
                  case 5:
                  exit(0);
                  default:
                  cout<<endl<<"enter valid data !!!";
                

            
                }
               


            } while(1);
        }
    }while(1);
    return 0;
}