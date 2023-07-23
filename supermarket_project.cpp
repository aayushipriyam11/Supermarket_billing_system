#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
 class shop
 {
    private:
       int pcode;
       float price;
       float dis;
       string pname;
    public:
       void menu();
       void admin();
       void buyer();
       void add();
       void edit();
       void rem();
       void list();
       void receipt();
 };
 void shop:: menu()
 {
    m:
    int ch;
    string email;
    string password;

    cout << " Supermarket Main Menu:"<<endl<<endl;
    cout<< "\t 1) Administrator\n\t 2)Buyer\n\t 3)Exit"<<endl; 
    cout<<"Please Select"<<endl;
    cin>>ch;
    switch(ch){
    case 1:
        cout<<"\t\tPlease login\n";
        cout<<"\t\tEnter Email\n";
        cin>>email;
        cout<<"\t\tEnter password\n";
        cin>>password;
        if(email=="admin@gmail.com"&& password=="admin@123")
        {
            admin();
        }
        else
        {
            cout<<"Invalid email/password"<<endl;
        }
        break;
    case 2:
        buyer();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout<<"Invalid Input";
    }
    goto m;
}

void shop::admin()
{
    m:
    int choice;
    cout<<"Administrator menu :"<<endl<<endl;
    cout<< "\t 1) Add the product\n\t 2)Modify the product\n\t 3)Delete the product\n\t 4)Back to main menu"<<endl; 
    cout<<"Please enter your choice"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
             add();
             break;
        case 2:
              edit(); 
              break;
        case 3:
               rem();
               break;
        case 4: 
               menu();
               break;
        default:
               cout<<"Invalid choice"<<endl;
    }
    goto m;
}
void shop:: buyer()
{
    m:
    int ch;
    cout<<"\t  Buyer\n\n";
     cout<< "\t 1) Buy the product\n\t 2)Go back"<<endl; 
    cout<<"Please enter your choice"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:
               receipt();
               break;
        case 2:
               menu();
        default:
                cout<<"Invalid choice";
    }
    goto m;
}
void shop:: add()
{
    m:
     fstream data;
     int c;
     int token=0;
     float p;
     float d;
     string name;
     cout<<"\n\n\t\t Add new product";
     cout<<"\n\n\tProduct code of the product :";
     cin>>pcode;
     cout<<"\tName of the product :";
     cin>>pname;
     cout<<"\tPrice of the product :";
     cin>>price;
     cout<<"\tDiscount on the product :";
     cin>>dis;

     data.open("productdatabase.txt",ios::in);
     if(!data)
     {
        data.open("productdatabase.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
     }
     else{
        data>>c>>name>>p>>d;//Initializing the index of file

        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>name>>p>>d;
        }
        data.close();
      
      if(token==1)
     {
        goto m;
     }
     else{
        data.open("productdatabase.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();

     }
   }
     cout<<"\n\n\t\t Record inserted"<<endl<<endl;
}

void shop::edit()
{
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    int p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t Enter Product code: ";
    cin>>pkey;

    data.open("productdatabase.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nfile dosen't exist!"<<endl<<endl;
    }
    else{
        data1.open("productdatabase1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code: ";
                cin>>c;
                cout<<"\t\t Name of the product: ";
                cin>>n;
                cout<<"\t\tPrice: ";
                cin>>p;
                cout<<"\t\t Discount: ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited"<<endl<<endl;
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("productdatabase.txt");
        rename("productdatabase1.txt","productdatabase.txt");
        
        if(token==0)
        {
            cout<<"\n\nRecord not found "<<endl<<endl;
        }


    }
}

void shop::rem()
{
    fstream data,data1,data2;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("productdatabase.txt",ios::in);
    if(!data)
    {
        cout<<"File dosen't exist"<<endl;
    }
    else{
        data1.open("productdatabase1.txt",ios::out);
        data2.open("deleteddatabase.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey){
              cout<<"\n\n\t Product deleted successfully"<<endl<<endl;
              data2<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
              token++;
            }
            else{
                   data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
    data.close();
    data1.close();
    data2.close();
    remove("productdatabase.txt");
    remove("deleteddatabase.txt");
    rename("productdatabase1.txt","productdatabase.txt");
    
    if(token==0)
    {
        cout<<"\n\n Record not found"<<endl<<endl;
    }
}
}

void shop:: list()
{
    fstream data;
    data.open("productdatabase.txt",ios::in);
     cout<<"\n\n______________________________________________\n";
     cout<< "ProNo\t\tName\t\t\tPrice\n";
     cout<<"\n\n______________________________________________\n";
     data>>pcode>>pname>>price>>dis;
     while(!data.eof())
     {
        cout<<pcode<<"\t\t"<<pname<<"\t                        "<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
     }
     data.close();
}
void shop:: receipt()
{
    fstream data;
    vector<int> arrpc;
    vector<int>arrq;
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\tLIST";
    data.open("productdatabase.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";

    }
    else{
        data.close();
        list();
        cout<<"\n__________________________________________________";
        cout<<"\n|                                                |";
        cout<<"\n           Please place the order                 ";
        cout<<"\n|                                                |";
        cout<<"\n__________________________________________________\n";
        do{

            int m,n;
            cout<<"\n Enter the product code: ";
            cin>>m;
            arrpc.push_back(m);
            cout<<" Enter the product quantity: ";
            cin>>n;
            arrq.push_back(n);
            cout<<"\n\n y-> To buy another product\nn-> To exit after calculating total bill"<<endl;
            cin>>choice;
        }while (choice=='y');
        cout<<"\n\n                     RECEIPT                \n";
        cout<<"\nProduct No\t product Name\t product quantity\t price\t Amount\t Amount with discount\n";

        for(int i=0;i<arrpc.size();i++)
        {
            ifstream data1;
            data1.open("productdatabase.txt",ios::in);

            data1>>pcode>>pname>>price>>dis;
            while(data1)
            {
                if(pcode==arrpc[i])
                {
                    amount =price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t\t"<<arrq[i]<<"\t\t    "<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                    break;

                }
                data1>>pcode>>pname>>price>>dis;
            }data1.close();
        }
        data.close();
    }
    cout<<"\n\n";
    cout<<"    Total amount= "<<total<<endl<<endl;

}
int main()
{
    shop sp;
    sp.menu();
}
