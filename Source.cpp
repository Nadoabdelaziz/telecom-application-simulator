#include <iostream>
using namespace std;

struct rendate {
    int year;
    int month;
    int day;
};

struct stdate {
    int year;
    int month;
    int day;

};

struct Line {
    string mobnumber;
    string Packtype;
    float balance;
    stdate sdate;
    rendate rdate;
};

struct User {
    int ID;
    string Name;
    string Email;
    char password;
    string address;
    Line L[3];
    int setoflines;
}U[4];


void changePack(int id) {
    //know which user is taking
    for (int i = 0;i < 4;i++) {
        int packchoice;
        int count = 0;
        int choice;
        //comparing user id to all id's
        if (id == U[i].ID) {

          

            for (int j = 0;j < 3;j++) {
                //know number of lines that user owes
                if (U[i].L[j].mobnumber != "0") {
                    //ask user to enter which line or number 
                    cout << "choose which line you want" << endl;
                    //to show mobile numbers for user to choose from
                    cout << j + 1 << ") " << U[i].L[j].mobnumber << endl;
                    //know how many times line is valid to know number of lines
                    count++;
                }
            }
            //user enters his choice of which line
            cin >> choice;
            //makes sure that user doesn't enter invalid answer
            while (choice > count || choice <= 0) {
                //shows invalid input
                cout << "Invalid Input" << endl;
                //let user enter his choice again
                cin >> choice;
            }
            //change packtype of current user
            cout << "Current Package type is :" << U[i].L[choice - 1].Packtype << endl;
            //tell user to choose which packtype he wants
            cout << "to Change to Prepaid Package type Press 1 " << endl << "to change to postpaid package type press 2 " << endl<<"to change to Card package type press 3"<<endl;
            //user enters desired packtype
            cin >> packchoice;
            //tell user about his current packtype of desired line
            

        }
        switch (packchoice) {
        case 1:
            // change packtype to prepaid
            U[i].L[choice - 1].Packtype = "Prepaid";
            //shows the current 
            cout << "Current Package Changed completed for  " << U[i].L[choice - 1].Packtype << endl;
            break;
        case 2:
            U[i].L[choice - 1].Packtype = "Postpaid";
            cout << "Current Package Changed completed for  " << U[i].L[choice - 1].Packtype << endl;
            break;
        case 3:
            U[i].L[choice - 1].Packtype = "Card";
            cout << "Current Package Changed completed for  " << U[i].L[choice - 1].Packtype << endl;
            break;

        default:
            cout << "invalid answer" << endl;
            cin >> packchoice;
            break;
        }
    }
}


void renewSubscription(int id) {
    //to know which user is talking
    for (int i = 0;i < 4;i++) {
        //use a count to know number of lines of user
        int count = 0;
        //for the user to enter which line 
        int choice;
        //to know which user is talking
        if (id == U[i].ID) {
            int ch;
            //changing packtype
            cout << "To change Package Press 1" << endl << endl;;
            //renewing subscription
            cout << "To Renew Subscription Press 2" << endl<<endl;
            //user enters his choice
            cin >> ch;
            //if user chooses to change pack
            if (ch == 1) {
                //changing packype
                changePack(id);
                break;
            }
            //if user choose to renew only
            if (ch == 2) {

                //user choose which line he wants 
                for (int j = 0;j < 3;j++) {
                    //know number of lines that user owes
                    if (U[i].L[j].mobnumber != "0") {
                        //ask user to enter which line or number 
                        cout << "choose which line you want" << endl;
                        //to show mobile numbers for user to choose from
                        cout << j + 1 << ") " << U[i].L[j].mobnumber << endl;
                        //know how many times line is valid to know number of lines
                        count++;
                    }
                }
                //user enters his choice of which line
                cin >> choice;
                //makes sure that user doesn't enter invalid answer
                while (choice > count || choice <= 0) {
                    //shows invalid input
                    cout << "Invalid Input" << endl;
                    //let user enter his choice again
                    cin >> choice;
                }
                //the subscription has been updated completly
                cout << "subscription completly updated for  "<<U[i].L[choice-1].mobnumber << endl;
                break;
            }
        }
    }
}



void recharge(int id) {

}

void transfer(int id) {

}

//to do
//if user enters wrong user id

void call(int id) {
    for (int i = 0;i < 4;i++) {
        if (id == U[i].ID) {
            int choice = 0;
            int count = 0;
            // Print all mobile numbers asccoiated with current user
            for (int j = 0;j < 3;j++) {
                // Check if mobile number exists 
                if (U[i].L[j].mobnumber != "0") {
                    // Print index + mobile number
                    cout << "please an option below" << endl;
                    cout << j + 1 << ")" << U[i].L[j].mobnumber << endl;
                    // Increment count of mobile numbers
                    count++;
                }
            }
            // Ask user to input index of prefered mobile number 
            cin >> choice;
            // Check if choice is valid
            while (choice > count || choice <= 0) {
                cout << "wrong input" << endl;
                cin >> choice;
            }
            // Decrement balance of chosen mobile number
            U[i].L[choice - 1].balance--;
            cout << "Your Current Balance for " << U[i].L[choice - 1].mobnumber << " is " << U[i].L[choice - 1].balance << endl;
        }
    }




}


void message(int id) {
    //check which user of our 4 users
    for (int i = 0;i < 4;i++) {

        //to make sure which user is talking
        if (id == U[i].ID) {
            int count = 0;
            int choice;
            //to know which line of three lines
            for (int j = 0;j < 3;j++) {
                //shows only valid lines
                if (U[i].L[j].mobnumber != "0") {
                    //ask user to enter which line or number 
                    cout << "choose which line you want" << endl;
                    //shows all lines owned by user
                    cout << j + 1 << ") " << U[i].L[j].mobnumber << endl;
                    count++;
                }
            }
            //enter which line user wants
            cout << "please enter your desired choice" << endl;
            cin >> choice;

            //if user enters invalid choice
            while (choice > count || choice <= 0)
            {
                cout << "In valid choice" << endl;
                cin >> choice;
            }


            U[i].L[choice - 1].balance--;
            cout << "new balance for" << " : " << U[i].L[choice - 1].mobnumber << " is " << U[i].L[choice - 1].balance << endl;
        }

    }

}





void operations(int id) {
    int operation;
    int continou;
    //check if user to continou operations or exit
    do {
        cout << "welcome to our service please choose an option below " << endl << endl;;
        cout << "To renew subscription Press 1" << endl << endl;
        cout << "To Recharge balance Press 2" << endl << endl;
        cout << "To Transfer balance Press 3" << endl << endl;
        cout << "To make a Call Press 4" << endl << endl;
        cout << "To send a Message Press 5" << endl << endl;

        //let user choose desired operation
        cin >> operation;

        //excuting user choice 
        switch (operation) {

        case 1: //when user choooses to change packtype
            renewSubscription(id);
            break;
        case 2: //when user chooses to recharge 
            recharge(id);
            break;

        case 3: //when user chooses to transfer balance
            transfer(id);
            break;
        case 4: //when user chooses to call
            call(id);
            break;
        case 5: //when user chooses to message
            message(id);
            break;
        default: //when user enters invalid choice
            cout << "In valid choice";
            break;

        }

        //ask user if he wants to countinou
        cout << "To make another operation press 1 ";
        cout << "if you want to wxit press any key";
        cin >> continou;
    } while (continou == 1);
    cout << "thank you ";

}

int  Login(int id) {
    for (int i = 0;i < 4;i++) {
        if (id == U[i].ID) {
            return(U[i].ID);
        }

    }
}






int main() {

    U[0].ID = "0100154320";
    U[0].address = "Rehab";
    U[0].Email = "ali@gmail.com";
    U[0].Name = "Ali";
    U[0].setoflines = 2;
    U[0].L[0].mobnumber = "0155412389";
    U[0].L[0].balance = 150;
    U[0].L[0].Packtype = "Card";
    U[0].L[0].rdate.day = 30;
    U[0].L[0].rdate.month = 11;
    U[0].L[0].rdate.year = 2009;
    U[0].L[1].mobnumber = 9544;
    U[0].L[1].balance = 540;
    U[0].L[1].Packtype = "Prepaid";
    U[0].L[1].rdate.day = 10;
    U[0].L[1].rdate.month = 10;
    U[0].L[1].rdate.year = 2010;


    U[1].ID = 12389;
    U[1].address = "Rehab";
    U[1].Email = "ali@gmail.com";
    U[1].Name = "Ali";
    U[1].setoflines = 1;
    U[1].L[0].mobnumber = 9542;
    U[1].L[0].balance = 320;
    U[1].L[0].Packtype = "prepaid";
    U[1].L[0].rdate.day = 30;
    U[1].L[0].rdate.month = 1;
    U[1].L[0].rdate.year = 2018;

    int id;
    cout << "please enter id" << endl;
    cin >> id;
    int currentUser = Login(id);
    operations(currentUser);

}






