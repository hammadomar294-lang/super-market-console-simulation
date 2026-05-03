#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

struct Category
{
    int CategoryId;
    std::string CategoryName;
    int Tax;
    int MaxAmount;
    int LeastAmount;


    Category(int id, const std::string &name, int tax, int maxAmount, int leastAmount) : CategoryId(id), 
CategoryName(name), Tax(tax),
MaxAmount(maxAmount), LeastAmount(leastAmount)
{}
};


struct Product
{
    int Id;
    std::string Name;
    double Price;
    int Quantity;

// existing product constructor
Product(int id , std::string name , double price , int quantity) : Id(id) , Name(name) , Price(price) , Quantity(quantity)
{}

};

#pragma region test functions

void NumbersGrid(int n)
{
    if (n==0) return;
    if (n==1) cout<<"1"<<endl;
    for (int i=0 ; i<n ; i++) 
    {
        for (int j = 1 ; j<=n ; j++)
        {
            
            if (j==n)
            {
                 cout<<j+(i*n);
                 break;
            }
            if (to_string(j+(i*n)).length()== 1)
                cout<<j+(i*n)<<"   * ";
            else if (to_string(j+(i*n)).length()== 2) 
                cout<<j+(i*n)<<"  * ";
            
            
        }

        cout<<"\n";
    }
}
void ReverseVector(vector<int> v)
{
    int temp=0;
    for (int i = 0 ; i<v.size()/2 ; i++)
    {
        temp=v[v.size()-1-i];
        v[v.size()-1-i]=v[i];
        v[i]=temp;
    }
    for (auto& num : v)
    {
        cout<<num<<" ";
    }
}
int GetMinutes()
{
    cout << "Enter time (hours.minutes):  (write 0 to stop)";

    float time;
    cin >> time;
    if (time<0.0) return 0;
    int hours = (int)time;
    int minutes = (int)((time - hours) * 100);

    return hours * 60 + minutes;
}
void CalculateTime()
{
    int input=0 , minutes=0 , hours =0 , sum =0;
   while (true){
        input=GetMinutes();
        if (input==0) break;
        sum+=input;  
    }
    hours=sum/60;
    minutes=sum%60;
    cout<<"time is "<<hours<<" : "<<minutes<<endl;
}
#pragma endregion

#pragma region load and save data test

struct Student
{
    int StudentId;
    string Name;
    string Password;
    int level;
    int NumberOfRegisteredCourses=0;
};

Student StudentArray[50];
int StudentCounter=0;

void LoadStudents()
{
    ifstream file("students.txt");
    if (!file.is_open())
    {
        cout<<"file students.txt could not be opened"<<endl;
        return;
    }
    Student student;
    while (file>>student.StudentId>>student.Name>>student.Password>>student.level>>student.NumberOfRegisteredCourses)
    {
        StudentArray[StudentCounter]=student;
        StudentCounter++;
    }
    file.close();
}

void SaveStudents()
{
    ofstream file("students.txt");
    if (!file.is_open())
    {
        cout<<"file students.txt could not be opened"<<endl;
        return;
    }
    for (int i = 0 ; i < StudentCounter ; i++)
    {
        file << StudentArray[i].StudentId << " "
             << StudentArray[i].Name << " "
             << StudentArray[i].Password << " "
             << StudentArray[i].level << " "
             << StudentArray[i].NumberOfRegisteredCourses
             << endl;
    }
    file.close();
}

Student MakeStudent(int id , string name , string password , int level , int NumberOfRegisteredCourses=0)
{
    Student student;
    student.StudentId=id;
    student.Name=name;
    student.Password=password;
    student.level=level;
    student.NumberOfRegisteredCourses=NumberOfRegisteredCourses;
    return student;
}

void SaveStudentToArray(Student student)
{
    StudentArray[StudentCounter]=student;
    StudentCounter++;
}

#pragma endregion


void ShowProducts(const vector<Product> &products)
{
    
    for (int i = 1 , j = 0; i <= products.size()/2 , j < products.size()/2 ; i++ , j++)
    {
            cout<<i + j<<". " <<products[i + j - 1].Name << "  " << products[i + j - 1].Price << " EGP " << products[i + j - 1].Quantity << " Unit\t" <<
               i + j + 1<<". "<<products[i + j].Name << "  " << products[i + j].Price << " EGP " << products[i + j].Quantity << " Unit\t"<<"\n \n";
    }
    if (products.size() % 2 != 0)
        cout<<products.size()<<". "<<products[products.size() - 1].Name << "  " << products[products.size() - 1].Price << " EGP " << products[products.size() - 1].Quantity<< " Unit" <<"\n \n";
    
}

int main()
{
    Product product1{1,"milk",40,100};
    Product product2{2,"cheese",120,10};
    Product product3{3,"cream",300,30};
    Product product4{3,"test1",300,30};
    Product product5{3,"test2",300,30};
    Product product6{3,"test3",300,30};
    Product product7{3,"test4",300,30};
    Product product8{3,"test5",300,30};
    Product product9{3,"test6",300,30};
    // Product product10{3,"test7",300,30};
    
    vector <Product> products = {product1 , product2 , product3 , product4 , product5 , product6 , product7 , product8 , product9 };
    
    ShowProducts(products);
  
    return 0;
}
    
