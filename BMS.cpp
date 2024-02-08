#include <bits/stdc++.h>
using namespace std;

// single personal account manager class
class BankAccount{
private:
    string Name;
    int AccountNo;
    float Balance;

public:
    BankAccount()
    {

    }
    BankAccount(string name, int accntNo, float bal )
    {
        Name=name;
        AccountNo=accntNo;
        Balance=bal;
    }
    string getName()
    {
        return Name;
    }
    int  getAccountNo()
    {
        return AccountNo;
    }
    float getBalance()
    {
        return Balance;
    }
    void Deposit(float Amount)
    {
        Balance=Balance+Amount;
        cout<<"\t\t"<<Amount<<" Credited in  Account "<<AccountNo<<endl;
        cout<<"\t\t"<<"Current balance "<<Balance<<endl;
    }
    void Withdraw(float Amount)
    {
        if(Balance>=Amount)
        {
            Balance=Balance-Amount;
            cout<<"\t\t"<<Amount<<" Debited from Account "<<AccountNo<<endl;
            cout<<"\t\t"<<"Current balance "<<Balance<<endl;
        }
        else
        {
            cout<<"\t\t"<<"Insufficient balance"<<endl;
        }
    }

};

// all accounts store and manage class
class BankManagement
{
private:
    vector<BankAccount> Accounts;

public:
    void AddAccount(string Name, int AccountNo,float Balance)
    {
        Accounts.push_back(BankAccount(Name,AccountNo, Balance));
    }
    void showAllAccounts()
    {
        cout<<endl;
        cout<<"\t\t\t All Account Holders "<<endl;
        cout<<endl;
        cout<<"\t\t"<<left<<setw(10)<<"Name"<<left<<setw(10)<<"Account No."<<left<<setw(10)<<"Balance"<<endl;
        for(int i = 0; i<Accounts.size();i++){
            cout<<"\t\t"<<left<<setw(10)<<Accounts[i].getName()<<left<<setw(10)<<Accounts[i].getAccountNo()<<left<<setw(10)<<Accounts[i].getBalance()<<endl;
        }
    }

    void searchAccount(int AccountNo)
    {
        int found=false;
        for(int i = 0; i<Accounts.size();i++){
            if(Accounts[i].getAccountNo()==AccountNo){
            found=true;
            cout<<endl;
            cout<<"\t\t\tAccount Details "<<endl;
            cout<<endl;
            cout<<"\t\t"<<left<<setw(10)<<"Name"<<left<<setw(10)<<"Account No."<<left<<setw(10)<<"Balance"<<endl;
            cout<<"\t\t"<<left<<setw(10)<<Accounts[i].getName()<<left<<setw(10)<<Accounts[i].getAccountNo()<<left<<setw(10)<<Accounts[i].getBalance()<<endl;
            }
        }
        if(!found) cout<<"\t\t!!Account not found"<<endl;
    }
    BankAccount* findAccount(int Acc)
    {
        for(int i=0;i<Accounts.size();i++)
        {
            if(Accounts[i].getAccountNo()==Acc)
            {
                searchAccount(Acc);
                return &Accounts[i];
            }

        }
        BankAccount *acnt=new BankAccount();
        return acnt;
    }

};

void LandingPage()
{
        cout<<endl;
        cout<<"\t\t-- BANK MANAGEMENT SYSTEM --"<<endl;
		cout<<"\t\t\tMain Menu"<<endl;
		cout<<"\t\t 1. Create New Account"<<endl;
		cout<<"\t\t 2. Show All Account"<<endl;
		cout<<"\t\t 3. Search Account"<<endl;
		cout<<"\t\t 4. Deposit Money"<<endl;
		cout<<"\t\t 5. Withdraw Money"<<endl;
		cout<<"\t\t 6. Exit"<<endl;
		cout<<"\t\t-------------------------------"<<endl;
}



 void createAccount(BankManagement &Bank)
 {
        string name;
        int accountNum;
        double balance;
        cout<<"\t\tEnter Name :";
        cin>>name;
        cout<<"\t\tEnter Account Number :";
        cin>>accountNum;
        cout<<"\t\tEnter Initial Balance :";
        cin>>balance;
        Bank.AddAccount(name,accountNum,balance);
        cout<<"\t\t----Account Created Successfully...."<<endl;

 }

int main()
{
    BankManagement Bank;
    int choice;
    int op=1;
    do
    {
        system("cls");
        LandingPage();
        cout<<"\t\tEnter Your Choice :";
        cin>>choice;
        switch(choice){
            case 1:{
                createAccount(Bank);
                break;
                }
            case 2:
                {
                Bank.showAllAccounts();
                break;
                }
            case 3:
                {
                    int AccnNo;
                    cout<<"\t\tEnter Account Number: ";
                    cin>>AccnNo;
                    Bank.searchAccount(AccnNo);
                    break;
                }
            case 4:
                {
                    int  AccntNo;
                    float amount;
                    cout<<"\t\tEnter Account No. ";
                    cin>>AccntNo;
                    cout<<endl;
                    cout<<"\t\t"<<AccntNo<<"  Before"<<endl;
                    BankAccount *account=Bank.findAccount(AccntNo);
                    cout<<endl;
                    cout<<"\t\t"<<account->getAccountNo()<<"  After"<<endl;
                    if(account!=NULL)
                    {
                        cout<<"\t\tEnter amount to deposit: ";
                        cin>>amount;
                        account->Deposit(amount);
                    }
                    else
                    {
                        cout<<"\t\t Invalid Account Number"<<endl;
                    }
                    break;
                }
            case 5:
                {
                    int  accntNo;
                    float amount;
                    cout<<"\t\tEnter Account No. ";
                    cin>>accntNo;
                    BankAccount* account=Bank.findAccount(accntNo);
                    if(account!=NULL)
                    {
                        cout<<"\t\tEnter amount to Withdraw: ";
                        cin>>amount;
                        account->Withdraw(amount);
                    }
                    else
                    {
                        cout<<"\t\t Invalid Account Number"<<endl;
                    }
                    break;
                }
            case 6:
                {
                    exit(1);
                    break;
                }

        }
        cout<<endl;
        cout<<"\tCountinue or Exit [1/0] ? ";
        cin>>op;
    }
    while(op==1);
    cout<<endl;
    return 0;
}