#include<iostream>
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
    cout<<" Buyer\n\n";
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
               break;
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
     cout<<"\n\tName of the product :";
     cin>>pname;
     cout<<"\n\tPrice of the product :";
     cin>>price;
     cout<<"\n\tDiscount on the product :";
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
     cout<<"\n\n\t\t Record inserted";
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
    cout<<"\n\t\t\t Enter Product code: ";
    cin>>pkey;

    data.open("productdatabase.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nfile dosen't exist!";
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
                cout<<"\n\t\t Name of the product: ";
                cin>>n;
                cout<<"Price";
                cin>>p;
                cout<<"\n\t\t Discount: ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited";
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
        rename("productdatabase1.txt","productdatabse.txt");
        
        if(token==0)
        {
            cout<<"\n\nRecord not found ";
        }


    }
}

void shop::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("productdatabase.txt",ios::in);
    if(!data)
    {
        cout<<"File dosen't exist";
    }
    else{
        data1.open("productdatabase1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey){
              cout<<"\n\n\t Product deleted successfully";
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
        cout<<"\n\n Record not found";
    }
}
}

void shop:: list()
{
    fstream data;
    data.open("productdatabase.txt",ios::in);
     cout<<"\n\n______________________________________________\n";
     cout<< "ProNo\t\tName\t\tPrice\n";
     cout<<"\n\n______________________________________________\n";
     data>>pcode>>pname>>price>>dis;
     while(!data.eof())
     {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
     }
     data.close();
}
void shop:: receipt()
{
    fstream data;
    int arrc[1000];
    int arrq[1000];
    char choice;
    int c=0;
    float amount;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEIPT";
    data.open("productdatabase.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";

    }
    else{
        data.close();
        list();
        cout<<"\n__________________________________________________\n";
        cout<<"\n|                                                 \n";
        cout<<"\n           Please place the order                 \n";
        cout<<"\n|                                                 \n";
        cout<<"\n__________________________________________________\n";
        do{

            m:
            cout<<"\n\n Enter the product code: ";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity: ";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code. please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n y-> To buy another product\nn-> To exit after calculating total bill";
            cin>>choice;
        }while (choice=='y');
        cout<<"\n\n                     RECEIPT                \n";
        cout<<"\nProduct No\t product Name\t product quantity\t price\t Amount\t Amount with discount\n";

        for(int i=0;i<c;i++)
        {
            data.open("productdatabase.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount =price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                    break;

                }
                data>>pcode>>pname>>price>>dis;
            }
        
        data.close();
        }
    }
    cout<<"\n\n";
    cout<<"\t\t Total amount= "<<total;

}
int main()
{
    shop sp;
    sp.menu();
}
