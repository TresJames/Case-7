#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

void printTopNames(int n, vector <string> &femalenames, vector <string> &malenames, vector <int> malenumfreq, vector <int> femalenumfreq, ofstream& finaloutput);
int searchNames(const vector <string> &names, string input);



int main(int argc, char *argv[]) {
    ofstream finaloutput;
    finaloutput.open (argv[2]);
    int boyindex=-1, girlindex=-1, i;


    int freq;
    char gender;
    string names;
    
    if(argc != 4) {
        cout << "Wrong number of arguments " << endl << "Correct usage: ifilename ofilename #namesToPrint" << endl;
        return -1;
    }
    
    
    ifstream fin;
    fin.open(argv[1]);
    if(fin.fail()) {
        cout << argv[1] << " not opened";
        return -1;
    }
    
    int n;
    istringstream ss(argv[3]);
    ss >> n;
    
    vector <string> malenames, femalenames;
    vector <int> malenumfreq, femalenumfreq;
    
    while(fin >> names >> gender >> freq) {
        if (gender == 'M') {
            malenames.push_back(names);
            malenumfreq.push_back(freq);
        }
        else if (gender == 'F') {
            femalenames.push_back(names);
            femalenumfreq.push_back(freq);
        }
}

cout << setw(11) << left << "Name" << setw(10) << right << "Girl Rank" << setw(10) << right << "Frequency"
     << setw(10) << right << "Boy Rank" << setw(10) << right << "Frequency" << endl << endl;  
      

    string line, var1, var2;
     
   do{
       cin >> line;
   if (line == "")break;      
      ss.clear();
      ss.str(line);
      ss >> var1 >> var2;
      boyindex = searchNames(malenames, var1);
      girlindex = searchNames(femalenames, var1);  

if (boyindex == -1 && girlindex == -1) {
   cout << setw(11) << left << line << setw(10) << right << "---" << setw(10) << right << "---"     
   << setw(10) << right << "---" << setw(10) << right << "---" << endl << endl;  
      }

else if (girlindex == -1) {
      
    cout << setw(11) << left << line << setw(10) << right << "---" << setw(10) << right << "---" 
     << setw(10) << right << boyindex << setw(10) << right <<freq << endl << endl;  
      
}

else if (boyindex == -1) {
      
    cout << setw(11) << left << line << setw(10) << right << girlindex << setw(10) << right << freq     
   << setw(10) << right << "---" << setw(10) << right << "---" << endl << endl;  
      
}


else if(boyindex != -1 && girlindex != -1){
        cout << setw(11) << left << line << setw(10) << right << girlindex << setw(10) << right << freq     
   << setw(10) << right << boyindex << setw(10) << right << freq << endl << endl;  
     
}

     
      
}while(getline(cin,line));

     

    printTopNames(n, femalenames, malenames, malenumfreq, femalenumfreq, finaloutput);
    
    finaloutput.close();
    fin.close();
    return 0;
}

void printTopNames(int n, vector <string> &femalenames, vector <string> &malenames, vector <int> malenumfreq, vector <int> femalenumfreq, ofstream& finaloutput) {
    int i;
    
    finaloutput << n << " Most Popular Boys and Girls Names" << endl << endl << setw(10) << left << "Girls" << setw(10) << right << "Frequency" << "    " << 
    setw(10) << left << "Boys" << setw(10) << right << "Frequency" << endl;
    
    for (i = 0; i < femalenames.size(); i++) {
            if (i == n)
               break;
            finaloutput << left << setw(10) << femalenames[i] << right << setw(10) << femalenumfreq[i] << "    " 
            << left << setw(10) << malenames[i] << right << setw(10) << malenumfreq[i] << endl;
    }
}

int searchNames(const vector <string> &names, string input) {
int i;


for (i = 0; i < names.size(); i++) {
   if (names[i] == input) {
      return i+1;

   
}
}
return -1;
}
