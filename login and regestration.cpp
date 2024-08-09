#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//signup ->new account
//login -> old account
void login();
void signup();
int main()
{
    string choice;
    cout << "Do you want to signup or login?" << endl;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (choice == "login")
    {
        login();
    }
    else if (choice == "signup")
    {
        signup();
    }
    return 0;
}
void login()
{
    string username, password;
    cout << "username:" << endl;
    getline(cin, username);
    cout << "password" << endl;
    getline(cin, password);
    string filename = username + ".txt";
    ifstream file(filename);
    if (file)
    {
        string storedpass;
        getline(file, storedpass);
        if (password == storedpass)
        {
            cout << "welocme" << endl;
        }
        else
        {
            cout << "password is incorrect.Please try again" << endl;
            getline(cin, storedpass);
            if (password == storedpass)
            {
                cout << "welcome" << endl;
            }
            else
            {
                cout << "password is incorrect again. Access denied." << endl;
            }
        }
        file.close();
    }
    else
    {
        cout << "account doesn't exist" << endl;
    }

}
void signup()
{
    string username, password;
    while (true)
    {
        cout << "username:" << endl;
        getline(cin, username);
        string filename = username + ".txt";
        ifstream file(filename);
        if (file)
        {
            cout << "this username is used . Please enter anther user name" << endl;
            file.close();
        }
        else
        {
            ofstream newfile(filename);
            if (newfile)
            {
                cout << "Enter your password:" << endl;
                getline(cin, password);
                newfile << password; // Store the password in the file
                newfile.close(); //
                cout << "Signup successful. Your account has been created." << endl;
            }
            else
            {
                cout << "Error creating the file,Try again" << endl;
            }
            break; //exit loop when username is valid
        }
    }

}