#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string name,vector<string> &a,vector<int> &b,vector<char> &c){
    ifstream file (name);
    string text;
    char format[] ="%[^:]: %d %d %d";
    while(getline(file,text)){
        int i,j,k;
        char name[100];
        sscanf(text.c_str(),format,name,&i,&j,&k);
        a.push_back(name);
        b.push_back(i+j+k);
        c.push_back(score2grade(i+j+k));
    }
}

void getCommand(string &command, string &key){
    cout << "Please input your command: " ;
    cin >> command;
    if(toUpperStr(command) == "GRADE" || toUpperStr(command) == "NAME"){
        cin.ignore();
        getline(cin,key);
    }
    
}

void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key){
    
    int x=0;
    
    cout << "---------------------------------\n";

        for(unsigned int i=0; i<names.size() ;i++){
            if(key == toUpperStr(names[i])){
                cout << names[i] << "'s score = " << scores[i] << endl;
                cout << names[i] << "'s grade = " << grades[i] << endl;
                x++;
            }else if(i == names.size()-1 && x==0){
                cout << "Cannot found."<<endl;
            }
        }

    cout << "---------------------------------\n";

}

void searchGrade(vector<string> &names,vector<int> &scores,vector<char> &grades,string key)
{
    int a;
    cout << "---------------------------------\n";
        for(unsigned int i = 0;i<names.size();i++){
            if(*key.c_str() == grades[i]){
                cout << names[i] << " (" << scores [i]<< ")" << endl;
                a++;
            }else if (i == names.size()-1 && a==0){
                cout << "Cannot found"<< endl;
            }
        }
        cout << "---------------------------------\n";
    }


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
