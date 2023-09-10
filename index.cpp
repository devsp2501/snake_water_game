#include<iostream>
#include<fstream>
#include<string.h>
#include <regex>
#include <iomanip>// The iomanip header file in C++ stands for input/output manipulation. It provides functionality to manipulate input and output formatting options, such as setting the width and precision of floating-point output, aligning output to a specific column, and more
using namespace std;

void login();
void registration();

void forgot();

// Snake water game using inheritance
class GameObject {
public:
    GameObject(string name) : m_name(name) {}
    virtual ~GameObject() {} //  This is the destructor for the class. It's marked as virtual to ensure that any derived classes are properly destroyed when they're deleted.
    virtual string getType() { return "GameObject"; } //- This is a virtual function that returns the type of the object. It's marked as virtual so that it can be overridden by derived classes.
    string getName() { return m_name; } // - This function returns the name of the object.
protected:
    string m_name;
};

class RockPaperScissor : public GameObject {
public:
    RockPaperScissor(string name) : GameObject(name) {}
    virtual ~RockPaperScissor() {}
    virtual string getType() override { return "RockPaperScissor"; }
    int play(char you, char computer);
};

int RockPaperScissor::play(char you, char computer) {
    // This function returns 1 if you win ,-1 if you lose and 0 if it ends in draw

    // If you and the computer have chosen the same character which eventually ends in a draw
    if (you == computer) {
        return 0;
    }

    // If you have chosen snake and the computer have chosen the gun and vice versa
    if (you == 's' and computer == 'r') {
        return -1;
    }
    else if (you == 'r' and computer == 's') {
        return 1;
    }

    // If you have chosen water and the computer have chosen the snake and vice versa
    if (you == 'p' and computer == 's') {
        return -1;
    }
    else if (you == 's' and computer == 'p') {
        return 1;
    }

    // If you have chosen gun and the computer have chosen the water and vice versa
    if (you == 'r' and computer == 'p') {
        return -1;
    }
    else if (you == 'p' and computer == 'r') {
        return 1;
    }
    return 0;
}




int main()
{

     int choice;

    cout << "**************************************************" << endl;
    cout << "*                                                *" << endl;
    cout << "*             WELCOME TO MY GAME!                *" << endl;
    cout << "*                                                *" << endl;
    cout << "**************************************************" << endl;
    cout << endl;
    cout << "\n\t\t\t 1. Login \n\t\t\t 2. Register \n\t\t\t 3. Forgot Password \n\t\t\t 4. Exit \n\t\t\t Enter your choice : ";
    cin >> choice;

    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
             case 3:
             forgot();
             break;
        case 4:
         cout<<"\t\t\t THANKYOU! \n\n";
            exit(0);
            break;
        default:
            cout << "\n\t\t\t Invalid choice. Please try again." << endl;
            break;
    }

//game code
   

}

void game(){
         srand(time(0)); // The first line of the code seeds the random number generator with the current time so that the computer's choice is different each time the game is played.
    RockPaperScissor game("RockPaperScissor");

    int numGames;
    cout << "How many times would you like to play? ";
    cin >> numGames;

    int totalWins = 0;
    int totalLosses = 0;
    int totalDraws = 0;

// hashing
    for (int i = 0; i < numGames; i++) {
        char you;
        char computer;

        int number = rand() % 100 + 1; //  generates a sequence of pseudo-random integers. 

        if (number < 33) {
            computer = 's';
        }
        else if (number >= 33 and number < 66) {
            computer = 'g';
        }
        else {
            computer = 'w';
        }

        cout << "Enter 's' for snake, 'w' for water, and 'g' for gun: ";
        cin >> you;

        int result = game.play(you, computer);

        if (result == 0) {
            cout << "Game Draw !!" << endl;
            totalDraws++;
        }

        if (result == 1) {
            cout << "Congratulations, You Won !!" << endl;
            totalWins++;
        }
   
        if (result == -1) {
            cout << "OOPS, You lose !!" << endl;
            totalLosses++;
        }

        cout << "You chose " << you << " and computer chose " << computer << endl;
    }

    ofstream outfile("scores.txt");
    if (outfile.is_open()) {
        outfile << "Total Wins: " << totalWins << endl;
        outfile << "Total Losses: " << totalLosses << endl;
        outfile << "Total Draws: " << totalDraws << endl;
        outfile.close();
        ifstream infile("scores.txt");
if (infile.is_open()) {
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
    infile.close();
}
else {
    cout << "Unable to open file." << endl;
}
    }
}

void login()
{
    int count;
    string userId,emailId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please Enter the Username and Password : " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userId;
    cout << "\t\t\t PASSWORD ";
    cin >> password;

     ifstream input("records.txt");

    while(input>>id>>pass)
    {
      
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {
        cout<<userId<<"\n Your Login is successfull \n Thanks for Loging In ! \n";
        // main();
    }
    else
    {
        cout<<"\n LOGIN ERROR!! \n Please check your Username and Password \n";
         main();
    }


          srand(time(0));
    RockPaperScissor game("Rock Paper Scissors");

    int numGames;
    cout << "How many times would you like to play? ";
    cin >> numGames;

    int totalWins = 0;
    int totalLosses = 0;
    int totalDraws = 0;

    for (int i = 0; i < numGames; i++) {
        char you;
        char computer;

        int number = rand() % 100 + 1;

        if (number < 33) {
            computer = 's';
        }
        else if (number >= 33 and number < 66) {
            computer = 'r';
        }
        else {
            computer = 'p';
        }

        cout << "Enter 'r' for rock, 'p' for paper, and 's' for scissor: ";
        cin >> you;

        int result = game.play(you, computer);

        if (result == 0) {
            cout << "Game Draw !!" << endl;
            totalDraws++;
        }

        if (result == 1) {
            cout << "Congratulations, You Won !!" << endl;
            totalWins++;
        }
   
        if (result == -1) {
            cout << "OOPS, You lose !!" << endl;
            totalLosses++;
        }

        cout << "You chose " << you << " and computer chose " << computer << endl;
    }

    ofstream outfile("scores.txt");
    if (outfile.is_open()) {
        // outfile << "Total Wins: " << totalWins << endl;
        // outfile << "Total Losses: " << totalLosses << endl;
        // outfile << "Total Draws: " << totalDraws << endl;
        outfile.close();
        ifstream infile("scores.txt");
if (infile.is_open()) {
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
    infile.close();
}
else {
    cout << "Unable to open file." << endl;
}
    }

    main();

}


void registration() {
    string ruserId, ruserEmail, rpassword, cpassword;

    system("cls");
    cout << "\t\t\t Enter the Username : ";
    cin >> ruserId;

    // Check if user ID is already taken
     ifstream f1("records.txt");
    string line;
    while (getline(f1, line)) {
        istringstream iss(line);
        string userId;
        getline(iss, userId, '|');
        if (userId == ruserId) {
            cout << "\t\t\t User ID already taken. Please try again." << endl;
            registration(); // Call the registration function recursively to start over
            return;
        }
    }

    while (true) {
        cout << "\t\t\t Enter the Email : ";
        cin >> ruserEmail;

        try {
            // Regular expression to match the email pattern
            regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
            if (!regex_match(ruserEmail, pattern)) {
                throw invalid_argument("Invalid email address!");
            }

            // Check if email is already registered
            ifstream f2("records.txt");
            string line;
            while (getline(f2, line)) {
                istringstream iss(line);
                string email;
                getline(iss >> ws, email, '|');
                if (email == ruserEmail) {
                    cout << "\t\t\t Email already registered. Please try again." << endl;
                    registration(); // Call the registration function recursively to start over
                    return;
                }
            }
            break; // If the email is valid and not registered, break out of the loop
        } catch (const invalid_argument& e) {
            cout << "\t\t\t" << e.what() << endl;
        }
    }

    while (true) {
        cout << "\t\t\t Enter the password : ";
        cin >> rpassword;
        cout << "\t\t\t Enter the confirm password : ";
        cin >> cpassword;

        if (rpassword != cpassword) {
            cout << "\t\t\t Passwords do not match. Please try again." << endl;
        } else {
            break; // If the passwords match, break out of the loop
        }
    }

        system("cls");
    cout << "\n\t\t\t Registration is successful! \n";
     srand(time(0));
    RockPaperScissor game("Rock Paper Scissors");

    int numGames;
    cout << "How many times would you like to play? ";
    cin >> numGames;

    int totalWins = 0;
    int totalLosses = 0;
    int totalDraws = 0;

    for (int i = 0; i < numGames; i++) {
        char you;
        char computer;

        int number = rand() % 100 + 1;

        if (number < 33) {
            computer = 's';
        }
        else if (number >= 33 and number < 66) {
            computer = 'r';
        }
        else {
            computer = 'p';
        }

        cout << "Enter 'r' for Rock, 'p' for paper, and 's' for sccissor: ";
        cin >> you;

        int result = game.play(you, computer);

        if (result == 0) {
            cout << "Game Draw !!" << endl;
            totalDraws++;
        }

        if (result == 1) {
            cout << "Congratulations, You Won !!" << endl;
            totalWins++;
        }
   
        if (result == -1) {
            cout << "OOPS, You lose !!" << endl;
            totalLosses++;
        }

        cout << "You chose " << you << " and computer chose " << computer << endl;
    }

    ofstream outfile("scores.txt");
    if (outfile.is_open()) {
        // outfile << "Total Wins: " << totalWins << endl;
        // outfile << "Total Losses: " << totalLosses << endl;
        // outfile << "Total Draws: " << totalDraws << endl;
        outfile.close();
        ifstream infile("scores.txt");
if (infile.is_open()) {
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
    infile.close();
}
else {
    cout << "Unable to open file." << endl;
}
    }

   ofstream f32("scores.txt", ios::app);
     f32<<"Name & Password : "<< ruserId <<' '<< rpassword << " | " <<" Email : "<< setw(3) << ruserEmail << " | " <<"Confirm Password : "<< setw(3) << cpassword <<" | "<<"Total Wins : "<< setw(3) << totalWins <<" | "<<"Total Losses : "<< setw(3) << totalLosses <<" | "<<"Total Draws : "<< setw(3) << totalDraws << endl;
//  f3 << ruserId <<' '<< rpassword << " | " <<" Email : "<< setw(3) << ruserEmail << " | " <<"Confirm Password : "<< setw(3) << cpassword <<" | "<<"Total Wins : "<< setw(3) << totalWins <<" | "<<"Total Losses : "<< setw(3) << totalLosses <<" | "<<"Total Draws : "<< setw(3) << totalDraws << endl;

     f32.close();
    // system("cls");
  
    // // Open the file for appending and write the user details to it
    ofstream f3("records.txt", ios::app);
    //  f3 <<"Name & Password : "<< ruserId <<' '<< rpassword << " | " <<" Email : "<< setw(3) << ruserEmail << " | " <<"Confirm Password : "<< setw(3) << cpassword <<" | "<<"Total Wins : "<< setw(3) << totalWins <<" | "<<"Total Losses : "<< setw(3) << totalLosses <<" | "<<"Total Draws : "<< setw(3) << totalDraws << endl;
//  f3 << ruserId <<' '<< rpassword << " | " <<" Email : "<< setw(3) << ruserEmail << " | " <<"Confirm Password : "<< setw(3) << cpassword <<" | "<<"Total Wins : "<< setw(3) << totalWins <<" | "<<"Total Losses : "<< setw(3) << totalLosses <<" | "<<"Total Draws : "<< setw(3) << totalDraws << endl;
f3<<ruserId<<' '<<rpassword<<endl;
     f3.close();
    // system("cls");
    cout<<"\n\t\t\t Registration is successfull! \n";

    main();
}


void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t You Forgot the password! No Worries \n";
    cout<<"Press 1 to search your id by Username"<<endl;
    cout<<"Press 2 to get back to the menu"<<endl;
    cout<<"\t\t\t Enter your choice : ";
    cin>>option;
    switch(option)
    {
        case 1:
        {
            int count=0;
            string suserId,sId,spass;
            cout<<"\n\t\t\t Enter the username which you remember : ";
            cin>>suserId;

            ifstream f2("records.txt");
            while(f2>>sId>>spass)
            {
                if(sId==suserId)
                {
                    count=1;
                }
            }
            f2.close();
            if(count==1)
            {
                cout<<"\n\n Your account is found! \n";
                cout<<"\n\n Your password is : "<<spass;
                main();
            }
            else{
                cout<<"\n\t Sorry! your account is not found! \n";
                main();
            }
            break;
        }
        case 2:
            {
                main();
            }
        default: 
            cout<<"\t\t\t Wrong  choice! Please try again"<<endl;
    }
}