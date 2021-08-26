#include <bits/stdc++.h>

using namespace std;

class Product
{
    int Productid, quantity;
    float Productprice;
    string productName;

    public:

    Product *next;
    Product *prev;

    Product(){
        Productid = quantity = 0;
        Productprice = 0.0;
        productName = "";
        next = NULL;
        prev = NULL;
    }

    int returnQuantity(){
        return quantity;
    }

    int returnId(){
        return Productid;
    }

    float returnPrice(){
        return Productprice;
    }

    string returnName(){
        return productName;
    }

    void setQuantity(int quantity){
        this->quantity = quantity;
    }

    void setId(int Productid){
        this->Productid = Productid;
    }

    void setPrice(float Productprice){
        this->Productprice = Productprice;
    }

    void setName(string productName){
        this->productName = productName;
    }

    void setUp(int Productid, int quantity, float Productprice, string productName){
        this->Productid = Productid;
        this->quantity = quantity;
        this->Productprice = Productprice;
        this->productName = productName;
    }

    void modifyQ(int n){
        this->quantity -= n;
    }

    void modify(int quantity, float Productprice, string productName){
        this->quantity = quantity;
        this->Productprice = Productprice;
        this->productName = productName;
    }

    void display(){
        cout<<"\n\t"<<Productid<<"\t\t"<<productName<<"\t\t\t"<<Productprice<<"\t\t\t"<<quantity;
    }
};

class Product_operation{
    public:

    Product* head;

    int ProductCount;

    Product_operation(){
        head = NULL;
        ProductCount = 0;
    }

    void InsertatEnd(int Productid, int quantity, float Productprice, string productName){
        Product* newProdut = new Product();
        newProdut->setUp(Productid, quantity, Productprice, productName);
        newProdut->next = NULL;

        if(head == NULL){
            head = newProdut;
            ProductCount++;
            return;
        }

        Product* Traverse = head;

        while(Traverse->next != NULL)
            Traverse= Traverse->next;

        Traverse->next = newProdut;
        newProdut->prev = Traverse;
        ProductCount++;
    }

    void DeletebyId(int Productid){
        if(ProductCount == 0){
            cout<<"\n\tEmpty!!!";
            return;
        }

        Product* Traverse = head;

        while(Traverse->returnId() != Productid && Traverse->next != NULL)
            Traverse = Traverse->next;

        if(Traverse->next == NULL && Traverse->returnId() != Productid){
            cout<<"\n\tInvalid ID!!!";
            return;
        }

        if(Traverse->prev != NULL)
            Traverse->prev->next = Traverse->next;
        else
            head = Traverse->next;

        if(Traverse->next != NULL)
            Traverse->next->prev = Traverse->prev;

        delete Traverse;
        ProductCount--;
    }

    void modify(int Productid){
        if(ProductCount == 0){
            cout<<"\n\tEmpty!!!";
            return;
        }

        Product* Traverse = head;

        while(Traverse->returnId() != Productid && Traverse->next != NULL)
            Traverse = Traverse->next;

        if(Traverse->next == NULL && Traverse->returnId() != Productid){
            cout<<"\n\tInvalid ID!!!";
            return;
        }

        int quantity;
        float Productprice;
        string Productname;
        cout<<"\n\tEnter Product Name : ";
        cin>>Productname;
        cout<<"\n\tEnter Price : ";
        cin>>Productprice;
        cout<<"\n\tEnter Quantity : ";
        cin>>quantity;

        Traverse->modify(quantity, Productprice, Productname);
    }

    void modifyQty(int Productid, int qty){
        Product* Traverse = head;

        while(Traverse->returnId() != Productid && Traverse->next != NULL)
            Traverse = Traverse->next;

        Traverse->modifyQ(qty);
    }


    void display(){
        cout<<"\n\t\t\t\t\t\tLIST OF ITEMS"<<endl;
        Product* Traverse = head;
        cout<<"\n\tID"<<"\t\tProduct Name"<<"\t\tPrice"<<"\t\tAvailable Quantity(units of measure(ex- Liter/KG etc)";

        if(ProductCount == 0){
            cout<<"\n\n\tEmpty!!!";
            return;
        }

        while(Traverse != NULL){
            Traverse->display();
            Traverse = Traverse->next;
        }
    }


    ~Product_operation(){
        while(head != NULL){
            Product* Traverse = head;
            head = head->next;
            delete Traverse;
        }
    }
}p;
// This is used to display a smiley face onto the scree
void Smiley(){
    cout<< "\n\t                                       ";
    cout<< "\n\t   ^^             ^^                       ";
    cout<< "\n\t                           ";
    cout<< "\n\t    \\     |_|     /                ";
    cout<< "\n\t     \\           /                         ";
    cout<< "\n\t      \\ _______ /                                 ";
    cout<< "\n\t       ---------                                "<<endl;
    cout<< "\n\t    THANK YOU!!! VISIT AGAIN ^_^"<<endl;
}

class Customer
{
    string Customername;
    long long int Customerno;
    string address;
    int Customerid;

    public:

    Product trolley[10];
    int trolleylen;
    int Customerbill;
    Customer *next;
    Customer *prev;

    Customer(){
        Customername = "";
        address = "";
        Customerno = 0;
        Customerid = 1000;
        next = NULL;
        prev = NULL;
        Customerbill=0;
        trolleylen=0;
    }

    int returnID(){
        return Customerid;
    }

    void setID(int n){
        this->Customerid += n;
    }

    void setUp(string name, long long int no, string add){
        this->Customername = name;
        this->address = add;
        this->Customerno = no;
    }

    void show_trolley(){
        int i=0;
        while(i < trolleylen){
            trolley[i].display();
            i++;
        }
    }

    void display(){
        cout<<"\n\t\t"<<Customerid<<"\t\t  "<<Customername<<"\t\t"<<Customerno<<"\t\t"<<address;
    }

    void IncrementCustomerBill(int n){
        Customerbill+=n;
    }

    int ShowCusotmerBill(){
        return Customerbill;
    }
};

int customer_menu()
{
    char ch ;
    cout<<"\n\n\tPress any key to continue\n\t";
    cin>>ch;
    system("cls");

    int choice = 0;

    cout<<"\n\n\t\t\t\tCUSTOMER PORTAL"<<endl;
    cout<<"\n\t1) Display all items"<<endl;
    cout<<"\t2) Buy"<<endl;
    cout<<"\t3) Exit"<<endl;
    cout<<"\t4) Main menu"<<endl;
    cout<<"\n\tEnter your Choice (1-4) : ";
    cin>>choice;
    return choice;
}

class CustomerOperation
{

    public:

    Customer* head;

    int CustomerCount;

    CustomerOperation(){
        head = NULL;

        CustomerCount = 0;
    }

    void InsertatEnd(string Customername, long long int mobileno, string address){
        Customer* newCustomer = new Customer();
        newCustomer->setUp(Customername, mobileno, address);
        newCustomer->setID(CustomerCount);
        newCustomer->next = NULL;

        if(head == NULL){
            head = newCustomer;
            CustomerCount++;
            Customer_choice(newCustomer);
            return;
        }

        Customer* Traverse = head;

        while(Traverse->next != NULL)
            Traverse = Traverse->next;

        Traverse->next = newCustomer;
        newCustomer->prev = Traverse;
        CustomerCount++;
        Customer_choice(newCustomer);
    }


    void display(){
        cout<<"\n\t\t\t\t\t\tCUSTOMERS RECORD"<<endl;
        Customer* Traverse = head;
        cout<<"\n\t\tCustomerID"<<"\t\tName"<<"\t\tMobile No."<<"\t\tAddress"<<endl;

        if(CustomerCount == 0){
            cout<<"\n\n\tEmpty!!!";
            return;
        }

        while(Traverse != NULL){
            Traverse->display();
            Traverse = Traverse->next;
        }
    }

    void Customer_choice(Customer* cus){
        int choice;
        int quantity, productid;
        do{
            choice= customer_menu();
            switch(choice){
                case 1 :p.display();
                        break;

                case 2 :p.display();
                        this->buy('Y', cus);
                        choice = 5;
                        break;

                case 3 :cout<<endl;
                        Smiley();
                        cout<<endl;
                        exit(0);

            }
        }while(choice <4 && choice >0);
    }

    void search_and_buy(int P_id, int Qty, Customer* customer){

        Product* Traverse= p.head;

        while(Traverse->returnId()!=P_id && Traverse->next!=NULL){
            Traverse=Traverse->next;
        }

        if(Traverse->next==NULL && Traverse->returnId()!=P_id){
            cout<<"\n\tThis Product is not present in the shop";
            return;
        }

        else if(Traverse->returnId()==P_id){
            if(customer->trolleylen==10){
                cout<<"\n\tYour Trolley is already full. Can't fill it more ";
                return;
            }
            else{
                Product* Traverse = p.head;

                while(Traverse->returnId() != P_id && Traverse->next != NULL)
                    Traverse = Traverse->next;


                if(Traverse->returnQuantity() < Qty){
                    cout<<"\n\tRequired Quantity not available!!"<<endl;
                    return;
                }

                else{
                    customer->Customerbill+= Traverse->returnPrice()*Qty;
                    customer->trolley[customer->trolleylen].setQuantity(Qty);
                    customer->trolley[customer->trolleylen].setPrice(Traverse->returnPrice());
                    customer->trolley[customer->trolleylen].setName(Traverse->returnName());
                    customer->trolley[customer->trolleylen].setId(P_id);
                    customer->trolleylen++;
                }
            }
        }
    }

    void show_trolley(int customer_ID){
        Customer* Traverse= head;

        while(Traverse->returnID()!=customer_ID|| Traverse->next!=NULL){
            Traverse=Traverse->next;
        }

        if(Traverse->next==NULL && Traverse->returnID()!=customer_ID){
            cout<<"\n\tThis Customer has not visited the shop";
            return;
        }

        else if(Traverse->returnID()==customer_ID){
            cout<<"\n\t\tCustomerID"<<"\t\tName"<<"\t\tMobile No."<<"\t\tAddress";
            Traverse->display();
        }
    }

    void buy(char choice, Customer* CID){
        if(!(choice=='Y' || choice=='y')){
            cout<<"\n\t\t\t\t\t\tBILL"<<endl;
            cout<<"\n\tID"<<"\t\tProduct Name"<<"\t\tPrice"<<"\t\tQuantity"<<endl;
            CID->show_trolley();
            cout<< "\n\n\tBill Amount :"<<CID->Customerbill;
            cout<< "\n\tDo you want to pay Rs "<<CID->Customerbill<<" (Y/N) : ";
            char Payment;
            cin>> Payment;
            if(Payment=='Y' || Payment =='y'){
                for(int i=0; i< CID->trolleylen; i++){
                    int pid= CID->trolley[i].returnId();
                    int pqty= CID->trolley[i].returnQuantity();
                    p.modifyQty(pid, pqty);
                }
                Smiley();
                char ch;
                cout<<"\n\tEnter 1 to exit ";
                cin>>ch;
            }
            else
                Smiley();
        }
        else{
            char  say;
            int product_id;
            int Quantity;
            if(p.head != NULL){
                cout<<"\n\n\tEnter product ID of item you want to buy : ";
                cin>> product_id;
                cout<<"\n\tEnter Quantity : ";
                cin>> Quantity;
                search_and_buy(product_id, Quantity, CID);
                cout<< "\n\tDo you want to continue buying (Y/N) : ";
                cin>> say;
                buy(say,CID);
            }
        }
    }

    ~CustomerOperation(){
        while(head != NULL){
            Customer* Traverse = head;
            head = head->next;
            delete Traverse;
        }
    }

}c;

void administator()
{
    system("cls");
    int choice = 0;

    int id, quantity;
    float price;
    string name;

	do{
        cout<<"\n\n\t\t\t\tADMINISTRATOR PORTAL"<<endl;

        cout<<"\n\t1) Add a new product"<<endl;
        cout<<"\t2) Modify existing product"<<endl;
        cout<<"\t3) Total number of products"<<endl;
        cout<<"\t4) Delete a particular product"<<endl;
        cout<<"\t5) Display all products"<<endl;
        cout<<"\t6) Customers list"<<endl;
        cout<<"\t7) Main menu"<<endl;


        cout<<"\n\tEnter your Choice (1-7) : ";
        cin>>choice;

        switch(choice){
            case 1 :system("cls");
                    cout<<"\n\tEnter Product Details";
                    cout<<"\n\n\tEnter Product ID : ";
                    cin>>id;
                    cout<<"\n\tEnter Product Name : ";
                    cin>>name;
                    cout<<"\n\tEnter Price of Product(per unit of measure): ";
                    cin>>price;
                    cout<<"\n\tEnter The Quantity in Stock: ";
                    cin>>quantity;
                    p.InsertatEnd(id, quantity, price, name);
                    system("cls");
                    break;

            case 2 :system("cls");
                    p.display();
                    cout<<endl;
                    cout<<"\n\tEnter Product ID to modify : ";
                    cin>>id;
                    p.modify(id);
                    system("cls");
                    break;

            case 3 :system("cls");
                    cout<<"\n\tTotal Number of Products : "<<p.ProductCount;
                    break;

            case 4 :system("cls");
                    p.display();
                    cout<<endl;
                    cout<<"\n\tEnter Product ID to delete : ";
                    cin>>id;
                    p.DeletebyId(id);
                    system("cls");
                    break;

            case 5 :system("cls");
                    p.display();
                    break;

            case 6 :system("cls");
                    c.display();
                    break;
        }
    }while(choice < 7 && choice > 0);
    system("cls");
}

void Trolley(){
                    cout<<"\n\t                      _";
                    cout<<"\n\t                     //" ;
                    cout<<"\n\t ___________________//";
                    cout<<"\n\t \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/";
                    cout<<"\n\t  \\/\\/\\/\\/\\/\\/\\/\\/\\/";
                    cout<<"\n\t   \\/\\TROLLEY\\/\\/\\/";
                    cout<<"\n\t    \\/\\/\\/\\/\\/\\/\\/";
                    cout<<"\n\t     \\==========/";
                    cout<<"\n\t      OO      OO";

}

int main()
{
    int choice = 0;

    string name;
    string add;
    long long int no;

    do{
        system("cls");
        cout<<"\n\n\t\t\t\t\tMAIN MENU";
        cout<<"\n\n\t1) Administrator";
        cout<<"\n\t2) Customer";
        cout<<"\n\tElse Enter any other key to exit";
        cout<<"\n\n\tEnter your Choice (1-2) : ";
        cin>>choice;

        switch(choice){
            case 1: administator();
                    break;

            case 2: Trolley();
                    cout<<"\n\tEnter Basic Details";
                    cout<<"\n\n\tEnter Name : ";
                    cin>>name;
                    cout<<"\n\tEnter Mobile No. : ";
                    cin>>no;
                    cout<<"\n\tEnter Address : ";
                    cin>>add;
                    c.InsertatEnd(name, no, add);
                    break;

            case 3: cout<<"\n\n\t\t\tTHANK YOU VISIT AGAIN"<<endl;
        }
    }while(choice==1 || choice ==2);
}
