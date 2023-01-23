#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include <vector>
#include <windows.h>

using namespace std;
double operate(double num1, double num2, char op){
    if (op == '*'){
        return num1 * num2;
    } else if (op == '+'){
        return num1 + num2;
    } else if (op == '-'){
        return num1 - num2;
    } else {
        return num1 / num2;
    }
}

int main() {
    string temp;
    string validate[17] = {"2","3","4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "j", "q", "k", "a"};
    char operators[4] = {'+', '-', '/', '*'};
    string file_name;
    string hasil;
    string angka[4];
    double angka_akhhir[4];
    string pilihan;
    int count = 0;
    bool exit = false;
    bool flag =  false;
    char blank;
    clock_t start, ends;
    while (!exit){
        vector <string> history;
        
                                                                                                    
        cout <<   ",---.    ,---.                                ,--." << endl;                                      
        cout <<   "'.-.  \\  /    |      ,---.  ,--,--. ,--.--.  ,-|  |      ,---.   ,--,--. ,--,--,--.  ,---." << endl;  
        cout <<   ".-' .' /  '  |     | .--' ' ,-.  | |  .--' ' .-. |     | .-. | ' ,-.  | |        | | .-. : " << endl;
        cout <<   " /   '-. '--|  |     \\ `--. \\ '-'  | |  |    \\ `-' |     ' '-' ' \\ '-'  | |  |  |  | \\   --." << endl; 
        cout <<   "'-----'    `--'      `---'  `--`--' `--'     `---'      .`-  /   `--`--' `--`--`--'  `----' " << endl;
        cout <<   "                                                        `---'                               " << endl;
  

        cout << "   24 Game solver " << endl;
        cout << "   1. Input by user" << endl;
        cout << "   2. Random generate number" << endl;
        cout << "   3. Exit" << endl;
        cout << "   > ";
        cin >> pilihan;
        if (pilihan == "1"){
            cout << "   > ";
                for (int i = 0; i < 4; i++){
                    cin >> angka[i];
                    while (find(begin(validate), end(validate), angka[i]) == end(validate)){
                        cout << "   Invalid input" << endl;
                        cout << "   > ";
                        cin >> angka[i];
                    }

            }
            cout << angka[0] << " " << angka[1] << " " << angka[2] << " " << angka[3] << endl;

            // convert j q k a to 11 12 13 1
            for (int i = 0; i < 4; i++){
                if (angka[i] ==  "J" || angka[i] == "j"){
                    angka_akhhir[i] = 11;
                } else if (angka[i] ==  "Q" || angka[i] == "q"){
                    angka_akhhir[i] = 12;
                } else if (angka[i] ==  "K" || angka[i] == "k"){
                    angka_akhhir[i] = 13;
                } else if (angka[i] ==  "A" || angka[i] == "a"){
                    angka_akhhir[i] = 1;
                } else {
                    angka_akhhir[i] = stod(angka[i]); 
                }
            }
            

        } else if (pilihan == "2"){
            srand(time(0));

            // convert 11 12 13 1 to j q k a
            for (int i  = 0; i < 4; i++){
                angka_akhhir[i] = (rand() % 13) + 1;
                if (angka_akhhir[i] ==  13){
                    angka[i] = "K";
                } else if (angka_akhhir[i] ==  12){
                    angka[i] = "Q";
                } else if (angka_akhhir[i] == 11){
                    angka[i] = "J";
                } else if (angka_akhhir[i] == 1){
                    angka[i] = "A";
                } else {
                    angka[i] = to_string(int(angka_akhhir[i]));
                }
            }
            cout << angka[0] << " " << angka[1] << " " << angka[2] << " " << angka[3] << endl;

        } else if (pilihan == "3"){
            exit = true;
            cout << "   Have a great day ^^" << endl;
        }
        else {
            cout << "Invalid input" << endl;
        }

        if (pilihan == "1" || pilihan == "2"){
            flag = false;
            start = clock();
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    for (int k = 0; k < 4; k++){
                        for (int l = 0; l < 4; l++){
                            if (i != j && j != k && i != k && j != l && k != l && i != l){
                                for (int m = 0; m < 4; m++){
                                    for (int n = 0; n < 4; n++){
                                        for (int o = 0; o < 4; o++){

                                            // (a op b) op (c op d)
                                            if (operate(operate(angka_akhhir[i], angka_akhhir[j], operators[m]), operate(angka_akhhir[k], angka_akhhir[l], operators[o]), operators[n]) == 24) {
                                                hasil = "(" + to_string(int(angka_akhhir[i])) + " " + operators[m] + " " + to_string(int(angka_akhhir[j])) + " ) " + operators[n] + " (" + to_string(int(angka_akhhir[k])) + " " + operators[o] + " " + to_string(int(angka_akhhir[l])) + ")";
                                                history.push_back(hasil);
                                                
                                                
                                            }
                                            // ((a op b) op c) op d
                                            if (operate(operate(operate(angka_akhhir[i], angka_akhhir[j], operators[m]), angka_akhhir[k], operators[n]), angka_akhhir[l], operators[o]) == 24) {
                                                hasil = "(( " + to_string(int(angka_akhhir[i])) + " " + operators[m] + " " + to_string(int(angka_akhhir[j])) + " ) " + operators[n] + " " + to_string(int(angka_akhhir[k])) + " ) " + operators[o] + " " + to_string(int(angka_akhhir[l]));
                                                history.push_back(hasil);
                                                
                                                
                                            }
                                            // (a op (b op c)) op d
                                            if (operate(operate(angka_akhhir[i], operate(angka_akhhir[j], angka_akhhir[k], operators[n]), operators[m]), angka_akhhir[l], operators[o]) == 24) {
                                                hasil = "(" + to_string(int(angka_akhhir[i])) + " " + operators[m] + " ( " + to_string(int(angka_akhhir[j])) + " " + operators[n] + " " + to_string(int(angka_akhhir[k])) + " )) " + operators[o] + " " + to_string(int(angka_akhhir[l]));
                                                history.push_back(hasil);
                                                
                                                
                                            }
                                            // a op ((b op c) op d)
                                            if (operate(angka_akhhir[i], operate(operate(angka_akhhir[j], angka_akhhir[k], operators[n]), angka_akhhir[l], operators[o]), operators[m]) == 24) {
                                                hasil = to_string(int(angka_akhhir[i])) + " " + operators[m] + " (( " + to_string(int(angka_akhhir[j])) + " " + operators[n] + " " + to_string(int(angka_akhhir[k])) + " ) " + operators[o] + " " + to_string(int(angka_akhhir[l])) + ")";
                                                history.push_back(hasil);
                                                
                                                
                                            }
                                            // a op (b op (c op d))
                                            if (operate(angka_akhhir[i], operate(angka_akhhir[j], operate(angka_akhhir[k], angka_akhhir[l], operators[o]), operators[n]), operators[m]) == 24) {
                                                hasil = to_string(int(angka_akhhir[i])) + " " + operators[m] + " ( " + to_string(int(angka_akhhir[j])) + " " + operators[n] + " ( " + to_string(int(angka_akhhir[k])) + " " + operators[o] + " " + to_string(int(angka_akhhir[l])) + " ))";
                                                history.push_back(hasil);
                                                
                                            }
                                            

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

        // calculate time
        ends = clock();
        double time_taken = double(ends - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken : " << time_taken << setprecision(5) << " sec " << endl;
        if (history.size() == 0){
            cout << "No Solution!" << endl;
            
        }
        else{

            // sort, remove duplicate, and print solution
            sort( history.begin(), history.end() );
            history.erase( unique( history.begin(), history.end() ), history.end() );
            cout << history.size() << " Solution found!" << endl;
            for (int i = 0; i < history.size(); i++){
                cout << history[i] << endl;
            } 

            // save file
            while(!flag){
            cout << "Apakah ingin menyimpan solusi ? (y/n)" << endl;
            cout << "   > ";
            cin >> pilihan;
            if (pilihan == "y" || pilihan == "Y"){
                flag = true;
                cout << "Masukkan nama file untuk menyimpan hasil solusi!" << endl;
                cout << "   > ";
                cin >> file_name;
                cout << "Saving file..." << endl;
                ofstream save_file ("../test/" + file_name + ".txt");
                for (int i = 0; i < history.size(); i++){
                    save_file << history[i] << endl;
                }
                save_file.close();
                Sleep(2000);
                cout << "File berhasil disimpan!" << endl;
            } else if (pilihan == "n" || pilihan == "N"){
                flag = true;
                cout << "File tidak disimpan!" << endl;
                
                
            } else {
                cout << "Invalid input" << endl;
            }
    
        }
    }

    }

    }

}