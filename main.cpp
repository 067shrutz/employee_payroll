#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Employee
{
    int emp_id;
    string name;
    double salary;
    Employee*next;

    Employee(int id,string n,double s)
    {
        emp_id = id;
        name = n;
        salary = s;
        next = nullptr;
    }
};
class Payroll
{
    private:
        Employee *head;
    public:
        Payroll()
        {
            head = nullptr;
        }
        void addEmployee()
        {
            int id;
            string n;
            double s;
            cout << "\n--- Add New Employee ---" << endl;
            cout << "Enter Employee ID: ";
            cin >> id;

            cout << "Enter Employee Name: ";
            cin >> n;

            cout << "Enter Base Salary: ";
            cin >> s;

            Employee* newNode = new Employee(id, n, s);

            if (head == nullptr)
            {
                head = newNode;
                cout << "Success: " << n << " added as the first employee!" << endl;
                return;
            }
           Employee* current = head;
           while (current->next != nullptr)
           {
            current = current->next;
           }
        current->next = newNode;
        cout << "Success: " << n << " added to the system!" << endl;
        }
        void displayEmployee()
        {
            if(head==nullptr)
            {
                cout << "No employees found in system." << endl;
                endl;
                return;
            } 
            Employee *temp = head;

            while (temp != nullptr)
            {
                cout<<"Emmployee ID :"<<temp->emp_id
                << endl;
                cout<<"name  :"<<temp->name<<
                endl;
                cout<<"Salary :"<<temp->salary<<
                endl;
                cout<<"-----------------------------"<<endl;

                temp = temp->next;

            }
        

        }
        void deleteEmployee()
        {

        }
        void updateEmployee()
        {

        }
        void generatePayroll()
        {
            if(head==nullptr)
            {
                cout << "No employees found in system." << endl;
                return;
            }
            EmployeeNode *current = head;
            double TaxRate = 0.15;
            double totalPayout = 0.0;

            cout << "\n---Payroll Report---" << endl;

            while(current!=nullptr)
            {
                double deduction = current->salary * TaxRate;
                double netSalary = current->salary - deduction;
                totalPayout += netSalary;

                cout << "Employee ID: " << current->emp_id << "|" << "Name: " << current->name << endl;
                cout << "Gross Salary: " << current->salary << endl;
                cout << "Tax Deduction: " << deduction << endl;
                cout << "Net Salary: " << netSalary << endl;
            }
            cout << "Total Company Payout: " << totalPayout << endl;
            cout << " == == == == == == == == == == == == == == == == = "<<endl;
        }
        void saveToCSV()
        {
            ofstream file("payroll.csv");
            if (file.is_open())
            {
                EmployeeNode *current = head;
                while (current != nullptr)
                {
                    file << current->emp_id << "," << current->name << "," << current->netSalary << endl;
                    current = current->next;
                }
                file.close();
            }
            cout << "Payroll data saved to payroll.csv successfully!" << endl;
        }
};
int main() {
    Payroll payroll;
    int choice;

    do {
        // Display the menu
        cout << "\n=== Payroll Management System ===\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Delete Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Generate Payroll\n";
        cout << "6. Save to CSV\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;

        // Execute based on user input
        switch (choice) {
            case 1:
                payroll.addEmployee();
                break;
            case 2:
                payroll.displayEmployee();
                break;
            case 3:
                payroll.deleteEmployee();
                break;
            case 4:
                payroll.updateEmployee();
                break;
            case 5:
                payroll.generatePayroll();
                break;
            case 6:
                payroll.saveToCSV();
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please select a valid option (0-6).\n";
        }
    } while (choice != 0); // Loop continues until the user enters 0

    return 0;
}