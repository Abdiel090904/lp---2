# lp---2
#include <iostream>
using namespace std;

class Drugs{ //drogras
    private:
        string Name; //nombre de la drogra
        int Amount; //cantidad de drogas
        double Price; // precio de la droga

    public:
        Drugs(string N,int A,double P){ //construcctor
            Name = N;
            Amount = A;
            Price = P;
        }

        ~Drugs(){ //destructor
            cout <<"The drug " << Name << " is being destroyed" << endl;
        }
        
        Drugs& SetName(string N){ // esta haceindo la autorreferencia al objeto
            Name = N;
            return *this;
        }

        Drugs& SetAmount(int A){
            Amount = A;
            return *this;
        }

        Drugs& SetPrice(double p){
            Price = p;
            return *this;
        }

        string GetName(){
            return Name;
        }

        int GetAmount(){
            return Amount;
        }

        double GetPrice(){
            return Price;
        }
};

class DrugStore{
    private:
        string Name;
        Drugs *ListOfProducts[50];
        int Index;

    public:
        DrugStore(string N){
            Name = N;
            Index = 0;
        }

        ~DrugStore(){
            cout << "The drugstore " << Name << " is being destroyed." << endl; 
        }

        DrugStore &AddDrugs(Drugs *D){
            if (not((Index < 0) or (Index > 49))){
                ListOfProducts[Index] = D;
                Index++;
            }
            return *this;
        }

        DrugStore &Remove(string D){
            for (int i = 0; i < Index; i++)
            {
                if (ListOfProducts[i] ->  GetName() == D ){
                    for (int j = i; j < Index - 1; j++)
                    {
                        ListOfProducts[j] = ListOfProducts[j+i];
                    }
                    ListOfProducts[49] = NULL;
                    Index--;
                }
            }
            return *this;
        }

        DrugStore &SetName(string N){
            Name = N;
            return *this;
        }

        string GetName(){
            return Name;
        }

        DrugStore &ShowInfo(){
            cout<< Name << endl;
            for (int i = 0; i < Index; i++)
            {
                cout << "\t Name: " << ListOfProducts[i] -> GetName() << endl;
                cout << "\t Price: " << ListOfProducts[i] -> GetPrice() << endl;
                cout << "\t Amount: " << ListOfProducts[i] -> GetAmount() << endl<<endl;
            }
            return *this;
        }
};  

int main(){
    Drugs Paracetamol("Paracetamol", 10, 2.5);
    //Drugs  *Paracetamol = New Drugs("Paracetamol",10,2.5);
    Drugs Ibuprofen("Ibuprofen", 10, 2.30);

    DrugStore TheCorner("The Corner");
    TheCorner.AddDrugs(&Paracetamol);
    //TheCorner.AddDrugs(Paracetamol);
    TheCorner.AddDrugs(&Ibuprofen);
    
    TheCorner.ShowInfo();
}
