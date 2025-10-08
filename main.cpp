#include <iostream>
#include <fstream>
#include <string>

class Client 
{
private:
    std::string company_name;
    std::string owner_name;
    std::string phone_number;
    std::string address;
    std::string activity_type;
public:
    Client() 
    {
        company_name = "default company_name";
        owner_name = "default owner_name";
        phone_number = "default phone_number";
        address = "default address";
        activity_type = "default activity_type";
    }

    Client(const std::string& company_name, const std::string& owner_name, const std::string& phone_number,
    const std::string& address, const std::string& activity_type) 
    {
        this->company_name = company_name;
        this->owner_name = owner_name;
        this->phone_number = phone_number;
        this->address = address;
        this->activity_type = activity_type;
    }

    void read_from_cin() 
    {
        std::cout << "Company(no spaces): ";
        std::cin >> company_name;
        std::cout << "Owner(no spaces): ";
        std::cin >> owner_name;
        std::cout << "Phone(no spaces): ";
        std::cin >> phone_number;
        std::cout << "Address(no spaces): ";
        std::cin >> address;
        std::cout << "Activity(no spaces): ";
        std::cin >> activity_type;
    }

    void print_to_console() const 
    {
        std::cout << "Company: "  << company_name << std::endl;
        std::cout << "Owner: "    << owner_name << std::endl;
        std::cout << "Phone: "    << phone_number << std::endl;
        std::cout << "Address: "  << address << std::endl;
        std::cout << "Activity: " << activity_type << std::endl;
        std::cout << "-------------------" << std::endl;
    }

    const std::string& get_company_name() const 
    { 
        return company_name;
    }

    const std::string& get_owner_name() const      
    { 
        return owner_name;
     }
    const std::string& get_phone_number() const
    {
        return phone_number;
    }
    const std::string& get_address() const
    { 
        return address;
    }
    const std::string& get_activity_type() const
    { 
        return activity_type; 
    }

};

class Directory 
{
private:
    std::string data_file;
public:
    Directory(const std::string& file_name) 
    {
        data_file = file_name;
    }


    void add_client() 
    {
        Client c;
        c.read_from_cin();
        std::ofstream out(data_file, std::ios::app);
        if (!out) 
        { 
            std::cout << "File error\n"; return; 
        }

        out << c.get_company_name() << " "
        << c.get_owner_name()   << " "
        << c.get_phone_number() << " "
        << c.get_address()      << " "
        << c.get_activity_type() << "\n";

        std::cout << "Saved\n";
    }

    void show_all() const 
    {
        std::ifstream in(data_file.c_str());
        if (!in) 
        { 
            std::cout << "No data\n"; return; 
        }
        std::string a,b,c,d,e;
        int count = 0;
        while (in >> a >> b >> c >> d >> e) 
        {
            Client rec(a,b,c,d,e);
            rec.print_to_console();
            count = count + 1;
        }
        if (count == 0) 
        {
            std::cout << "No records\n";
        }
    }

    void search_by_company() const 
    {
        std::cout << "Query: ";
        std::string q; 
        std::cin >> q;
        std::ifstream in(data_file.c_str());
        if (!in) 
        { 
            std::cout << "No data\n"; return; 
        }
        std::string a,b,c,d,e;
        int found = 0;
        while (in >> a >> b >> c >> d >> e) 
        {
            if (a.find(q) != -1) 
            {
                Client rec(a,b,c,d,e);
                rec.print_to_console();
                found = found + 1;
            }
        }
        if (found == 0) 
        {
             std::cout << "Nothing found\n";
        }
    }
};

int main() {
    Directory dir("directory.txt");
    while (true) 
    {
        std::cout << "\n1.Show  2.Add  3.Search  0.Exit\n";
        std::cout << "Choice: ";
        int m; 
        if (!(std::cin >> m))
        {
             return 0;
        }
        if (m == 0) 
        {
            std::cout << "Bye\n"; break;
        }

        if (m == 1) 
        {
            dir.show_all();
        }
        else if (m == 2) 
        {
            dir.add_client();
        }
        else if (m == 3)
        {
            dir.search_by_company();
        }
        else 
        {
            std::cout << "Invalid\n";
        }
    }
    return 0;
}
