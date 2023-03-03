#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

class Bank_Account {
  int acno;
  char actype;
  int money_deposit;
  char name[70] ;
public:
  void report() const;
  int retMoney_deposit() const;
  int retacno() const;
  char rttype() const;
  void dep(int) ;
  void displayAc() const;
  void draw(int) ;
  void updation() ;
  void create_Bank_Account() ;
};
void Bank_Account:: updation(){
  cout<<"\n\t enter account no.:"<<acno;
  cout<<"\n\t Updation Bank_Account Holder Name:";
  cin.ignore();
  cin.getline(name,50);
  cout << "\n\t Updation Type of bank Account:";
  cin >> actype;
  actype=toupper(actype);
  cout<<"\n\tUpdation Balance Total_money:";
  cin>>money_deposit;
    
}
void Bank_Account::create_Bank_Account() {
  system("CLS");
  cout<<"\n\tPlease Enter the Bank_Account No.:";
  cin>>acno;
  cout<<"\n\tPlease Enter the Bank_Account holder name.:";
  cin.ignore();
  cin.getline(name,50);
  cout<<"\n\tPlease enter the type of the Bank_Account (C/S)";
  cout << "Please enter the staring Total-money:";
  cin>>money_deposit;
  cout<<"\n\tBank_Account created:";
}
void Bank_Account::displayAc() const{
  cout<<"\n\tBank_Account no.:"<<acno;
  cout<<"\n\tBank_Account Holder name.:"<<name;
  cout<<"\n\t Type of Bank_Acc.:"<<actype;
  cout<<"\n\tBank_Account Total Money.:"<<money_deposit; 
}
int Bank_Account::retacno() const{
  return acno;
}
char Bank_Account::rttype() const{
  return actype;
}
void Bank_Account::report() const{
  cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<actype<<setw(6)<<money_deposit<<endl;
}
void Bank_Account:: dep(int x ){
  money_deposit+=x;

}
int Bank_Account::retMoney_deposit() const{
  return money_deposit;
}
void Bank_Account::draw(int x) {
  money_deposit-=x;
}
void write_Bank_Account();
void display_sp(int);
void display_all();
void delete_Bank_Account(int);
void Money_Deposit_Withdraw(int,int);
void Updation_Bank_Account(int);

int main(){
  char ch;
  int num;
  do{
    system("CLS");
    cout<<"\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!";
    cout<<"\n\t\tBANK MANAGEMENT SYSTEM";
    cout<<"\n\t\t!!!!!!!!!!!!!!!!!!!!!!!\n";
    cout<<"\t\t   ::MAIN MENU::\n";
    cout<<"\n\t\t1.NEW Bank_Account";
    cout<<"\n\t\t2. Money_Deposit total Money";
    cout<<"\n\t\t3.WITHDRAW total-money";
    cout<<"\n\t\t4.BALANCE ENQUIRY";
    cout<<"\n\t\t5. ALL BANK ACCOUNT HOLDER LIST";
    cout<<"\n\t\t6.CLOSE AN BANK ACCOUNT ";
    cout<<"\n\t\t7. UPDATION AN BANK ACCOUNT";
    cout<<"\n\t\t8. EXIT";
    cout<<"\n\t\tSelect Your Option(1-8)";
    cin>>ch;

    switch(ch){
      case '1':
        write_Bank_Account();
        break;
      case '2': 
        system("CLS");
        cout<<"\n\n\tPlease Enter the bank_acc no :";
        cin>> num;
        Money_Deposit_Withdraw(num,1);
        break;
      case '3':
        system("CLS");
        cout<<"\n\nPlease Enter the bank ac no : ";
        cin>> num;
        Money_Deposit_Withdraw(num,2);
        break;
      case '4':
        system("CLS");
        cout<<"\n\n\tPlease Enter the bank_acc no :";cin>> num; 
        display_sp(num);
      case '5':
        display_all();
        break;
      case '6':
        system("CLS");
        cout<<"\n\n\tPlease Enter the bank_acc no :";cin>> num; 
        delete_Bank_Account(num);
        break;
      case '7':
        system("CLS");
        cout<<"\n\n\tPlease Enter the bank_acc no :"; 
        cin>> num;
        Updation_Bank_Account(num);
        break;
      case '8':
        system("CLS");
        cout<<"\n\n\tBrought to you by code-projects.org";
        break;
      default :cout <<"/a";
    }
    cin.ignore();
    cin.get();
  }while (ch!='8');
  return 0; }
  
  void write_Bank_Account(){
    Bank_Account ac;
    ofstream outFile;
    outFile.open("Bank_Account.dat",ios::binary|ios::app);
    ac.create_Bank_Account();
    outFile.write(reinterpret_cast<char *>(&ac),sizeof(Bank_Account));

  }
  void delete_Bank_Account(int n ){
    Bank_Account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Bank_Account.dat",ios::binary);
    if(!inFile){
      cout<<"File could not be open !! Press any key";
      return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *>(&ac),sizeof(Bank_Account))){
      if(ac.retacno()!=n){
        outFile.write(reinterpret_cast<char *>(&ac),sizeof(Bank_Account));
      }
    }
    inFile.close();
    outFile.close();
    remove("Bank_Account.dat");
    cout << "\nRecord Deleted";

  }
  void display_sp(int n ){
    Bank_Account ac;
    bool flag=false;
    ifstream inFile;
    inFile.open("Bank_Account.dat",ios::binary);
    if(!inFile){
      cout<<"File could not be open !! Press any key";
      return;
    }
    cout<< "\n\tBalance details\n ";
    while(inFile.read(reinterpret_cast<char *>(&ac),sizeof(Bank_Account))){
      if(ac.retacno()==n){
        ac.displayAc();
        flag=true;
      }
    }
    inFile.close();
    if(flag==false)
      cout<<"\n\n\tBank_Account number does not exist";
  }
  void display_all(){
    system("CLS");
    Bank_Account ac;
    ifstream inFile;
    inFile.open("Bank_Account.dat",ios::binary);
    if(!inFile){
      cout<<"File could not be open !! Press any key";
      return;
    }
    cout<<"\n\n\t\tBank_Account HOLDER LIST \n\n";
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!======\n";
    cout<<"A/c no.    NAME    Type Balance\n";
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!======\n";
    while(inFile.read(reinterpret_cast<char *>(&ac),sizeof(Bank_Account))){
      ac.report();

    }
    inFile.close();  }
void Updation_Bank_Account(int n ){
  bool found =false;
  Bank_Account ac;
  fstream File;
  File.open("Bank_Account.dat",ios::binary|ios::in|ios::out);
  if(!File){
    cout<<"File could not be open Press any key";
    return ;
  }
  while(!File.eof() && found==false)
  {
    File.read(reinterpret_cast<char *>(&ac),sizeof(Bank_Account));
    if(ac.retacno()==n){
      ac.displayAc();
      cout<<"\n\n\tPlease Enter the new details of Bank_Account"<< endl;
      ac.updation();
      int pos=(-1)*static_cast<int>(sizeof(Bank_Account));
      File.seekp(pos,ios::cur);
      File.write(reinterpret_cast<char *>(&ac),sizeof(Bank_Account));
      cout<<"Record Updated";
      found=true;
    }
  }
  File.close();
  if(found==false){
    cout<<"\n\n\tRecord Not Found ";

  }
}
void Money_Deposit_Withdraw(int n,int option ){
  int amt ;
  bool found=false;
  Bank_Account ac;
  fstream File;
  File.open("Bank_Account.dat",ios::binary|ios::in|ios::out);
  if(!File){
    cout<<"File could not be open Press any key";
    return ;
  }
  while(!File.eof() && found==false)
  {
    File.read(reinterpret_cast<char *>(&ac),sizeof(Bank_Account));
    if(ac.retacno()==n){
      ac.displayAc();
      if(option ==1){
      cout<<"\n\n\tTO Money_DepositSS Total-Money";
				cout<<"\n\n\tPlease Enter The Total-Money to be Money_Deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
    if(option==2){
				cout<<"\n\n\tTO WITHDRAW Total-Money";
				cout<<"\n\n\tPlease Enter The Total-Money to be withdraw: ";
				cin>>amt;
				int bal=ac.retMoney_deposit()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
			cout<<"\n\n\tRecord Updated";
			found=true;
  }
  }
    File.close();
	if(found==false)
		cout<<"\n\n\tRecord Not Found ";
}