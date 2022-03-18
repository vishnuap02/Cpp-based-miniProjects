//Vishnu Abhay Parvatikar.
//cs20b1129
//inheritence Problem Related to Banking.
#include <bits/stdc++.h>
using namespace std;
int keysv = 1, keyck = 1;
class account
{
public:
    double accBal;
    int accNo;
    void creditamt(double amt)
    {
        accBal += amt;
        cout << "\n The amount Rs." << amt << " has been Credited Sucessfully .\n Total Balance : " << accBal << endl;
    }
    bool debitamt(double amt)
    {
        if (amt > accBal) //case when insufficient Balance.
        {
            cout << "\n Error : Debit Amount Exceeded Account Balance ..!";
            return false;
        }
        accBal -= amt;
        cout << "\n The amount Rs." << amt << " has been Debited Sucessfully .\n Total Balance : " << accBal << endl;
        return true;
    }
    double getBalance()
    {
        return accBal;
    }
};
class savingsAcc : public account //child class savingsAcc
{
public:
    double intRate;
    savingsAcc *next; //address pointing to next location & last one to NULL.
    savingsAcc()      //default constructor
    {
        this->accNo = 0;
        this->accBal = 0.0;
        this->intRate = 0.0;
        this->next = NULL;
    }
    savingsAcc(int ano, double bal, double interest) //parameterized constructor
    {
        this->accNo = ano;
        this->accBal = bal;
        this->intRate = interest;
        this->next = NULL;
    }
    double calculateInt()
    {
        double intRate = 10;
        return (intRate / 100) * accBal; //Assuming Time = 1 unit of time(yr).
    }
    void printSavAcc()
    {
        cout << "\n The balance : " << accBal << "\n The Interest rate: " << intRate << "\n The interest : " << calculateInt() << endl;
    }
};
class checkingAcc : public account //child class checkingAcc.
{
public:
    double feeCharged;
    checkingAcc *next; //address pointing to next location & last one to NULL.
    checkingAcc()      //default constructor
    {
        accNo = 0;
        accBal = 0.0;
        feeCharged = 0.0;
        next = NULL;
    }
    checkingAcc(int ano, double bal, double fee) //parametrized constructor
    {
        accNo = ano;
        accBal = bal;
        feeCharged = fee;
        next = NULL;
    }
    void creditCheck(int amt) //checks whther transaction is done , if done then debits fee.
    {
        bool dm;
        creditamt(amt);
        cout << "\n Fee of " << feeCharged << " is Charged For Successfull Transaction..!";
        dm = debitamt(feeCharged);
    }
    void debitCheck(int amt) //checks whther transaction is done , if done then debits fee.
    {
        bool ck;
        ck = debitamt(amt);
        cout << "\n Fee of " << feeCharged << " is Charged For Successfull Transaction..!";
        if (ck)
        {
            ck = debitamt(feeCharged);
        }
    }
};
bool searchSv(savingsAcc *head, int acno) //this function checks whether there is identical account number.
{
    bool cfs = true;
    savingsAcc *temp = head;
    while (temp != NULL)
    {
        if (temp->accNo == acno)
        {
            cfs = false;
            break;
        }
        temp = temp->next;
    }
    return cfs;
}
bool searchCk(checkingAcc *head, int acno) //this function checks whether there is identical account number.
{
    bool cfs = true;
    checkingAcc *temp = head;
    while (temp != NULL)
    {
        if (temp->accNo == acno)
        {
            cfs = false;
            break;
        }
        temp = temp->next;
    }
    return cfs;
}
int main()
{
    savingsAcc *heads = NULL;
    checkingAcc *headc = NULL;
    int ch = 1, inc, ano, cw;
    double bal, inst, fees;
    bool h;
    cout << "\n \n \n-------------###|||..VISHNU CENTRAL BANKING..|||###--------------- \n";
    cout << "\n ___________________________________________interface made by vishnu \n";
    while (ch != 10)
    {
        cout << "\n Enter your choice : \n";
        cout << "1. Open Account (Savings or Checking Account) \t 2. Credit (Savings or Checking Account) \n 3. Debit (Savings or Checking Account)";
        cout << "\t 4. Change/Update Interest rate (Savings Account) \n 5. Calculate Interest (Savings Account - Print) \t 6. Calculate and Update Interest (Savings Account - Credit)";
        cout << "\n 7. Change/Update Fee Amount (Checking Account) \t 8. Print Checking Fee (Checking Account) \n 9. Transact and Update (Checking Account - Debit) \t 10. Exit \t : \t";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n Enter 1 for saving Account :: 2 for checking Account : ";
            cin >> inc;
            if (inc == 1)
            {
                while (true) //to take Unique Account number from user.
                {
                    cout << "\n Enter Account number ,account balance and interest rate";
                    cin >> ano >> bal >> inst;
                    bool fs;
                    fs = searchSv(heads, ano);
                    if (fs)
                    {
                        savingsAcc *newnode = new savingsAcc(ano, bal, inst);
                        if (heads == NULL)
                        {
                            heads = newnode;
                        }
                        else
                        {
                            savingsAcc *temp = heads;
                            while (temp->next != NULL)
                            {
                                temp = temp->next;
                            }
                            temp->next = newnode;
                        }
                        break;
                    }
                    else
                    {
                        cout << "\n Enter another Account Number : Number Exists ..!";
                        continue;
                    }
                }
            }
            else
            {

                while (true) //to take Unique Account number from user.
                {
                    cout << "\n Enter Account number , Account balance and Fee charged : \t";
                    cin >> ano >> bal >> inst;
                    bool fs;
                    fs = searchCk(headc, ano);
                    if (fs)
                    {
                        checkingAcc *newnode = new checkingAcc(ano, bal, inst);
                        if (headc == NULL)
                        {
                            headc = newnode;
                        }
                        else
                        {
                            checkingAcc *temp = headc;
                            while (temp->next != NULL)
                            {
                                temp = temp->next;
                            }
                            temp->next = newnode;
                        }
                        break;
                    }
                    else
                    {
                        cout << "\n Enter another Account Number : Number Exists ..!";
                        continue;
                    }
                }
                break;
            case 2:
                cout << "\n Enter 1 for saving Account :: 2 for checking Account : ";
                cin >> inc;
                cw = 0;
                if (inc == 1)
                {
                    cout << "\n Enter account number : ";
                    cin >> ano;
                    savingsAcc *temp = heads;
                    while (temp != NULL)
                    {
                        if (temp->accNo == ano) //condn used to check whether Account Number Exists .
                        {
                            cw = 1;
                            cout << "\n Enter amount : ";
                            cin >> bal;
                            temp->creditamt(bal);
                            break;
                        }
                        temp = temp->next;
                    }
                    if (cw == 0) //if account doesn't Exists print This.
                    {
                        cout << "\n invalid Account Number !!";
                    }
                }
                else
                {
                    cout << "\n Enter account number : ";
                    cin >> ano;
                    checkingAcc *temp = headc;
                    while (temp != NULL)
                    {
                        if (temp->accNo == ano) //condn used to check whether Account Number Exists .
                        {
                            cw = 1;
                            cout << "\n Enter amount : ";
                            cin >> bal;
                            temp->creditCheck(bal);
                            break;
                        }
                        temp = temp->next;
                    }
                    if (cw == 0) //if account doesn't Exists print This.
                    {
                        cout << "\n invalid Account Number !!";
                    }
                }
                break;
            case 3:
                cout << "\n Enter 1 for saving Account :: 2 for checking Account : ";
                cin >> inc;
                cw = 0; //checking whether account no. is valid or not in below step.
                if (inc == 1)
                {
                    cout << "\n Enter account number : ";
                    cin >> ano;
                    savingsAcc *temp = heads;
                    while (temp != NULL)
                    {
                        if (temp->accNo == ano) //condn used to check whether Account Number Exists .
                        {
                            cw = 1;
                            h = false;
                            cout << "\n Enter amount : ";
                            cin >> bal;
                            h = temp->debitamt(bal);
                            break;
                        }
                        temp = temp->next;
                    }
                    if (cw == 0) //if account doesn't Exists print This.
                    {
                        cout << "\n invalid Account Number !!";
                    }
                }
                else
                {
                    cout << "\n Enter account number : ";
                    cin >> ano;
                    checkingAcc *temp = headc;
                    while (temp != NULL)
                    {
                        if (temp->accNo == ano) //condn used to check whether Account Number Exists .
                        {
                            cw = 1;
                            cout << "\n Enter amount : ";
                            cin >> bal;
                            temp->debitCheck(bal);
                            break;
                        }
                        temp = temp->next;
                    }
                    if (cw == 0) //if account doesn't Exists print This.
                    {
                        cout << "\n invalid Account Number !!";
                    }
                }
                break;
            case 4:
                cout << "\n Enter account number : ";
                cin >> ano;
                cw = 0;
                if (true) //this is ensure the scope of temp is within this itself to avoid redeclaration error
                {
                    savingsAcc *temp = heads;
                    while (temp != NULL)
                    {
                        if (temp->accNo == ano) //condn used to check whether Account Number Exists .
                        {
                            cw = 1;

                            cout << "\n Enter New Interest rate For S.B account : (Rate is between 0 to 100)";
                            cin >> inst;
                            temp->intRate = inst;
                            break;
                        }
                        temp = temp->next;
                    }
                    if (cw == 0) //if account doesn't Exists print This.
                    {
                        cout << "\n invalid Account Number !!";
                    }
                }
                break;
            case 5:
                cout << "\n Enter account number : ";
                cin >> ano;
                cw = 0;
                if (true) //this is ensure the scope of temp is within this itself to avoid redeclaration error
                {
                    savingsAcc *temp = heads;
                    while (temp != NULL)
                    {
                        if (temp->accNo == ano) //condn used to check whether Account Number Exists .
                        {
                            cw = 1;
                            inst = temp->calculateInt();
                            cout << "\n The interest Amount is : " << inst;
                            temp->printSavAcc();
                            break;
                        }
                        temp = temp->next;
                    }
                    if (cw == 0) //if account doesn't Exists print This.
                    {
                        cout << "\n invalid Account Number !!";
                    }
                }
                break;
            case 6:
                cout << "\n Enter account number : ";
                cin >> ano;
                cw = 0;
                if (true) //this is ensure the scope of temp is within this itself to avoid redeclaration error
                {
                    savingsAcc *temp = heads;
                    while (temp != NULL)
                    {
                        if (temp->accNo == ano) //condn used to check whether Account Number Exists .
                        {
                            cw = 1;
                            inst = temp->calculateInt();
                            cout << "\n The interest Amount is : " << inst;
                            temp->creditamt(inst);
                            break;
                        }
                        temp = temp->next;
                    }
                    if (cw == 0) //if account doesn't Exists print This.
                    {
                        cout << "\n invalid Account Number !!";
                    }
                }
                break;
            case 7:
                cw = 0;
                cout << "\n Enter account number : ";
                cin >> ano;
                if (true) //this is ensure the scope of temp is within this itself to avoid redeclaration error
                {
                    checkingAcc *temp = headc;
                    while (temp != NULL)
                    {
                        if (temp->accNo == ano) //condn used to check whether Account Number Exists .
                        {
                            cw = 1;
                            cout << "\n Enter New Fees Charged per Transaction Amount  : ";
                            cin >> inst;
                            temp->feeCharged = inst;
                            break;
                        }
                        temp = temp->next;
                    }
                    if (cw == 0) //if account doesn't Exists print This.
                    {
                        cout << "\n invalid Account Number !!";
                    }
                }
                break;
            case 8:
                cw = 0;
                cout << "\n Enter account number : ";
                cin >> ano;
                if (true) //this is ensure the scope of temp is within this itself to avoid redeclaration error
                {
                    checkingAcc *temp = headc;
                    while (temp != NULL)
                    {
                        if (temp->accNo == ano) //condn used to check whether Account Number Exists .
                        {
                            cw = 1;
                            cout << "\n The Fees Charged per Transaction for Account number  : " << ano << " is : " << temp->feeCharged;
                            break;
                        }
                        temp = temp->next;
                    }
                    if (cw == 0) //if account doesn't Exists print This.
                    {
                        cout << "\n invalid Account Number !!";
                    }
                }
                break;
            case 9:
                cout << "\n Enter account number : ";
                cin >> ano;
                if (true)
                {
                    checkingAcc *temp = headc;
                    while (temp != NULL)
                    {
                        if (temp->accNo == ano) //condn used to check whether Account Number Exists .
                        {
                            cw = 1;
                            cout << "\n Enter amount : ";
                            cin >> bal;
                            temp->debitCheck(bal);
                            break;
                        }
                        temp = temp->next;
                    }
                    if (cw == 0) //if account doesn't Exists print This.
                    {
                        cout << "\n invalid Account Number !!";
                    }
                }
                break;
            case 10:
                exit(0);
            default:
                cout << "\n Enter valid Choice ..!";
            }
        }
    }
    return 0;
}