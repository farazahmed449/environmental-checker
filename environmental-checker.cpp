#include <iostream>
#include <ctime>
using namespace std;


struct Reading {
    string type;
    float value;
    string status;
    string timeanddate;
};


string getCurrentDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}

int main() {
    Reading history[100];  
    int count = 0;         
    int choice;

    do {
        cout << "\n==== Simple Environmental Checker ====\n";
        cout << "1. Check Temperature\n";
        cout << "2. Check Pollution (AQI)\n";
        cout << "3. View History\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        

        if (choice == 1) {
            Reading temp;
            temp.type = "Temperature";
            

            cout << "Enter Temperature in Celsius: ";
            cin >> temp.value;
            

            if (temp.value < -100 || temp.value > 100) {
                cout << "Invalid temperature!\n";
                continue;
                
            }

            if (temp.value < 30)
            temp.status = "Safe";
            
            else if (temp.value <= 40)
            temp.status = "Moderate";
            
            else
            temp.status = "Dangerous";

            cout << "Status: " << temp.status << endl;

            temp.timeanddate = getCurrentDateTime(); 
            history[count] = temp;
            count++;
        }

        else if (choice == 2) {
            Reading pollution;
            pollution.type = "Pollution";

            cout << "Enter AQI (0 to 500): ";
            cin >> pollution.value;

            if (pollution.value < 0 || pollution.value > 500) {
            cout << "Invalid AQI!\n";
            continue;
            }

            if (pollution.value < 100)
            pollution.status = "Safe";
            
            else if (pollution.value <= 150)
            pollution.status = "Moderate";
            
            else
            pollution.status = "Dangerous";

            cout << "Status: " << pollution.status << endl;

            pollution.timeanddate = getCurrentDateTime();  
            history[count] = pollution;
            count++;
        }

        else if (choice == 3) {
            if (count == 0) {
                cout << "No history availabel.\n";
            } 
            
			else {
                cout << "\n--- History ---\n";
                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". " << history[i].type
                   << " = " << history[i].value
                   << " = " << history[i].status
                   << " (" << history[i].timeanddate << ")";
       }  
       }
       }

        else if (choice == 4) {
            cout << "Exiting... Stay Safe!\n";
        }
        

        else {
            cout << "Invalid option!\n";
        }
        

    } 
	
	while (choice != 4);

    return 0;
}
